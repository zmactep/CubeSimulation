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

  Level* current = levels[level];
  int w = current->getWidth(),
      h = current->getHeight();

  if(x < 0 || x > w || y < 0 || y > h)
    return NULL;

  QList<Cube*> list;

  // LIST
  // UP UP UP
  // UP UP UP
  // UP UP UP
  // CU CU CU
  // CU __ CU
  // CU CU CU
  // DN DN DN
  // DN DN DN
  // DN DN DN

  Level* up = levels[level-1];
  Level* down = levels[level+1];


}

Cube* Environment::getCube(int level, int x, int y)
{
  if(level > levelCount || level < 0)
    return NULL;

  Level* current = levels[level];
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
