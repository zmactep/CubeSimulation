#include "environment.h"

Environment::Environment()
{
}

Environment::~Environment()
{
  delete[] agents;
  delete[] levels;
}
