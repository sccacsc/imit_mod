#include "MCCT.h"
#include "MTG.h"
#include <QDebug>
#include <cmath>

Mark_chain_cont_time::Mark_chain_cont_time(int num, int size, unsigned int seed, std::vector<std::vector<float>> mQ)
    : N(num), matrixSize(size), time(0) {

    dur = std::vector<float>(matrixSize, 0.0f);
    mtg = new MTG(seed);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Mark_chain_cont_time::step);

    if (mQ.empty()) {
        m_Q = {
            {-11, 3, 8},
            {8, -10, 2},
            {6, 1, -7}
        };
        float lambda = 0.1f;
        for (auto& row : m_Q)
            for (auto& val : row)
                val *= lambda;
    } else {
        m_Q = mQ;
    }
}

void Mark_chain_cont_time::dur_output() {
    for (int i = 0; i < matrixSize; ++i) {
        dur[i] /= time;
        //qDebug() << "P" << i << "=" << dur[i];
        switch (i) {
        case 0: qDebug() << "☀️ Clear" << "=" << dur[i]; break;
        case 1: qDebug() << "⛅ Cloudy" << "=" << dur[i]; break;
        case 2: qDebug() << "🌧️ Overcast" << "=" << dur[i]; break;
        default: qDebug() << "Unknown";
        }
    }
}

int Mark_chain_cont_time::get_next_state(const std::vector<float>& row, int cur_state) {
    auto A = mtg->generate();
    int k = 0;
    do{
        if(k != cur_state){
            A += row[k] / row[cur_state];
        }
        ++k;
    }
    while(A > 0);
    return k - 1;
}

void Mark_chain_cont_time::start() {
    stepsDone = 0;
    currentState = 0;
    time = 0;
    std::fill(dur.begin(), dur.end(), 0.0f);
    schedule_next_step();
}

void Mark_chain_cont_time::schedule_next_step() {
    if (stepsDone >= N) {
        dur_output();
        return;
    }

    float U = mtg->generate();
    float tau = -log(U) / (-m_Q[currentState][currentState]);
    int delay_ms = static_cast<int>(1000);

    dur[currentState] += tau;
    time += tau;

    currentState = get_next_state(m_Q[currentState], currentState);
    stepsDone++;

    emit stateChanged(currentState);
    qDebug() << "t =" << time << "| state =" << currentState;

    timer->start(delay_ms);
}

void Mark_chain_cont_time::step() {
    timer->stop();
    schedule_next_step();
}

int Mark_chain_cont_time::get_day(){
    return static_cast<int>(time);
}
