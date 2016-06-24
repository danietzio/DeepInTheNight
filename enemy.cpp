#include "enemy.h"
#include <QBrush>
#include <qmath.h>
#include <QtMath>
#include <QDebug>
#include <QBrush>
int y00 = 0;
int time = 0;
static int direction = 1;
enemy::enemy()
{
    setPos(2730,700);
    setPixmap(QPixmap(":/new/idle_right_enemy/F:/Qt/Poroje/SPRITE/ENEMY/idle/Right/1.png"));
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(20);
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
    qreal l1 = (x() - x_pl)*(x() - x_pl);
    qreal l2 = (y()  - y_pl)*(y()   - y_pl);
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
               setPos(x() ,y());
           }
           else  setPos(x() + speed ,y() );
}

void enemy::moveleft()
{
    static int counter_l = 0;
           if(counter_l < 15) {
               counter_l++;
               setPos(x() ,y());
           }
           else  setPos(x() - speed,y() );
}

void enemy::move()
{
    static int counter1 = 0;
    counter1++;
    if(x_pl > 1500 - 2370 + x()  && x_pl < 3500 - 2370 + x()) {
        if(calculateDistance() > 1100 && calculateDistance()  < 1400)
        {

                suspection = true;
                mark_r = false;
                mark_l = false;
                mark = false;
                mark_ctrl = false;
                mark_shift = false;
                turn_left = true;
                turn_right = false;

        }
        else if(calculateDistance() < 1100 && calculateDistance() > 700 && x_pl < x()) {
            qDebug() << x() << x_pl << y_pl << y()  << calculateDistance() << direction;

                suspection = false;
                mark_ctrl = false;
                mark_l = true;
                mark = true;
                mark_r = false;
                mark_ctrl = false;
                mark_shift = false;
                turn_left = true;
                turn_right = false;
                speed = 7;

        }
        else if(calculateDistance()  < 700 && calculateDistance() > 0  && x_pl < x()) {
                suspection = false;
                mark_l = true;
                mark = true;
                mark_r = false;
                mark_shift = false;
                mark_ctrl = true;
                turn_left = true;
                turn_right = false;
                speed = 7;
                time += 10;
                if ( time < 200 ) { mark_ctrl = true; speed = 7;}
                else if(time < 2000) {mark_ctrl = false; speed = 5;}
                if ( time > 2000) { time = 0;}

        }
        else if(calculateDistance()  < 700 && calculateDistance() > 0  && x() < x_pl) {
                suspection = false;
                mark_l = false;
                mark_r = true;
                mark = true;
                mark_ctrl = true;
                mark_shift = false;
                turn_left = false;
                turn_right = true;
                time += 10;
                speed = 7;
                if ( time < 200 ) { mark_ctrl = true; speed = 7;}
                else if(time < 2000) {mark_ctrl = false; speed = 5;}
                if ( time > 2000) { time = 0;}
        }
        else if(calculateDistance() < 1100 && calculateDistance() > 700 &&   x() < x_pl) {
                suspection = false;
                mark_ctrl = false;
                mark_l = false;
                mark_r = true;
                mark = true;
                mark_shift = false;
                turn_left = false;
                turn_right = true;
                speed = 7;

         }
        if(counter1 % 9 == 0 && mark_ctrl == false && mark_r == false &&  mark_l == false && suspection == true && mark_ctrl == false) {
            static int  counter_suspection_left = 0;
                   switch(counter_suspection_left % 4) {
                         case 0:
                           setPixmap(QPixmap(":/new/enemy_suspection/F:/Qt/Poroje/SPRITE/ENEMY/ready-to-fight/SUSPECTED/1.png"));
                           counter_suspection_left++;
                           break;
                         case 1:
                           setPixmap(QPixmap(":/new/enemy_suspection/F:/Qt/Poroje/SPRITE/ENEMY/ready-to-fight/SUSPECTED/2.png"));
                           counter_suspection_left++;
                           break;
                         case 2:
                           setPixmap(QPixmap(":/new/enemy_suspection/F:/Qt/Poroje/SPRITE/ENEMY/ready-to-fight/SUSPECTED/3.png"));
                           counter_suspection_left++;
                           break;
                         case 3:
                           setPixmap(QPixmap(":/new/enemy_suspection/F:/Qt/Poroje/SPRITE/ENEMY/ready-to-fight/SUSPECTED/4.png"));
                           counter_suspection_left++;
                           counter_suspection_left = 0;
                           break;
                       }
            }
            else if(counter1 % 9 == 0 && mark_l == false && mark_r == false && turn_right == true && suspection == false && mark_ctrl == false) {
                static int  counter_right_idle_enemy = 0;
                           switch(counter_right_idle_enemy % 6) {
                             case 0:
                               setPixmap(QPixmap(":/new/idle_right_enemy/F:/Qt/Poroje/SPRITE/ENEMY/idle/Right/1.png"));
                               counter_right_idle_enemy++;
                               break;
                             case 1:
                               setPixmap(QPixmap(":/new/idle_right_enemy/F:/Qt/Poroje/SPRITE/ENEMY/idle/Right/2.png"));
                               counter_right_idle_enemy++;
                               break;
                             case 2:
                               setPixmap(QPixmap(":/new/idle_right_enemy/F:/Qt/Poroje/SPRITE/ENEMY/idle/Right/3.png"));
                               counter_right_idle_enemy++;
                               break;
                             case 3:
                               setPixmap(QPixmap(":/new/idle_right_enemy/F:/Qt/Poroje/SPRITE/ENEMY/idle/Right/4.png"));
                               counter_right_idle_enemy++;
                               break;
                           case 4:
                             setPixmap(QPixmap(":/new/idle_right_enemy/F:/Qt/Poroje/SPRITE/ENEMY/idle/Right/5.png"));
                             counter_right_idle_enemy++;
                             break;
                           case 5:
                             setPixmap(QPixmap(":/new/idle_right_enemy/F:/Qt/Poroje/SPRITE/ENEMY/idle/Right/6.png"));
                             counter_right_idle_enemy++;
                             counter_right_idle_enemy = 0;
                             break;
                           }
            }
            else if(counter1 % 9 == 0 && mark_l == false && mark_r == false && turn_left == true && suspection == false) {
                static int  counter_left_idle_enemy = 0;
                           switch(counter_left_idle_enemy % 6) {
                             case 0:
                               setPixmap(QPixmap(":/new/left_enemt/F:/Qt/Poroje/SPRITE/ENEMY/idle/Left/1.png"));
                               counter_left_idle_enemy++;
                               break;
                             case 1:
                               setPixmap(QPixmap(":/new/left_enemt/F:/Qt/Poroje/SPRITE/ENEMY/idle/Left/2.png"));
                               counter_left_idle_enemy++;
                               break;
                             case 2:
                               setPixmap(QPixmap(":/new/left_enemt/F:/Qt/Poroje/SPRITE/ENEMY/idle/Left/3.png"));
                               counter_left_idle_enemy++;
                               break;
                             case 3:
                               setPixmap(QPixmap(":/new/left_enemt/F:/Qt/Poroje/SPRITE/ENEMY/idle/Left/4.png"));
                               counter_left_idle_enemy++;
                               break;
                           case 4:
                             setPixmap(QPixmap(":/new/left_enemt/F:/Qt/Poroje/SPRITE/ENEMY/idle/Left/5.png"));
                             counter_left_idle_enemy++;
                             break;
                           case 5:
                             setPixmap(QPixmap(":/new/left_enemt/F:/Qt/Poroje/SPRITE/ENEMY/idle/Left/6.png"));
                             counter_left_idle_enemy++;
                             counter_left_idle_enemy = 0;
                             break;
                           }
                    }
                else if(counter1 % 4 == 0 && mark_l == true && mark_r == false && suspection == false && mark_ctrl == false) {
                static int counter_enemy_left_walk = 0;
                           switch(counter_enemy_left_walk % 9) {
                             case 0:
                                setPixmap(QPixmap(":/new/enemy_left_walk/F:/Qt/Poroje/SPRITE/ENEMY/walk/Left/1.png"));
                                counter_enemy_left_walk++;
                                break;
                             case 1:
                                setPixmap(QPixmap(":/new/enemy_left_walk/F:/Qt/Poroje/SPRITE/ENEMY/walk/Left/2.png"));
                                counter_enemy_left_walk++;
                                break;
                             case 2:
                                setPixmap(QPixmap(":/new/enemy_left_walk/F:/Qt/Poroje/SPRITE/ENEMY/walk/Left/3.png"));
                                counter_enemy_left_walk++;
                                break;
                             case 3:
                                setPixmap(QPixmap(":/new/enemy_left_walk/F:/Qt/Poroje/SPRITE/ENEMY/walk/Left/4.png"));
                                counter_enemy_left_walk++;
                                break;
                             case 4:
                                setPixmap(QPixmap(":/new/enemy_left_walk/F:/Qt/Poroje/SPRITE/ENEMY/walk/Left/5.png"));
                                counter_enemy_left_walk++;
                                break;
                             case 5:
                                setPixmap(QPixmap(":/new/enemy_left_walk/F:/Qt/Poroje/SPRITE/ENEMY/walk/Left/6.png"));
                                counter_enemy_left_walk++;
                                break;
                             case 6:
                                setPixmap(QPixmap(":/new/enemy_left_walk/F:/Qt/Poroje/SPRITE/ENEMY/walk/Left/7.png"));
                                counter_enemy_left_walk++;
                                break;
                             case 7:
                                setPixmap(QPixmap(":/new/enemy_left_walk/F:/Qt/Poroje/SPRITE/ENEMY/walk/Left/8.png"));
                                counter_enemy_left_walk++;
                                break;
                             case 8:
                                setPixmap(QPixmap(":/new/enemy_left_walk/F:/Qt/Poroje/SPRITE/ENEMY/walk/Left/9.png"));
                                counter_enemy_left_walk++;
                                counter_enemy_left_walk = 0;
                                break;
                           }
                    }
                    else if(counter1 % 4 == 0 && mark_l == false && mark == true && mark_r == true && suspection == false && mark_ctrl == false) {
                static int counter_enemy_right_walk = 0;
                           switch(counter_enemy_right_walk % 9) {
                             case 0:
                               setPixmap(QPixmap(":/new/enemy_right_walk/F:/Qt/Poroje/SPRITE/ENEMY/walk/Right/1.png"));
                               counter_enemy_right_walk++;
                               break;
                             case 1:
                               setPixmap(QPixmap(":/new/enemy_right_walk/F:/Qt/Poroje/SPRITE/ENEMY/walk/Right/2.png"));
                               counter_enemy_right_walk++;
                               break;
                             case 2:
                               setPixmap(QPixmap(":/new/enemy_right_walk/F:/Qt/Poroje/SPRITE/ENEMY/walk/Right/3.png"));
                               counter_enemy_right_walk++;
                               break;
                             case 3:
                               setPixmap(QPixmap(":/new/enemy_right_walk/F:/Qt/Poroje/SPRITE/ENEMY/walk/Right/4.png"));
                               counter_enemy_right_walk++;
                               break;
                             case 4:
                             setPixmap(QPixmap(":/new/enemy_right_walk/F:/Qt/Poroje/SPRITE/ENEMY/walk/Right/5.png"));
                             counter_enemy_right_walk++;
                             break;
                             case 5:
                             setPixmap(QPixmap(":/new/enemy_right_walk/F:/Qt/Poroje/SPRITE/ENEMY/walk/Right/6.png"));
                             counter_enemy_right_walk++;
                             break;
                             case 6:
                             setPixmap(QPixmap(":/new/enemy_right_walk/F:/Qt/Poroje/SPRITE/ENEMY/walk/Right/7.png"));
                             counter_enemy_right_walk++;
                             break;
                             case 7:
                             setPixmap(QPixmap(":/new/enemy_right_walk/F:/Qt/Poroje/SPRITE/ENEMY/walk/Right/8.png"));
                             counter_enemy_right_walk++;
                             break;
                             case 8:
                             setPixmap(QPixmap(":/new/enemy_right_walk/F:/Qt/Poroje/SPRITE/ENEMY/walk/Right/9.png"));
                             counter_enemy_right_walk++;
                             counter_enemy_right_walk = 0;
                             break;

                           }
                    }
                    else if(counter1 % 9 == 0 && mark_l == true && mark == true && mark_r == false && suspection == false && mark_ctrl == true) {
                static int counter_enemy_left_fight = 0;
                switch(counter_enemy_left_fight % 7) {
                  case 0:
                    setPixmap(QPixmap(":/new/fight_left_enemy/F:/Qt/Poroje/SPRITE/ENEMY/fighter/left/1.png"));
                    counter_enemy_left_fight++;
                    break;
                  case 1:
                    setPixmap(QPixmap(":/new/fight_left_enemy/F:/Qt/Poroje/SPRITE/ENEMY/fighter/left/2.png"));
                    counter_enemy_left_fight++;
                    break;
                  case 2:
                    setPixmap(QPixmap(":/new/fight_left_enemy/F:/Qt/Poroje/SPRITE/ENEMY/fighter/left/3.png"));
                    counter_enemy_left_fight++;
                    break;
                  case 3:
                    setPixmap(QPixmap(":/new/fight_left_enemy/F:/Qt/Poroje/SPRITE/ENEMY/fighter/left/4.png"));
                    counter_enemy_left_fight++;
                    break;
                  case 4:
                    setPixmap(QPixmap(":/new/fight_left_enemy/F:/Qt/Poroje/SPRITE/ENEMY/fighter/left/5.png"));
                    counter_enemy_left_fight++;
                    break;
                  case 5:
                    setPixmap(QPixmap(":/new/fight_left_enemy/F:/Qt/Poroje/SPRITE/ENEMY/fighter/left/6.png"));
                    counter_enemy_left_fight++;
                    break;
                  case 6:
                    setPixmap(QPixmap(":/new/fight_left_enemy/F:/Qt/Poroje/SPRITE/ENEMY/fighter/left/7.png"));
                    counter_enemy_left_fight++;
                    counter_enemy_left_fight = 0;
                    break;
                    }
                    }
                    else if(counter1 % 9 == 0 && mark_l == false && mark == true && mark_r == true && suspection == false && mark_ctrl == true) {
                        static int counter_enemy_right_fight = 0;
                        switch(counter_enemy_right_fight % 7) {
                          case 0:
                            setPixmap(QPixmap(":/new/fight_right_enemy/F:/Qt/Poroje/SPRITE/ENEMY/fighter/Right/1.png1.png"));
                            counter_enemy_right_fight++;
                            break;
                          case 1:
                            setPixmap(QPixmap(":/new/fight_right_enemy/F:/Qt/Poroje/SPRITE/ENEMY/fighter/Right/2.png"));
                            counter_enemy_right_fight++;
                            break;
                          case 2:
                            setPixmap(QPixmap(":/new/fight_right_enemy/F:/Qt/Poroje/SPRITE/ENEMY/fighter/Right/3.png"));
                            counter_enemy_right_fight++;
                            break;
                          case 3:
                            setPixmap(QPixmap(":/new/fight_right_enemy/F:/Qt/Poroje/SPRITE/ENEMY/fighter/Right/4.png"));
                            counter_enemy_right_fight++;
                            break;
                          case 4:
                            setPixmap(QPixmap(":/new/fight_left_enemy/F:/Qt/Poroje/SPRITE/ENEMY/fighter/left/5.png"));
                            counter_enemy_right_fight++;
                            break;
                          case 5:
                            setPixmap(QPixmap(":/new/fight_right_enemy/F:/Qt/Poroje/SPRITE/ENEMY/fighter/Right/6.png"));
                            counter_enemy_right_fight++;
                            break;
                          case 6:
                            setPixmap(QPixmap(":/new/fight_right_enemy/F:/Qt/Poroje/SPRITE/ENEMY/fighter/Right/7.png"));
                            counter_enemy_right_fight++;
                            counter_enemy_right_fight = 0;
                            break;
                                      }
                                }
                            if(mark_r == true && mark == true)moveright();
                            if(mark_l == true && mark == true)moveleft();
                        }
                else {
                 mark_ctrl = false;
                 mark = true;

                    if(x()  > 1600 && x()  < 1700) {
                        direction = 1 ;
                    }
                    if(x() < 3500 && x()  > 3400) {
                        direction = -1;
                    }
                    if(direction == +1)
                    {
                        mark_r = true;
                        mark_l = false;
                        moveright();
                    }
                    else if(direction == -1) {
                        mark_l = true;
                        mark_r = false;
                        moveleft();
                    }
                    if(counter1 % 9 == 0 && mark_r == true && mark_l == false && mark == true) {
                        static int counter_enemy_right_walk = 0;
                                   switch(counter_enemy_right_walk % 9) {
                                     case 0:
                                       setPixmap(QPixmap(":/new/enemy_right_walk/F:/Qt/Poroje/SPRITE/ENEMY/walk/Right/1.png"));
                                       counter_enemy_right_walk++;
                                       break;
                                     case 1:
                                       setPixmap(QPixmap(":/new/enemy_right_walk/F:/Qt/Poroje/SPRITE/ENEMY/walk/Right/2.png"));
                                       counter_enemy_right_walk++;
                                       break;
                                     case 2:
                                       setPixmap(QPixmap(":/new/enemy_right_walk/F:/Qt/Poroje/SPRITE/ENEMY/walk/Right/3.png"));
                                       counter_enemy_right_walk++;
                                       break;
                                     case 3:
                                       setPixmap(QPixmap(":/new/enemy_right_walk/F:/Qt/Poroje/SPRITE/ENEMY/walk/Right/4.png"));
                                       counter_enemy_right_walk++;
                                       break;
                                     case 4:
                                     setPixmap(QPixmap(":/new/enemy_right_walk/F:/Qt/Poroje/SPRITE/ENEMY/walk/Right/5.png"));
                                     counter_enemy_right_walk++;
                                     break;
                                     case 5:
                                     setPixmap(QPixmap(":/new/enemy_right_walk/F:/Qt/Poroje/SPRITE/ENEMY/walk/Right/6.png"));
                                     counter_enemy_right_walk++;
                                     break;
                                     case 6:
                                     setPixmap(QPixmap(":/new/enemy_right_walk/F:/Qt/Poroje/SPRITE/ENEMY/walk/Right/7.png"));
                                     counter_enemy_right_walk++;
                                     break;
                                     case 7:
                                     setPixmap(QPixmap(":/new/enemy_right_walk/F:/Qt/Poroje/SPRITE/ENEMY/walk/Right/8.png"));
                                     counter_enemy_right_walk++;
                                     break;
                                     case 8:
                                     setPixmap(QPixmap(":/new/enemy_right_walk/F:/Qt/Poroje/SPRITE/ENEMY/walk/Right/9.png"));
                                     counter_enemy_right_walk++;
                                     counter_enemy_right_walk = 0;
                                     break;
                                   }
                         }
                    else if(mark_r == false && mark == true && mark_l == true && mark_ctrl == false && counter1 % 9 == 0) {
                        static int counter_enemy_left_walk = 0;
                                   switch(counter_enemy_left_walk % 9) {
                                     case 0:
                                        setPixmap(QPixmap(":/new/enemy_left_walk/F:/Qt/Poroje/SPRITE/ENEMY/walk/Left/1.png"));
                                        counter_enemy_left_walk++;
                                        break;
                                     case 1:
                                        setPixmap(QPixmap(":/new/enemy_left_walk/F:/Qt/Poroje/SPRITE/ENEMY/walk/Left/2.png"));
                                        counter_enemy_left_walk++;
                                        break;
                                     case 2:
                                        setPixmap(QPixmap(":/new/enemy_left_walk/F:/Qt/Poroje/SPRITE/ENEMY/walk/Left/3.png"));
                                        counter_enemy_left_walk++;
                                        break;
                                     case 3:
                                        setPixmap(QPixmap(":/new/enemy_left_walk/F:/Qt/Poroje/SPRITE/ENEMY/walk/Left/4.png"));
                                        counter_enemy_left_walk++;
                                        break;
                                     case 4:
                                        setPixmap(QPixmap(":/new/enemy_left_walk/F:/Qt/Poroje/SPRITE/ENEMY/walk/Left/5.png"));
                                        counter_enemy_left_walk++;
                                        break;
                                     case 5:
                                        setPixmap(QPixmap(":/new/enemy_left_walk/F:/Qt/Poroje/SPRITE/ENEMY/walk/Left/6.png"));
                                        counter_enemy_left_walk++;
                                        break;
                                     case 6:
                                        setPixmap(QPixmap(":/new/enemy_left_walk/F:/Qt/Poroje/SPRITE/ENEMY/walk/Left/7.png"));
                                        counter_enemy_left_walk++;
                                        break;
                                     case 7:
                                        setPixmap(QPixmap(":/new/enemy_left_walk/F:/Qt/Poroje/SPRITE/ENEMY/walk/Left/8.png"));
                                        counter_enemy_left_walk++;
                                        break;
                                     case 8:
                                        setPixmap(QPixmap(":/new/enemy_left_walk/F:/Qt/Poroje/SPRITE/ENEMY/walk/Left/9.png"));
                                        counter_enemy_left_walk++;
                                        counter_enemy_left_walk = 0;
                                        break;
                                   }
                    }
                }


}
