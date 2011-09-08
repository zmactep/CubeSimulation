#include "level.h"

Level::Level()
{
  width = height = 0;
  cubes = NULL;
}

Level::~Level()
{
  for( int i = 0; i < height; i++ )
  {
    delete[] cubes[i];
    cubes[i] = NULL;
  }

  delete cubes;
  cubes = NULL;
}

bool Level::loadLevel( QString fileName )
{
  QFile file(fileName);

  if(!file.open(QFile::ReadOnly))
    return false;

  QStringList params = QString("").append(file.readLine()).split(' ');

  width = params.first().toInt();
  height = params.last().toInt();

  cubes = new Cube*[height];


  QByteArray line;
  for( int i = 0; i < height; i++ )
  {
    line = file.readLine();
    if(line == NULL || line.length() < width)
    {
      file.close();
      return false;
    }

    cubes[i] = new Cube[width];

    for( int j = 0; j < width; j++ )
    {
      if(line.at(j) == '0')
        cubes[i][j].setTransparent(true);
      else
        cubes[i][j].setTransparent(false);
    }
  }

  file.close();
  return true;
}

Cube *Level::getCube( int x, int y )
{
  if(x > width || x < 0 || y > height || y < 0)
    return NULL;

  return &cubes[y][x];
}
