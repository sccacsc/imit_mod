#ifndef MCCT_H
#define MCCT_H

#include <vector>

class MTG;

class Mark_chain_cont_time{ //моделируется цепь маркова с непрерывным временем
private:
    int N; //число объём выборки
    float time; //время

    int matrixSize; //размер матриц перехода и вероятностей
    std::vector<std::vector<float>> m_Q; // матрица переходов

    std::vector<float> dur; //матрица для статистики

    int get_next_state(std::vector<float> next_possible_state, int cur_state);
    MTG* mtg;
public:
    Mark_chain_cont_time(int num, int size = 3, unsigned int seed = 1231213, std::vector<std::vector<float>> mQ = {});
    void dur_output();
    void imit();
};

#endif // MCCT_H
