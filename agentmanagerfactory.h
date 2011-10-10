#ifndef AGENTMANAGERFACTORY_H
#define AGENTMANAGERFACTORY_H

#include "agentmanager.h"

class AgentManagerFactory
{
public:
  virtual AgentManager* createManagers( int number )
  {
    return new AgentManager[number];
  }
};

#endif // AGENTMANAGERFACTORY_H
