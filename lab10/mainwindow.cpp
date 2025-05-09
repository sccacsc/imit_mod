#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "match.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QLabel* MainWindow::create_ui_name(QHBoxLayout* layot_ui){
    QLabel* name_label = new QLabel(this);
    layot_ui->addWidget(name_label);

    return name_label;
}

QLabel* MainWindow::create_ui_score(QHBoxLayout* layot_ui){
    QLabel* score_label = new QLabel(this);
    layot_ui->addWidget(score_label);

    return score_label;
}


std::vector<Match> MainWindow::play_round(std::vector<Match> matchs, QVBoxLayout* layot_ui){
    std::vector<Match> temp;
    for (auto it = matchs.begin(); it != matchs.end(); ++it){

        QVBoxLayout* lay = new QVBoxLayout();
        QWidget *layWidget = new QWidget();
        layWidget->setStyleSheet("background-color: black; border: 2px solid #001f4d;");
        layWidget->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        layWidget->setLayout(lay);
        layot_ui->addWidget(layWidget);

        auto result_1 = it->play_match();
        QHBoxLayout* lay_1  = new QHBoxLayout();
        lay->addLayout(lay_1);
        QLabel* team_name_1 = create_ui_name(lay_1);
        team_name_1->setText(QString::fromStdString(result_1.first));
        QLabel* score_1 = create_ui_score(lay_1);

        if(matchs.size() == 1){

        }
        else{
            ++it;
            auto result_2 = it->play_match();

            QHBoxLayout* lay_2  = new QHBoxLayout();
            lay->addLayout(lay_2);
            QLabel* team_name_2 = create_ui_name(lay_2);
            team_name_2->setText(QString::fromStdString(result_2.first));
            QLabel* score_2 = create_ui_score(lay_2);

        temp.push_back(Match(score_1, score_2, team_name_1, team_name_2));
        }
    }
    return temp;
}

void MainWindow::on_pushButton_clicked()
{
    ui->pushButton->setText("Следующий\nтур");

    if(counter == 0){
        std::vector<Match> matchs_of_16 = {
            Match(ui->lbl_team_score_23, ui->lbl_team_score_24, ui->lbl_team_name_23, ui->lbl_team_name_24),
            Match(ui->lbl_team_score_21, ui->lbl_team_score_22, ui->lbl_team_name_21, ui->lbl_team_name_22),
            Match(ui->lbl_team_score_19, ui->lbl_team_score_20, ui->lbl_team_name_19, ui->lbl_team_name_20),
            Match(ui->lbl_team_score_17, ui->lbl_team_score_18, ui->lbl_team_name_17, ui->lbl_team_name_18),
            Match(ui->lbl_team_score_15, ui->lbl_team_score_16, ui->lbl_team_name_15, ui->lbl_team_name_16),
            Match(ui->lbl_team_score_13, ui->lbl_team_score_14, ui->lbl_team_name_13, ui->lbl_team_name_14),
            Match(ui->lbl_team_score_3, ui->lbl_team_score_4, ui->lbl_team_name_3, ui->lbl_team_name_4),
            Match(ui->lbl_team_score_5, ui->lbl_team_score_6, ui->lbl_team_name_5, ui->lbl_team_name_6)
        };
        matchs_of_semifinals = play_round(matchs_of_16, ui->quarterfinals);
        ++counter;
    }

    else if(counter == 1){
    match_of_finals = play_round(matchs_of_semifinals, ui->semifinals);
        ++counter;
    }
    else if(counter == 2){
        match_of_grandfinals = play_round(match_of_finals, ui->finals);
        ++counter;
    }
    else if(counter == 3){
        play_round(match_of_grandfinals, ui->winner);
        ++counter;

    }
    else {};


}

