/********************************************************************************
** Form generated from reading UI file 'gameover.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOVER_H
#define UI_GAMEOVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_gameover
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;
    QTableWidget *tableWidget;

    void setupUi(QDialog *gameover)
    {
        if (gameover->objectName().isEmpty())
            gameover->setObjectName(QString::fromUtf8("gameover"));
        gameover->resize(877, 630);
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(48);
        gameover->setFont(font);
        label = new QLabel(gameover);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(41, 74, 311, 111));
        pushButton = new QPushButton(gameover);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 310, 89, 24));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Agency FB"));
        font1.setPointSize(9);
        pushButton->setFont(font1);
        pushButton_2 = new QPushButton(gameover);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(160, 310, 89, 24));
        pushButton_2->setFont(font1);
        label_2 = new QLabel(gameover);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 190, 72, 15));
        label_2->setFont(font1);
        lineEdit = new QLineEdit(gameover);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(110, 190, 113, 23));
        lineEdit->setFont(font1);
        pushButton_3 = new QPushButton(gameover);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(240, 190, 89, 24));
        pushButton_3->setFont(font1);
        tableWidget = new QTableWidget(gameover);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(440, 20, 401, 591));

        retranslateUi(gameover);

        QMetaObject::connectSlotsByName(gameover);
    } // setupUi

    void retranslateUi(QDialog *gameover)
    {
        gameover->setWindowTitle(QApplication::translate("gameover", "Dialog", nullptr));
        label->setText(QApplication::translate("gameover", "\346\270\270\346\210\217\347\273\223\346\235\237!", nullptr));
        pushButton->setText(QApplication::translate("gameover", "\351\200\200\345\207\272", nullptr));
        pushButton_2->setText(QApplication::translate("gameover", "\351\207\215\346\226\260\345\274\200\345\247\213", nullptr));
        label_2->setText(QApplication::translate("gameover", "\344\275\240\347\232\204\345\220\215\345\255\227:", nullptr));
        pushButton_3->setText(QApplication::translate("gameover", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gameover: public Ui_gameover {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVER_H
