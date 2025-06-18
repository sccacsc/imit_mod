#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "model.h"
#include "agent.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_timer_tick();

private:
    Ui::MainWindow *ui;
    QTimer* timer;
    Model* model;
    Bank* bank;
    InputFlow* input;
};

#endif // MAINWINDOW_H
