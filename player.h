#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class player : public entity
{
Q_OBJECT
public:
    player();
    void init(QObject *parent = nullptr);
    virtual void timerEvent(QTimerEvent *);
    virtual QRectF boundingRect() const;
    virtual void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void updatePosition();
protected:
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);

public:
    QPixmap Pfly1,Pfly2;
    bool isone;
    bool movingUp=0,movingDown=0,movingLeft=0,movingRight=0;
signals:
    void PLcrash();
public slots:
    void docrash();
};

#endif // PLAYER_H
