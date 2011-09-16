#include "map.h"

Map::Map()
{
  levelCount = 0;
}

Map::~Map()
{
  if(levels)
  {
    delete[] levels;
    levels = NULL;
  }
}

bool Map::loadLevels( QString fileName )
{
  QFile file(fileName);
  QStringList list;
  QString line;
  int count = 0;

  if(!file.open(QFile::ReadOnly))
    return false;

  while(!(line = QString("").append(file.readLine())).isEmpty())
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


//  Looks like shit, DON`T YOU THINK SO?!
QList<Cube*> Map::getAround( int level, int x, int y )
{
   QList<Cube*> list;

  if(level > levelCount || level < 0)
    return list;

  Level* current = &levels[level];
  int w = current->getWidth(),
      h = current->getHeight();

  if(x < 0 || x >= w || y < 0 || y >= h)
    return list;

  // LIST

  // UP UP UP   0  1  2        NW N NE
  // UP UP UP   3  4  5        W     E
  // UP UP UP   6  7  8        SW S SE

  // CU CU CU   9  10 11       NW N NE
  // CU CU CU   12 13 14       W     E
  // CU CU CU   15 16 17       SW S SE

  // DN DN DN   18 19 20       NW N NE
  // DN DN DN   21 22 23       W     E
  // DN DN DN   24 25 26       SW S SE

  // try to see around and get something
  bool west, east, north, south, up, down;
  west = x;
  east = (w - 1) - x;
  north = y;
  south = (h - 1) - y;
  up = level;
  down = (levelCount - 1) - level;

  int i,j,k;
  for( i=level-1; level+1; i++ )
      for( j=y-1; y+1; j++ )
          for( k=x-1; x+1; k++ )
          {
              list.append(getCube(i,j,k));
          }

  list.replace(14, NULL); // pin the object, who get a view

  if (!west)
  {
      list.replace(0, NULL);
      list.replace(3, NULL);
      list.replace(6, NULL);
      list.replace(9, NULL);
      list.replace(12, NULL);
      list.replace(15, NULL);
      list.replace(18, NULL);
      list.replace(21, NULL);
      list.replace(24, NULL);
  }
  if(!east)
  {
      list.replace(2, NULL);
      list.replace(4, NULL);
      list.replace(8, NULL);
      list.replace(11, NULL);
      list.replace(14, NULL);
      list.replace(17, NULL);
      list.replace(20, NULL);
      list.replace(23, NULL);
      list.replace(26, NULL);
      // no any cubes at the eastt
  }
  if(!north)
  {
      list.replace(0, NULL);
      list.replace(1, NULL);
      list.replace(2, NULL);
      list.replace(9, NULL);
      list.replace(10, NULL);
      list.replace(11, NULL);
      list.replace(18, NULL);
      list.replace(19, NULL);
      list.replace(20, NULL);
      // no any cubes at the north
  }
  if(!south)
  {
      list.replace(6, NULL);
      list.replace(7, NULL);
      list.replace(8, NULL);
      list.replace(15, NULL);
      list.replace(16, NULL);
      list.replace(17, NULL);
      list.replace(24, NULL);
      list.replace(25, NULL);
      list.replace(26, NULL);
      // no any cubes at the south
  }
  if(!up)
  {
      list.replace(0, NULL);
      list.replace(1, NULL);
      list.replace(2, NULL);
      list.replace(3, NULL);
      list.replace(4, NULL);
      list.replace(5, NULL);
      list.replace(6, NULL);
      list.replace(7, NULL);
      list.replace(8, NULL);
      // no any cubes at the up
  }
  if(!down)
  {
      list.replace(18, NULL);
      list.replace(19, NULL);
      list.replace(20, NULL);
      list.replace(21, NULL);
      list.replace(22, NULL);
      list.replace(23, NULL);
      list.replace(24, NULL);
      list.replace(25, NULL);
      list.replace(26, NULL);
      //no cubes down
  }

  for ( i=list.length(); i>=0; i-- )
              if(list.at(i)==NULL) list.removeAt(i);

  return list;
}

Cube* Map::getCube(int level, int x, int y)
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

bool Map::getCoord( Cube* cube, int* x, int* y )
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

Map Map::operator =( Map &m ) {
    levelCount = m.levelCount;
    levels = new Level[levelCount];
    for (int i = 0; i<levelCount; i++)
        levels[i] = m.levels[i];
    return *this;
}
