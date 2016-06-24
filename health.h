#ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
class health : public QObject , public QGraphicsPixmapItem {
    Q_OBJECT
public:
   health(int x);
   health &operator-=(int x);
   void set_pos(qreal x,qreal y);
   void set_health(int y);
   bool operator <(int x);
   ~health();
   QTimer *timer;

protected slots:
   void sprite();
private:
   int intilized_health;

};


#endif // HEALTH_H
