#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "entity.h"
enum BA_cond{
    BA_cond1=0,BA_cond2,BA_condsize
};

class background : public entity
{
public:
    background();
    virtual void init(QObject *parent = nullptr){};
    virtual void timerEvent(QTimerEvent *){};
    virtual QRectF boundingRect() const;
    virtual void keyPressEvent(QKeyEvent *event){};
    void keyReleaseEvent(QKeyEvent *event){};
    void changeDisplay();
    BA_cond nowcond=BA_cond1;
protected:
    virtual void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
public:
QPixmap back1,back2;

};

#endif // BACKGROUND_H
