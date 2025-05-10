#include "norm_dis.h"
#include "mtgen.h"

#include <cmath>
#include <algorithm>
#include <QString>
#include <QStringList>



Norm_distr::Norm_distr(unsigned int n, float mn, float var, unsigned int sd) : seed(sd),
    N(n),
    k(std::ceil(std::sqrt(N))),
    mean(mn),
    variance(var),
    gen(sd),
    chi_squared(0.0f){
}

Norm_distr::~Norm_distr() = default;

float Norm_distr::generate(){
    float sum = 0;
    for(unsigned int i = 0; i < 12; ++i){
        sum += gen.generate();
    }
    return mean + std::sqrt(variance)*(sum - 6);
}

void Norm_distr::generate_N(){
    for(unsigned int i = 0; i < N; ++i){
        norm_values.push_back(generate());
    }
}


double normal_cdf(double x, double mean, double std_dev) {
    return 0.5 * (1.0 + std::erf((x - mean) / (std_dev * std::sqrt(2))));
}

std::vector<unsigned int> Norm_distr::generate_statistic() {
    auto min = *(std::min_element(norm_values.begin(), norm_values.end())) - 0.1f;
    auto max = *(std::max_element(norm_values.begin(), norm_values.end())) + 0.1f;  // лучше чуть расширить
    float step = (max - min) / float(k);
    std::vector<unsigned int> stat(k, 0);

    for (auto& value : norm_values) {
        int index = static_cast<int>((value - min) / step);
        if (index >= 0 && index < k)
            ++stat[index];
        else if (index == k)
            ++stat[k - 1];
    }

    for(auto i = 0; i < k; ++i){
        float ni = static_cast<float>(stat[i]);
        float left = min + i * step; float right = left + step;
        float pi = normal_cdf(right, mean, std::sqrt(variance)) - normal_cdf(left, mean, std::sqrt(variance));
        chi_squared += (ni * ni) / (N * pi);
    }
    chi_squared -= N;

    return stat;
}

std::vector<unsigned int> Norm_distr::generate_statistic(QStringList* categories) {
    auto min = *(std::min_element(norm_values.begin(), norm_values.end())) - 0.1f;
    auto max = *(std::max_element(norm_values.begin(), norm_values.end())) + 0.1f;  // лучше чуть расширить
    float step = (max - min) / float(k);
    std::vector<unsigned int> stat(k, 0);

    for (auto& value : norm_values) {
        int index = static_cast<int>((value - min) / step);
        if (index >= 0 && index < k)
            ++stat[index];
        else if (index == k)  // значение == max может попасть в последний интервал
            ++stat[k - 1];
    }

    for(auto i = 0; i < k; ++i){
        float ni = static_cast<float>(stat[i]);
        float left = min + i * step; float right = left + step;
        float pi = normal_cdf(right, mean, std::sqrt(variance)) - normal_cdf(left, mean, std::sqrt(variance));
        chi_squared += (ni * ni) / (N * pi);
    }
    chi_squared -= N;

    for (int i = 0; i < k; ++i) {
        float left = min + i * step;
        float right = left + step;
        QString label = QString("[%1; %2)").arg(left, 0, 'f', 2).arg(right, 0, 'f', 2);
        *categories << label;
    }

    return stat;
}

float Norm_distr::get_chi_squared(){
    return chi_squared;
}

float Norm_distr::get_emp_mean(){
    float sum = 0;
    for(auto &x : norm_values){
        sum += x;
    }
    emp_mean = sum / N;
    return emp_mean;
}
float Norm_distr::get_emp_var(){
    float sum = 0;
    for(auto &x : norm_values){
        sum += (x * x);
    }
    return (sum / N) - (emp_mean * emp_mean);
}

void Norm_distr::change_seed(unsigned int sd){
    seed = sd;
}

std::vector<float> Norm_distr::get_norm_values(){
    return norm_values;
}
