#include "speedenemy.h"
#include"random"
#include"mainwindow.h"
speedenemy::speedenemy(QObject *parent)
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
        health=10;
        break;
    }
    case 2:{
        health=15;
        break;
    }
    }
    health*=((MainWindow*)parent)->healthmuti;
    connect(this,&speedenemy::ENcrash,this,&speedenemy::docrash);
}
void speedenemy::docrash(int num){
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
void speedenemy::init(QObject *parent){
    QString imagepath=QDir::currentPath()+"/image";

    Efly.load(imagepath+"/"+"SPfly.png");
    lx=rand()%(int)(500-boundingRect().width());
    ly=0;
    setPos(lx,ly);
    update();
}
QRectF speedenemy::boundingRect() const{
    return QRectF(0,0,Efly.width(),Efly.height());
}
void speedenemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->drawPixmap(0,0,Efly);
}
void speedenemy::timerEvent(QTimerEvent *event)  {
if(isVisible()){
        if (ly > scene()->sceneRect().bottom()) {
            ((MainWindow*)parent())->totalenemy--;
            scene()->removeItem(this);
            delete this;
                }
        else {
            ly+= 15;
            setPos(lx, ly);
        }
    }}
