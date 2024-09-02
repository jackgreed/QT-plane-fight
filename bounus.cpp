#include"bounus.h"
#include"enemy.h"
#include"player.h"
#include"mainwindow.h"
bounus::bounus(QObject*parent)
{
setParent(parent);
connect(this,&bounus::BOcrash,this,&bounus::docrash);
}
void bounus::init(QObject *parent){
    init(parent,addlife);
}
void bounus::init(QObject *fakeparent,BO_cond how){
    cond=how;
    QString imagepath=QDir::currentPath()+"/image";
    BOfly1.load(imagepath+"/"+"BOfly1.png");
    BOfly2.load(imagepath+"/"+"BOfly2.png");
    BOfly3.load(imagepath+"/"+"BOfly3.png");
    BOfly4.load(imagepath+"/"+"BOfly4.png");
    BOfly_1.load(imagepath+"/"+"BOfly_1.png");
    lx=((enemy*)fakeparent)->lx+((enemy*)fakeparent)->boundingRect().width()/2-boundingRect().width()/2;
    ly=((enemy*)fakeparent)->ly;
    setPos(lx,ly);
    update();
}
QRectF bounus::boundingRect()const{
    return  QRectF(0,0,BOfly1.width(),BOfly2.width());
}
void bounus::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    switch (cond){
    case enemybullet:{
        painter->drawPixmap(0,0,BOfly_1);
        break;

    }
    case addlife:{
        painter->drawPixmap(0,0,BOfly1);
        break;
    }
    case addweapon:{
        painter->drawPixmap(0,0,BOfly2);
        break;
    }
    case adddamage:{
        painter->drawPixmap(0,0,BOfly3);
        break;
    }
    case killall:{
        painter->drawPixmap(0,0,BOfly4);
    }
    }



}
void bounus::timerEvent(QTimerEvent *event){
    if (ly > scene()->sceneRect().bottom()) {
        scene()->removeItem(this);
        delete this;
        return;
            }
    else {
        ly+= 15;
        setPos(lx, ly);
    }
    for (QGraphicsItem *item : scene()->items()) {

        if (item != this && dynamic_cast<player*>(item) && collidesWithItem(item)) {


            emit BOcrash();
            return;
        }
    }
}
void bounus::docrash(int i){
    if(!i){
    switch (cond){
    case enemybullet:{
        emit ((MainWindow*)parent())->losslife();
        break;

    }
    case addlife:{
        emit ((MainWindow*)parent())->gainlife();
        break;
    }
    case addweapon:{
        emit ((MainWindow*)parent())->updateweapon();
        break;
    }
    case adddamage:{
        emit((MainWindow*)parent())->gaindamage();
        break;
    }
    case killall:{
        emit((MainWindow*)parent())->killenemy();
        qDebug()<<"llikllik";
        break;
    }
    }}
    if (scene() && !isInDeletedState) {
        isInDeletedState=1;

        scene()->removeItem(this);
        delete this;


        return;
    }

}
