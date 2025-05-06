#ifndef LAB8_2_H
#define LAB8_2_H

#include <QLabel>
#include <QObject>

#include <string>
#include <vector>

class MTG;

class lab8_2 : public QObject{

    Q_OBJECT
public:
    lab8_2(QObject *parent = nullptr);
    ~lab8_2();

private slots:
    void onPredictClicked();

private:
    //QObject* parent;
    QLabel *titleAnswer;
    std::string predict();
    MTG* generator;

    std::vector<float> probs; // 1/20
    std::vector<std::string> answers = {
        "Бесспорно", "Предрешено", "Никаких сомнений", "Определённо да",
        "Можешь быть уверен в этом", "Мне кажется — «да»",
        "Вероятнее всего", "Хорошие перспективы", "Знаки говорят — «да»",
        "Да", "Пока не ясно, попробуй снова", "Спроси позже",
        "Лучше не рассказывать", "Сейчас нельзя предсказать",
        "Сконцентрируйся и спроси опять", "Даже не думай",
        "Мой ответ — «нет»", "По моим данным — «нет»",
        "Перспективы не очень хорошие", "Весьма сомнительно"
    };

};
#endif // LAB8_2_H
