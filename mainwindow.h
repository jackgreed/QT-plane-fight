#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QGraphicsItem>
#include<QPainter>
#include<QDebug>
#include<QKeyEvent>
#include"entity.h"
#include<QVector>
#include<QMediaPlayer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
enum timerank{
    vreyslow=0,slow,normal,fast,veryfast
};
enum hardrank{
    Heasy=0,Hnormal,Hhard
};

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *event);
    void initmusic();
    void addenemy();
    QVector<entity*>allentity;
    QVector<QPair<entity*,bool>>allBUllet;//ptr,isempty

    double rec_time=0;
    int score=0;
    double weaponcount=8;
    int life=3;
    double enemycount=10;
    bool isend=1;
    int Tvolume=80;
    int bulletdamage=1;
    int healthmuti=1;
    int totalenemy=0;
    timerank speed;
    QMediaPlayer *bgm;
    entity* theplayer;
    entity* bac;
    int timerid=-1;
    hardrank hard;
private:
    Ui::MainWindow *ui;
    QGraphicsScene* game_scene;
signals:
    void addscore();
    void losslife();
    void endgame();
    void gainlife();
    void updateweapon();
    void newbuff(QObject*parent,int how=-2);
    void gaindamage();
    void bulletRecycle(int index);
    void killenemy();
    void startgame();
public slots:
    void scoreadd();
    void lifeloss();
    void gameend();
    void lifegain();
    void weaponupdate();
    void buffnew(QObject*parent,int how=-2);
    void recyclebullet(int index);
    void enemykill();
    void nextmusic();
    void damagegain();
    void gamestart();
private slots:
    void on_pushButton_clicked();
    void on_radioButton_clicked();
    void on_comboBox_currentIndexChanged(int index);
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
};
#endif // MAINWINDOW_H
