#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"gameover.h"
#include"player.h"
#include "bullet.h"
#include"enemy.h"
#include"math.h"
#include<memory>
#include"bounus.h"
#include <QMediaPlayer>
#include<QDir>
#include"normalenemy.h"
#include"sheidenemy.h"
#include"random"
#include"background.h"
#include"speedenemy.h"
#include"numbershow.h"
#include"superenemy.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initmusic();
    QString temp,temp2;
    ui->score_label->setText("分数:"+temp.setNum(score));
    ui->weapon_label->setText("武器射速:"+temp.setNum(10/weaponcount)+"发/s 武器伤害:"+temp2.setNum(bulletdamage));
    ui->life_label->setText("生命:"+temp.setNum(life));
    ui->time_label->setText("时间"+temp.setNum(rec_time));
    hard=Hnormal;
    connect(this,&MainWindow::startgame,this,&MainWindow::gamestart);
    connect(this,&MainWindow::addscore,this,&MainWindow::scoreadd);
    connect(this,&MainWindow::losslife,this,&MainWindow::lifeloss);
    connect(this,&MainWindow::endgame,this,&MainWindow::gameend);
    connect(this,&MainWindow::gainlife,this,&MainWindow::lifegain);
    connect(this,&MainWindow::updateweapon,this,&MainWindow::weaponupdate);
    connect(this,&MainWindow::gaindamage,this,&MainWindow::damagegain);
    connect(this,&MainWindow::bulletRecycle,this,&MainWindow::recyclebullet);
    connect(this,&MainWindow::killenemy,this,&MainWindow::enemykill);
    QObject::connect(bgm, &QMediaPlayer::mediaStatusChanged,this,[this](QMediaPlayer::MediaStatus status) {
        if (status == QMediaPlayer::EndOfMedia) {
            qDebug() << "Media playback finished.";
            this->nextmusic();
        }
    });
    connect(this,&MainWindow::newbuff,this,&MainWindow::buffnew);
    game_scene = new QGraphicsScene(this);
    game_scene->setSceneRect(0, 0, 500, 850);
    bulletdamage=1;
    bac=new background;
    game_scene->addItem(bac);
    theplayer = new player;
    theplayer->init(this);
    game_scene->addItem(theplayer);
    theplayer->setPos(250, 700);
    allentity.push_back(theplayer);
    allentity.push_back(bac);
    ui->game_view->setScene(game_scene);
    speed=(timerank)(ui->comboBox->currentIndex());
    //初始化对象池
    for(int i=0;i<100;i++){
        auto foo=new bullet;
        game_scene->addItem(foo);
        foo->init(this);
        foo->hide();
        foo->index=i;
        allBUllet.push_back({foo,1});
    }
    for(int i=0;i<5;i++){
        auto foo=new numbershow;
        foo->place=i;
        game_scene->addItem(foo);
        foo->init(this);

    }
    game_scene->update();
    timerid=startTimer(1000/(((int)speed+1)*12));

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(!isend){
    for (int i=0;i<game_scene->items().size();i++) {
        ((entity*)(game_scene->items()[i]))->keyPressEvent(event);

}
 }
}
void MainWindow::keyReleaseEvent(QKeyEvent *event){
    if(!isend){
    for (int i=0;i<game_scene->items().size();i++) {
        ((entity*)(game_scene->items()[i]))->keyReleaseEvent(event);
}}}
void MainWindow::timerEvent(QTimerEvent *event)
{
    if(!isend){
        ui->game_view->viewport()->update();
        static int limit=200;
        if(score>=limit){
            healthmuti*=2;
            limit*=2;
            ((background*)bac)->changeDisplay();
            auto others=new QMediaPlayer;
            QString musicpath=QDir::currentPath()+"/others";
            others->setMedia((QUrl::fromLocalFile(musicpath+"/levelchange.wav")));
            others->setVolume(5*Tvolume);
            others->play();
            QObject::connect(others, &QMediaPlayer::mediaStatusChanged, others, [this,others](QMediaPlayer::MediaStatus status){if(status == QMediaPlayer::EndOfMedia){others->deleteLater();}});
            game_scene->update();
        }
    rec_time+=1.0/(12*((int)speed+1));
    ((player*)allentity[0])->updatePosition();
    QString temp;
    ui->time_label->setText("时间:"+QString::number(rec_time,'f',2));
    static int counter=0;
    counter++;
    if(counter>=weaponcount){
        for(int i=0;i<allBUllet.size();i++){
            if(allBUllet[i].second){
                allBUllet[i].first->init(this);
                allBUllet[i].first->show();
                allBUllet[i].second=0;
                break;
            }
        }
    counter=0;
    }
    static int Ecoun=0;
    Ecoun++;
    if(Ecoun>=enemycount){
        addenemy();

        Ecoun=0;
        enemycount=(sqrt(enemycount*enemycount-1)>1?sqrt(enemycount*enemycount-1):1);//难度逐渐上升
        qDebug()<<enemycount;
    }
    for (int i=0;i<game_scene->items().size();i++) {
        ((entity*)(game_scene->items()[i]))->timerEvent(event);

}
 }}
void MainWindow::scoreadd(){
    switch(hard){
    case Heasy:{
        score++;break;
    }
    case  Hnormal:{
        score+=2;break;
    }
    case Hhard:{
        score+=3;break;
    }
    }

    QString temp;
    ui->score_label->setText("分数:"+temp.setNum(score));
}
void MainWindow::lifeloss(){
    life--;
    QString temp;
    ui->life_label->setText("生命:"+temp.setNum(life));
    auto others=new QMediaPlayer;
    QString musicpath=QDir::currentPath()+"/others";
    others->setMedia((QUrl::fromLocalFile(musicpath+"/lifeloss.wav")));
    others->setVolume(5*Tvolume);
    others->play();
    QObject::connect(others, &QMediaPlayer::mediaStatusChanged, others, [this,others](QMediaPlayer::MediaStatus status){if(status == QMediaPlayer::EndOfMedia){others->deleteLater();}});
    if(life<=0){
        emit endgame();
    }
}
void MainWindow::gameend(){
    isend=1;
    auto gover=new gameover(this);
    gover->show();
}
void MainWindow::lifegain(){
    life++;
    QString temp;
    ui->life_label->setText("生命:"+temp.setNum(life));
    auto others=new QMediaPlayer;
    QString musicpath=QDir::currentPath()+"/others";
    others->setMedia((QUrl::fromLocalFile(musicpath+"/lifegain.wav")));
    others->setVolume(5*Tvolume);
    others->play();
    QObject::connect(others, &QMediaPlayer::mediaStatusChanged, others, [this,others](QMediaPlayer::MediaStatus status){if(status == QMediaPlayer::EndOfMedia){others->deleteLater();}});

}
void MainWindow::weaponupdate(){
    if(weaponcount==1){
        bulletdamage+=1;
    }
    else{
    weaponcount--;
    }
    QString temp,temp2;
    auto others=new QMediaPlayer;
    QString musicpath=QDir::currentPath()+"/others";
    others->setMedia((QUrl::fromLocalFile(musicpath+"/weaponupdate.wav")));
    others->setVolume(5*Tvolume);
    others->play();
    QObject::connect(others, &QMediaPlayer::mediaStatusChanged, others, [this,others](QMediaPlayer::MediaStatus status){if(status == QMediaPlayer::EndOfMedia){others->deleteLater();}});

    ui->weapon_label->setText("武器射速:"+temp.setNum(10/weaponcount)+"发/s 武器伤害:"+temp2.setNum(bulletdamage));
}
void MainWindow::buffnew(QObject*parent,int how){
    auto buff=new bounus(this);
    if(how==-2)how=rand()%(int)(BO_size);
    buff->init(parent,(BO_cond)how);
    allentity.push_back(buff);
    game_scene->addItem(buff);
}
void MainWindow::on_pushButton_clicked()
{
    if(isend){
    isend=0;
    ui->pushButton->setText(tr("暂停"));
    }
    else{
        isend=1;
        ui->pushButton->setText(tr("开始"));
    }
}

void MainWindow::on_radioButton_clicked()
{
    static bool foo=0;
    if(foo)Tvolume=50;
    if(!foo)Tvolume=0;
    bgm->setVolume(Tvolume);
    foo=!foo;
}
void MainWindow::initmusic(){
    bgm=new QMediaPlayer;
    QString musicpath=QDir::currentPath()+"/music";
    QDir dir(musicpath);
    QStringList music=dir.entryList(QDir::Files);
    int temp=rand()%music.count();
    QString selectedMusic = musicpath + "/" + music[temp];
    bgm->setMedia(QUrl::fromLocalFile(selectedMusic));
    bgm->setVolume(Tvolume);
    bgm->play();
}
void MainWindow::nextmusic(){
    QString musicpath=QDir::currentPath()+"/music";
    QDir dir(musicpath);
    QStringList music=dir.entryList(QDir::Files);
    int temp=rand()%music.count();
    QString selectedMusic = musicpath + "/" + music[temp];
    bgm->setMedia(QUrl::fromLocalFile(selectedMusic));
    bgm->setVolume(Tvolume);
    bgm->play();
}
void MainWindow::addenemy(){
    if(totalenemy<=20){
        totalenemy++;
    int temp=rand()%100;
    if(temp<70){
        auto ene=new normalenemy(this);
        ene->init(this);
        allentity.push_back(ene);
        game_scene->addItem(ene);
    }
    else if(temp<80){
        auto ene=new speedenemy(this);
        ene->init(this);
        allentity.push_back(ene);
        game_scene->addItem(ene);
    }
    else if(temp<95){
        auto ene=new sheidenemy(this);
        ene->init(this);
        allentity.push_back(ene);
        game_scene->addItem(ene);
    }
    else{
        auto ene=new superenemy(this);
        ene->init(this);
        allentity.push_back(ene);
        game_scene->addItem(ene);
    }
}}
void MainWindow::damagegain(){
    bulletdamage+=1;
    QString temp,temp2;
    auto others=new QMediaPlayer;
    QString musicpath=QDir::currentPath()+"/others";
    others->setMedia((QUrl::fromLocalFile(musicpath+"/damagegain.wav")));
    others->setVolume(5*Tvolume);
    others->play();
    QObject::connect(others, &QMediaPlayer::mediaStatusChanged, others, [this,others](QMediaPlayer::MediaStatus status){if(status == QMediaPlayer::EndOfMedia){others->deleteLater();}});

    ui->weapon_label->setText("武器射速:"+temp.setNum(10/weaponcount)+"发/s 武器伤害:"+temp2.setNum(bulletdamage));
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    killTimer(timerid);
    speed=(timerank)index;

    timerid=startTimer(1000/(12*((int)speed+1)));

}

void MainWindow::on_pushButton_4_clicked()
{
    hard=Heasy;
}

void MainWindow::on_pushButton_3_clicked()
{
    hard=Hnormal;
}

void MainWindow::on_pushButton_2_clicked()
{
    hard=Hhard;
}
void MainWindow::recyclebullet(int index){
    allBUllet[index].first->hide();
    allBUllet[index].second=1;
}
void MainWindow::enemykill(){

    auto others=new QMediaPlayer;
    QString musicpath=QDir::currentPath()+"/others";
    others->setMedia((QUrl::fromLocalFile(musicpath+"/enemykill.wav")));
    others->setVolume(5*Tvolume);
    others->play();
    QObject::connect(others, &QMediaPlayer::mediaStatusChanged, others, [this,others](QMediaPlayer::MediaStatus status){if(status == QMediaPlayer::EndOfMedia){others->deleteLater();}});

    for (QGraphicsItem *item : game_scene->items()) {

        if (dynamic_cast<enemy*>(item)) {
            emit ((enemy*)item)->ENcrash(-1);

        }
    }

}
void MainWindow::gamestart(){
    if(timerid!=-1)killTimer(timerid);
    for (QGraphicsItem *item : game_scene->items()) {

        if (dynamic_cast<enemy*>(item)) {
            emit ((enemy*)item)->ENcrash(-1);

        }
    }
    for (QGraphicsItem *item : game_scene->items()) {

        if (dynamic_cast<bullet*>(item)) {
            emit ((bullet*)item)->BUcrash();

        }
    }
    for (QGraphicsItem *item : game_scene->items()) {

        if (dynamic_cast<bounus*>(item)) {
            emit ((bounus*)item)->BOcrash(1);

        }
    }
    score=0;weaponcount=8;bulletdamage=1;life=3;rec_time=0;
    QString temp,temp2;
    enemycount=10;
    healthmuti=1;
    ui->score_label->setText("分数:"+temp.setNum(score));
    ui->weapon_label->setText("武器射速:"+temp.setNum(10/weaponcount)+"发/s 武器伤害:"+temp2.setNum(bulletdamage));
    ui->life_label->setText("生命:"+temp.setNum(life));
    ui->time_label->setText("时间"+temp.setNum(rec_time));
    speed=(timerank)(ui->comboBox->currentIndex());
    theplayer->setPos(250,700);
    theplayer->lx=250;theplayer->ly=700;
    ((player*)theplayer)->movingUp=0;
    ((player*)theplayer)->movingDown=0;
    ((player*)theplayer)->movingLeft=0;
    ((player*)theplayer)->movingRight=0;
    ui->pushButton->setText("开始");

    timerid=startTimer(1000/(((int)speed+1)*12));

}
