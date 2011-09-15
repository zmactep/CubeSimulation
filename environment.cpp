#include "environment.h"

Environment::Environment()
{
  levelCount = 0;
}

Environment::~Environment()
{
  if(levels)
  {
    delete[] levels;
    levels = NULL;
  }
}

bool Environment::loadLevels( QString fileName )
{
  QFile file(fileName);
  QStringList list;
  QString line;
  int count = 0;

  if(!file.open(QFile::ReadOnly))
    return false;

  while(line = QString.append(file.readLine()))
  {
    count++;
    line.remove('\n');
    list.append(line);
  }

  levels = new Level[count];
  for( int i = 0; i < count; i++ )
    if(!levels->loadLevel(list.at(i)))
      return false;

  levelCount = count;

  return true;
}

QList<Cube*> Environment::getAround( int level, int x, int y )
{
  if(level > levelCount || level < 0)
    return NULL;

  Level* current = &levels[level];
  int w = current->getWidth(),
      h = current->getHeight();

  if(x < 0 || x >= w || y < 0 || y >= h)
    return NULL;

  QList<Cube*> list;

  // LIST
  // UP UP UP   1  2  3
  // UP UP UP   4  5  6
  // UP UP UP   7  8  9
  // CU CU CU   A  B  C
  // CU __ CU   D     E
  // CU CU CU   F 10 11
  // DN DN DN  12 13 14
  // DN DN DN  15 16 17
  // DN DN DN  18 19 1A

  bool west, east, north, south, up, down;
  west = x;
  east = (w - 1) - x;
  north = y;
  south = (h - 1) - y;
  up = level;
  down = (levelCount - 1) - level;


}

Cube* Environment::getCube(int level, int x, int y)
{
  if(level > levelCount || level < 0)
    return NULL;

  Level* current = &levels[level];
  int w = current->getWidth(),
      h = current->getHeight();

  if(x < 0 || x > w || y < 0 || y > h)
    return NULL;

  return current->getCube(x, y);
}

bool Environment::getCoord( Cube* cube, int* x, int* y )
{
  int tx, ty;

  for( int i = 0; i < levelCount; i++ )
    if(levels[i].getCoord(cube, &tx, &ty))
    {
      *x = tx;
      *y = ty;
      return true;
    }

  return false;
}
