#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCharts>
#include <random>

#include "norm_dis.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    nd(nullptr),
    flagChart(false)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

unsigned int gen_seed(){
    std::random_device rd;  // может использовать аппаратный генератор
    std::mt19937 gen(rd()); // Mersenne Twister

    // Диапазон от 0 до UINT_MAX
    std::uniform_int_distribution<unsigned int> dist(0, UINT_MAX);

    return dist(gen);
}

float get_chi_squared_crit(int dof) {
    static const std::map<int, float> chi_crit_05 = {
        {1, 3.841}, {2, 5.991}, {3, 7.815}, {4, 9.488}, {5, 11.070},
        {6, 12.592}, {7, 14.067}, {8, 15.507}, {9, 16.919}, {10, 18.307},
        {11, 19.675}, {12, 21.026}, {13, 22.362}, {14, 23.685}, {15, 24.996},
        {16, 26.296}, {17, 27.587}, {18, 28.869}, {19, 30.144}, {20, 31.410}
    };

    if (chi_crit_05.count(dof)) {
        return chi_crit_05.at(dof);
    } else {
        qDebug() << "Степень свободы вне диапазона таблицы (1–20)";
    }
    return -1.0;
}

void MainWindow::on_pushButton_clicked()
{
    // Безопасное удаление nd
    if (nd != nullptr) {
        delete nd;
        nd = nullptr;
    }

    unsigned int N = ui->dsb_N->value();
    nd = new Norm_distr(N, ui->dsb_mean->value(), ui->dsb_var->value(), gen_seed());
    nd->generate_N();

    QStringList categories;

    auto stat = nd->generate_statistic(&categories);

    float chi_squared = nd->get_chi_squared();
    float chi_squared_crit = get_chi_squared_crit(categories.size() - 2 -1);
    ui->chi_squared->setText("Хи-квадрат " + QString::number(chi_squared) + " > " +
                             QString::number(chi_squared_crit) + "?"+
                                     (chi_squared > chi_squared_crit ? " Отвергаем гипотезу" : " Принимаем гипотезу"));

    ui->emp_mean->setText(QString::number(nd->get_emp_mean()));
    ui->emp_var->setText(QString::number(nd->get_emp_var()));

    QBarSet *set0 = new QBarSet("График частот");
    for (auto st : stat) {
        *set0 << static_cast<qreal>(st) / N; // обязательно скобки!
    }

    QBarSeries *series = new QBarSeries();
    series->append(set0);

    if(!flagChart){
        // Создание диаграммы
        chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Столбчатая диаграмма");
        chart->setAnimationOptions(QChart::SeriesAnimations);

        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        // Отображение в ChartView
        chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        // Вставка в UI
        QVBoxLayout *layout = new QVBoxLayout(ui->wdg_graph);
        layout->addWidget(chartView);
        flagChart = true;
    }
    else{
        // Удаляем старую серию и оси
        chart->removeAllSeries();

        for (auto axis : chart->axes()) {
            chart->removeAxis(axis);
        }

        // Добавляем серию
        chart->addSeries(series);

        // Создаем новую ось X с нужными метками
        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        // Создаем ось Y
        QValueAxis *axisY = new QValueAxis();
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        // Обновляем
        chart->update();

    }


}
