#ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsTextItem>
#include <QTextDocument>
class health : public QGraphicsTextItem {
public:
   health(int x);
   health &operator-=(int x);
   void set_pos(qreal x,qreal y);
   void set_Health(int y);
   bool operator <(int x);
   ~health();
private:
   QTextDocument *text ;
   int intilized_Health;

};


#endif // HEALTH_H
