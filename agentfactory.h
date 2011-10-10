#ifndef AGENTFACTORY_H
#define AGENTFACTORY_H

#include "agent.h"

class AgentFactory
{
public:
  virtual Agent* createAgents( int number )
  {
    return new Agent[number];
  }
};

#endif // AGENTFACTORY_H
