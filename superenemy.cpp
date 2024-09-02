#include "superenemy.h"
#include"random"
#include"mainwindow.h"

superenemy::superenemy(QObject *parent)
{
    setZValue(0);
    setParent(parent);
    switch(((MainWindow*)parent)->hard){
    case 0:{
        health=5;
        break;
    }
    case 1:
    {
        health=8;
        break;
    }
    case 2:{
        health=12;
        break;
    }
    }
    health*=((MainWindow*)parent)->healthmuti;
    connect(this,&superenemy::ENcrash,this,&superenemy::docrash);
}
void superenemy::docrash(int num){
    if(isVisible()){

    if(num!=-1){
    health-=num;
    }
    else{
        health=0;
    }
    if(health<=0){
    emit ((MainWindow*)parent())->addscore();
    int temp=rand()%1;
    if(temp==0){

    emit ((MainWindow*)parent())->newbuff(this);
    }
    ((MainWindow*)parent())->totalenemy--;
    scene()->removeItem(this);
    delete this;
    }}
}
void superenemy::init(QObject *parent){
    QString imagepath=QDir::currentPath()+"/image";

    Efly.load(imagepath+"/"+"SUfly.png");
    lx=rand()%(int)(500-boundingRect().width());
    ly=0;
    setPos(lx,ly);
    update();
}
QRectF superenemy::boundingRect() const{
    return QRectF(0,0,Efly.width(),Efly.height());
}
void superenemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->drawPixmap(0,0,Efly);
}
void superenemy::timerEvent(QTimerEvent *){
    if(isVisible()){
        static int clock=0;
        clock++;
        if(clock==50){
            emit ((MainWindow*)parent())->newbuff(this,-1);
            clock=0;
        }
            if (ly > scene()->sceneRect().bottom()) {
                ((MainWindow*)parent())->totalenemy--;
                scene()->removeItem(this);
                delete this;
                    }
            else {
                ly+= 2;
                setPos(lx, ly);
            }
        }}





























