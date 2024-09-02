#ifndef NORMALENEMY_H
#define NORMALENEMY_H

#include "enemy.h"

class normalenemy : public enemy
{
   Q_OBJECT
public:
    normalenemy(QObject *parent);
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

#endif // NORMALENEMY_H
