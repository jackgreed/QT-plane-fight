#ifndef SPEEDENEMY_H
#define SPEEDENEMY_H

#include "enemy.h"

class speedenemy : public enemy
{
   Q_OBJECT
public:
    speedenemy(QObject *parent);
    virtual void init(QObject *parent = nullptr);
    virtual void timerEvent(QTimerEvent *);
    virtual QRectF boundingRect() const;
    virtual void keyPressEvent(QKeyEvent *){};

protected:
    virtual void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
signals:
     virtual void ENcrash(int num);
public slots:
     virtual void docrash(int num);
};

#endif // SPEEDENEMY_H
