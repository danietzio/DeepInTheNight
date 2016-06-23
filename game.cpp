#include "game.h"
#include "map.h"
#include "QRegion"
#include <QDebug>
#include "player.h"
bool exist_pl = false;
game::game()
{
    scene = new QGraphicsScene();
    this->setScene(scene);
    scene->setSceneRect(0,0,34744,1024);
    Player = new player(this);
    exist_pl = true;
    Player->setFlag(QGraphicsItem::ItemIsFocusable);
    Player->setFocus();
    _map = new map(this);
    scene->addItem(_map);
    scene->addItem(Player);
    scene->setBackgroundBrush(QBrush(QPixmap(":/new/img/images/BACKGROUND.jpg")));

    this->setMouseTracking(true);
    //this->showFullScreen();
}
