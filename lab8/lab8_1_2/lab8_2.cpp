#include "lab8_2.h"
#include "mtGenerator.h"

#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDebug>
#include <QLineEdit>

lab8_2::lab8_2(QObject *parent) : QObject(parent){
    unsigned int seed = 31436345;
    generator = new MTG(seed);

    probs = std::vector<float>(20, 0.05);

    QWidget *window = new QWidget();

    QLineEdit *lineEdit = new QLineEdit(window);
    lineEdit->setText("Введите Ваш вопрос");
    lineEdit->setAlignment(Qt::AlignCenter);

    QPushButton *predictButton  = new QPushButton(window);
    predictButton->setText("Предсказать");

    titleAnswer = new QLabel(window);
    titleAnswer->setText("???");
    titleAnswer->setAlignment(Qt::AlignCenter);

    QVBoxLayout *layout = new QVBoxLayout(window);
    layout->addWidget(lineEdit, Qt::AlignCenter);
    layout->addWidget(predictButton, Qt::AlignCenter);
    layout->addWidget(titleAnswer, Qt::AlignCenter);

    connect(predictButton, &QPushButton::clicked, this, &lab8_2::onPredictClicked);

    window->resize(300, 150);
    window->show();
}

lab8_2::~lab8_2() = default;

std::string lab8_2::predict(){
    float some = generator->generate();
    qDebug() << some;
    for(auto i = 0; i < probs.size(); ++i){
        if((some - probs[i]) <= 0) return answers[i];
        else some -= probs[i];
    }
    return "ошибка";
}

void lab8_2::onPredictClicked() {
    titleAnswer->setText(QString::fromStdString(predict()));
}

