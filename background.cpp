#include "background.h"

background::background()
{
    setZValue(-1);
    QString imagepath=QDir::currentPath()+"/image";
    back1.load(imagepath+"/"+"back1.png");
    back2.load(imagepath+"/"+"back2.png");
    setPos(0,0);
    update();
}
QRectF background::boundingRect() const{
    return QRectF(0,0,back1.width(),back1.width());
}
void background::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    switch(nowcond){
    case BA_cond1:{
        painter->drawPixmap(0,0,back1);
        break;
    }
    case BA_cond2:
        painter->drawPixmap(0,0,back2);
        break;



    }
}
void background::changeDisplay(){
    switch(nowcond){
    case BA_cond1:{
        nowcond=BA_cond2;
        break;
    }
    case BA_cond2:
        nowcond=BA_cond1;
        break;



    }
    update();
}
