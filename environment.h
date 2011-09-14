#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <QString>
#include <QStringList>
#include <QList>
#include <QFile>

#include "cube.h"
#include "level.h"

class Environment
{
private:
  Level *levels;
  int levelCount;

public:
    Environment();
    ~Environment();

    bool loadLevels( QString );

    QList<Cube*> getAround( int, int, int );
    Cube* getCube( int, int, int );
    bool getCoord( Cube*, int*, int* );
};

#endif // ENVIRONMENT_H
