#ifndef MAP_H
#define MAP_H

#include <QString>
#include <QStringList>
#include <QList>
#include <QFile>

#include "cube.h"
#include "level.h"

class Map
{
private:
    Level *levels;
    int levelCount;

public:
    Map();
    ~Map();

    bool loadLevels( QString );
    Cube* getCube( int, int, int );
    bool getCoord( Cube*, int*, int* );
    QList<Cube*> getAround( int, int, int ); // view for agent

    Map operator =( Map &m );
};

#endif // MAP_H
