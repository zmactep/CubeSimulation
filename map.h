#ifndef MAP_H
#define MAP_H

#include <QString>
#include <QStringList>
#include <QList>
#include <QFile>

#include "cube.h"
#include "level.h"
#include "agent.h"
#include "environment.h"

class Map
{
private:
    Level *levels;
    int levelCount;

public:
    Map();

    bool loadLevels( QString );
    Cube* getCube( int, int, int );
    bool getCoord( Cube*, int*, int* );
    QList<Cube*> getAround( int, int, int );

    Map operator =( Map &m );
};

#endif // MAP_H
