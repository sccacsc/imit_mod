#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>

#include "mtgen.h"

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

private slots:
    void on_startButton_clicked();

    void on_addProbBtn_clicked();

private:
    Ui::MainWindow *ui;

    //chart
    bool inline check();
    void inline visual();
    QChart* chart;
    QChartView* chartView;
    int probCount;
    std::vector<QLineEdit*> probsInput;
    bool flagChart;

    //modeling
    void inline calculation();
    std::vector<float> probs;
    std::vector<float> statistic;
    std::vector<QLabel*> empiricalProbs;

    //gen
    MTG* mtgGen;

};
#endif // MAINWINDOW_H
