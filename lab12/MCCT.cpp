#include "MCCT.h"
#include "MTG.h"

#include <QDebug>

#include <iostream>

Mark_chain_cont_time::Mark_chain_cont_time(int num, int size, unsigned int seed, std::vector<std::vector<float>> mQ) : N(num),
    time(0){
    matrixSize = size;
    dur = {0,0,0};
    mtg = new MTG(seed);

    if(mQ.empty()){
        m_Q = {
                                               {-11, 3, 8}, //из лекций
                                               {8, -10, 2},
                                               {6, 1, -7},
                                               };
    }

    else {m_Q = mQ;}
}

void Mark_chain_cont_time::dur_output(){
    for(int i = 0; i < matrixSize; ++i){
        dur[i] /= time; //t из method()
        std::cout << "P" << i << " = " << dur[i] << std::endl;
    }
}

int Mark_chain_cont_time::get_next_state(std::vector<float> next_possible_state, int cur_state){
    auto A = mtg->generate();
    int k = 0;
    do{
        if(k != cur_state){
        A += next_possible_state[k] / next_possible_state[cur_state];
        }
        ++k;
    }
    while(A > 0);
    return k - 1;
}

void Mark_chain_cont_time::imit(){
    int i = 0;
    for(int k = 0; k < N; ++k){
        float tau = log(mtg->generate()) / -m_Q[i][i];
        dur[i] += tau;
        time += tau;

        i = get_next_state(m_Q[i], i);

        //qDebug() << "Time: " << time << " \nState: " << i;
    }
}

