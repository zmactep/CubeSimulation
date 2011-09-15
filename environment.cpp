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
