#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Match;
class QHBoxLayout;
class QVBoxLayout;
class QLabel;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    std::vector<Match> play_round(std::vector<Match> matchs, QVBoxLayout* layot_ui);
    QLabel* create_ui_name(QHBoxLayout* layot_ui);
    QLabel* create_ui_score(QHBoxLayout* layot_ui);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    int counter = 0;
    std::vector<Match> matchs_of_semifinals;
    std::vector<Match> match_of_finals;
    std::vector<Match> match_of_grandfinals;
};
#endif // MAINWINDOW_H
