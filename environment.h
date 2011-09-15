#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <QString>
#include <QStringList>
#include <QList>
#include <QFile>

#include "cube.h"
#include "level.h"
#include "agent.h"

class Environment
{
private:
  Level *levels;
  int levelCount;
  Agent *redTeam;
  Agent *blueTeam;
public:
    Environment();
    ~Environment();

    bool loadLevels( QString );


    Cube* getCube( int, int, int );
    bool getCoord( Cube*, int*, int* );

    // here will be AGENT API
    bool moveMe (Cube* whereTo);

    QList<Cube*> getAround( int, int, int );

};

#endif // ENVIRONMENT_H
