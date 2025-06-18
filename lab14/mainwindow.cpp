#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow),
    timer(new QTimer(this)), model(new Model),
    bank(new Bank(3)), input(new InputFlow(bank)) {

    ui->setupUi(this);
    global_model = model;

    model->add_event(new arrival_event(0.0f, input));

    connect(timer, &QTimer::timeout, this, &MainWindow::on_timer_tick);
    timer->start(1000);
}

MainWindow::~MainWindow() {
    delete ui;
    delete bank;
    delete input;
    delete model;
}

void MainWindow::on_timer_tick() {
    if (model->has_events()) {
        model->run_step();
        ui->queueSizeLabel->setText("В очереди: " + QString::number(bank->queue_size()));
        ui->timeLabel->setText("Текущее время: " + QString::number(model->current_time()));
        ui->servedLabel->setText("Обслужено: " + QString::number(bank->served()));

    }
}
