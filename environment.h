#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "cube.h"
#include "level.h"
#include "agent.h"

class Environment
{
private:
  Agent *agents;
  int agentsCount;

  Level *levels;
  int levelsCount;

public:
  Environment();
  ~Environment();
};

#endif // ENVIRONMENT_H
