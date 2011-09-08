#ifndef LEVEL_H
#define LEVEL_H

#include <QByteArray>
#include <QString>
#include <QStringList>
#include <QFile>

#include "cube.h"

class Level
{
private:
  int width, height;
  Cube **cubes;

public:
  Level();
  ~Level();

  bool loadLevel( QString fileName );

  Cube *getCube( int x, int y );
};

#endif // LEVEL_H
