#include "score.h"
#include "QTimer"
#include "QDebug"
score::score()
{
    setPos(150,55);
    intilized_score = 0;
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(sprite()));
    timer->start(100);
}

score &score::operator-=(int x)
{
    intilized_score -= 10;
    return (*this);
}

void score::set_pos(qreal x, qreal y)
{
    qreal x0 = x - 300;
    qDebug() << x;
    setPos(x0 ,55);
}

void score::set_score(int y)
{
    intilized_score -= 20;
    if(intilized_score < 0)intilized_score = 0;
}

bool score::operator <(int x)
{
    if(intilized_score < x) return true;
    else return false;
}

score::~score()
{
    deleteLater();
}

void score::sprite()
{
    switch(intilized_score) {
    case 0 :
        setPixmap(QPixmap(":/new/score/F:/Qt/Poroje/SPRITE/progressBar/Red/10.png"));
        break;
    case 10 :
        setPixmap(QPixmap(":/new/score/F:/Qt/Poroje/SPRITE/progressBar/Red/9.png"));
        break;
    case 20 :
        setPixmap(QPixmap(":/new/score/F:/Qt/Poroje/SPRITE/progressBar/Red/8.png"));
        break;
    case 30 :
        setPixmap(QPixmap(":/new/score/F:/Qt/Poroje/SPRITE/progressBar/Red/7.png"));
        break;
    case 40 :
        setPixmap(QPixmap(":/new/score/F:/Qt/Poroje/SPRITE/progressBar/Red/6.png"));
        break;
    case 50 :
        setPixmap(QPixmap(":/new/score/F:/Qt/Poroje/SPRITE/progressBar/Red/5.png"));
        break;
    case 60 :
        setPixmap(QPixmap(":/new/score/F:/Qt/Poroje/SPRITE/progressBar/Red/4.png"));
        break;
    case 70 :
        setPixmap(QPixmap(":/new/score/F:/Qt/Poroje/SPRITE/progressBar/Red/3.png"));
        break;
    case 80 :
        setPixmap(QPixmap(":/new/score/F:/Qt/Poroje/SPRITE/progressBar/Red/2.png"));
        break;
    case 90 :
        setPixmap(QPixmap(":/new/score/F:/Qt/Poroje/SPRITE/progressBar/Red/1.png"));
        break;
    case 100 :
        setPixmap(QPixmap(":/new/score/F:/Qt/Poroje/SPRITE/progressBar/Red/0.png"));
        break;
    }
}

