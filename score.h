#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsPixmapItem>
#include <QObject>
class score : public QObject , public QGraphicsPixmapItem {
    Q_OBJECT
public:
   score();
   score &operator-=(int x);
   void set_pos(qreal x,qreal y);
   void set_score(int y);
   bool operator <(int x);
   ~score();
   QTimer *timer;

protected slots:
   void sprite();
private:
   int intilized_score;

};
#endif // SCORE_H
