#include <obj.h>


obj::obj(QGraphicsView *v)
{
    view = v;
}
obj::~obj()
{
    delete timer;
    deleteLater();
}
int obj::speed = 3;
