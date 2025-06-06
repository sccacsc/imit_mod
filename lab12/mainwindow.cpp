#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "MCCT.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    Mark_chain_cont_time mcct(100000);
    mcct.imit();
    mcct.dur_output();

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
