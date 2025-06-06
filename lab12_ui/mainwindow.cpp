#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "MCCT.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , simulator(nullptr)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_startButton_clicked() {
    if (simulator) {
        delete simulator;
    }

    simulator = new Mark_chain_cont_time(100000, 3, 42);
    connect(simulator, &Mark_chain_cont_time::stateChanged, this, &MainWindow::updateStateLabel);
    simulator->start();
}

void MainWindow::updateStateLabel(int state) {
    QString text;
    switch (state) {
    case 0: text = "☀️ Clear"; break;
    case 1: text = "⛅ Cloudy"; break;
    case 2: text = "🌧️ Overcast"; break;
    default: text = "Unknown";
    }
    ui->labelState->setText("Current state: " + text);
    ui->labelDay->setText("Day " + QString::number(simulator->get_day()));
}
