#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    probCount(0),
    flagChart(false),
    mtgGen( new MTG(124432132))
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mtgGen;
}

bool inline MainWindow::check(){
    for(auto i : probsInput){
        probs.push_back((i->text()).toFloat());
    }
    auto sum = std::accumulate(probs.begin(), probs.end(), 0.0f);
    if(sum < 1){
        probs.push_back(1-sum);
    }
    else if (sum > 1) return 0;

    statistic = std::vector<float>(probs.size(), 0);

    return 1;
}

void inline MainWindow::calculation(){
    for(auto j = 0; j < ui->spinBoxNexp->value(); ++j){
        float some = mtgGen->generate();
        for(auto i = 0; i < probs.size(); ++i){
            if((some - probs[i]) <= 0){
                statistic[i] = 1 + statistic[i];
                break;
            }
            else some -= probs[i];
        }
    }

}

void inline MainWindow::visual(){
    auto N = ui->spinBoxNexp->value();
    //наблюдаемые вероятности
    for(auto i = 0; i < empiricalProbs.size(); ++i){
        empiricalProbs[i]->setText(QString::number(statistic[i] / N));
    }

    QBarSet *set0 = new QBarSet("График частот");
    for(float val : statistic){
        *set0 << static_cast<qreal>(val / N);
    }

    //среднее наблюдаемое
    float empirical_mean = 0.0f;
    for(int i = 0; i < statistic.size(); ++i){
        empirical_mean += (i+1) * (statistic[i] / N);
    }
    ui->meanE->setText(QString::number(empirical_mean));

    //дисперсия наблюдаемая
    double empirical_var = 0.0;
    for (size_t i = 0; i < statistic.size(); ++i) {
        empirical_var += (((i+1) - empirical_mean) * ((i+1) - empirical_mean)) * (statistic[i] / N);
    }

    ui->varianceE->setText(QString::number(empirical_var));

    //среднее теор.
    float mean = 0.0f;
    for (size_t i = 0; i < probs.size(); ++i) {
        mean += (i+1) * probs[i];
    }
    ui->meanT->setText(QString::number(mean));

    //дисперсия теор
    double var = 0.0;
    for (size_t i = 0; i < probs.size(); ++i) {
        var += (((i+1) - mean) * ((i+1) - mean)) * probs[i];
    }
    ui->varianceT->setText(QString::number(var));

    //Погрешности
    ui->lbl_err_var->setText(QString::number(abs(empirical_var - var) / var * 100) + " %");
    ui->lbl_err_mean->setText(QString::number(abs(empirical_mean - mean) / mean * 100)+ " %");

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

void MainWindow::on_startButton_clicked()
{
    probs.clear();
    statistic.clear();

    if(check()){
        calculation();
        visual();
    }
    else QMessageBox::critical(this, "Ошибка", "Сумма вероятностей больше 1");
}


void MainWindow::on_addProbBtn_clicked()
{
    QWidget* wdg = new QWidget();

    QHBoxLayout* lay = new QHBoxLayout();

    QLabel* empLbl = new QLabel("Наблюдаемая вероятность");

    QLineEdit* lineEdit = new QLineEdit();  // Создаём поле для ввода
    lineEdit->setPlaceholderText("0..1");
    lineEdit->setAlignment(Qt::AlignRight);

    QDoubleValidator* validator = new QDoubleValidator(lay);
    lineEdit->setValidator(validator);  // Применяем валидацию для чисел с плавающей точкой

    lay->addWidget(lineEdit); lay->addWidget(empLbl);

    wdg->setLayout(lay);

    if(probCount < 7){
        ui->verticalLayout->addWidget(wdg);
        probsInput.push_back(lineEdit);
        empiricalProbs.push_back(empLbl);
        ++probCount;
    }

}

