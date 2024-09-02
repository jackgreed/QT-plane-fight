#include "sheidenemy.h"
#include"random"
#include"mainwindow.h"
sheidenemy::sheidenemy(QObject *parent)
{
    setZValue(0);
    setParent(parent);
    switch(((MainWindow*)parent)->hard){
    case 0:{
        health=3;
        break;
    }
    case 1:
    {
        health=5;
        break;
    }
    case 2:{
        health=10;
        break;
    }
    }
    health*=((MainWindow*)parent)->healthmuti;
    connect(this,&sheidenemy::ENcrash,this,&sheidenemy::docrash);
}
void sheidenemy::docrash(int num){
    if(num!=-1){
    health-=num;}
    else{
        health=0;
    }
    if(health<=0){
    emit ((MainWindow*)parent())->addscore();
    int temp=rand()%8;
    if(temp==1){

    emit ((MainWindow*)parent())->newbuff(this);}
    ((MainWindow*)parent())->totalenemy--;
    scene()->removeItem(this);
    delete this;
    }
}
void sheidenemy::init(QObject *parent){
    QString imagepath=QDir::currentPath()+"/image";

    Efly.load(imagepath+"/"+"SEfly.png");
    lx=rand()%(int)(500-boundingRect().width());
    ly=0;
    setPos(lx,ly);
    update();
}
QRectF sheidenemy::boundingRect() const{
    return QRectF(0,0,Efly.width(),Efly.height());
}
void sheidenemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->drawPixmap(0,0,Efly);
}
void sheidenemy::timerEvent(QTimerEvent *event)  {

        if (ly > scene()->sceneRect().bottom()) {
            ((MainWindow*)parent())->totalenemy--;
            scene()->removeItem(this);

            delete this;
                }
        else {
            ly+= 1;
            setPos(lx, ly);
        }
    }
