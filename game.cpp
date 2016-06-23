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
    scene->setSceneRect(0,0,25000,1024);
    Enemy = new enemy();
    Player = new player(this,Enemy);
    exist_pl = true;
    Player->setFlag(QGraphicsItem::ItemIsFocusable);
    Player->setFocus();
    _map = new map(this);
    scene->addItem(_map);
    scene->addItem(Player);
    scene->setBackgroundBrush(QBrush(QPixmap(":/new/img/F:/Qt/Poroje/backg1 (2).jpg")));

    scene->addItem(Enemy);
    this->setMouseTracking(true);
    //this->showFullScreen();
}
