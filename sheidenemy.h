#ifndef SHEIDENEMY_H
#define SHEIDENEMY_H

#include "enemy.h"

class sheidenemy : public enemy
{
     Q_OBJECT
public:
    sheidenemy(QObject *parent);
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

#endif // SHEIDENEMY_H
