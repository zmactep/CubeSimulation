#ifndef LEVEL_H
#define LEVEL_H

#include <QString>
#include <QStringList>
#include <QFile>

#include "cube.h"

class Level
{
private:
  Cube **cubes;
  int width,
      height;

public:
    Level();
    ~Level();

    bool loadLevel( QString );

    Cube *getCube( int, int );
    bool getCoord( Cube*, int*, int* );

    inline int getWidth( void )
    {
      return width;
    }

    inline int getHeight( void )
    {
      return height;
    }

    Level operator = ( Level& );
};

#endif // LEVEL_H
