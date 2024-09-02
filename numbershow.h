#ifndef NUMBERSHOW_H
#define NUMBERSHOW_H

#include "entity.h"

class numbershow : public entity
{
public:
    numbershow();
    virtual void init(QObject *parent = nullptr);
    virtual void timerEvent(QTimerEvent *);
    virtual QRectF boundingRect() const;
    virtual void keyPressEvent(QKeyEvent *event){};
    void keyReleaseEvent(QKeyEvent *event){};
    short numcond=-2;
    short place=0;
protected:
    virtual void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
public:
    QPixmap num0,num1,num2,num3,num4,num5,num6,num7,num8,num9,notnum;
};

#endif // NUMBERSHOW_H
