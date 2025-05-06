#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLineEdit>
#include <QDoubleValidator>
#include <numeric>

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

void MainWindow::on_pushButton_2_clicked(bool checked)
{

}

bool inline MainWindow::check(){
    for(auto i : probsInput){
        probs.push_back((i->text()).toFloat());
    }
    auto sum = std::accumulate(probs.begin(), probs.end(), 0.0f);
    if(sum != 1){
        probs.push_back(1-sum);
    }
    statistic = std::vector<float>(probs.size(), 0);

    return 1;
}

void inline MainWindow::visual(){

    QBarSet *set0 = new QBarSet("График частот");
    for(float val : statistic){
        *set0 << static_cast<qreal>(val / ui->spinBox->value());
    }
    QBarSeries *series = new QBarSeries();
    series->append(set0);

    QStringList categories;
    for(auto i = 0; i < statistic.size(); ++i){
        categories << QString::number(i + 1);
    }

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
    QVBoxLayout *layout = new QVBoxLayout(ui->chartContainer);
        layout->addWidget(chartView);
    flagChart = true;
        }
        else{
            chart->removeAllSeries();
            // Добавление серии на график
            chart->addSeries(series);

            // Повторная настройка осей (если нужно)
            chart->createDefaultAxes();

            // Обновление графика
            chart->update();
        }
}

void inline MainWindow::calculation(){
    for(auto j = 0; j < ui->spinBox->value(); ++j){
        float some = gen->generate();
        for(auto i = 0; i < probs.size(); ++i){
            if((some - probs[i]) <= 0){
                statistic[i] = 1 + statistic[i];
                break;
            }
            else some -= probs[i];
        }
    }

}

void MainWindow::on_pushButton_clicked()
{
    probs.clear();
    statistic.clear();

    if(check()){
        calculation();
        visual();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QWidget* wdg = new QWidget();

    QHBoxLayout* lay = new QHBoxLayout();
    QLabel* lbl = new QLabel();

    QLineEdit* lineEdit = new QLineEdit();  // Создаём поле для ввода
    lineEdit->setPlaceholderText("0..1");

    QDoubleValidator* validator = new QDoubleValidator(lay);
    lineEdit->setValidator(validator);  // Применяем валидацию для чисел с плавающей точкой

    lay->addWidget(lbl); lay->addWidget(lineEdit);

    wdg->setLayout(lay);

    if(probCount < 7){
        ui->verticalLayout->addWidget(wdg);
        probsInput.push_back(lineEdit);
        ++probCount;        // Добавляем в layout
    }

}

