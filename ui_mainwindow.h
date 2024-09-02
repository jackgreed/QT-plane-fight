/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *game_view;
    QWidget *right_widget;
    QWidget *gridLayoutWidget;
    QGridLayout *rightLayout;
    QLabel *weapon_label;
    QPushButton *pushButton;
    QLabel *life_label;
    QLabel *time_label;
    QLabel *score_label;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QRadioButton *radioButton;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1043, 920);
        MainWindow->setMinimumSize(QSize(1043, 920));
        MainWindow->setMaximumSize(QSize(1043, 920));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        game_view = new QGraphicsView(centralwidget);
        game_view->setObjectName(QString::fromUtf8("game_view"));
        game_view->setEnabled(true);
        game_view->setGeometry(QRect(20, 0, 511, 881));
        game_view->setTabletTracking(true);
        right_widget = new QWidget(centralwidget);
        right_widget->setObjectName(QString::fromUtf8("right_widget"));
        right_widget->setGeometry(QRect(560, 10, 461, 861));
        gridLayoutWidget = new QWidget(right_widget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 461, 851));
        rightLayout = new QGridLayout(gridLayoutWidget);
        rightLayout->setObjectName(QString::fromUtf8("rightLayout"));
        rightLayout->setVerticalSpacing(0);
        rightLayout->setContentsMargins(0, 0, 0, 0);
        weapon_label = new QLabel(gridLayoutWidget);
        weapon_label->setObjectName(QString::fromUtf8("weapon_label"));
        weapon_label->setMaximumSize(QSize(16777215, 50));

        rightLayout->addWidget(weapon_label, 4, 0, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        rightLayout->addWidget(pushButton, 3, 0, 1, 1);

        life_label = new QLabel(gridLayoutWidget);
        life_label->setObjectName(QString::fromUtf8("life_label"));
        life_label->setMaximumSize(QSize(16777215, 50));

        rightLayout->addWidget(life_label, 7, 0, 1, 1);

        time_label = new QLabel(gridLayoutWidget);
        time_label->setObjectName(QString::fromUtf8("time_label"));
        time_label->setMaximumSize(QSize(459, 50));

        rightLayout->addWidget(time_label, 6, 0, 1, 1);

        score_label = new QLabel(gridLayoutWidget);
        score_label->setObjectName(QString::fromUtf8("score_label"));
        score_label->setMaximumSize(QSize(16777215, 50));

        rightLayout->addWidget(score_label, 5, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(7);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 50));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(gridLayoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);


        rightLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        radioButton = new QRadioButton(gridLayoutWidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        rightLayout->addWidget(radioButton, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(16777215, 50));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout_2->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_2);


        rightLayout->addLayout(verticalLayout, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1043, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        weapon_label->setText(QApplication::translate("MainWindow", "\346\255\246\345\231\250:", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\346\270\270\346\210\217\345\274\200\345\247\213", nullptr));
        life_label->setText(QApplication::translate("MainWindow", "\347\224\237\345\221\275:", nullptr));
        time_label->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264:", nullptr));
        score_label->setText(QApplication::translate("MainWindow", "\345\210\206\346\225\260:", nullptr));
        label->setText(QApplication::translate("MainWindow", "\351\200\237\345\272\246:", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "\351\235\236\345\270\270\346\205\242", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "\346\205\242", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "\346\255\243\345\270\270", nullptr));
        comboBox->setItemText(3, QApplication::translate("MainWindow", "\345\277\253", nullptr));
        comboBox->setItemText(4, QApplication::translate("MainWindow", "\351\235\236\345\270\270\345\277\253", nullptr));

        comboBox->setCurrentText(QApplication::translate("MainWindow", "\346\255\243\345\270\270", nullptr));
        radioButton->setText(QApplication::translate("MainWindow", "\351\235\231\351\237\263", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\351\232\276\345\272\246:", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "easy", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "normal", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "hard", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
