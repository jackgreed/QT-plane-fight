#include "numbershow.h"
#include"mainwindow.h"
#include"math.h"
numbershow::numbershow()
{
setZValue(10);
}
void numbershow::init(QObject *parent){
    setParent(parent);
    QString imagepath=QDir::currentPath()+"/image";
    num0.load(imagepath+"/"+"num0.png");
    num1.load(imagepath+"/"+"num1.png");
    num2.load(imagepath+"/"+"num2.png");
    num3.load(imagepath+"/"+"num3.png");
    num4.load(imagepath+"/"+"num4.png");
    num5.load(imagepath+"/"+"num5.png");
    num6.load(imagepath+"/"+"num6.png");
    num7.load(imagepath+"/"+"num7.png");
    num8.load(imagepath+"/"+"num8.png");
    num9.load(imagepath+"/"+"num9.png");
    notnum.load(imagepath+"/"+"notnum.png");
    setPos(20*(4-place),0);
    update();
}
void numbershow::timerEvent(QTimerEvent *){
    if(place!=4){
    numcond=(((MainWindow*)parent())->life%(int)(pow(10,place+1))-((MainWindow*)parent())->life%(int)(pow(10,place)))/(int)(pow(10,place));
    setPos(20*(4-place),0);}
    else{
        numcond=-1;
        setPos(20*(4-place),0);}
}
QRectF numbershow::boundingRect() const{
    return QRectF(num0.width()/2,num0.height()/2,num0.width(),num0.height());
}
void numbershow::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    switch (numcond){
    case 0:
        painter->drawPixmap(0,0,num0);
        break;
    case 1:
        painter->drawPixmap(0,0,num1);
        break;
    case 2:
        painter->drawPixmap(0,0,num2);
        break;
    case 3:
        painter->drawPixmap(0,0,num3);
        break;
    case 4:
        painter->drawPixmap(0,0,num4);
        break;
    case 5:
        painter->drawPixmap(0,0,num5);
        break;
    case 6:
        painter->drawPixmap(0,0,num6);
        break;
    case 7:
        painter->drawPixmap(0,0,num7);
        break;
    case 8:
        painter->drawPixmap(0,0,num8);
        break;
    case 9:
        painter->drawPixmap(0,0,num9);
        break;
    case -1:
        painter->drawPixmap(0,0,notnum);
        break;









    }
}
