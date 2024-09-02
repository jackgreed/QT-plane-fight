#include "gameover.h"
#include "ui_gameover.h"
#include"mainwindow.h"
#include <QAbstractTableModel>
#include <QVector>
#include <QMap>
#include <QStringList>
#include<QFile>
#include<QDir>
#include<QUrl>
gameover::gameover(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gameover)
{
    ui->setupUi(this);
    QString rootpaath=QDir::currentPath();
    QFile rank(rootpaath+"/"+"rank.txt");
    rank.open(QIODevice::ReadOnly);
    while(!rank.atEnd()){
        QString temp1;
        temp1=rank.readLine();
        QStringList temp2=temp1.split(' ');
        if(temp2.size()>=2)
        scoreList.push_back({temp2[0],temp2[1].toInt()});
    }

    std::sort(scoreList.begin(),scoreList.end(),[](QPair<QString,int>&a,QPair<QString,int>&b){return a.second>b.second;});
    rank.close();
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(rank.size());
    ui->tableWidget->setHorizontalHeaderLabels({"排名","名称","分数"});
    for(int i=0;i<scoreList.size();i++){
        auto foo=new QTableWidgetItem;
        foo->setText(QString::number(i+1));
        auto bar=new QTableWidgetItem;
        bar->setText(scoreList[i].first);
        auto foobar=new QTableWidgetItem;
        foobar->setText(QString::number(scoreList[i].second));
        ui->tableWidget->setItem(i,0,foo);
        ui->tableWidget->setItem(i,1,bar);
        ui->tableWidget->setItem(i,2,foobar);
    }

}

gameover::~gameover()
{
    delete ui;
}

void gameover::on_pushButton_clicked()
{
    QApplication* app;
    app->exit(0);
}

void gameover::on_pushButton_2_clicked()
{
    emit ((MainWindow*)parent())->startgame();

    this->close();
}

void gameover::on_lineEdit_textChanged(const QString &arg1)
{


}

void gameover::on_pushButton_3_clicked()
{
    QString rootpaath = QDir::currentPath();
    QFile rank(rootpaath + "/" + "rank.txt");
    scoreList.push_back({ui->lineEdit->text(),((MainWindow*)parent())->score});
    std::sort(scoreList.begin(),scoreList.end(),[](QPair<QString,int>&a,QPair<QString,int>&b){return a.second>b.second;});
    if(rank.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&rank);

        for(int i = 0; i < scoreList.size(); i++) {
            out << (scoreList[i].first.isEmpty()?"Defualt":scoreList[i].first) << " " << QString::number(scoreList[i].second) << "\n";  // 使用 \n 换行符
        }

        rank.close();
    }
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(rank.size());
    ui->tableWidget->setHorizontalHeaderLabels({"排名","名称","分数"});
    for(int i=0;i<scoreList.size();i++){
        auto foo=new QTableWidgetItem;
        foo->setText(QString::number(i+1));
        auto bar=new QTableWidgetItem;
        bar->setText(scoreList[i].first.isEmpty()?"Defualt":scoreList[i].first);
        auto foobar=new QTableWidgetItem;
        foobar->setText(QString::number(scoreList[i].second));
        ui->tableWidget->setItem(i,0,foo);
        ui->tableWidget->setItem(i,1,bar);
        ui->tableWidget->setItem(i,2,foobar);
    }
}

