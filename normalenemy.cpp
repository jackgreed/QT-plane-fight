#include "normalenemy.h"
#include"random"
#include"mainwindow.h"
normalenemy::normalenemy(QObject *parent)
{
    setZValue(0);
    setParent(parent);
    switch(((MainWindow*)parent)->hard){
    case 0:{
        health=1;
        break;
    }
    case 1:
    {
        health=2;
        break;
    }
    case 2:{
        health=4;
        break;
    }
    }
    health*=((MainWindow*)parent)->healthmuti;
    connect(this,&normalenemy::ENcrash,this,&normalenemy::docrash);
}
void normalenemy::docrash(int num){
    if(isVisible()){

    if(num!=-1){
    health-=num;
    }
    else{
        health=-1;
    }
    if(health<=0){
    emit ((MainWindow*)parent())->addscore();
    int temp=rand()%8;
    if(temp==1){

    emit ((MainWindow*)parent())->newbuff(this);
    }
    ((MainWindow*)parent())->totalenemy--;
    scene()->removeItem(this);
    delete this;
    }}
}
void normalenemy::init(QObject *parent){
    QString imagepath=QDir::currentPath()+"/image";

    Efly.load(imagepath+"/"+"NEfly.png");
    lx=rand()%(int)(500-boundingRect().width());
    ly=0;
    setPos(lx,ly);
    update();
}
QRectF normalenemy::boundingRect() const{
    return QRectF(0,0,Efly.width(),Efly.height());
}
void normalenemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->drawPixmap(0,0,Efly);
}
void normalenemy::timerEvent(QTimerEvent *event)  {
if(isVisible()){
        if (ly > scene()->sceneRect().bottom()) {
            ((MainWindow*)parent())->totalenemy--;
            scene()->removeItem(this);
            delete this;
                }
        else {
            ly+= 5;
            setPos(lx, ly);
        }
    }}
