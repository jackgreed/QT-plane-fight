#ifndef BULLET_H
#define BULLET_H

#include "entity.h"

class bullet : public entity
{
Q_OBJECT
public:
    bullet();

    virtual void init(QObject *parent = nullptr);
    virtual void timerEvent(QTimerEvent *);
    virtual QRectF boundingRect() const;
    virtual void keyPressEvent(QKeyEvent*){};
    bool isInDeletedState=0;
    int index=-1;
protected:
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);

public:
    QPixmap Bfly;
signals:
    void BUcrash();
public slots:
    void docrash();
};

#endif // BULLET_H
