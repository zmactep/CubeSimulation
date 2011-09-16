#ifndef AGENTMANAGER_H
#define AGENTMANAGER_H

#include "map.h"
#include "agent.h"

class AgentManager
{
private:
    Map view; // map created by views from agents
    QList<Agent> agents; // list of agents
public:
    AgentManager();

    // where should it be pushed?
    bool addAgent(); // ask Enviroment for permission
    bool moveAgent(); // ask Environment for permission
    // Agents logic will be here
};

#endif // AGENTMANAGER_H
