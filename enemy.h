#ifndef ENEMY_H
#define ENEMY_H
#include"QMainWindow"
#include "entity.h"

class enemy : public entity
{
Q_OBJECT
public:
    enemy(){qDebug()<<"?";};
    virtual void init(QObject *parent = nullptr)=0;
    virtual void timerEvent(QTimerEvent *)=0;
    virtual QRectF boundingRect() const=0;
    virtual void keyPressEvent(QKeyEvent *)=0;

protected:
    virtual void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget)=0;
public:
    QPixmap Efly;
    int health;
signals:
     virtual void ENcrash(int num);
public slots:
     virtual void docrash(int num)=0;
};

#endif // ENEMY_H
