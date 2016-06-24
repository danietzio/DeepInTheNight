#include <enemy2.h>
#include <qmath.h>
#include <QPoint>
#include <QLine>
#include <QDebug>
enemy2::enemy2(QGraphicsScene *scene,qreal x2,qreal y2)
{
    setPos(1500,0);
    Scene = scene;
    Health = new health(100);
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(10);

    //set x2, y2
    x_2 = x2;
    y_2 = y2;
}
int enemy2::speed = 3;

void enemy2::moveright()
{
    static int counter_r = 0;
           if(counter_r < 15)
           {
               counter_r++;
               setPos(x() ,y());
           }
           else  setPos(x() + speed,y() );
}

void enemy2::moveleft()
{
    static int counter_l = 0;
           if(counter_l < 15) {
               counter_l++;
               setPos(x() ,y());
           }
           else  setPos(x() - speed,y() );
}

void enemy2::movedown()
{
    static int counter_l = 0;
           if(counter_l < 15) {
               counter_l++;
               setPos(x() ,y());
           }
           else  setPos(x() ,y() + speed );
}

void enemy2::moveup()
{
    static int counter_l = 0;
           if(counter_l < 15) {
               counter_l++;
               setPos(x() ,y());
           }
           else  setPos(x() - speed,y() - speed);
}

float enemy2::calculateDistance()
{
    qreal l1 = (x() + 2300 - x_pl)*(x() + 2300 - x_pl);
    qreal l2 = (y() + 2300  - y_pl)*(y() + 2300  - y_pl);
    qreal l = l1 + l2;
    float x = qSqrt(l);
    return x ;
}

void enemy2::move()
{
    mark_l = true;
    //Set Player Position
      x_pl = x_player;
      y_pl = y_player;
      static float g = -10;
         g  += 0.1;
        if(y() >= 0) {
            setPos(x(),y() - g);
            qDebug()<<y();
        }
        else {
            setPixmap(QPixmap(":/new/bat/F:/Qt/Poroje/SPRITE/BAT/left/5.png"));
            mark_l = false;
        }


    //move left
     if(mark_l == true) moveleft();


     //Sprite
     static int counter_bat_move = 0;
     static int counter1 = 0;
     counter1++;
        if(counter1 % 12 == 0 && mark_l == true) {
                switch(counter_bat_move % 4) {
                      case 0:
                        setPixmap(QPixmap(":/new/bat/F:/Qt/Poroje/SPRITE/BAT/left/1.png"));
                        counter_bat_move++;
                        break;
                      case 1:
                        setPixmap(QPixmap(":/new/bat/F:/Qt/Poroje/SPRITE/BAT/left/2.png"));
                        counter_bat_move++;
                        break;
                      case 2:
                        setPixmap(QPixmap(":/new/bat/F:/Qt/Poroje/SPRITE/BAT/left/3.png"));
                        counter_bat_move++;
                        break;
                      case 3:
                        setPixmap(QPixmap(":/new/bat/F:/Qt/Poroje/SPRITE/BAT/left/4.png"));
                        counter_bat_move++;
                        counter_bat_move = 0;
                        break;
                    }
        }
}
