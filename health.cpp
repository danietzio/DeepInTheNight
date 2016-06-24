#include "health.h"
health::health(int x)
{
    setPos(1000,0);
    intilized_Health = x;
    text = new QTextDocument(QString::number(intilized_Health));
    setDocument(text);
    show();
    setFont(QFont("impact"));
}

health &health::operator-=(int x)
{
    intilized_Health -= x;
    return (*this);
}

void health::set_pos(qreal x, qreal y)
{
    setPos(x,y);
}

void health::set_Health(int y)
{
    intilized_Health -= 1;
    text->setPlainText(QString::number(x()));

}

bool health::operator <(int x)
{
    if(intilized_Health < x) return true;
    else return false;
}

health::~health()
{
    text->deleteLater();
    deleteLater();
}

