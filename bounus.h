#ifndef BOUNUS_H
#define BOUNUS_H

#include "entity.h"
enum BO_cond{
    enemybullet=-1,addlife=0,addweapon,adddamage,killall,BO_size
};

class bounus : public entity
{
    Q_OBJECT
public:
    bounus(QObject*parent);
    void init(QObject*parent=nullptr);
    void init(QObject*parent=nullptr,BO_cond how=addlife);
    virtual void timerEvent(QTimerEvent*);
    virtual QRectF boundingRect() const;
    virtual void ketPressEvent(QKeyEvent *){};
    bool isInDeletedState=0;
protected:
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
public:
    QPixmap BOfly1,BOfly2,BOfly3,BOfly4,BOfly_1;

    BO_cond cond;
signals:
    void BOcrash(int i=0);
public slots:
    void docrash(int i=0);
};

#endif // BOUNUS_H
