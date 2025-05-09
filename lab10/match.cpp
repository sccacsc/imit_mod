#include "match.h"
#include <utility>
#include <random>
#include <climits>


unsigned int gen_seed(){
    std::random_device rd;  // может использовать аппаратный генератор
    std::mt19937 gen(rd()); // Mersenne Twister

    // Диапазон от 0 до UINT_MAX
    std::uniform_int_distribution<unsigned int> dist(0, UINT_MAX);

    return dist(gen);
}

Match::Match(std::string t1, std::string t2) : poisson_gen(gen_seed(), 1.7){
    team_score_1.first = t1; team_score_1.second = 0;
    team_score_2.first = t2; team_score_1.second = 0;
}

Match::Match(QLabel* sc_1, QLabel* sc_2) : poisson_gen(gen_seed(), 1.7),
    lbl_team_score_1(sc_1),
    lbl_team_score_2(sc_2){
    //team_score_1.first = team_1->text().toStdString();
    team_score_1.second = 0;
    //team_score_2.first = team_2->text().toStdString();
    team_score_1.second = 0;
}

Match::Match(QLabel* sc_1, QLabel* sc_2, QLabel* t_1, QLabel* t_2) : poisson_gen(gen_seed(), 1.7),
    lbl_team_1(t_1),
    lbl_team_2(t_2),
    lbl_team_score_1(sc_1),
    lbl_team_score_2(sc_2)
{
    team_score_1.first = t_1->text().toStdString();
    team_score_1.second = 0;
    team_score_2.first = t_2->text().toStdString();
    team_score_1.second = 0;
}

Match::~Match() = default;

std::pair<std::string, unsigned int> Match::play_match(){
    while(true){
        team_score_1.second = poisson_gen.generate();
        team_score_2.second = poisson_gen.generate();

        if(lbl_team_score_1 != nullptr && lbl_team_score_2 != nullptr){
            lbl_team_1->setText(QString::fromStdString(team_score_1.first));
            lbl_team_2->setText(QString::fromStdString(team_score_2.first));
            lbl_team_score_1->setText(QString::number(team_score_1.second));
            lbl_team_score_2->setText(QString::number(team_score_2.second));
        }

        if(team_score_1.second > team_score_2.second){
            return team_score_1;
        }
        else if(team_score_1.second < team_score_2.second){
            return team_score_2;
        }
    }
}
