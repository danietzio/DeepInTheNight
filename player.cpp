#include "player.h"
#include <QObject>
#include <QDebug>
#include <QColor>
#include <QBrush>
#include <QtMath>
#define PI 3.14159265
#include <QScrollBar>
#include <QGraphicsView>
#include "game.h"
#include <QImage>
#include <QMainWindow>
#include <QWidget>
#include <QEvent>
static int time;
int x_player,y_player;
bool mark_ctrl_player;
bool health_enemy_decrease;
player::player(QGraphicsView *v,QGraphicsScene *_Scene)
{
    /*sprite = new QImage(":/new/img/F:/Qt/Poroje/SPRITE/main character/walk/right.png");
    setPixmap(QPixmap::fromImage(sprite->copy(flap_sprite_x,0,sprite->width() / 9,130)));*/
    setPos(480,650);
    timer = new QTimer();

    view = v;
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    if(mark == true) { timer->start(10);}
    else timer->stop();

    Scene = _Scene;

    Health = new health(100);
    Scene->addItem(Health);

    //set Scroll Bar Off
    view->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));

    //Score
     Score = new score();
     Scene->addItem(Score);

    li = collidingItems();
}
int player::speed = 3;
int player::speed_down = 2;

void player::keyReleaseEvent(QKeyEvent * event)
{
    if(event->key() == Qt::Key_Right && barkhord == true && barkhord1 == true )  {
        mark_r = false;
        mark = false;
        right_realesed = true;
        right_pressed = false;
        mark_shift = false;
        mark_ctrl = false;
    }
    if(event->key() == Qt::Key_Left && barkhord == true && barkhord1 == true) {
        mark_l = false;
        mark = false;
        left_realesed   = true;
        left_pressed = false;
        mark_shift = false;
        mark_ctrl = false;
    }
    if(event->key() == Qt::Key_Shift && barkhord == true && barkhord1 == true) {
        speed = 3;
        mark_shift = false;
    }
    if(event->key() == Qt::Key_Down && barkhord1 == true && barkhord == true) {
        speed = 3;
        mark_ctrl = false;
        ctrl_released = true;
    }

}

bool player::checkCollision()
{
    li = collidingItems();
    if(!li.empty()) {
        collied_with_enemy = true;
        return true;
    }
    else {
        collied_with_enemy = false;
        return false;
    }
}

void player::checkHealth()
{
    if((*Health) < 0) { this->deleteLater(); return; }
    if(collied_with_enemy == true && mark_ctrl == true && mark_ctrl_enemy == false) {
        health_enemy_decrease = true;
    }
    else health_enemy_decrease = false;
    if(health_player_decrease == true) Health->set_health(10);

}

void player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Right && barkhord1 == true && barkhord == true) {
        mark_r = true;
        mark = true;
        right_pressed = true;
        right_realesed = false;
        turn_right = true;
        turn_left = false;
        mark_shift = false;
        mark_ctrl = false;
    }
    if(event->key() == Qt::Key_Shift && barkhord == true && barkhord1 == true && mark_ctrl == false) {
        speed = 5;
        mark_shift = true;
    }
    if(event->key() == Qt::Key_Left && barkhord1 == true && barkhord == true) {
        mark_l = true;
        mark = true;
        left_pressed = true;
        left_realesed = false;
        turn_left = true;
        turn_right = false;
        mark_shift = false;
        mark_ctrl = false;
    }
   if (event->key() == Qt::Key_Space )  {
        static int count = 0;
        if(count ==0) { basey0 = y0; count++;}
        mark_s = true;
        mark = true;
        mark_shift = false;
        mark_ctrl = false;
        if(left_pressed == true) {mark_l = true;mark_r = false;}
        else if(right_pressed == true) {mark_r = true;mark_l = false;}
        else { mark_r = false;mark_l = false;}
        barkhord1 = false;
        barkhord = false;
    }
   if(event->key() == Qt::Key_Down && barkhord1 == true && barkhord == true && mark_shift == false) {
       time += 10;
       if ( time < 10000 ) {
           mark_ctrl = true;
           speed = 7;
       }
       else if ( time < 1000 ) {
           mark_ctrl = false;
           speed = 3;}
       if ( time > 1000) {
           time = 0;
       }
   }
}

int player::getx()
{
    return x();
}
int player::gety()
{
    return y();
}

int player::getSpeed()
{
    return speed;
}

void player::setSpeed(int value)
{
    speed = value;
}

void player::moveright()
{
    static int counter_r = 0;
           if(counter_r < 50)
           {
               counter_r++;
               setPos(x(),y());
           }
           else  setPos(x() + speed,y());
}

void player::moveleft()
{
    static int counter_l = 0;
           if(counter_l < 15) {
               counter_l++;
               setPos(x(),y());
           }
           else  setPos(x() - speed,y());
}

void player::moveup()
{
    setPos(x(),y() - 2);
}

void player::movedown()
{
    setPos(x(),y() + speed_down);
}

player::~player()
{
    x_player = -1;
    y_player = -1;
    Health->deleteLater();
    timer->deleteLater();
    this->deleteLater();
}

//player::~player()
//     {
//    view->deleteLater();
//   Scene->deleteLater();
//    Health->deleteLater();
//    timer->deleteLater();
//    deleteLater();
//}
void player::move() {
    //Set ScrollBar
    //qDebug() << x();
    if(x() > 400)view->horizontalScrollBar()->setValue(x() - 400);
    //view->setHorizontaalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //view->setHorizontalScrollBar((Qt::ScrollBarAlwaysOff);
    //view->setVertic
    //MoveMent CoorDinates
   if(x() >=  0 && x() < 500) {
        if(barkhord == true && barkhord1 == true)setPos(x(),640);
        setRotation(0);
        y0 = 640;
    }
    if(x() >= 500 && x() < 790 ) {
        if(barkhord1 == true)setPos(x(),((float)4.01/15)*(x() - 500) + 610);
        setRotation(qreal(qAtan(((float)4.01/ 15))  * 180 / PI));
        y0 = (float)(4.01/15)*(x() - 500) + 610;

    }
    if(x() >= 790 && x() < 990 ) {
        if(barkhord == true && barkhord1 == true)setPos(x(),670);
        setRotation(0);
        y0 = 670;

    }
    if(x() >= 990 && x() < 1090 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-1.01/5))*(x() - 1000) + 670);
        setRotation(qreal(qAtan(((float)(-1.01/ 5)))  * 180 / PI));
        y0 = (((float)(-1.01/5))*(x() - 1000) + 670);

    }
    if(x() >= 1090 && x() < 1190 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-1.01/10))*(x() - 1100) + 650);
        setRotation(qreal(qAtan(((float)(-1.01/ 10)))  * 180 / PI));
        y0 = (((float)(-1.01/10))*(x() - 1100) + 650);

    }
    if(x() >= 1190 && x() < 1390 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(1.01/20))*(x() - 1200) + 640);
        setRotation(qreal(qAtan(((float)(1.01/20)))  * 180 / PI));
        y0 = ((float)(1.01/20))*(x() - 1200) + 640;

    }
    if(x() >= 1390 && x() < 1590 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-1.01/20))*(x() - 1400) + 650);
        setRotation(qreal(qAtan(((float)(-1.01/20)))  * 180 / PI));
        y0 = ((float)(-1.01/20))*(x() - 1400) + 650;

    }
    if(x() >= 1590 && x() < 1990 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(1.01/40))*(x() - 1600) + 640);
        setRotation(qreal(qAtan(((float)(1.01/40)))  * 180 / PI));
        y0 = ((float)(1.01/40))*(x() - 1600) + 640;

    }
    if(x() >= 1990 && x() < 2490 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-1.01/50))*(x() - 2000) + 650);
        setRotation(qreal(qAtan(((float)(-1.01/50)))  * 180 / PI));
        y0 = ((float)(-1.01/50))*(x() - 2000) + 650;

    }
    if(x() >= 2490 && x() < 2890 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(1.01/40))*(x() - 2500) + 660);
        setRotation(qreal(qAtan(((float)(1.01/40)))  * 180 / PI));
        y0 = ((float)(1.01/40))*(x() - 2500) + 660;

    }
    if(x() >= 2890 && x() < 2990 ) {

        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(+2.01/10))*(x() - 2900) + 650);
        setRotation(qreal(qAtan(((float)(+2.01/10)))  * 180 / PI));
        y0 = ((float)(+2.01/10))*(x() - 2900) + 650;

    }
    if(x() >= 2990 && x() < 3140 ) {

        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(2.01/15))*(x() - 3000) + 650);
        setRotation(qreal(qAtan(((float)(2.01/15)))  * 180 / PI));
        y0 = ((float)(2.01/15))*(x() - 3000) + 650;

    }
    if(x() >= 3140 && x() < 3320 ) {
        if(barkhord1 == true && barkhord == true)setPos(x(),680);
        setRotation(0);
        y0 = 680;
    }
    if(x() >= 3320 && x() < 3490 ) {

        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-6.01/17))*(x() - 3330) + 660);
        setRotation(qreal(qAtan(((float)(-6.01/17)))  * 180 / PI));
        y0 = ((float)(-6.01/17))*(x() - 3330) + 660;
    }
    if(x() >= 3490 && x() < 4420 ) {
        if(barkhord1 == true && barkhord == true)setPos(x(),565);
        setRotation(0);
        y0 = 565;
    }
    if(x() >= 4420 && x() < 4730 ) {
            if(y() >= 565 && turn_right == true && turn_left == false){
                speed_down = 8 ;
                mark_d = true;
                mark = true;
                mark_r = true;
            }
            if(y() >= 485 && turn_right == false && turn_left == true){
                speed_down = 8 ;
                mark_d = true;
                mark = true;
                mark_l = true;
            }
            if(y() > 900) {
                this->deleteLater();
                    speed_down = 4 ;
                    mark_d = false;
                    mark = false;
                    mark_r = false;
                    mark_l = true;
                    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            }
    }

    if(x() >= 4730 && x() < 4850 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-2.01/18))*(x() - 4730) + 495);
        setRotation(qreal(qAtan(((float)(-2.01/18)))  * 180 / PI));
        y0 = ((float)(-2.01/18))*(x() - 4730) + 495;

    }
    if(x() >= 4850 && x() < 5270 ) {
        if(y() >= 480 && turn_right == true && turn_left == false){
            speed_down = 8 ;
            mark_d = true;
            mark = true;
            mark_r = true;
        }
        if(y() >= 424 && turn_right == false && turn_left == true){
            speed_down = 8 ;
            mark_d = true;
            mark = true;
            mark_l = true;
        }
        if(y() > 900) {
            this->deleteLater();
                speed_down = 4 ;
                mark_d = false;
                mark = false;
                mark_r = false;
                mark_l = true;
                view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        }

     }

    if(x() >= 5270 && x() < 5580 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-5.01/37))*(x() - 5270) + 435);
        setRotation(qreal(qAtan(((float)(-5.01/37)))  * 180 / PI));
        y0 = ((float)(-5.01/37))*(x() - 5270) + 435;
    }
    if(x() >= 5580 && x() < 6115 ) {
        y0 = 1024;
        if(y() >= 385 && x() < 5800 && turn_right == true && turn_left == false){
            speed_down = 8 ;
            mark_d = true;
            mark = true;
            mark_r = true;
        }
        if(y() >= 558 &&  turn_left == true){
            speed_down = 8 ;
            mark_d = true;
            mark = true;
            mark_l = true;
        }
        if(y() > 900) {
            this->deleteLater();
                speed_down = 4 ;
                mark_d = false;
                mark = false;
                mark_r = false;
                mark_l = true;
                view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        }

     }
    if(x() >= 6115 && x() < 6260 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(+15.01/185))*(x() - 6115) + 570);
        setRotation(qreal(qAtan(((float)(+15.01/185)))  * 180 / PI));
        y0 = ((float)(+15.01/185))*(x() - 6115) + 570;
    }

   if(x() >= 6260 && x() < 6300 ) {
            if(y() > 581 && turn_right == true){
                mark_r = true;
                mark_d = true;
            }
            if(y() > 673 && turn_left == true){
                mark_d = true;
                speed_down = 9;
                mark = true;
            }
     }
    if(x() >= 6300 && x() < 6450 ) {
        if(barkhord1 == true && barkhord == true)setPos(x(),671);
        setRotation(0);
        y0 = 671;
    }
    if(x() >= 6450 && x() < 6920 ) {
              if(y() > 672  && turn_right == true && turn_left == false) {
                  mark_r = true;
                  mark_d = true;
                  speed_down = 8;
                  mark_l = false;
                  mark = true;
              }
              if(y() >= 589 && x() < 6870 && turn_left  == true && turn_right == false) {
                  mark_l = true;
                  mark_d = true;
                  speed_down = 8;
                  mark_r = false;
                  mark = true;
              }

        }

    if(x() >= 6920 && x() < 7075 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-10.01/175)*(x() - 6910)) + 590);
        setRotation(qreal(qAtan(((float)(-10.01/175)))  * 180 / PI));
        y0 = ((float)(-10.01/175))*(x() - 6910) + 590;
    }
    if(x() >= 7045 && x() < 7420 ) {
              if(y() >= 580 && x() > 7025 && turn_right == true ) {
                  mark_d = true;
                  mark_r = true;
                  mark = true;
                  mark_l = false;
                  speed_down = 8;
              }
              if(y() > 950) {

                  this->deleteLater();
                  view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

              }
        }

    if(x() >= 7420 && x() < 7440 ) {
            if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-24.01/20)*(x() - 7430)) + 915);
            setRotation(qreal(qAtan(((float)(-24.01/20)))  * 180 / PI));
            y0 = ((float)(-24.01/20))*(x() - 7430) + 915;
        }
        if(x() >= 7440 && x() < 7490 ) {
            if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-100.01/50)*(x() - 7450)) + 891);
            setRotation(qreal(qAtan(((float)(-100.01/50)))  * 180 / PI));
            y0 = ((float)(-100.01/50))*(x() - 7450) + 891;
        }
        if(x() >= 7490 && x() < 7540 ) {
            if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-80.01/50)*(x() - 7500)) + 791);
            setRotation(qreal(qAtan(((float)(-80.01/50)))  * 180 / PI));
            y0 = ((float)(-80.01/50))*(x() - 7500) + 791;
        }
        if(x() >= 7540 && x() < 7620 ) {
            if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-55.01/80)*(x() - 7550)) + 711);
            setRotation(qreal(qAtan(((float)(-55.01/80)))  * 180 / PI));
            y0 = ((float)(-50.01/80))*(x() - 7550) + 711;
        }

        if(x() >= 7620 && x() < 7670 ) {
            if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-15.01/50)*(x() - 7630)) + 656);
            setRotation(qreal(qAtan(((float)(-15.01/50)))  * 180 / PI));
            y0 = ((float)(-15.01/50))*(x() - 7630) + 656;
        }
        if(x() >= 7670 && x() < 7990 ) {
            if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-10.01/320)*(x() - 7680)) + 641);
            setRotation(qreal(qAtan(((float)(-10.01/320)))  * 180 / PI));
            y0 = ((float)(-10.01/320))*(x() - 7680) + 641;
        }
        if(x() >= 7990 && x() < 8290 ) {
            if((barkhord1 == true && barkhord == true))setPos(x(),((float)(+10.01/300)*(x() - 8000)) + 631);
            setRotation(qreal(qAtan(((float)(10.01/300)))  * 180 / PI));
            y0 = ((float)(10.01/300))*(x() - 8000) + 631;
        }
        if(x() >= 8290 && x() < 8640 ) {
            if((barkhord1 == true && barkhord == true))setPos(x(),((float)(45.01/350)*(x() - 8300)) + 641);
            setRotation(qreal(qAtan(((float)(45.01/350)))  * 180 / PI));
            y0 = ((float)(45.01/350))*(x() - 8300) + 641;
        }
        if(x() >= 8640 && x() < 8790 ) {
            if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-35.01/150)*(x() - 8650)) + 686);
            setRotation(qreal(qAtan(((float)(-35.01/150)))  * 180 / PI));
            y0 = ((float)(-35.01/150))*(x() - 8650) + 686;
        }
        if(x() >= 8790 && x() < 8940 ) {
            if((barkhord1 == true && barkhord == true))setPos(x(),((float)(1.01/15)*(x() - 8800)) + 651);
            setRotation(qreal(qAtan(((float)(1.01/15)))  * 180 / PI));
            y0 = ((float)(1.01/15))*(x() - 8800) + 651;
        }
        if(x() >= 8940 && x() < 9080 ) {
            if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-1.01/14)*(x() - 8950)) + 661);
            setRotation(qreal(qAtan(((float)(-1.01/14)))  * 180 / PI));
            y0 = ((float)(-1.01/14))*(x() - 8950) + 661;
        }
        if(x() >= 9080 && x() < 9220 ) {
            if((barkhord1 == true && barkhord == true))setPos(x(),((float)(4.01/14)*(x() - 9090)) + 651);
            setRotation(qreal(qAtan(((float)(4.01/14)))  * 180 / PI));
            y0 = ((float)(4.01/14))*(x() - 9090) + 651;
        }
        if(x() >= 9220 && x() < 9290 ) {
            if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-10.01/70)*(x() - 9230)) + 691);
            setRotation(qreal(qAtan(((float)(-10.01/70)))  * 180 / PI));
            y0 = ((float)(-10.01/70))*(x() - 9230) + 691;
        }
        if(x() >= 9290 && x() < 9355 ) {
            if((barkhord1 == true && barkhord == true))setPos(x(),((float)(10.01/65)*(x() - 9300)) + 681);
            setRotation(qreal(qAtan(((float)(10.01/65)))  * 180 / PI));
            y0 = ((float)(10.01/65))*(x() - 9300) + 681;
        }
        if(x() >= 9355 && x() < 9540 ) {
            if((barkhord1 == true && barkhord == true))setPos(x(),691);
            setRotation(0);
            y0 = 691;
        }
        if(x() >= 9540 && x() < 9690 ) {
            if((barkhord1 == true && barkhord == true))setPos(x(),((float)(20.01/150)*(x() - 9550)) + 691);
            setRotation(qreal(qAtan(((float)(20.01/150)))  * 180 / PI));
            y0 = ((float)(20.01/150))*(x() - 9550) + 691;
        }
        if(x() >= 9690 && x() < 9970 ) {
            if((barkhord1 == true && barkhord == true))setPos(x(),711);
            setRotation(0);
            y0 = 711;
        }
        if(x() >= 9970 && x() < 10290 ) {
            if((barkhord1 == true && barkhord == true))setPos(x(),((float)(20.01/320)*(x() - 9980)) + 711);
            setRotation(qreal(qAtan(((float)(20.01/320)))  * 180 / PI));
            y0 = ((float)(20.01/320))*(x() - 9980) + 711;
        }
        if(x() >= 10290 && x() < 10490 ) {
            if((barkhord1 == true && barkhord == true))setPos(x(),((float)(20.01/200)*(x() - 10300)) + 731);
            setRotation(qreal(qAtan(((float)(20.01/200)))  * 180 / PI));
            y0 = ((float)(20.01/200))*(x() - 10300) + 731;
        }
        if(x() >= 10490 && x() < 10740 ) {
            if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-25.01/250)*(x() - 10500)) + 751);
            setRotation(qreal(qAtan(((float)(-25.01/250)))  * 180 / PI));
            y0 = ((float)(-25.01/250))*(x() - 10500) + 751;
        }
        if(x() >= 10740 && x() < 11065 ) {
            if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-5.01/325)*(x() - 10750)) + 726);
            setRotation(qreal(qAtan(((float)(-5.01/325)))  * 180 / PI));
            y0 = ((float)(-5.01/325))*(x() - 10750) + 726;
        }

        if(x() >= 11065 && x() < 11170 ) {
            if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-30.01/105)*(x() - 11075)) + 721);
            setRotation(qreal(qAtan(((float)(-30.01/105)))  * 180 / PI));
            y0 = ((float)(-30.01/105))*(x() - 11075) + 721;
        }
        if(x() >= 11170 && x() < 11310 ) {
            if((barkhord1 == true && barkhord == true))setPos(x(),((float)(5.01/120)*(x() - 11180)) + 691);
            setRotation(qreal(qAtan(((float)(5.01/120)))  * 180 / PI));
            y0 = ((float)(5.011/20))*(x() - 11180) + 691;
        }
        if(x() >= 11310 && x() < 11510 ) {
            if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-5.01/200)*(x() - 11320)) + 696);
            setRotation(qreal(qAtan(((float)(-5.01/200)))  * 180 / PI));
            y0 = ((float)(-5.01/200))*(x() - 11320) + 696;
        }
        if(x() >= 11510 && x() < 11575 ) {
            if((barkhord1 == true && barkhord == true))setPos(x(),((float)(30.01/65)*(x() - 11520)) + 691);
            setRotation(qreal(qAtan(((float)(30.01/65)))  * 180 / PI));
            y0 = ((float)(30.01/65))*(x() - 11520) + 691;
        }
        if(x() >= 11575 && x() < 11940 ) {
            if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-30.01/365)*(x() - 11585)) + 721);
            setRotation(qreal(qAtan(((float)(-30.01/365)))  * 180 / PI));
            y0 = ((float)(-30.01/365))*(x() - 11585) + 721;
        }
        if(x() >= 11940 && x() < 12260 ) {
            if((barkhord1 == true && barkhord == true))setPos(x(),691);
            setRotation(0);
            y0 =691;
        }

        if(x() >= 12260 && x() < 12490 ) {
            if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-30.01/230)*(x() - 12270)) + 691);
            setRotation(qreal(qAtan(((float)(-30.01/230)))  * 180 / PI));
            y0 = ((float)(-303.01/230))*(x() - 12270) + 691;
        }
        if(x() >= 12490 && x() < 13040 ) {
            if((barkhord1 == true && barkhord == true))setPos(x(),((float)(80.01/550)*(x() - 12500)) + 661);
            setRotation(qreal(qAtan(((float)(80.01/550)))  * 180 / PI));
            y0 = ((float)(80.01/550))*(x() - 12500) + 661;
        }
        if(x() >= 13040 && x() < 13270 ) {
            if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-50.01/230)*(x() - 13050)) + 741);
            setRotation(qreal(qAtan(((float)(-50.01/230)))  * 180 / PI));
            y0 = ((float)(-50.01/230))*(x() - 13050) + 741;
        }
        if(x() >= 13270 && x() < 13410 ) {
            if((barkhord1 == true && barkhord == true))setPos(x(),((float)(10.01/140)*(x() - 13280)) + 691);
            setRotation(qreal(qAtan(((float)(10.01/140)))  * 180 / PI));
            y0 = ((float)(10.01/140))*(x() - 13280) + 691;
        }
        if(x() >= 13410 && x() < 13430 ) {
            if((barkhord1 == true && barkhord == true))setPos(x(),701);
            setRotation(0);
            y0 =701;
        }
        if(x() >= 13430 && x() < 13490 ) {
            if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-15.01/60)*(x() - 13440)) + 701);
            setRotation(qreal(qAtan(((float)(-15.01/60)))  * 180 / PI));
            y0 = ((float)(-15.01/60))*(x() - 13440) + 701;
        }

        if(x() >= 13490 && x() < 13530 ) {
            if((barkhord1 == true && barkhord == true))setPos(x(),((float)(5.01/40)*(x() - 13500)) + 686);
            setRotation(qreal(qAtan(((float)(5.01/40)))  * 180 / PI));
            y0 = ((float)(5.01/40))*(x() - 13500) + 686;
        }
        if(x() >= 13530 && x() < 13550 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-10.01/20)*(x() - 13540)) + 691);
               setRotation(0);
               y0 = ((float)(-10.01/20))*(x() - 13540) + 691;
           }
        if(x() >= 13550 && x() < 13680 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(60.01/130)*(x() - 13560)) + 681);
               setRotation(qreal(qAtan(((float)(60.01/130)))  * 180 / PI));
               y0 = ((float)(60.01/130))*(x() - 13560) + 681;
           }

       if(x() >= 13680 && x() < 13790 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-10.01/110)*(x() - 13690)) + 741);
               setRotation(qreal(qAtan(((float)(-10.01/110)))  * 180 / PI));
               y0 = ((float)(-10.01/110))*(x() - 13690) + 741;
           }
        if(x() >= 13790 && x() < 14040 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(20.01/250)*(x() - 13800)) + 741);
               setRotation(qreal(qAtan(((float)(20.01/250)))  * 180 / PI));
               y0 = ((float)(20.01/250))*(x() - 13800) + 741;
           }
        if(x() >= 14040 && x() < 14190 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(40.01/150)*(x() - 14050)) + 751);
               setRotation(qreal(qAtan(((float)(40.01/150)))  * 180 / PI));
               y0 = ((float)(40.01/150))*(x() - 14050) + 751;
           }
       if(x() >= 14190 && x() < 14350 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(10.01/160)*(x() - 14200)) + 791);
               setRotation(qreal(qAtan(((float)(10.01/160)))  * 180 / PI));
               y0 = ((float)(10.01/160))*(x() - 14200) + 791;
           }
           if(x() >= 14350 && x() < 14690 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(10.01/340)*(x() - 14360)) + 801);
               setRotation(qreal(qAtan(((float)(10.01/340)))  * 180 / PI));
               y0 = ((float)(10.01/340))*(x() - 14360) + 801;
           }
           if(x() >= 14690 && x() < 14890 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(30.01/200)*(x() - 14700)) + 811);
               setRotation(qreal(qAtan(((float)(30.01/200)))  * 180 / PI));
               y0 = ((float)(30.01/220))*(x() - 14700) + 811;
           }
           if(x() >= 14890 && x() < 15090 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(10.01/200)*(x() - 14900)) + 841);
               setRotation(qreal(qAtan(((float)(10.01/200)))  * 180 / PI));
               y0 = ((float)(10.01/200))*(x() - 14900) + 841;
           }
           if(x() >= 15090 && x() < 15390 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-10.01/300)*(x() - 15100)) + 851);
               setRotation(qreal(qAtan(((float)(-10.01/300)))  * 180 / PI));
               y0 = ((float)(-10.01/300))*(x() - 15100) + 851;
           }
           if(x() >= 15390 && x() < 15890 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-10.01/500)*(x() - 15400)) + 841);
               setRotation(qreal(qAtan(((float)(-10.01/500)))  * 180 / PI));
               y0 = ((float)(-10.01/500))*(x() - 15400) + 841;
           }
           if(x() >= 15890 && x() < 16090 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(15.01/200)*(x() - 15900)) + 831);
               setRotation(qreal(qAtan(((float)(15.01/200)))  * 180 / PI));
               y0 = ((float)(15.01/200))*(x() - 15900) + 831;
           }
           if(x() >= 16090 && x() < 17090 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-5.01/1000)*(x() - 16100)) + 846);
               setRotation(qreal(qAtan(((float)(-5.01/1000)))  * 180 / PI));
               y0 = ((float)(-5.01/1000))*(x() - 16100) + 846;
           }

           if(x() >= 17090 && x() < 17190 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(1.01/10)*(x() - 17100)) + 841);
               setRotation(qreal(qAtan(((float)(1.01/10)))  * 180 / PI));
               y0 = ((float)(1.01/10))*(x() - 17100) + 841;
           }
           if(x() >= 17190 && x() < 17490 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-10.01/300)*(x() - 17200)) + 851);
               setRotation(qreal(qAtan(((float)(-10.01/300)))  * 180 / PI));
               y0 = ((float)(-10.01/300))*(x() - 17200) + 851;
           }
           if(x() >= 17490 && x() < 18590 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(15.01/1100)*(x() - 17500)) + 841);
               setRotation(qreal(qAtan(((float)(15.01/1100)))  * 180 / PI));
               y0 = ((float)(15.01/1100))*(x() - 17500) + 841;
           }
           if(x() >= 18590 && x() < 18780 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-25.01/190)*(x() - 18600)) + 856);
               setRotation(qreal(qAtan(((float)(-25.01/190)))  * 180 / PI));
               y0 = ((float)(-25.01/190))*(x() - 18600) + 856;
           }
           if(x() >= 18780 && x() < 18800 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(10.01/20)*(x() - 18790)) + 831);
               setRotation(qreal(qAtan(((float)(10.01/20)))  * 180 / PI));
               y0 = ((float)(10.01/20))*(x() - 18790) + 831;
           }
           if(x() >= 18800 && x() < 18990 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-20.01/190)*(x() - 18810)) + 841);
               setRotation(qreal(qAtan(((float)(-20.01/190)))  * 180 / PI));
               y0 = ((float)(-20.01/190))*(x() - 18810) + 841;
           }
           if(x() >= 18990 && x() < 19140 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-10.01/150)*(x() - 19000)) + 821);
               setRotation(qreal(qAtan(((float)(-10.01/150)))  * 180 / PI));
               y0 = ((float)(-10.01/150))*(x() - 19000) + 821;
           }
           if(x() >= 19140 && x() < 19190 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-20.01/50)*(x() - 19150)) + 811);
               setRotation(qreal(qAtan(((float)(-20.01/50)))  * 180 / PI));
               y0 = ((float)(-20.01/50))*(x() - 19150) + 811;
           }
           if(x() >= 19190 && x() < 19390 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(), 791);
               setRotation(0);
               y0 = 791;
           }


           if(x() >= 19390 && x() < 19435 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(10.01/45)*(x() - 19400)) + 791);
               setRotation(qreal(qAtan(((float)(10.01/45)))  * 180 / PI));
               y0 = ((float)(10.01/45))*(x() - 19400) + 791;
           }
           if(x() >= 19435 && x() < 19470 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),801);
               setRotation(0);
               y0 = 801;
           }
           if(x() >= 19470 && x() < 19590 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-50.01/120)*(x() - 19480)) + 801);
               setRotation(qreal(qAtan(((float)(-50.01/120)))  * 180 / PI));
               y0 = ((float)(-50.01/120))*(x() - 19480) + 801;
           }
           if(x() >= 19590 && x() < 19610 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(10.01/20)*(x() - 19600)) + 751);
               setRotation(qreal(qAtan(((float)(10.01/20)))  * 180 / PI));
               y0 = ((float)(10.01/20))*(x() - 19600) + 751;
           }

           if(x() >= 19610 && x() < 19650 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-10.01/40)*(x() - 19620)) + 761);
               setRotation(qreal(qAtan(((float)(-10.01/40)))  * 180 / PI));
               y0 = ((float)(-10.01/45))*(x() - 19620) + 761;
           }
           if(x() >= 19650 && x() < 19670 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(10.01/20)*(x() - 19660)) + 751);
               setRotation(qreal(qAtan(((float)(10.01/20)))  * 180 / PI));
               y0 = ((float)(10.01/20))*(x() - 19660) + 751;
           }
           if(x() >= 19670 && x() < 19820 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),761);
               setRotation(0);
               y0 = 761;
           }
           if(x() >= 19820 && x() < 19960 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(60.01/140)*(x() - 19830)) + 761);
               setRotation(qreal(qAtan(((float)(60.01/140)))  * 180 / PI));
               y0 = ((float)(60.01/140))*(x() - 19830) + 761;
           }
           if(x() >= 19960 && x() < 20040 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),821);
               setRotation(0);
               y0 = 821;
           }

           if(x() >= 20040 && x() < 20170 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-30.01/130)*(x() - 20050)) + 821);
               setRotation(qreal(qAtan(((float)(-30.01/130)))  * 180 / PI));
               y0 = ((float)(-30.01/130))*(x() - 20050) + 821;
           }
           if(x() >= 20170 && x() < 20340 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-20.01/170)*(x() - 20180)) + 791);
               setRotation(qreal(qAtan(((float)(-20.01/170)))  * 180 / PI));
               y0 = ((float)(-20.01/170))*(x() - 20180) + 791;
           }
           if(x() >= 20340 && x() < 20440 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),771);
               setRotation(0);
               y0 = 771;
           }
           if(x() >= 20440 && x() < 20800 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-55.01/360)*(x() - 20450)) + 771);
               setRotation(qreal(qAtan(((float)(-55.01/360)))  * 180 / PI));
               y0 = ((float)(-55.01/360))*(x() - 20450) + 771;
           }
            if(x() >= 20800 && x() < 20830 ) {
                       if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-20.01/30)*(x() - 20810)) + 715);
                       setRotation(qreal(qAtan(((float)(-20.01/30)))  * 180 / PI));
                       y0 = ((float)(-20.01/30))*(x() - 20810) + 715;
           }
           if(x() >= 20830 && x() < 20880 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(10.01/50)*(x() - 20840)) + 696);
               setRotation(qreal(qAtan(((float)(10.01/50)))  * 180 / PI));
               y0 = ((float)(10.01/50)*(x() - 20840)) + 696;
           }
           if(x() >= 20880 && x() < 20900 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-10.01/20)*(x() - 20890)) + 706);
               setRotation(qreal(qAtan(((float)(-10.01/20)))  * 180 / PI));
               y0 = ((float)(-10.01/20))*(x() - 20890) + 706;
           }
           if(x() >= 20900 && x() < 20940 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(10.01/40)*(x() - 20910)) + 696);
               setRotation(qreal(qAtan(((float)(24.01/20)))  * 180 / PI));
               y0 = ((float)(10.01/40))*(x() - 20910) + 696;
           }
           if(x() >= 20940 && x() < 21090 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-5.01/150)*(x() - 20950)) + 691);
               setRotation(qreal(qAtan(((float)(-5.01/150)))  * 180 / PI));
               y0 = ((float)(-5.01/150))*(x() - 20950) + 691;
           }

           if(x() >= 21090 && x() < 21190 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-10.01/100)*(x() - 21100)) + 690);
               setRotation(qreal(qAtan(((float)(-10.01/100)))  * 180 / PI));
               y0 = ((float)(-10.01/100))*(x() - 21100) + 690;
           }
           if(x() >= 21190 && x() < 21490 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-15.01/300)*(x() - 21200)) + 676);
               setRotation(qreal(qAtan(((float)(-15.01/300)))  * 180 / PI));
                   y0 = ((float)(-15.01/300))*(x() - 21200) + 676;
               }
               if(x() >= 21490 && x() < 21790 ) {
                   if((barkhord1 == true && barkhord == true))setPos(x(),((float)(6.01/300)*(x() - 21500)) + 661);
                   setRotation(qreal(qAtan(((float)(6.01/300)))  * 180 / PI));
                   y0 = ((float)(6.01/300))*(x() - 21500) + 661;
               }

               if(x() >= 21790 && x() < 21890 ) {
                   if((barkhord1 == true && barkhord == true))setPos(x(),((float)(4.01/100)*(x() - 21800)) + 666);
                   setRotation(qreal(qAtan(((float)(4.01/100)))  * 180 / PI));
                   y0 = ((float)(4.01/100))*(x() - 21800) + 666;
               }
               if(x() >= 21890 && x() < 22090 ) {
                   if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-15.01/200)*(x() - 21900)) + 671);
                   setRotation(qreal(qAtan(((float)(-15.01/200)))  * 180 / PI));
                   y0 = ((float)(-15.01/200))*(x() - 21900) + 671;
               }
               if(x() >= 22090 && x() < 22190 ) {
                   if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-15.01/100)*(x() - 22100)) + 651);
                   setRotation(qreal(qAtan(((float)(-15.01/100)))  * 180 / PI));
                   y0 = ((float)(-15.01/100))*(x() - 22100) + 651;
               }
               /*------------------------------###############################----------------------------------*/
               if(x() >= 22190 && x() < 22280 ) {
                   if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-10.01/90)*(x() - 22200)) + 656);
                   setRotation(qreal(qAtan(((float)(-10.01/90)))  * 180 / PI));
                   y0 = ((float)(-10.01/90))*(x() - 22200) + 656;
               }
               if(x() >= 22280 && x() < 22590 ) {
                   if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-35.01/310)*(x() - 22290)) + 646);
                   setRotation(qreal(qAtan(((float)(-35.01/310)))  * 180 / PI));
                   y0 = ((float)(-35.01/310))*(x() - 22290) + 646;
               }
               if(x() >= 22590 && x() < 22690 ) {
                   if((barkhord1 == true && barkhord == true))setPos(x(),((float)(5.01/100)*(x() - 22600)) + 611);
                   setRotation(qreal(qAtan(((float)(5.01/100)))  * 180 / PI));
                   y0 = ((float)(5.01/100))*(x() - 22600) + 611;
               }
               if(x() >= 22690 && x() < 22870 ) {
                   if((barkhord1 == true && barkhord == true))setPos(x(),((float)(35.01/180)*(x() - 22700)) + 616);
                   setRotation(qreal(qAtan(((float)(35.01/180)))  * 180 / PI));
                   y0 = ((float)(35.01/180))*(x() - 22700) + 616;
               }
               if(x() >= 22870 && x() < 22940 ) {
                   if((barkhord1 == true && barkhord == true))setPos(x(),((float)(30.01/150)*(x() - 22880)) + 656);
                   setRotation(qreal(qAtan(((float)(30.01/150)))  * 180 / PI));
                   y0 = ((float)(30.01/150))*(x() - 22880) + 656;
               }

               if(x() >= 22940 && x() < 22990 ) {
                   if((barkhord1 == true && barkhord == true))setPos(x(),((float)(30.01/70)*(x() - 22950)) + 681);
                   setRotation(qreal(qAtan(((float)(30.01/70)))  * 180 / PI));
                   y0 = ((float)(30.01/70))*(x() - 22950) + 681;
               }
               if(x() >= 22990 && x() < 23110 ) {
                   if((barkhord1 == true && barkhord == true))setPos(x(),((float)(10.01/120)*(x() - 23000)) + 691);
                   setRotation(qreal(qAtan(((float)(10.01/120)))  * 180 / PI));
                   y0 = ((float)(10.01/120))*(x() - 23000) + 691;
               }
               if(x() >= 23110 && x() < 23190 ) {
                   if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-10.01/80)*(x() - 23120)) + 701);
                   setRotation(qreal(qAtan(((float)(-10.01/80)))  * 180 / PI));
                   y0 = ((float)(-10.01/80))*(x() - 23120) + 701;
               }
               if(x() >= 23190 && x() < 23290 ) {
                   if((barkhord1 == true && barkhord == true))setPos(x(),((float)(15.01/100)*(x() - 23200)) + 691);
                   setRotation(qreal(qAtan(((float)(15.01/100)))  * 180 / PI));
                   y0 = ((float)(15.01/100))*(x() - 23200) + 691;
               }
               if(x() >= 23290 && x() < 23360 ) {
                   if((barkhord1 == true && barkhord == true))setPos(x(),((float)(2.01/70)*(x() - 23300)) + 706);
                   setRotation(qreal(qAtan(((float)(2.01/70)))  * 180 / PI));
                   y0 = ((float)(2.01/70))*(x() - 23300) + 706;
               }

               if(x() >= 23360 && x() < 23390 ) {
                   if((barkhord1 == true && barkhord == true))setPos(x(),((float)(4.01/30)*(x() - 23370)) + 708);
                   setRotation(qreal(qAtan(((float)(4.01/30)))  * 180 / PI));
                   y0 = ((float)(4.01/30))*(x() - 23370) + 708;
               }
               if(x() >= 23390 && x() < 23590 ) {
                   if((barkhord1 == true && barkhord == true))setPos(x(),((float)(10.01/200)*(x() - 23400)) + 711);
                   setRotation(qreal(qAtan(((float)(10.01/200)))  * 180 / PI));
                   y0 = ((float)(10.01/200))*(x() - 23400) + 711;
               }

               if(x() >= 23590 && x() < 23690 ) {
                   if((barkhord1 == true && barkhord == true))setPos(x(),((float)(20.01/100)*(x() - 23600)) + 721);
                   setRotation(qreal(qAtan(((float)(20.01/100)))  * 180 / PI));
                   y0 = ((float)(20.01/100))*(x() - 23600) + 721;
               }
               if(x() >= 23690 && x() < 23790 ) {
                   if((barkhord1 == true && barkhord == true))setPos(x(),((float)(20.01/100)*(x() - 23700)) + 751);
                   setRotation(qreal(qAtan(((float)(20.01/100)))  * 180 / PI));
                   y0 = ((float)(20.01/100))*(x() - 23700) + 751;
               }
               if(x() >= 23790 && x() < 23890 ) {
                   if((barkhord1 == true && barkhord == true))setPos(x(),((float)(10.01/100)*(x() - 23800)) + 771);
                   setRotation(qreal(qAtan(((float)(10.01/100)))  * 180 / PI));
                   y0 = ((float)(10.01/100))*(x() - 23800) + 771;
               }
               if(x() >= 23890 && x() < 23990 ) {
                   if((barkhord1 == true && barkhord == true))setPos(x(),((float)(5.01/100)*(x() - 23900)) + 781);
                   setRotation(qreal(qAtan(((float)(5.01/100)))  * 180 / PI));
                   y0 = ((float)(5.01/100))*(x() - 23900) + 781;
               }

               if(x() >= 23990 && x() < 24100 ) {
                   if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-15.01/110)*(x() - 24000)) + 785);
                   setRotation(qreal(qAtan(((float)(-15.01/110)))  * 180 / PI));
                   y0 = ((float)(-15.01/110))*(x() - 24110) + 785;
               }
                         if(x() >= 24100 && x() < 24290) {
                             if((barkhord1 == true && barkhord == true))setPos(x(),((float)(20.01/190)*(x() - 24110)) + 763);
                             setRotation(qreal(qAtan(((float)(20.01/190)))  * 180 / PI));
                             y0 = ((float)(20.01/190))*(x() - 24300) + 763;
                         }
                         if(x() >= 24290 && x() < 24390) {
                             if((barkhord1 == true && barkhord == true))setPos(x(), 780);
                             setRotation(0);
                             y0 = 780;
                         }
                         if(x() >= 24390 && x() < 24690) {
                             if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-20.01/300)*(x() - 24400)) + 780);
                             setRotation(qreal(qAtan(((float)(-20.01/300)))  * 180 / PI));
                             y0 = ((float)(-20.01/300))*(x() - 24700) + 780;
                         }
                         if(x() >= 24690 && x() < 24790) {
                             if((barkhord1 == true && barkhord == true))setPos(x(),760);
                             setRotation(0);
                             y0 = 760;
                         }
                         if(x() >= 24790 && x() < 24880) {
                             if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-20.01/90)*(x() - 24800)) + 760);
                             setRotation(qreal(qAtan(((float)(-20.01/90)))  * 180 / PI));
                             y0 = ((float)(-20.01/90))*(x() - 24890) + 760;
                         }
                         if(x() >= 24880 && x() < 24990) {
                             if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-10.01/110)*(x() - 24890)) + 740);
                             setRotation(qreal(qAtan(((float)(-10.01/110)))  * 180 / PI));
                             y0 = ((float)(-10.01/110))*(x() - 25000) + 740;
                         }
                         if(x() >= 24990 && x() < 25960) {
                             if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-50.01/970)*(x() - 25000)) + 730);
                             setRotation(qreal(qAtan(((float)(-50.01/970)))  * 180 / PI));
                             y0 = ((float)(-50.01/970))*(x() - 25970) + 730;
                         }
                         if(x() >= 25960 && x() < 26050) {
                             if((barkhord1 == true && barkhord == true))setPos(x(),((float)(40.01/80)*(x() - 25970)) + 670);
                             setRotation(qreal(qAtan(((float)(40.01/80)))  * 180 / PI));
                             y0 = ((float)(40.01/80))*(x() - 26060) + 670;
                         }
                         if(x() >= 26050 && x() < 28035) {
                             if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-70.01/2005)*(x() - 26060)) + 715);
                             setRotation(qreal(qAtan(((float)(-70.01/2005)))  * 180 / PI));
                             y0 = ((float)(-70.01/2005))*(x() - 28045) + 715;
                         }
                         if(x() >= 28035 && x() < 28340) {
                             if((barkhord1 == true && barkhord == true))setPos(x(),((float)(43.01/305)*(x() - 28045)) + 627);
                             setRotation(qreal(qAtan(((float)(43.01/305)))  * 180 / PI));
                             y0 = ((float)(43.01/305))*(x() - 28350) + 627;
                         }
                         if(x() >= 28340 && x() < 28530) {
                             if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-60.01/190)*(x() - 28350)) + 670);
                             setRotation(qreal(qAtan(((float)(-60.01/190)))  * 180 / PI));
                             y0 = ((float)(-60.01/190))*(x() - 28540) + 670;
                         }
                         if(x() >= 28530 && x() < 28700) {
                             if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-20.01/160)*(x() - 28540)) + 610);
                             setRotation(qreal(qAtan(((float)(-20.01/160)))  * 180 / PI));
                             y0 = ((float)(-20.01/680))*(x() - 28710) + 610;
                         }
                         if(x() >= 28700 && x() < 28840) {
                             if((barkhord1 == true && barkhord == true))setPos(x(),((float)(10.01/140)*(x() - 28710)) + 590);
                             setRotation(qreal(qAtan(((float)(10.01/140)))  * 180 / PI));
                             y0 = ((float)(10.01/140))*(x() - 28850) + 590;
                         }
                         if(x() >= 28850 && x() < 28950) {
                             if((barkhord1 == true && barkhord == true))setPos(x(),((float)(143.01/110)*(x() - 28860)) + 610);
                             setRotation(qreal(qAtan(((float)(143.01/110)))  * 180 / PI));
                             y0 = ((float)(143.01/110))*(x() - 28960) + 610;
                         }
                         if(x() >= 28940 && x() < 29500) {
                             if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-1.01/560)*(x() - 28950)) + 743);
                             setRotation(qreal(qAtan(((float)(-1.01/560)))  * 180 / PI));
                             y0 = ((float)(-1.01/560))*(x() - 29510) + 743;
                         }
                         if(x() >= 29500 && x() < 29870) {
                             if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-37.01/370)*(x() - 29510)) + 750);
                             setRotation(qreal(qAtan(((float)(-37.01/370)))  * 180 / PI));
                             y0 = ((float)(-37.01/370))*(x() - 29880) + 750;
                         }
                         if(x() >= 29870 && x() < 29902) {
                             if((barkhord1 == true && barkhord == true))setPos(x(),((float)(2.01/32)*(x() - 29880)) + 713);
                             setRotation(qreal(qAtan(((float)(2.01/32)))  * 180 / PI));
                             y0 = ((float)(2.01/32))*(x() - 29912) + 713;
                         }
                         if(x() >= 29902 && x() < 29960) {
                             if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-18.01/58)*(x() - 29912)) + 715);
                             setRotation(qreal(qAtan(((float)(-18.01/58)))  * 180 / PI));
                             y0 = ((float)(-18.01/58))*(x() - 29970) + 715;
                         }
                         if(x() >= 29960 && x() < 30000) {
                             if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-10.01/40)*(x() - 29970)) + 697);
                             setRotation(qreal(qAtan(((float)(-10.01/40)))  * 180 / PI));
                             y0 = ((float)(-10.01/40))*(x() - 300010) + 697;
                         }
                         if(x() >= 30000 && x() < 30035) {
                             if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-1.01/35)*(x() - 30010)) + 687);
                             setRotation(qreal(qAtan(((float)(-1.01/35)))  * 180 / PI));
                             y0 = ((float)(-1.01/35))*(x() - 30045) + 687;
                         }
                         if(x() >= 30035 && x() < 30100) {
                             if((barkhord1 == true && barkhord == true))setPos(x(),((float)(27.01/65)*(x() - 30045)) + 686);
                             setRotation(qreal(qAtan(((float)(27.01/65)))  * 180 / PI));
                             y0 = ((float)(27.01/65))*(x() - 30110) + 686;
                         }
                         if(x() >= 30100 && x() < 30170) {
                             if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-3.01/70)*(x() - 30110)) + 713);
                             setRotation(qreal(qAtan(((float)(-3.01/70)))  * 180 / PI));
                             y0 = ((float)(-3.01/70))*(x() - 30180) + 713;
                         }
                         if(x() >= 30170 && x() < 30200) {
                             if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-20.01/30)*(x() - 30180)) + 710);
                             setRotation(qreal(qAtan(((float)(-20.01/30)))  * 180 / PI));
                             y0 = ((float)(-20.01/30))*(x() - 30210) + 710;
                         }
                         if(x() >= 30200 && x() < 30278) {
                             if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-4.01/78)*(x() - 30210)) + 690);
                             setRotation(qreal(qAtan(((float)(-4.01/78)))  * 180 / PI));
                             y0 = ((float)(-4.01/78))*(x() - 30288) + 690;
                         }
                         if(x() >= 30278 && x() < 30490) {
                             if((barkhord1 == true && barkhord == true))setPos(x(),((float)(9.01/212)*(x() - 30288)) + 686);
                             setRotation(qreal(qAtan(((float)(9.01/212)))  * 180 / PI));
                             y0 = ((float)(9.01/212))*(x() - 30500) + 686;
                         }
                         if(x() >= 30490 && x() < 30740) {
                             if((barkhord1 == true && barkhord == true))setPos(x(),((float)(18.01/250)*(x() - 30500)) + 695);
                             setRotation(qreal(qAtan(((float)(18.01/250)))  * 180 / PI));
                             y0 = ((float)(18.01/250))*(x() - 30750) + 695;
                         }
                         if(x() >= 30740 && x() < 31010) {
                             if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-53.01/270)*(x() - 30750)) + 713);
                             setRotation(qreal(qAtan(((float)(-53.01/270)))  * 180 / PI));
                             y0 = ((float)(-53.01/270))*(x() - 31020) + 713;
                         }
                         if(x() >= 31010 && x() < 32286) {
                             if((barkhord1 == true && barkhord == true))setPos(x(),((float)(10.01/1276)*(x() - 31020)) + 660);
                             setRotation(qreal(qAtan(((float)(10.01/1276)))  * 180 / PI));
                             y0 = ((float)(10.01/1276))*(x() - 32296) + 660;
                         }
                         if(x() >= 32286 && x() < 32331) {
                             if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-3.01/45)*(x() - 32296)) + 670);
                             setRotation(qreal(qAtan(((float)(-3.01/45)))  * 180 / PI));
                             y0 = ((float)(-3.01/45))*(x() - 32341) + 670;
                         }

                         if(x() >= 32331 && x() < 32340) {
                             if((barkhord1 == true && barkhord == true))setPos(x(),((float)(1.01/9)*(x() - 32341)) + 687);
                             setRotation(qreal(qAtan(((float)(1.01/9)))  * 180 / PI));
                             y0 = ((float)(1.01/9))*(x() - 32350) + 687;
                         }
                         if(x() >= 32340 && x() < 32400) {
                             if((barkhord1 == true && barkhord == true))setPos(x(),((float)(22.01/60)*(x() - 32350)) + 688);
                             setRotation(qreal(qAtan(((float)(22.01/60)))  * 180 / PI));
                             y0 = ((float)(22.01/60))*(x() - 32410) + 688;
                         }
                         if(x() >= 32400 && x() < 32480) {
                             if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-9.01/80)*(x() - 32410)) + 710);
                             setRotation(qreal(qAtan(((float)(-9.01/80)))  * 180 / PI));
                             y0 = ((float)(-9.01/80))*(x() - 32490) + 710;
                         }
                         if(x() >= 32480 && x() < 32580) {
                             if((barkhord1 == true && barkhord == true))setPos(x(),((float)(9.01/100)*(x() - 32490)) + 701);
                             setRotation(qreal(qAtan(((float)(9.01/100)))  * 180 / PI));
                             y0 = ((float)(9.01/100))*(x() - 32590) + 701;
                         }
                         if(x() >= 32580 && x() < 32640) {
                             if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-15.01/60)*(x() - 32590)) + 710);
                             setRotation(qreal(qAtan(((float)(-15.01/60)))  * 180 / PI));
                             y0 = ((float)(-15.01/60))*(x() - 32650) + 710;
                         }
                         if(x() >= 32640 && x() < 32710) {
                             if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-35.01/70)*(x() - 32650)) + 695);
                             setRotation(qreal(qAtan(((float)(-35.01/70)))  * 180 / PI));
                             y0 = ((float)(-35.01/70))*(x() - 32720) + 695;
                         }
                         if(x() >= 32710 && x() < 34734) {
                             if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-30.01/2024)*(x() - 32720)) + 660);
                             setRotation(qreal(qAtan(((float)(-30.01/2024)))  * 180 / PI));
                             y0 = ((float)(-30.01/2024))*(x() - 34744) + 660;
                         }
                         if(x() >= 34734 && x() < 34800) {
                             if((barkhord1 == true && barkhord == true))setPos(x(),650);
                             setRotation(0);
                             y0 = 650;
                         }

        //Sprite
           static int counter1 = 0;
           static int counter_right_walk = 0;
           static int counter_right_run = 0;
           static int counter_left_walk = 0;
           static int counter_left_run = 0;
           static int counter_idle_left = 0;
           static int counter_idle_right = 0;
           static int counter_jump_idle_left = 0;
           static int counter_jump_idle_right = 0;
           static int counter_jump_right = 0;
           static int counter_jump_left = 0;
           static int counter_fight_right = 0;
           static int counter_fight_left = 0;
           counter1++;
        if(counter1 % 10 == 0 && speed_down != 8 && mark_r == true && mark == true && mark_l == false
                && barkhord == true && barkhord1 == true && mark_shift == false && mark_ctrl == false) {

         switch(counter_right_walk % 9) {
           case 0:
             setPixmap(QPixmap(":/new/walk_right/F:/Qt/Poroje/SPRITE/main character/walk/WalkRight/1.png"));
             counter_right_walk++;
             break;
           case 1:
             setPixmap(QPixmap(":/new/walk_right/F:/Qt/Poroje/SPRITE/main character/walk/WalkRight/2.png"));
             counter_right_walk++;
             break;
           case 2:
             setPixmap(QPixmap(":/new/walk_right/F:/Qt/Poroje/SPRITE/main character/walk/WalkRight/3.png"));
             counter_right_walk++;
             break;
           case 3:
             setPixmap(QPixmap(":/new/walk_right/F:/Qt/Poroje/SPRITE/main character/walk/WalkRight/4.png"));
             counter_right_walk++;
             break;
           case 4:
             setPixmap(QPixmap(":/new/walk_right/F:/Qt/Poroje/SPRITE/main character/walk/WalkRight/5.png"));
             counter_right_walk++;
             break;
           case 5:
             setPixmap(QPixmap(":/new/walk_right/F:/Qt/Poroje/SPRITE/main character/walk/WalkRight/6.png"));
             counter_right_walk++;
             break;
           case 6:
             setPixmap(QPixmap(":/new/walk_right/F:/Qt/Poroje/SPRITE/main character/walk/WalkRight/7.png"));
             counter_right_walk++;
             break;
           case 7:
             setPixmap(QPixmap(":/new/walk_right/F:/Qt/Poroje/SPRITE/main character/walk/WalkRight/8.png"));
             counter_right_walk++;
             break;
           case 8:
             setPixmap(QPixmap(":/new/walk_right/F:/Qt/Poroje/SPRITE/main character/walk/WalkRight/9.png"));
             counter_right_walk++;
             counter_right_walk = 0;
             break;
             }
        }
        else if(counter1 % 10 == 0 && speed_down != 8 && mark_l == true && mark == true && mark_r == false
                && barkhord == true && barkhord1 == true && mark_shift == false && mark_ctrl == false) {
         switch(counter_left_walk % 9) {
           case 0:
             setPixmap(QPixmap(":/new/walk_left/F:/Qt/Poroje/SPRITE/main character/walk/New folder/1.png"));
             counter_left_walk++;
             break;
           case 1:
             setPixmap(QPixmap(":/new/walk_left/F:/Qt/Poroje/SPRITE/main character/walk/New folder/2.png"));
             counter_left_walk++;
             break;
           case 2:
             setPixmap(QPixmap(":/new/walk_left/F:/Qt/Poroje/SPRITE/main character/walk/New folder/3.png"));
             counter_left_walk++;
             break;
           case 3:
             setPixmap(QPixmap(":/new/walk_left/F:/Qt/Poroje/SPRITE/main character/walk/New folder/4.png"));
             counter_left_walk++;
             break;
           case 4:
             setPixmap(QPixmap(":/new/walk_left/F:/Qt/Poroje/SPRITE/main character/walk/New folder/5.png"));
             counter_left_walk++;
             break;
           case 5:
             setPixmap(QPixmap(":/new/walk_left/F:/Qt/Poroje/SPRITE/main character/walk/New folder/6.png"));
             counter_left_walk++;
             break;
           case 6:
             setPixmap(QPixmap(":/new/walk_left/F:/Qt/Poroje/SPRITE/main character/walk/New folder/7.png"));
             counter_left_walk++;
             break;
           case 7:
             setPixmap(QPixmap(":/new/walk_left/F:/Qt/Poroje/SPRITE/main character/walk/New folder/8.png"));
             counter_left_walk++;
             break;
           case 8:
             setPixmap(QPixmap(":/new/walk_left/F:/Qt/Poroje/SPRITE/main character/walk/New folder/9.png"));
             counter_left_walk++;
             counter_left_walk = 0;
             break;
             }
        }
       else  if(counter1 % 15 == 0 && speed_down != 8  && mark_l == false && mark_r == false && mark == false &&
                barkhord == true && barkhord1 == true && turn_right == true && turn_left == false) {
            switch(counter_idle_right % 9) {
              case 0:
                setPixmap(QPixmap(":/new/idle/F:/Qt/Poroje/SPRITE/main character/idle/idle_right/1.png"));
                counter_idle_right++;
                break;
              case 1:
                setPixmap(QPixmap(":/new/idle/F:/Qt/Poroje/SPRITE/main character/idle/idle_right/2.png"));
                counter_idle_right++;
                break;
              case 2:
                setPixmap(QPixmap(":/new/idle/F:/Qt/Poroje/SPRITE/main character/idle/idle_right/3.png"));
                counter_idle_right++;
                break;
              case 3:
                setPixmap(QPixmap(":/new/idle/F:/Qt/Poroje/SPRITE/main character/idle/idle_right/4.png"));
                counter_idle_right++;
                break;
              case 4:
                setPixmap(QPixmap(":/new/idle/F:/Qt/Poroje/SPRITE/main character/idle/idle_right/5.png"));
                counter_idle_right++;
                break;
             case  5:
                 setPixmap(QPixmap(":/new/idle/F:/Qt/Poroje/SPRITE/main character/idle/idle_right/6.png"));
                counter_idle_right++;
                counter_idle_right=0;
                 break;
                }
        }
        else if(counter1 % 15 == 0 && speed_down != 8 && mark_l == false && mark_r == false && mark == false
           && barkhord == true && barkhord1 == true && turn_left == true && turn_right == false) {
            switch(counter_idle_left % 9) {
              case 0:
                setPixmap(QPixmap(":/new/idle_left/F:/Qt/Poroje/SPRITE/main character/idle/idle_left/1.png"));
                counter_idle_left++;
                break;
              case 1:
                setPixmap(QPixmap(":/new/idle_left/F:/Qt/Poroje/SPRITE/main character/idle/idle_left/2.png"));
                counter_idle_left++;
                break;
              case 2:
                setPixmap(QPixmap(":/new/idle_left/F:/Qt/Poroje/SPRITE/main character/idle/idle_left/3.png"));
                counter_idle_left++;
                break;
              case 3:
                setPixmap(QPixmap(":/new/idle_left/F:/Qt/Poroje/SPRITE/main character/idle/idle_left/4.png"));
                counter_idle_left++;
                break;
              case 4:
                setPixmap(QPixmap(":/new/idle_left/F:/Qt/Poroje/SPRITE/main character/idle/idle_left/5.png"));
                counter_idle_left++;
                break;
             case  5:
                 setPixmap(QPixmap(":/new/idle_left/F:/Qt/Poroje/SPRITE/main character/idle/idle_left/6.png"));
                counter_idle_left++;
                counter_idle_left=0;
                 break;
                }
            }
        else if(counter1 % 10 == 0 && speed_down != 8 && mark_l == false && mark_r == false && mark_s == true && barkhord == false
                && barkhord1 == false && turn_right == true) {
         switch(counter_jump_idle_right % 9) {
           case 0:
             if(going_up == true) {
                 setPixmap(QPixmap(":/new/jump_right_idle/F:/Qt/Poroje/SPRITE/main character/jump/right_idle/1.png"));
                 counter_jump_idle_right++;
             }
             break;
           case 1:
             if(going_up == true) {
                 setPixmap(QPixmap(":/new/jump_right_idle/F:/Qt/Poroje/SPRITE/main character/jump/right_idle/2.png"));
                 counter_jump_idle_right++;
             }
             break;
           case 2:
             if(going_up == true) {
                 setPixmap(QPixmap(":/new/jump_right_idle/F:/Qt/Poroje/SPRITE/main character/jump/right_idle/3.png"));
                 counter_jump_idle_right++;
             }
             break;
           case 3:
             if(going_down == true) {
                 setPixmap(QPixmap(":/new/jump_right_idle/F:/Qt/Poroje/SPRITE/main character/jump/right_idle/4.png"));
                 counter_jump_idle_right++;
             }
             break;
           case 4:
             if(going_down == true) {
                 setPixmap(QPixmap(":/new/jump_right_idle/F:/Qt/Poroje/SPRITE/main character/jump/right_idle/5.png"));
                 counter_jump_idle_right++;
                 counter_jump_idle_right = 0;
             }
             break;
             }
        }
         else if(counter1 % 10 == 0 && speed_down != 8 && mark_l == false && mark_r == false && mark_s == true && barkhord == false
                 && barkhord1 == false && turn_left == true) {
          switch(counter_jump_idle_left % 9) {
            case 0:
             if(going_up == true) {
                  setPixmap(QPixmap(":/new/jump_left_idle/F:/Qt/Poroje/SPRITE/main character/jump/left_idle/1.png"));
                  counter_jump_idle_left++;
             }
              break;
            case 1:
              if(going_up == true) {
                  setPixmap(QPixmap(":/new/jump_left_idle/F:/Qt/Poroje/SPRITE/main character/jump/left_idle/2.png"));
                  counter_jump_idle_left++;
              }
              break;
            case 2:
              if(going_up == true) {
                  setPixmap(QPixmap(":/new/jump_left_idle/F:/Qt/Poroje/SPRITE/main character/jump/left_idle/3.png"));
                  counter_jump_idle_left++;
              }
              break;
            case 3:
              if(going_down == true) {
                  setPixmap(QPixmap(":/new/jump_left_idle/F:/Qt/Poroje/SPRITE/main character/jump/left_idle/4.png"));
                  counter_jump_idle_left++;
              }
              break;
            case 4:
              if(going_down == true) {
                  setPixmap(QPixmap(":/new/jump_left_idle/F:/Qt/Poroje/SPRITE/main character/jump/left_idle/5.png"));
                  counter_jump_idle_left++;
                  counter_jump_idle_left = 0;
              }
              break;
              }
        }
        else if(counter1 % 10 == 0 && speed_down != 8 && mark_l == false && mark_r == true && mark_s == true && barkhord == false
                && barkhord1 == false && turn_right == true) {
         switch(counter_jump_right % 9) {
           case 0:
            if(going_up == true) {
                 setPixmap(QPixmap(":/new/jump_right/F:/Qt/Poroje/SPRITE/main character/jump/right/1.png"));
                 counter_jump_right++;
            }
             break;
           case 1:
             if(going_up == true) {
                 setPixmap(QPixmap(":/new/jump_right/F:/Qt/Poroje/SPRITE/main character/jump/right/2.png"));
                 counter_jump_right++;
             }
             break;
           case 2:
             if(going_up == true || going_down == true) {
                 setPixmap(QPixmap(":/new/jump_right/F:/Qt/Poroje/SPRITE/main character/jump/right/3.png"));
                 counter_jump_right++;
             }
             break;
           case 3:
             if(going_down == true) {
                 setPixmap(QPixmap(":/new/jump_right/F:/Qt/Poroje/SPRITE/main character/jump/right/4.png"));
                 counter_jump_right++;
                 counter_jump_right = 0;
             }
             break;
            }
        }
         else if(counter1 % 10 == 0 && speed_down != 8 && mark_l == true && mark_r == false && mark_s == true && barkhord == false
                 && barkhord1 == false && turn_left == true) {
          switch(counter_jump_left % 9) {
            case 0:
             if(going_up == true) {
                  setPixmap(QPixmap(":/new/jump_left/F:/Qt/Poroje/SPRITE/main character/jump/left/1.png"));
                  counter_jump_left++;
             }
              break;
            case 1:
              if(going_up == true) {
                  setPixmap(QPixmap(":/new/jump_left/F:/Qt/Poroje/SPRITE/main character/jump/left/2.png"));
                  counter_jump_left++;
              }
              break;
            case 2:
              if(going_up == true || going_down == true) {
                  setPixmap(QPixmap(":/new/jump_left/F:/Qt/Poroje/SPRITE/main character/jump/left/3.png"));
                  counter_jump_left++;
              }
              break;
            case 3:
              if(going_down == true) {
                  setPixmap(QPixmap(":/new/jump_left/F:/Qt/Poroje/SPRITE/main character/jump/left/4.png"));
                  counter_jump_left++;
                  counter_jump_left = 0;
              }
              break;
             }
         }
        else if(counter1 % 8 == 0 && speed_down != 8 && mark_l == false && mark_r == true && mark_shift == true
                && barkhord == true && barkhord1 == true && turn_right == true && mark_ctrl == false) {
            switch(counter_right_run % 9) {
              case 0:
                setPixmap(QPixmap(":/new/run_right/F:/Qt/Poroje/SPRITE/main character/Run/right/1.png"));
                counter_right_run++;
                break;
              case 1:
                setPixmap(QPixmap(":/new/run_right/F:/Qt/Poroje/SPRITE/main character/Run/right/2.png"));
                counter_right_run++;
                break;
              case 2:
                setPixmap(QPixmap(":/new/run_right/F:/Qt/Poroje/SPRITE/main character/Run/right/3.png"));
                counter_right_run++;
                break;
              case 3:
                setPixmap(QPixmap(":/new/run_right/F:/Qt/Poroje/SPRITE/main character/Run/right/4.png"));
                counter_right_run++;
                break;
              case 4:
                setPixmap(QPixmap(":/new/run_right/F:/Qt/Poroje/SPRITE/main character/Run/right/5.png"));
                counter_right_run++;
                break;
              case 5:
                setPixmap(QPixmap(":/new/run_right/F:/Qt/Poroje/SPRITE/main character/Run/right/6.png"));
                counter_right_run++;
                break;
              case 6:
                setPixmap(QPixmap(":/new/run_right/F:/Qt/Poroje/SPRITE/main character/Run/right/7.png"));
                counter_right_run++;
                break;
              case 7:
                setPixmap(QPixmap(":/new/run_right/F:/Qt/Poroje/SPRITE/main character/Run/right/8.png"));
                counter_right_run++;
                break;
              case 8:
                setPixmap(QPixmap(":/new/run_right/F:/Qt/Poroje/SPRITE/main character/Run/right/9.png"));
                counter_right_run++;
                counter_right_run = 0;
                break;
                }
             }
        else if(counter1 % 8 == 0 && speed_down != 8 && mark_l == true && mark_r == false && mark_shift == true
                && barkhord == true && barkhord1 == true && turn_left == true  && mark_ctrl == false) {
            switch(counter_left_run % 9) {
              case 0:
                setPixmap(QPixmap(":/new/run_left/F:/Qt/Poroje/SPRITE/main character/Run/left/1.png"));
                counter_left_run++;
                break;
              case 1:
                setPixmap(QPixmap(":/new/run_left/F:/Qt/Poroje/SPRITE/main character/Run/left/2.png"));
                counter_left_run++;
                break;
              case 2:
                setPixmap(QPixmap(":/new/run_left/F:/Qt/Poroje/SPRITE/main character/Run/left/3.png"));
                counter_left_run++;
                break;
              case 3:
                setPixmap(QPixmap(":/new/run_left/F:/Qt/Poroje/SPRITE/main character/Run/left/4.png"));
                counter_left_run++;
                break;
              case 4:
                setPixmap(QPixmap(":/new/run_left/F:/Qt/Poroje/SPRITE/main character/Run/left/5.png"));
                counter_left_run++;
                break;
              case 5:
                setPixmap(QPixmap(":/new/run_left/F:/Qt/Poroje/SPRITE/main character/Run/left/6.png"));
                counter_left_run++;
                break;
              case 6:
                setPixmap(QPixmap(":/new/run_left/F:/Qt/Poroje/SPRITE/main character/Run/left/7.png"));
                counter_left_run++;
                break;
              case 7:
                setPixmap(QPixmap(":/new/run_left/F:/Qt/Poroje/SPRITE/main character/Run/left/8.png"));
                counter_left_run++;
                break;
              case 8:
                setPixmap(QPixmap(":/new/run_left/F:/Qt/Poroje/SPRITE/main character/Run/left/9.png"));
                counter_left_run++;
                counter_left_run = 0;
                break;
                }
             }
        else if(counter1 % 10 == 0 && speed_down != 8 && mark_r == true && mark == true && mark_l == false && turn_right == true
                && barkhord == true && barkhord1 == true &&  mark_ctrl == true && mark_shift == false) {

         switch(counter_fight_right % 9) {
           case 0:
             setPixmap(QPixmap(":/new/fight_right/F:/Qt/Poroje/SPRITE/main character/fighter/Right/1.png"));
             counter_fight_right++;
             break;
           case 1:
             setPixmap(QPixmap(":/new/fight_right/F:/Qt/Poroje/SPRITE/main character/fighter/Right/2.png"));
             counter_fight_right++;
             break;
           case 2:
             setPixmap(QPixmap(":/new/fight_right/F:/Qt/Poroje/SPRITE/main character/fighter/Right/3.png"));
             counter_fight_right++;
             break;
           case 3:
             setPixmap(QPixmap(":/new/fight_right/F:/Qt/Poroje/SPRITE/main character/fighter/Right/4.png"));
             counter_fight_right++;
             break;
           case 4:
             setPixmap(QPixmap(":/new/fight_right/F:/Qt/Poroje/SPRITE/main character/fighter/Right/5.png"));
             counter_fight_right++;
             break;
           case 5:
             setPixmap(QPixmap(":/new/fight_right/F:/Qt/Poroje/SPRITE/main character/fighter/Right/6.png"));
             counter_fight_right++;
             break;
           case 6:
             setPixmap(QPixmap(":/new/fight_right/F:/Qt/Poroje/SPRITE/main character/fighter/Right/7.png"));
             counter_fight_right++;
             counter_fight_right = 0;
             break;
             }
        }
        else if(counter1 % 8 == 0  && speed_down != 8&& mark_r == false && mark == true && mark_l == true && turn_left == true
                && barkhord == true && barkhord1 == true && mark_ctrl == true && mark_shift == false) {

         switch(counter_fight_left % 9) {
           case 0:
             setPixmap(QPixmap(":/new/fight_left/F:/Qt/Poroje/SPRITE/main character/fighter/left/1.png"));
             counter_fight_left++;
             break;
           case 1:
             setPixmap(QPixmap(":/new/fight_left/F:/Qt/Poroje/SPRITE/main character/fighter/left/2.png"));
             counter_fight_left++;
             break;
           case 2:
             setPixmap(QPixmap(":/new/fight_left/F:/Qt/Poroje/SPRITE/main character/fighter/left/3.png"));
             counter_fight_left++;
             break;
           case 3:
             setPixmap(QPixmap(":/new/fight_left/F:/Qt/Poroje/SPRITE/main character/fighter/left/4.png"));
             counter_fight_left++;
             break;
           case 4:
             setPixmap(QPixmap(":/new/fight_left/F:/Qt/Poroje/SPRITE/main character/fighter/left/5.png"));
             counter_fight_left++;
             break;
           case 5:
             setPixmap(QPixmap(":/new/fight_left/F:/Qt/Poroje/SPRITE/main character/fighter/left/6.png"));
             counter_fight_left++;
             break;
           case 6:
             setPixmap(QPixmap(":/new/fight_left/F:/Qt/Poroje/SPRITE/main character/fighter/left/7.png"));
             counter_fight_left++;
             counter_fight_left = 0;
             break;
             }
        }
        else if(counter1 % 8 == 0 && mark_d == true && mark_r == true && mark == true && speed_down == 8) {
                  setPixmap(QPixmap(":/new/jump_right_idle/F:/Qt/Poroje/SPRITE/main character/jump/right_idle/4.png"));
        }
        else if(counter1 % 8 == 0 && mark_d == true && mark_l == true && mark == true && speed_down == 8) {
                  setPixmap(QPixmap(":/new/jump_left_idle/F:/Qt/Poroje/SPRITE/main character/jump/left_idle/4.png"));
        }
                //Move ProPerties

        if((mark == true && mark_r == true)) {
               moveright();
               mark_l = false;
        }
        if((mark == true && mark_l == true)) {
               moveleft();
               mark_r = false;
        }
        if(mark_d == true) {
               movedown();
        }
        if(mark_u == true) {
               moveup();
        }
        if(mark == true && mark_s == true) {
            static int count = 0;
            static float g = 7.5;
            static float x0;
                g  -= 0.1;
                if(g > 0){going_down = false ; going_up = true;}
                else { going_down = true ; going_up = false; }
            if(count == 0) {
                x0 = x();
                count++;
            }
            if(mark_l == false && mark_r == false)setPos(x0,y() - g);
            else setPos(x(),y() - g);

            if(y() > y0) {
                 count = 0;
                 barkhord = true;
                 barkhord1 = true;
                 mark_s = false;
                 mark_r = false;
                 mark_l = false;
                 mark = false;
                 mark_d = false;
                 mark_u = false;
                 mark_shift = false;
                 mark_ctrl = false;
                 left_pressed = false;
                 right_pressed = false;

                 g = 7.5;
               }
        }
        //SetHealthPos
        Health->set_pos(x() + 10,y() - 40);
        Score->set_pos(x() + 10,y() - 40 );
        //Check Health
        checkHealth();

        //Check Collision
        checkCollision();

        //set x_player,y_player
        x_player = x();
        y_player = y();
        mark_ctrl_player = mark_ctrl;
}
