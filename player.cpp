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
extern int y00;
static int time;
player::player(QGraphicsView *v,enemy *e)
{
    /*sprite = new QImage(":/new/img/F:/Qt/Poroje/SPRITE/main character/walk/right.png");
    setPixmap(QPixmap::fromImage(sprite->copy(flap_sprite_x,0,sprite->width() / 9,130)));*/
    setPos(0,650);
    timer = new QTimer();

    view = v;
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    if(mark == true) { timer->start(10);}
    else timer->stop();

    Enemy = e;
}
int player::speed = 3;
void player::keyReleaseEvent(QKeyEvent * event)
{
    if(event->key() == Qt::Key_Right && barkhord == true && barkhord1 == true )  {
        mark_r = false;
        mark = false;
        right_realesed = true;
        right_pressed = false;
    }
    if(event->key() == Qt::Key_Left && barkhord == true && barkhord1 == true) {
        mark_l = false;
        mark = false;
        left_realesed   = true;
        left_pressed = false;
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

void player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Right && barkhord1 == true && barkhord == true) {
        mark_r = true;
        mark = true;
        right_pressed = true;
        right_realesed = false;
        turn_right = true;
        turn_left = false;
    }
    if(event->key() == Qt::Key_Shift && barkhord == true && barkhord1 == true) {
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
    }
   if (event->key() == Qt::Key_Space )  {
        static int count = 0;
        if(count ==0) { basey0 = y0; count++;}
        mark_s = true;
        mark = true;
        if(left_pressed == true) {mark_l = true;mark_r = false;}
        else if(right_pressed == true) {mark_r = true;mark_l = false;}
        else { mark_r = false;mark_l = false;}
        barkhord1 = false;
        barkhord = false;
    }
   if(event->key() == Qt::Key_Down && barkhord1 == true && barkhord == true) {
       time += 10;
       if ( time < 300 ) { mark_ctrl = true; speed = 7;}
       if ( time > 600) { time = 0;}

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
    setPos(x(),y() + 2);
}

player::~player()
{
    delete timer;
    deleteLater();
}
void player::move() {
    //Set ScrollBar
    if(x() > 800)view->horizontalScrollBar()->setValue(x() - 800);
    //view->setHorizontaalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //view->setHorizontalScrollBar((Qt::ScrollBarAlwaysOff);
    //view->setVertic
    //MoveMent CoorDinates
   if(x() >=  0 && x() < 500) {
        if(barkhord == true && barkhord1 == true)setPos(x(),651);
        setRotation(0);
        y0 = 651;
    }
    if(x() >= 500 && x() < 790 ) {
        if(barkhord1 == true)setPos(x(),((float)4.01/15)*(x() - 500) + 651);
        setRotation(qreal(qAtan(((float)4.01/ 15))  * 180 / PI));
        y0 = (float)(4.01/15)*(x() - 500) + 651;

    }
    if(x() >= 790 && x() < 990 ) {
        if(barkhord == true && barkhord1 == true)setPos(x(),731);
        setRotation(0);
        y0 = 731;

    }
    if(x() >= 990 && x() < 1090 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-1.01/5))*(x() - 1000) + 731);
        setRotation(qreal(qAtan(((float)(-1.01/ 5)))  * 180 / PI));
        y0 = (((float)(-1.01/5))*(x() - 1000) + 731);

    }
    if(x() >= 1090 && x() < 1190 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-1.01/10))*(x() - 1100) + 711);
        setRotation(qreal(qAtan(((float)(-1.01/ 10)))  * 180 / PI));
        y0 = (((float)(-1.01/10))*(x() - 1100) + 711);

    }
    if(x() >= 1190 && x() < 1390 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(1.01/20))*(x() - 1200) + 701);
        setRotation(qreal(qAtan(((float)(1.01/20)))  * 180 / PI));
        y0 = ((float)(1.01/20))*(x() - 1200) + 701;

    }
    if(x() >= 1390 && x() < 1590 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-1.01/20))*(x() - 1400) + 711);
        setRotation(qreal(qAtan(((float)(-1.01/20)))  * 180 / PI));
        y0 = ((float)(-1.01/20))*(x() - 1400) + 711;

    }
    if(x() >= 1590 && x() < 1990 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(1.01/40))*(x() - 1600) + 701);
        setRotation(qreal(qAtan(((float)(1.01/40)))  * 180 / PI));
        y0 = ((float)(1.01/40))*(x() - 1600) + 701;

    }
    if(x() >= 1990 && x() < 2490 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-1.01/50))*(x() - 2000) + 711);
        setRotation(qreal(qAtan(((float)(-1.01/50)))  * 180 / PI));
        y0 = ((float)(-1.01/50))*(x() - 2000) + 711;

    }
    if(x() >= 2490 && x() < 2890 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(1.01/40))*(x() - 2500) + 701);
        setRotation(qreal(qAtan(((float)(1.01/40)))  * 180 / PI));
        y0 = ((float)(1.01/40))*(x() - 2500) + 701;

    }
    if(x() >= 2890 && x() < 2990 ) {

        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-2.01/10))*(x() - 2900) + 711);
        setRotation(qreal(qAtan(((float)(-2.01/10)))  * 180 / PI));
        y0 = ((float)(-2.01/10))*(x() - 2900) + 711;

    }
    if(x() >= 2990 && x() < 3140 ) {

        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(2.01/15))*(x() - 3000) + 691);
        setRotation(qreal(qAtan(((float)(2.01/15)))  * 180 / PI));
        y0 = ((float)(2.01/15))*(x() - 3000) + 691;

    }
    if(x() >= 3140 && x() < 3320 ) {
        if(barkhord1 == true && barkhord == true)setPos(x(),711);
        setRotation(0);
        y0 = 711;
    }
    if(x() >= 3320 && x() < 3490 ) {

        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-6.01/17))*(x() - 3330) + 711);
        setRotation(qreal(qAtan(((float)(-6.01/17)))  * 180 / PI));
        y0 = ((float)(-6.01/17))*(x() - 3330) + 711;
    }
    if(x() >= 3490 && x() < 4420 ) {
        if(barkhord1 == true && barkhord == true)setPos(x(),651);
        setRotation(0);
        y0 = 651;
    }
    if(x() >= 4420 && x() < 4740 ) {
            static int count = 0;
            static int _y0 = 0;
            y0 = 1024;

            if(y() >= 649 && y() <= 652 && count == 0){_y0 = 651;count++;}
            if(y() >= 569 && y() <= 573 && count == 0){_y0 = 571;count++;}
            mark_r = true;mark = true;
            if(y() > 950){
               count = 0;
            this->~player();
            view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            mark_r = false;mark = false;

            }
            if(_y0 == 651){setPos(x(), (0.7 * (x() - 4420)*(x() - 4420) / 150) + 651 );}
            if(_y0 == 571){setPos(x(), (2 *  (-x() + 4740)*(-x() + 4740) / 150) + 571 );}

    }
    if(x() >= 4740 && x() < 4910 ) {

        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-2.01/18))*(x() - 4740) + 571);
        setRotation(qreal(qAtan(((float)(-2.01/18)))  * 180 / PI));
        y0 = ((float)(-2.01/18))*(x() - 4740) + 571;

    }
    if(x() >= 4910 && x() < 5270 ) {
            static int count = 0;
            static int _y0 = 0;
             if(x() >= 4910 && x() < 4930 ) {
                 y0 = ((float)(-21.01/2))*(x() - 4920) + 551;
             }
             else if(x() >= 4930 && x() < 4945 ) {
                y0 = ((float)(150.01/10))*(x() - 4940) + 760;
             }
             else y0 = 1024;
            if(y() >= 549 && y() <= 554 && count == 0){_y0 = 551;count++;}
            if(y() >= 509 && y() <= 514 && count == 0){_y0 = 511;count++;}
            mark_r = true;mark = true;

            if(y() > 950){
                count = 0;
           // this->~player();
           // view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            }
            if(_y0 == 551){setPos(x(), (0.7 * (x() - 4910)*(x() - 4910)/ 150) + 551 );}
            if(_y0 == 511){setPos(x(), (2 * (-x() + 5270)*(-x() + 5270) / 220) + 511 );}

     }

    if(x() >= 5270 && x() < 5640 ) {

        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-5.01/37))*(x() - 5260) + 511);
        setRotation(qreal(qAtan(((float)(-5.01/37)))  * 180 / PI));
        y0 = ((float)(-5.01/37))*(x() - 5260) + 511;
    }
    if(x() >= 5640 && x() < 6040 ) {
             static int count = 0;
             static int _y0 = 0;
              if(x() >= 5640 && x() < 5740 ) {
                  y0 = ((float)(524.01/100))*(x() - 5640) + 461;
              }
              else y0 = 1024;
             if(y() >= 459 && y() <= 465 && count == 0){_y0 = 461;count++;}
             if(y() >= 653 && y() <= 457 && count == 0){_y0 = 656;count++;}
             mark_r = true;mark = true;

             if(y() > 950){
                 count = 0;
            // this->~player();
            // view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
             }
             if(_y0 == 461){setPos(x(), (2 * (x() - 5640)*(x() - 5640)/ 220) + 461 );}
             if(_y0 == 656){setPos(x(), (2 * (-x() + 6040)*(-x() + 6040) / 220) + 656 );}

     }

    if(x() >= 6040 && x() < 6105 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-329.01/65))*(x() - 6040) + 985);
        setRotation(qreal(qAtan(((float)(-329.01/65)))  * 180 / PI));
        y0 = ((float)(-329.01/65))*(x() - 6040) + 985;
    }
    if(x() >= 6105 && x() < 6290 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(+15.01/185))*(x() - 6115) + 656);
        setRotation(qreal(qAtan(((float)(+15.01/185)))  * 180 / PI));
        y0 = ((float)(+15.01/185))*(x() - 6115) + 656;
    }

   if(x() >= 6260 && x() < 6380 ) {
             static int count = 0;
             static int _y0 = 0;
                if(x() >= 6260 && x() < 6290 ) {
                    y0 = ((float)(314.01/30))*(x() - 6270) + 985;
                  }
                else  if(x() >= 6360 && x() < 6380 ) {
                    y0 = ((float)(-224.01/20))*(x() - 6370) + 985;
                }
              else y0 = 1024;
             if(y() >= 666 && y() <= 672 && count == 0){_y0 = 671;count++;}
             if(y() >= 758 && y() <= 764 && count == 0){_y0 = 761;count++;}
             mark_r = true;mark = true;

             if(y() > 950){
                 count = 0;
            // this->~player();
            // view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
             }
             if(_y0 == 671){setPos(x(), (0.5 * (x() - 6270)*(x() - 6270)/ 220) + 671 );}
             if(_y0 == 761){setPos(x(), (2 * (-x() + 6363)*(-x() + 6363) / 220) + 761 );}
     }

    if(x() >= 6380 && x() < 6510 ) {
        if(barkhord1 == true && barkhord == true)setPos(x(),760);
        setRotation(0);
        y0 = 760;
    }
    if(x() >= 6510 && x() < 6920 ) {
              static int count = 0;
              static int _y0 = 0;
                     if(x() >= 6900 && x() < 6920 ) {
                          y0 = ((float)(-329.01/20))*(x() - 6910) + 656;
                     }
                    else y0 = 1024;
              if(y() >= 758 && y() <= 763 && count == 0){_y0 = 761;count++;}
              if(y() >= 652 && y() <= 660 && count == 0){_y0 = 656;count++;}
              mark_r = true;mark = true;

              if(y() > 950){
                 count = 0;
             // this->~player();
             // view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
              }
              if(_y0 == 761){setPos(x(), (0.5 * (x() - 6510)*(x() - 6510)/ 220) + 761 );}
              if(_y0 == 656){setPos(x(), (2 * (-x() + 6920)*(-x() + 6920) / 220) + 656 );}
        }

    if(x() >= 6920 && x() < 7075 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-10.01/175)*(x() - 6910)) + 656);
        setRotation(qreal(qAtan(((float)(-10.01/175)))  * 180 / PI));
        y0 = ((float)(-10.01/175))*(x() - 6910) + 656;
    }
    if(x() >= 7045 && x() < 7420 ) {
              static int count = 0;
              static int _y0 = 0;
                     if(x() >= 7045 && x() < 7080 ) {
                          y0 = ((float)(339.01/35))*(x() - 7045) + 646;
                     }
                    else y0 = 1024;
              if(y() >= 642 && y() <= 648 && count == 0){_y0 = 645;count++;}
              mark_r = true;mark = true;

              if(y() > 950){
                 count = 0;
              //this->~player();
             // view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
              }
              if(_y0 == 645){setPos(x(), (2 * (x() - 7045)*(x() - 7045)/ 220) + 645 );}
        }

    if(x() >= 7420 && x() < 7440 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-24.01/20)*(x() - 7430)) + 985);
        setRotation(qreal(qAtan(((float)(-24.01/20)))  * 180 / PI));
        y0 = ((float)(-24.01/20))*(x() - 7430) + 985;
    }
    if(x() >= 7440 && x() < 7490 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-100.01/50)*(x() - 7450)) + 961);
        setRotation(qreal(qAtan(((float)(-100.01/50)))  * 180 / PI));
        y0 = ((float)(-100.01/50))*(x() - 7450) + 961;
    }
    if(x() >= 7490 && x() < 7540 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-80.01/50)*(x() - 7500)) + 861);
        setRotation(qreal(qAtan(((float)(-80.01/50)))  * 180 / PI));
        y0 = ((float)(-80.01/50))*(x() - 7500) + 861;
    }
    if(x() >= 7540 && x() < 7620 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-55.01/80)*(x() - 7550)) + 781);
        setRotation(qreal(qAtan(((float)(-55.01/80)))  * 180 / PI));
        y0 = ((float)(-50.01/80))*(x() - 7550) + 781;
    }

    if(x() >= 7620 && x() < 7670 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-15.01/50)*(x() - 7630)) + 726);
        setRotation(qreal(qAtan(((float)(-15.01/50)))  * 180 / PI));
        y0 = ((float)(-15.01/50))*(x() - 7630) + 726;
    }
    if(x() >= 7670 && x() < 7990 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-10.01/320)*(x() - 7680)) + 711);
        setRotation(qreal(qAtan(((float)(-10.01/320)))  * 180 / PI));
        y0 = ((float)(-10.01/320))*(x() - 7680) + 711;
    }
    if(x() >= 7990 && x() < 8290 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(+10.01/300)*(x() - 8000)) + 701);
        setRotation(qreal(qAtan(((float)(10.01/300)))  * 180 / PI));
        y0 = ((float)(10.01/300))*(x() - 8000) + 701;
    }
    if(x() >= 8290 && x() < 8640 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(45.01/350)*(x() - 8300)) + 711);
        setRotation(qreal(qAtan(((float)(45.01/350)))  * 180 / PI));
        y0 = ((float)(45.01/350))*(x() - 8300) + 711;
    }
    if(x() >= 8640 && x() < 8790 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-35.01/150)*(x() - 8650)) + 756);
        setRotation(qreal(qAtan(((float)(-35.01/150)))  * 180 / PI));
        y0 = ((float)(-35.01/150))*(x() - 8650) + 756;
    }
    if(x() >= 8790 && x() < 8940 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(1.01/15)*(x() - 8800)) + 721);
        setRotation(qreal(qAtan(((float)(1.01/15)))  * 180 / PI));
        y0 = ((float)(1.01/15))*(x() - 8800) + 721;
    }
    if(x() >= 8940 && x() < 9080 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-1.01/14)*(x() - 8950)) + 731);
        setRotation(qreal(qAtan(((float)(-1.01/14)))  * 180 / PI));
        y0 = ((float)(-1.01/14))*(x() - 8950) + 731;
    }
    if(x() >= 9080 && x() < 9220 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(4.01/14)*(x() - 9090)) + 721);
        setRotation(qreal(qAtan(((float)(4.01/14)))  * 180 / PI));
        y0 = ((float)(4.01/14))*(x() - 9090) + 721;
    }
    if(x() >= 9220 && x() < 9290 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-10.01/70)*(x() - 9230)) + 761);
        setRotation(qreal(qAtan(((float)(-10.01/70)))  * 180 / PI));
        y0 = ((float)(-10.01/70))*(x() - 9230) + 761;
    }
    if(x() >= 9290 && x() < 9355 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(10.01/65)*(x() - 9300)) + 751);
        setRotation(qreal(qAtan(((float)(10.01/65)))  * 180 / PI));
        y0 = ((float)(10.01/65))*(x() - 9300) + 751;
    }
    if(x() >= 9355 && x() < 9540 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),761);
        setRotation(0);
        y0 = 761;
    }
    if(x() >= 9540 && x() < 9690 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(20.01/150)*(x() - 9550)) + 761);
        setRotation(qreal(qAtan(((float)(20.01/150)))  * 180 / PI));
        y0 = ((float)(20.01/150))*(x() - 9550) + 761;
    }
    if(x() >= 9690 && x() < 9970 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),781);
        setRotation(0);
        y0 = 781;
    }
    if(x() >= 9970 && x() < 10290 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(20.01/320)*(x() - 9980)) + 781);
        setRotation(qreal(qAtan(((float)(20.01/320)))  * 180 / PI));
        y0 = ((float)(20.01/320))*(x() - 9980) + 781;
    }
    if(x() >= 10290 && x() < 10490 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(20.01/200)*(x() - 10300)) + 801);
        setRotation(qreal(qAtan(((float)(20.01/200)))  * 180 / PI));
        y0 = ((float)(20.01/200))*(x() - 10300) + 801;
    }
    if(x() >= 10490 && x() < 10740 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-25.01/250)*(x() - 10500)) + 821);
        setRotation(qreal(qAtan(((float)(-25.01/250)))  * 180 / PI));
        y0 = ((float)(-25.01/250))*(x() - 10500) + 821;
    }
    if(x() >= 10740 && x() < 11065 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-5.01/325)*(x() - 10750)) + 796);
        setRotation(qreal(qAtan(((float)(-5.01/325)))  * 180 / PI));
        y0 = ((float)(-5.01/325))*(x() - 10750) + 796;
    }

    if(x() >= 11065 && x() < 11170 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-30.01/105)*(x() - 11075)) + 791);
        setRotation(qreal(qAtan(((float)(-30.01/105)))  * 180 / PI));
        y0 = ((float)(-30.01/105))*(x() - 11075) + 791;
    }
    if(x() >= 11170 && x() < 11310 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(5.01/120)*(x() - 11180)) + 761);
        setRotation(qreal(qAtan(((float)(5.01/120)))  * 180 / PI));
        y0 = ((float)(5.011/20))*(x() - 11180) + 761;
    }
    if(x() >= 11310 && x() < 11510 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-5.01/200)*(x() - 11320)) + 766);
        setRotation(qreal(qAtan(((float)(-5.01/200)))  * 180 / PI));
        y0 = ((float)(-5.01/200))*(x() - 11320) + 766;
    }
    if(x() >= 11510 && x() < 11575 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(30.01/65)*(x() - 11520)) + 761);
        setRotation(qreal(qAtan(((float)(30.01/65)))  * 180 / PI));
        y0 = ((float)(30.01/65))*(x() - 11520) + 761;
    }
    if(x() >= 11575 && x() < 11940 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-30.01/365)*(x() - 11585)) + 791);
        setRotation(qreal(qAtan(((float)(-30.01/365)))  * 180 / PI));
        y0 = ((float)(-30.01/365))*(x() - 11585) + 791;
    }
    if(x() >= 11940 && x() < 12260 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),761);
        setRotation(0);
        y0 =761;
    }

    if(x() >= 12260 && x() < 12490 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-30.01/230)*(x() - 12270)) + 761);
        setRotation(qreal(qAtan(((float)(-30.01/230)))  * 180 / PI));
        y0 = ((float)(-303.01/230))*(x() - 12270) + 761;
    }
    if(x() >= 12490 && x() < 13040 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(80.01/550)*(x() - 12500)) + 731);
        setRotation(qreal(qAtan(((float)(80.01/550)))  * 180 / PI));
        y0 = ((float)(80.01/550))*(x() - 12500) + 731;
    }
    if(x() >= 13040 && x() < 13270 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-50.01/230)*(x() - 13050)) + 811);
        setRotation(qreal(qAtan(((float)(-50.01/230)))  * 180 / PI));
        y0 = ((float)(-50.01/230))*(x() - 13050) + 811;
    }
    if(x() >= 13270 && x() < 13410 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(10.01/140)*(x() - 13280)) + 761);
        setRotation(qreal(qAtan(((float)(10.01/140)))  * 180 / PI));
        y0 = ((float)(10.01/140))*(x() - 13280) + 761;
    }
    if(x() >= 13410 && x() < 13430 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),771);
        setRotation(0);
        y0 =771;
    }
    if(x() >= 13430 && x() < 13490 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-15.01/60)*(x() - 13440)) + 771);
        setRotation(qreal(qAtan(((float)(-15.01/60)))  * 180 / PI));
        y0 = ((float)(-15.01/60))*(x() - 13440) + 771;
    }

    if(x() >= 13490 && x() < 13530 ) {
        if((barkhord1 == true && barkhord == true))setPos(x(),((float)(5.01/40)*(x() - 13500)) + 756);
        setRotation(qreal(qAtan(((float)(5.01/40)))  * 180 / PI));
        y0 = ((float)(5.01/40))*(x() - 13500) + 756;
    }
    if(x() >= 13530 && x() < 13550 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-10.01/20)*(x() - 13540)) + 761);
           setRotation(0);
           y0 = ((float)(-10.01/20))*(x() - 13540) + 761;
       }
    if(x() >= 13550 && x() < 13680 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),((float)(60.01/130)*(x() - 13560)) + 751);
           setRotation(qreal(qAtan(((float)(60.01/130)))  * 180 / PI));
           y0 = ((float)(60.01/130))*(x() - 13560) + 751;
       }

   if(x() >= 13680 && x() < 13790 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-10.01/110)*(x() - 13690)) + 811);
           setRotation(qreal(qAtan(((float)(-10.01/110)))  * 180 / PI));
           y0 = ((float)(-10.01/110))*(x() - 13690) + 811;
       }
    if(x() >= 13790 && x() < 14040 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),((float)(20.01/250)*(x() - 13800)) + 811);
           setRotation(qreal(qAtan(((float)(20.01/250)))  * 180 / PI));
           y0 = ((float)(20.01/250))*(x() - 13800) + 811;
       }
    if(x() >= 14040 && x() < 14190 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),((float)(40.01/150)*(x() - 14050)) + 821);
           setRotation(qreal(qAtan(((float)(40.01/150)))  * 180 / PI));
           y0 = ((float)(40.01/150))*(x() - 14050) + 821;
       }
   if(x() >= 14190 && x() < 14350 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),((float)(10.01/160)*(x() - 14200)) + 861);
           setRotation(qreal(qAtan(((float)(10.01/160)))  * 180 / PI));
           y0 = ((float)(10.01/160))*(x() - 14200) + 861;
       }
       if(x() >= 14350 && x() < 14690 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),((float)(10.01/340)*(x() - 14360)) + 871);
           setRotation(qreal(qAtan(((float)(10.01/340)))  * 180 / PI));
           y0 = ((float)(10.01/340))*(x() - 14360) + 871;
       }
       if(x() >= 14690 && x() < 14890 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),((float)(30.01/200)*(x() - 14700)) + 881);
           setRotation(qreal(qAtan(((float)(30.01/200)))  * 180 / PI));
           y0 = ((float)(30.01/220))*(x() - 14700) + 881;
       }
       if(x() >= 14890 && x() < 15090 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),((float)(10.01/200)*(x() - 14900)) + 911);
           setRotation(qreal(qAtan(((float)(10.01/200)))  * 180 / PI));
           y0 = ((float)(10.01/200))*(x() - 14900) + 911;
       }
       if(x() >= 15090 && x() < 15390 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-10.01/300)*(x() - 15100)) + 921);
           setRotation(qreal(qAtan(((float)(-10.01/300)))  * 180 / PI));
           y0 = ((float)(-10.01/300))*(x() - 15100) + 921;
       }
       if(x() >= 15390 && x() < 15890 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-10.01/500)*(x() - 15400)) + 911);
           setRotation(qreal(qAtan(((float)(-10.01/500)))  * 180 / PI));
           y0 = ((float)(-10.01/500))*(x() - 15400) + 911;
       }
       if(x() >= 15890 && x() < 16090 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),((float)(15.01/200)*(x() - 15900)) + 901);
           setRotation(qreal(qAtan(((float)(15.01/200)))  * 180 / PI));
           y0 = ((float)(15.01/200))*(x() - 15900) + 901;
       }
       if(x() >= 16090 && x() < 17090 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-5.01/1000)*(x() - 16100)) + 916);
           setRotation(qreal(qAtan(((float)(-5.01/1000)))  * 180 / PI));
           y0 = ((float)(-5.01/1000))*(x() - 16100) + 916;
       }

       if(x() >= 17090 && x() < 17190 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),((float)(1.01/10)*(x() - 17100)) + 911);
           setRotation(qreal(qAtan(((float)(1.01/10)))  * 180 / PI));
           y0 = ((float)(1.01/10))*(x() - 17100) + 911;
       }
       if(x() >= 17190 && x() < 17490 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-10.01/300)*(x() - 17200)) + 921);
           setRotation(qreal(qAtan(((float)(-10.01/300)))  * 180 / PI));
           y0 = ((float)(-10.01/300))*(x() - 17200) + 921;
       }
       if(x() >= 17490 && x() < 18590 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),((float)(15.01/1100)*(x() - 17500)) + 911);
           setRotation(qreal(qAtan(((float)(15.01/1100)))  * 180 / PI));
           y0 = ((float)(15.01/1100))*(x() - 17500) + 911;
       }
       if(x() >= 18590 && x() < 18780 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-25.01/190)*(x() - 18600)) + 926);
           setRotation(qreal(qAtan(((float)(-25.01/190)))  * 180 / PI));
           y0 = ((float)(-25.01/190))*(x() - 18600) + 926;
       }
       if(x() >= 18780 && x() < 18800 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),((float)(10.01/20)*(x() - 18790)) + 901);
           setRotation(qreal(qAtan(((float)(10.01/20)))  * 180 / PI));
           y0 = ((float)(10.01/20))*(x() - 18790) + 901;
       }
       if(x() >= 18800 && x() < 18990 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-20.01/190)*(x() - 18810)) + 911);
           setRotation(qreal(qAtan(((float)(-20.01/190)))  * 180 / PI));
           y0 = ((float)(-20.01/190))*(x() - 18810) + 911;
       }
       if(x() >= 18990 && x() < 19140 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-10.01/150)*(x() - 19000)) + 891);
           setRotation(qreal(qAtan(((float)(-10.01/150)))  * 180 / PI));
           y0 = ((float)(-10.01/150))*(x() - 19000) + 891;
       }
       if(x() >= 19140 && x() < 19190 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-20.01/50)*(x() - 19150)) + 881);
           setRotation(qreal(qAtan(((float)(-20.01/50)))  * 180 / PI));
           y0 = ((float)(-20.01/50))*(x() - 19150) + 881;
       }
       if(x() >= 19190 && x() < 19390 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(), 861);
           setRotation(0);
           y0 = 861;
       }
       if(x() >= 19390 && x() < 19435 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),((float)(10.01/45)*(x() - 19400)) + 861);
           setRotation(qreal(qAtan(((float)(10.01/45)))  * 180 / PI));
           y0 = ((float)(10.01/45))*(x() - 19400) + 861;
       }
       if(x() >= 19435 && x() < 19470 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),871);
           setRotation(0);
           y0 = 871;
       }
       if(x() >= 19470 && x() < 19590 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-50.01/120)*(x() - 19480)) + 871);
           setRotation(qreal(qAtan(((float)(-50.01/120)))  * 180 / PI));
           y0 = ((float)(-50.01/120))*(x() - 19480) + 871;
       }
       if(x() >= 19590 && x() < 19610 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),((float)(10.01/20)*(x() - 19600)) + 821);
           setRotation(qreal(qAtan(((float)(10.01/20)))  * 180 / PI));
           y0 = ((float)(10.01/20))*(x() - 19600) + 821;
       }

       if(x() >= 19610 && x() < 19650 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-10.01/40)*(x() - 19620)) + 831);
           setRotation(qreal(qAtan(((float)(-10.01/40)))  * 180 / PI));
           y0 = ((float)(-10.01/45))*(x() - 19620) + 831;
       }
       if(x() >= 19650 && x() < 19670 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),((float)(10.01/20)*(x() - 19660)) + 821);
           setRotation(qreal(qAtan(((float)(10.01/20)))  * 180 / PI));
           y0 = ((float)(10.01/20))*(x() - 19660) + 821;
       }
       if(x() >= 19670 && x() < 19820 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),831);
           setRotation(0);
           y0 = 831;
       }
       if(x() >= 19820 && x() < 19960 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),((float)(60.01/140)*(x() - 19830)) + 831);
           setRotation(qreal(qAtan(((float)(60.01/140)))  * 180 / PI));
           y0 = ((float)(60.01/140))*(x() - 19830) + 831;
       }
       if(x() >= 19960 && x() < 20040 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),891);
           setRotation(0);
           y0 = 891;
       }

       if(x() >= 20040 && x() < 20170 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-30.01/130)*(x() - 20050)) + 891);
           setRotation(qreal(qAtan(((float)(-30.01/130)))  * 180 / PI));
           y0 = ((float)(-30.01/130))*(x() - 20050) + 891;
       }
       if(x() >= 20170 && x() < 20340 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-20.01/170)*(x() - 20180)) + 861);
           setRotation(qreal(qAtan(((float)(-20.01/170)))  * 180 / PI));
           y0 = ((float)(-20.01/170))*(x() - 20180) + 861;
       }
       if(x() >= 20340 && x() < 20440 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),841);
           setRotation(0);
           y0 = 841;
       }
       if(x() >= 20440 && x() < 20800 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-55.01/360)*(x() - 20450)) + 841);
           setRotation(qreal(qAtan(((float)(-55.01/360)))  * 180 / PI));
           y0 = ((float)(-55.01/360))*(x() - 20450) + 841;
       }
        if(x() >= 20800 && x() < 20830 ) {
                   if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-20.01/30)*(x() - 20810)) + 785);
                   setRotation(qreal(qAtan(((float)(-20.01/30)))  * 180 / PI));
                   y0 = ((float)(-20.01/30))*(x() - 20810) + 785;
       }
       if(x() >= 20830 && x() < 20880 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),((float)(10.01/50)*(x() - 20840)) + 766);
           setRotation(qreal(qAtan(((float)(10.01/50)))  * 180 / PI));
           y0 = ((float)(10.01/50)*(x() - 20840)) + 766;
       }
       if(x() >= 20880 && x() < 20900 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-10.01/20)*(x() - 20890)) + 776);
           setRotation(qreal(qAtan(((float)(-10.01/20)))  * 180 / PI));
           y0 = ((float)(-10.01/20))*(x() - 20890) + 776;
       }
       if(x() >= 20900 && x() < 20940 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),((float)(10.01/40)*(x() - 20910)) + 766);
           setRotation(qreal(qAtan(((float)(24.01/20)))  * 180 / PI));
           y0 = ((float)(10.01/40))*(x() - 20910) + 766;
       }
       if(x() >= 20940 && x() < 21090 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-5.01/150)*(x() - 20950)) + 776);
           setRotation(qreal(qAtan(((float)(-5.01/150)))  * 180 / PI));
           y0 = ((float)(-5.01/150))*(x() - 20950) + 776;
       }

       if(x() >= 21090 && x() < 21190 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-10.01/100)*(x() - 21100)) + 775);
           setRotation(qreal(qAtan(((float)(-10.01/100)))  * 180 / PI));
           y0 = ((float)(-10.01/100))*(x() - 21100) + 775;
       }
       if(x() >= 21190 && x() < 21490 ) {
           if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-15.01/300)*(x() - 21200)) + 761);
           setRotation(qreal(qAtan(((float)(-15.01/300)))  * 180 / PI));
               y0 = ((float)(-15.01/300))*(x() - 21200) + 761;
           }
           if(x() >= 21490 && x() < 21790 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(6.01/300)*(x() - 21500)) + 746);
               setRotation(qreal(qAtan(((float)(6.01/300)))  * 180 / PI));
               y0 = ((float)(6.01/300))*(x() - 21500) + 746;
           }

           if(x() >= 21790 && x() < 21890 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(4.01/100)*(x() - 21800)) + 751);
               setRotation(qreal(qAtan(((float)(4.01/100)))  * 180 / PI));
               y0 = ((float)(4.01/100))*(x() - 21800) + 751;
           }
           if(x() >= 21890 && x() < 22090 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-15.01/200)*(x() - 21900)) + 756);
               setRotation(qreal(qAtan(((float)(-15.01/200)))  * 180 / PI));
               y0 = ((float)(-15.01/200))*(x() - 21900) + 756;
           }
           if(x() >= 22090 && x() < 22190 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-15.01/100)*(x() - 22100)) + 741);
               setRotation(qreal(qAtan(((float)(-15.01/100)))  * 180 / PI));
               y0 = ((float)(-15.01/100))*(x() - 22100) + 741;
           }
           if(x() >= 22190 && x() < 22280 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-10.01/90)*(x() - 22200)) + 726);
               setRotation(qreal(qAtan(((float)(-10.01/90)))  * 180 / PI));
               y0 = ((float)(-10.01/90))*(x() - 22200) + 726;
           }
           if(x() >= 22280 && x() < 22590 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-35.01/310)*(x() - 22290)) + 716);
               setRotation(qreal(qAtan(((float)(-35.01/310)))  * 180 / PI));
               y0 = ((float)(-35.01/310))*(x() - 22290) + 716;
           }
           if(x() >= 22590 && x() < 22690 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(5.01/100)*(x() - 22600)) + 681);
               setRotation(qreal(qAtan(((float)(5.01/100)))  * 180 / PI));
               y0 = ((float)(5.01/100))*(x() - 22600) + 681;
           }
           if(x() >= 22690 && x() < 22870 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(35.01/180)*(x() - 22700)) + 686);
               setRotation(qreal(qAtan(((float)(35.01/180)))  * 180 / PI));
               y0 = ((float)(35.01/180))*(x() - 22700) + 686;
           }
           if(x() >= 22870 && x() < 22940 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(30.01/150)*(x() - 22880)) + 726);
               setRotation(qreal(qAtan(((float)(30.01/150)))  * 180 / PI));
               y0 = ((float)(30.01/150))*(x() - 22880) + 726;
           }

           if(x() >= 22940 && x() < 22990 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(30.01/70)*(x() - 22950)) + 751);
               setRotation(qreal(qAtan(((float)(30.01/70)))  * 180 / PI));
               y0 = ((float)(30.01/70))*(x() - 22950) + 751;
           }
           if(x() >= 22990 && x() < 23110 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(10.01/120)*(x() - 23000)) + 761);
               setRotation(qreal(qAtan(((float)(10.01/120)))  * 180 / PI));
               y0 = ((float)(10.01/120))*(x() - 23000) + 761;
           }
           if(x() >= 23110 && x() < 23190 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-10.01/80)*(x() - 23120)) + 771);
               setRotation(qreal(qAtan(((float)(-10.01/80)))  * 180 / PI));
               y0 = ((float)(-10.01/80))*(x() - 23120) + 771;
           }
           if(x() >= 23190 && x() < 23290 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(15.01/100)*(x() - 23200)) + 761);
               setRotation(qreal(qAtan(((float)(15.01/100)))  * 180 / PI));
               y0 = ((float)(15.01/100))*(x() - 23200) + 761;
           }
           if(x() >= 23290 && x() < 23360 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(2.01/70)*(x() - 23300)) + 776);
               setRotation(qreal(qAtan(((float)(2.01/70)))  * 180 / PI));
               y0 = ((float)(2.01/70))*(x() - 23300) + 776;
           }

           if(x() >= 23360 && x() < 23390 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(4.01/30)*(x() - 23370)) + 778);
               setRotation(qreal(qAtan(((float)(4.01/30)))  * 180 / PI));
               y0 = ((float)(4.01/30))*(x() - 23370) + 778;
           }
           if(x() >= 23390 && x() < 23590 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(10.01/200)*(x() - 23400)) + 781);
               setRotation(qreal(qAtan(((float)(10.01/200)))  * 180 / PI));
               y0 = ((float)(10.01/200))*(x() - 23400) + 781;
           }
           if(x() >= 23590 && x() < 23690 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(20.01/100)*(x() - 23600)) + 791);
               setRotation(qreal(qAtan(((float)(20.01/100)))  * 180 / PI));
               y0 = ((float)(20.01/100))*(x() - 23600) + 791;
           }
           if(x() >= 23690 && x() < 23790 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(20.01/100)*(x() - 23700)) + 811);
               setRotation(qreal(qAtan(((float)(20.01/100)))  * 180 / PI));
               y0 = ((float)(20.01/100))*(x() - 23700) + 811;
           }
           if(x() >= 23790 && x() < 23890 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(10.01/100)*(x() - 23800)) + 831);
               setRotation(qreal(qAtan(((float)(10.01/100)))  * 180 / PI));
               y0 = ((float)(10.01/100))*(x() - 23800) + 831;
           }
           if(x() >= 23890 && x() < 23990 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(5.01/100)*(x() - 23900)) + 841);
               setRotation(qreal(qAtan(((float)(5.01/100)))  * 180 / PI));
               y0 = ((float)(5.01/100))*(x() - 23900) + 841;
           }

           /* list<< QPoint(0,1024)      << QPoint(24800,1024)   << QPoint(24800,860)
                << QPoint(24700,880)  */
           if(x() >= 23990 && x() < 24690 ) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-15.01/150)*(x() - 24000)) + 846);
               setRotation(qreal(qAtan(((float)(-15.01/150)))  * 180 / PI));
               y0 = ((float)(-15.01/150))*(x() - 24000) + 846;
           }
           if(x() >= 24690 && x() < 24790) {
               if((barkhord1 == true && barkhord == true))setPos(x(),((float)(-20.01/100)*(x() - 24700)) + 841);
               setRotation(qreal(qAtan(((float)(-20.01/100)))  * 180 / PI));
               y0 = ((float)(-20.01/100))*(x() - 24700) + 841;
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
        if(counter1 % 10 == 0 && mark_r == true && mark == true && mark_l == false
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
        else if(counter1 % 10 == 0 && mark_l == true && mark == true && mark_r == false
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
       else  if(counter1 % 15 == 0  && mark_l == false && mark_r == false && mark == false &&
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
        else if(counter1 % 15 == 0 && mark_l == false && mark_r == false && mark == false
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
        else if(counter1 % 10 == 0 && mark_l == false && mark_r == false && mark_s == true && barkhord == false
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
         else if(counter1 % 10 == 0 && mark_l == false && mark_r == false && mark_s == true && barkhord == false
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
        else if(counter1 % 10 == 0 && mark_l == false && mark_r == true && mark_s == true && barkhord == false
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
         else if(counter1 % 10 == 0 && mark_l == true && mark_r == false && mark_s == true && barkhord == false
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
        else if(counter1 % 8 == 0 && mark_l == false && mark_r == true && mark_shift == true
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
        else if(counter1 % 8 == 0 && mark_l == true && mark_r == false && mark_shift == true
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
        else if(counter1 % 10 == 0 && mark_r == true && mark == true && mark_l == false && turn_right == true
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
        else if(counter1 % 8 == 0 && mark_r == false && mark == true && mark_l == true && turn_left == true
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
                //Move ProPerties

        if((mark == true && mark_r == true)) {
               moveright();
        }
        if((mark == true && mark_l == true)) {
               moveleft();
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
                if(g > 0){ going_down = false ; going_up = true;}
                else { going_down = true ; going_up = false; }
            if(count == 0) {
                x0 = x();
                count++;
            }
            if(mark_l == false && mark_r == false)setPos(x0,y() - g);
            else setPos(x(),y() - g);
                qDebug() << x() << y0 << y();

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
                 g = 7.5;
               }
        }
        //Send CoorDinates Of Player To Enemy
        Enemy->getPlayerCoordinate(x(),y());
    y00 = y0;

}
