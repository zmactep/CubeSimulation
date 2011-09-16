#include "level.h"

Level::Level()
{
  width = height = 0;
}

Level::~Level()
{
  for(int i = 0; i < height; i++)
    if(cubes[i])
    {
      delete[] cubes[i];
      cubes[i] = NULL;
    }

  if(cubes)
  {
    delete[] cubes;
    cubes = NULL;
  }
}

bool Level::loadLevel( QString fileName )
{
  QFile file(fileName);

  if(!file.open(QFile::ReadOnly))
    return false;

  QStringList parseString;

  // read first line "width height"
  // file:
  // x y
  // data
  // data 1 2 3 4 5 6 7 8 7 8
  // ....
  // data
  parseString = (QString("").append(file.readLine())).split(" ");
  width = ((QString)(parseString.first())).toInt();
  height = ((QString)(parseString.last())).toInt();

  cubes = new Cube*[height];

  int transp;
  for( int i = 0; i < height; i++) {
    cubes[i] = new Cube[width];

    parseString = (QString("").append(file.readLine())).split(' ');
    if(parseString.isEmpty())
      return false;

    if(parseString.length() < width)
      return false;

    for( int j = 0; j < width; j++ )
    {
      transp = ((QString)(parseString.at(j))).toInt();
      cubes[i][j].setTransparent((bool)transp);
    }
  }

  file.close();

  return true;
}

Cube *Level::getCube( int x, int y )
{
  if(x > 0 && x < width &&
     y > 0 && y < height)
    return &cubes[y][x];

  return NULL;
}

bool Level::getCoord( Cube* cube, int* x, int* y )
{
  for( int i = 0; i < height; i++ )
    for( int j = 0; j < width; j++ )
      if(cube == &cubes[i][j])
      {
        *x = j;
        *y = i;

        return true;
      }

  return false;
}

Level Level::operator = ( Level &l)
{
    width = l.width;
    height = l.height;
    cubes = new Cube*[height];
    for ( int i=0; i<height; i++ )
        cubes[i] = new Cube[width];
    for ( int i=0; i<height; i++ )
        for( int j=0; j<width; j++ )
        {
            cubes[i][j] = l.cubes[i][j];
        }
}
