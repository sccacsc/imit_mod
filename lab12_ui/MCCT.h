#ifndef MCCT_H
#define MCCT_H

#include <QObject>
#include <QTimer>
#include <vector>

class MTG;

class Mark_chain_cont_time : public QObject {
    Q_OBJECT

public:
    Mark_chain_cont_time(int num, int size, unsigned int seed, std::vector<std::vector<float>> mQ = {});
    void dur_output();
    void start();
    int get_day();

signals:
    void stateChanged(int state);

private slots:
    void step();

private:
    int N;
    int matrixSize;
    int stepsDone = 0;
    int currentState = 0;
    float time;
    std::vector<float> dur;
    std::vector<std::vector<float>> m_Q;
    MTG* mtg;
    QTimer* timer;

    int get_next_state(const std::vector<float>& row, int cur_state);
    void schedule_next_step();
};

#endif // MCCT_H
