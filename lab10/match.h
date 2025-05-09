#ifndef MATCH_H
#define MATCH_H

#include "poisson_distribution.h"
#include "qlabel.h"

#include <string>

class Match{
public:
    Match(std::string t1, std::string t2);
    Match(QLabel* sc_1, QLabel* sc_2);
    Match(QLabel* sc_1, QLabel* sc_2, QLabel* t_1, QLabel* t_2);
    ~Match();
    std::pair<std::string, unsigned int> play_match();
private:
    std::pair<std::string, unsigned int> team_score_1, team_score_2;
    Poisson_distribution poisson_gen;
    QLabel* lbl_team_1 = nullptr;
    QLabel* lbl_team_2 = nullptr;
    QLabel* lbl_team_score_1 = nullptr;
    QLabel* lbl_team_score_2 = nullptr;
};

#endif // MATCH_H
