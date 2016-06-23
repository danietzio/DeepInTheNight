#include "enemy.h"
#include <QBrush>
#include <qmath.h>
#include <QtMath>
#include <QDebug>
int y00 = 0;
int time = 0;
int direction = 1;
enemy::enemy()
{
    setRect(2730,740,40,40);
    setBrush(QBrush(QColor(Qt::blue)));
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(10);
}

void enemy::getPlayerCoordinate(qreal x, qreal y)
{
    x_pl = x;
    y_pl = y;
}

int enemy::speed = 3;

enemy::~enemy()
{
    delete timer;
    deleteLater();
}

float enemy::calculateDistance()
{
    qreal l1 = (x() + 2730 - x_pl)*(x() + 2730 - x_pl);
    qreal l2 = (y() + 740 - y_pl)*(y() + 740  - y_pl);
    qreal l = l1 + l2;
    float x = qSqrt(l);
    return x ;
}

void enemy::moveright()
{
    static int counter_r = 0;
           if(counter_r < 50)
           {
               counter_r++;
               setPos(x(),y());
           }
           else  setPos(x() + speed,y());
}

void enemy::moveleft()
{
    static int counter_l = 0;
           if(counter_l < 15) {
               counter_l++;
               setPos(x(),y());
           }
           else  setPos(x() - speed,y());
}

void enemy::move()
{
    qDebug() << x() << x_pl << y_pl << y()  << calculateDistance();
    if(x_pl > 2000 && x_pl < 3500) {
        if(calculateDistance() > 800 && calculateDistance()  < 1200)
        {
                suspection = true;
                mark_r = false;
                mark_l = false;
                mark = false;
                mark_ctrl = false;
                mark_shift = false;
                turn_left = true;
                turn_right = false;
                //Sprite Suspection
                static counter_suspection_left = 0;
                           switch(counter_suspection_left % 9) {
                             case 0:
                               setPixmap(QPixmap(":/new/idle/F:/Qt/Poroje/SPRITE/main character/idle/idle_right/1.png"));
                               counter_suspection_left++;
                               break;
                             case 1:
                               setPixmap(QPixmap(":/new/idle/F:/Qt/Poroje/SPRITE/main character/idle/idle_right/2.png"));
                               counter_suspection_left++;
                               break;
                             case 2:
                               setPixmap(QPixmap(":/new/idle/F:/Qt/Poroje/SPRITE/main character/idle/idle_right/3.png"));
                               counter_suspection_left++;
                               break;
                             case 3:
                               setPixmap(QPixmap(":/new/idle/F:/Qt/Poroje/SPRITE/main character/idle/idle_right/4.png"));
                               counter_suspection_left++;
                               break;
                             case 4:
                               setPixmap(QPixmap(":/new/idle/F:/Qt/Poroje/SPRITE/main character/idle/idle_right/5.png"));
                               counter_suspection_left++;
                               break;
                            case  5:
                                setPixmap(QPixmap(":/new/idle/F:/Qt/Poroje/SPRITE/main character/idle/idle_right/6.png"));
                               counter_suspection_left++;
                               counter_suspection_left=0;
                                break;
                           }

        }
        else if(calculateDistance() < 800 && calculateDistance() > 400 && x_pl < x()) {
                suspection = false;
                mark_ctrl = false;
                mark_l = true;
                mark_r = false;
                mark_shift = false;
                turn_left = true;
                turn_right = false;
                //Sprite Walk Left

        }
        else if(calculateDistance()  < 400 && calculateDistance() > 0  && x_pl < x()) {
                suspection = false;
                mark_l = true;
                mark_r = false;
                mark_shift = false;
                turn_left = true;
                turn_right = false;
                time += 10;
                if ( time < 100 ) { mark_ctrl = true; speed = 7;}
                else if(time < 200) {mark_ctrl = false; speed = 3;}
                if ( time > 200) { time = 0;}
                //Sprite Fighter Left

        }
        else if(calculateDistance()  < 400 && calculateDistance() > 0  && x() < x_pl) {
                suspection = false;
                mark_l = false;
                mark_r = true;
                mark_shift = false;
                turn_left = false;
                turn_right = true;
                time += 10;
                if ( time < 100 ) { mark_ctrl = true; speed = 7;}
                else if(time < 200) {mark_ctrl = false; speed = 3;}
                if ( time > 200) { time = 0;}
                //Sprite Fighter Right

        }
        else if(calculateDistance() < 800 && calculateDistance() > 400 &&   x() < x_pl) {
                suspection = false;
                mark_ctrl = false;
                mark_l = false;
                mark_r = true;
                mark_shift = false;
                turn_left = false;
                turn_right = true;
                //Sprite Walk Right

        }
    }
    else {
        if(x() == 2000) { direction = -1 ;}
        if(x() == 3500) { direction = 1;}
    }
    if(mark_r == true & mark == true) moveright();
    if(mark_l == true && mark == true ) moveleft();


}
