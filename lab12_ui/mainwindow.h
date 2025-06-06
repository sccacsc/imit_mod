#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "MCCT.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateStateLabel(int state);
    void on_startButton_clicked();

private:
    Ui::MainWindow *ui;
    Mark_chain_cont_time* simulator;
};

#endif // MAINWINDOW_H
