#include "game.h"
#include <QMainWindow>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game *Game = new game();
    Game->setFixedSize(2000,1024);
    Game->show();

    return a.exec();
}


