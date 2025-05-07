/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QLabel *meanT;
    QLabel *meanE;
    QLabel *lbl_err_mean;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLabel *varianceT;
    QLabel *varianceE;
    QLabel *lbl_err_var;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_3;
    QLabel *lbl_chi_squared;
    QHBoxLayout *horizontalLayout;
    QPushButton *addProbBtn;
    QPushButton *startButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *spinBoxNexp;
    QWidget *chartContainer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1016, 800);
        MainWindow->setMinimumSize(QSize(1000, 800));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setMinimumSize(QSize(1000, 750));
        horizontalLayout_4 = new QHBoxLayout(centralwidget);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        horizontalLayout_5->addWidget(label_2);

        meanT = new QLabel(centralwidget);
        meanT->setObjectName("meanT");

        horizontalLayout_5->addWidget(meanT);

        meanE = new QLabel(centralwidget);
        meanE->setObjectName("meanE");

        horizontalLayout_5->addWidget(meanE);

        lbl_err_mean = new QLabel(centralwidget);
        lbl_err_mean->setObjectName("lbl_err_mean");

        horizontalLayout_5->addWidget(lbl_err_mean);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");

        horizontalLayout_6->addWidget(label_7);

        varianceT = new QLabel(centralwidget);
        varianceT->setObjectName("varianceT");

        horizontalLayout_6->addWidget(varianceT);

        varianceE = new QLabel(centralwidget);
        varianceE->setObjectName("varianceE");

        horizontalLayout_6->addWidget(varianceE);

        lbl_err_var = new QLabel(centralwidget);
        lbl_err_var->setObjectName("lbl_err_var");

        horizontalLayout_6->addWidget(lbl_err_var);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_7->addWidget(label_3);

        lbl_chi_squared = new QLabel(centralwidget);
        lbl_chi_squared->setObjectName("lbl_chi_squared");

        horizontalLayout_7->addWidget(lbl_chi_squared);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        addProbBtn = new QPushButton(centralwidget);
        addProbBtn->setObjectName("addProbBtn");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addProbBtn->sizePolicy().hasHeightForWidth());
        addProbBtn->setSizePolicy(sizePolicy);
        addProbBtn->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setBold(false);
        font.setItalic(false);
        font.setStyleStrategy(QFont::PreferDefault);
        font.setHintingPreference(QFont::PreferDefaultHinting);
        addProbBtn->setFont(font);

        horizontalLayout->addWidget(addProbBtn);

        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");
        sizePolicy.setHeightForWidth(startButton->sizePolicy().hasHeightForWidth());
        startButton->setSizePolicy(sizePolicy);
        startButton->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(startButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        spinBoxNexp = new QSpinBox(centralwidget);
        spinBoxNexp->setObjectName("spinBoxNexp");
        spinBoxNexp->setMinimum(1);
        spinBoxNexp->setMaximum(10000000);
        spinBoxNexp->setSingleStep(100);

        horizontalLayout_2->addWidget(spinBoxNexp);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout);

        chartContainer = new QWidget(centralwidget);
        chartContainer->setObjectName("chartContainer");
        chartContainer->setMinimumSize(QSize(700, 0));

        horizontalLayout_3->addWidget(chartContainer);

        horizontalLayout_3->setStretch(1, 1);

        horizontalLayout_4->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1016, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\276\321\207\320\275\320\276\320\265 \321\201\321\200\320\265\320\264\320\275\320\265\320\265(\321\202/\320\275):", nullptr));
        meanT->setText(QCoreApplication::translate("MainWindow", "\321\202\320\265\320\276\321\200.", nullptr));
        meanE->setText(QCoreApplication::translate("MainWindow", "\320\275\320\260\320\261\320\273\321\216\320\264.", nullptr));
        lbl_err_mean->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\224\320\270\321\201\320\277\320\265\321\200\321\201\320\270\321\217(\321\202/\320\275):", nullptr));
        varianceT->setText(QCoreApplication::translate("MainWindow", "\321\202\320\265\320\276\321\200.", nullptr));
        varianceE->setText(QCoreApplication::translate("MainWindow", "\320\275\320\260\320\261\320\273\321\216\320\264.", nullptr));
        lbl_err_var->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\245\320\270-\320\272\320\262\320\260\320\264\321\200\320\260\321\202: ", nullptr));
        lbl_chi_squared->setText(QCoreApplication::translate("MainWindow", "\321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        addProbBtn->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214\n"
"\320\262\320\265\321\200\320\276\321\217\321\202\320\275\320\276\321\201\321\202\321\214", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\321\202\321\214\n"
"\320\274\320\276\320\264\320\265\320\273\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\">\320\247\320\270\321\201\320\273\320\276<br/>\321\215\320\272\321\201\320\277\320\265\321\200\320\270\320\274\320\265\320\275\321\202\320\276\320\262</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
