#include "lab8_1.h"
#include "mtGenerator.h"

#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDebug>

lab8_1::lab8_1(QObject *parent) : QObject(parent){
    unsigned int seed = 1245461214;
    generator = new MTG(seed);

    QWidget *window = new QWidget();

    QLabel *title = new QLabel(window);
    title->setText("Идти на пару?");
    title->setAlignment(Qt::AlignCenter);

    QPushButton *predictButton  = new QPushButton(window);
    predictButton->setText("Предсказать");

    titleAnswer = new QLabel(window);
    titleAnswer->setText("???");
    titleAnswer->setAlignment(Qt::AlignCenter);

    QVBoxLayout *layout = new QVBoxLayout(window);
    layout->addWidget(title, Qt::AlignCenter);
    layout->addWidget(predictButton, Qt::AlignCenter);
    layout->addWidget(titleAnswer, Qt::AlignCenter);

    connect(predictButton, &QPushButton::clicked, this, &lab8_1::onPredictClicked);

    window->resize(300, 150);
    window->show();
}

lab8_1::~lab8_1() = default;

bool lab8_1::predict(){
    auto some = generator->generate();
    qDebug() << some;
    return 0.5 <= some;
}

void lab8_1::onPredictClicked() {
    bool result = predict();
    titleAnswer->setText(result ? "ДА" : "НЕТ");
}

