#ifndef AGENT_H
#define AGENT_H

#include "cube.h"

#define MAX_HEALTH 100

class Agent
{
private:
  int agentID;
  int health;
  Cube *currentCube;

public:
  Agent();
};

#endif // AGENT_H
