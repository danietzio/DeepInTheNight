#include "health.h"
#include "QTimer"
#include "QDebug"
health::health(int x)
{
    setPos(150,55);
    intilized_health = 0;
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(sprite()));
    timer->start(100);
}

health &health::operator-=(int x)
{
    intilized_health -= 10;
    return (*this);
}

void health::set_pos(qreal x, qreal y)
{
    qreal x0 = x - 300;
    qDebug() << x;
    setPos(x0 ,55);
}

void health::set_health(int y)
{
    intilized_health -= 20;
    if(intilized_health < 0)intilized_health = 0;
}

bool health::operator<(int x)
{
    if(intilized_health < x) return true;
    else return false;
}

health::~health()
{

    deleteLater();
}

void health::sprite()
{
    switch(intilized_health) {
    case 0 :
        setPixmap(QPixmap(":/new/Health/F:/Qt/Poroje/SPRITE/progressBar/Blue/0.png"));
        break;
    case 10 :
        setPixmap(QPixmap(":/new/Health/F:/Qt/Poroje/SPRITE/progressBar/Blue/1.png"));
        break;
    case 20 :
        setPixmap(QPixmap(":/new/Health/F:/Qt/Poroje/SPRITE/progressBar/Blue/2.png"));
        break;
    case 30 :
        setPixmap(QPixmap(":/new/Health/F:/Qt/Poroje/SPRITE/progressBar/Blue/3.png"));
        break;
    case 40 :
        setPixmap(QPixmap(":/new/Health/F:/Qt/Poroje/SPRITE/progressBar/Blue/4.png"));
        break;
    case 50 :
        setPixmap(QPixmap(":/new/Health/F:/Qt/Poroje/SPRITE/progressBar/Blue/5.png"));
        break;
    case 60 :
        setPixmap(QPixmap(":/new/Health/F:/Qt/Poroje/SPRITE/progressBar/Blue/6.png"));
        break;
    case 70 :
        setPixmap(QPixmap(":/new/Health/F:/Qt/Poroje/SPRITE/progressBar/Blue/7.png"));
        break;
    case 80 :
        setPixmap(QPixmap(":/new/Health/F:/Qt/Poroje/SPRITE/progressBar/Blue/8.png"));
        break;
    case 90 :
        setPixmap(QPixmap(":/new/Health/F:/Qt/Poroje/SPRITE/progressBar/Blue/9.png"));
        break;
    case 100 :
        setPixmap(QPixmap(":/new/Health/F:/Qt/Poroje/SPRITE/progressBar/Blue/10.png"));
        break;
    }
}

