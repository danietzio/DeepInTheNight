#ifndef MAP_H
#define MAP_H
#include <QGraphicsPolygonItem>
#include <QGraphicsRectItem>
#include <QPaintEvent>
#include <QTimer>
#include <QObject>
#include <QPixmap>
#include <QMouseEvent>
#include <QVector>
#include <QPoint>
#include <QPainterPath>
#include <QPainter>
#include <QRectF>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <QScrollBar>
class map : public QObject , public QGraphicsPolygonItem ,public QPixmap {
Q_OBJECT
public:
    map(QGraphicsView *);
    QGraphicsView *view;
    QTimer *timer;

};

#endif // MAP_H
