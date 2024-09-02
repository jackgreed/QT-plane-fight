#ifndef ENTITY_H
#define ENTITY_H

#include <QObject>
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QGraphicsItem>
#include<QPainter>
#include<QDebug>
#include<QKeyEvent>
#include<QDir>
class entity : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    explicit entity(QObject *parent = nullptr);
    virtual void init(QObject *parent = nullptr)=0;
    virtual void timerEvent(QTimerEvent *){};
    virtual QRectF boundingRect() const{};
    virtual void keyPressEvent(QKeyEvent *event){};
    void keyReleaseEvent(QKeyEvent *event){};
protected:
    virtual void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget){};

public:
    qreal lx=0,ly=0;

signals:

};

#endif // ENTITY_H
