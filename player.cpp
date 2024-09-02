#include "player.h"
#include"enemy.h"
#include"mainwindow.h"
player::player()
{    
    setZValue(0);
    connect(this,&player::PLcrash,this,&player::docrash);
}

void player::init(QObject *parent) {
     setParent(parent);
     QString imagepath=QDir::currentPath()+"/image";
     Pfly1.load(imagepath+"/"+"Pfly1.png");
     Pfly2.load(imagepath+"/"+"Pfly2.png");


    isone=1;
    lx = 250; ly = 700;

    setPos(lx, ly);
    update();
}

QRectF player::boundingRect() const {

    return QRectF(0, 0, Pfly1.width(), Pfly1.height());
}

void player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    if (isone) {
        painter->drawPixmap(0, 0, Pfly1);
    } else {
        painter->drawPixmap(0, 0, Pfly2);
    }

    isone = !isone;
}
void player::updatePosition() {
    // 根据按键状态更新位置
    qreal up,down,left,right;
    up=scene()->sceneRect().top();
    down=scene()->sceneRect().bottom()-boundingRect().height();
    left=scene()->sceneRect().left();
    right=scene()->sceneRect().right()-boundingRect().width();
    if (movingUp && ly > up) ly -= 7;
    if (movingDown && ly < down) ly += 7;
    if (movingLeft && lx > left) lx -= 7;
    if (movingRight && lx < right) lx += 7;

    setPos(lx, ly);
    update();
}
void player::keyPressEvent(QKeyEvent *event){
    switch (event->key()) {
        case Qt::Key_W:
        case Qt::Key_Up:
            movingUp = true;
            break;
        case Qt::Key_S:
        case Qt::Key_Down:
            movingDown = true;
            break;
        case Qt::Key_A:
        case Qt::Key_Left:
            movingLeft = true;
            break;
        case Qt::Key_D:
        case Qt::Key_Right:
            movingRight = true;
            break;
        default:
            break;
        }
}
void player::keyReleaseEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_W:
        movingUp = false;
        break;
    case Qt::Key_S:
        movingDown = false;
        break;
    case Qt::Key_A:
        movingLeft = false;
        break;
    case Qt::Key_D:
        movingRight = false;
        break;
    default:
        break;
    }
}
void player::docrash(){
    emit ((MainWindow*)parent())->losslife();
}
void player::timerEvent(QTimerEvent *){
    for (QGraphicsItem *item : scene()->items()) {

        if (item != this && dynamic_cast<enemy*>(item) && collidesWithItem(item)) {
            emit PLcrash();
            emit ((enemy*)item)->ENcrash(-1);

            break;
        }
    }
}
