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
    void on_pushButton_2_clicked(bool checked);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    bool inline check();
    void inline visual();
    void inline calculation();
    Ui::MainWindow *ui;
    int probCount = 0;
    std::vector<float> probs;
    std::vector<QLineEdit*> probsInput;
    std::vector<float> statistic;
    MTG* gen = new MTG(123134123);
    bool flagChart = false;

    QChart* chart;
    QChartView* chartView;

};
#endif // MAINWINDOW_H
