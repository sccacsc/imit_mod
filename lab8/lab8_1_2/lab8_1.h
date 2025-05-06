#ifndef LAB8_1_H
#define LAB8_1_H

#include <QLabel>
#include <QObject>

class MTG;

class lab8_1 : public QObject{

    Q_OBJECT
public:
    lab8_1(QObject *parent = nullptr);
    ~lab8_1();

private slots:
    void onPredictClicked();

private:
    //QObject* parent;
    QLabel *titleAnswer;
    bool predict();
    MTG* generator;

};


#endif // LAB8_1_H
