#include "bullet.h"
#include"mainwindow.h"
#include"enemy.h"
bullet::bullet()
{
    setZValue(0);
    connect(this, &bullet::BUcrash, this, &bullet::docrash);
}

void bullet::init(QObject *parent){
    setParent(parent);

    QString imagepath=QDir::currentPath()+"/image";
    Bfly.load(imagepath+"/"+"Bfly.png");
    lx=((MainWindow*)parent)->allentity[0]->lx+((MainWindow*)parent)->allentity[0]->boundingRect().width()/2-boundingRect().width()/2;
    ly=((MainWindow*)parent)->allentity[0]->ly;
    setPos(lx,ly);
    update();

}
QRectF bullet::boundingRect() const{
    return QRectF(0,0,Bfly.width(),Bfly.height());
}
void bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->drawPixmap(0,0,Bfly);
}
void bullet::timerEvent(QTimerEvent *event)  {
if(isVisible()){
        if (ly < 50) {
            emit ((MainWindow*)parent())->bulletRecycle(index);

            return;
                }
        else {
            ly -= 10;
            setPos(lx, ly);
        }
        for (QGraphicsItem *item : scene()->items()) {

            if (item != this && dynamic_cast<enemy*>(item) && collidesWithItem(item)) {

                auto others=new QMediaPlayer;
                QString musicpath=QDir::currentPath()+"/others";
                //others->setMedia((QUrl::fromLocalFile(musicpath+"/bullet.wav")));
                //others->setVolume(5*((MainWindow*)parent())->Tvolume);
                //others->play();
                //QObject::connect(others, &QMediaPlayer::mediaStatusChanged, others, [this,others](QMediaPlayer::MediaStatus status){if(status == QMediaPlayer::EndOfMedia){others->deleteLater();}});

                emit ((enemy*)item)->ENcrash(((MainWindow*)parent())->bulletdamage);
                emit BUcrash();
                return;
            }
        }

    }
}
void bullet::docrash() {
    if(isVisible()){
    emit ((MainWindow*)parent())->bulletRecycle(index);

     return;}
}
