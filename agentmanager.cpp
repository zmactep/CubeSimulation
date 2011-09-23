#include "agentmanager.h"

AgentManager::AgentManager( int num )
{
  agentsCount = num;
  if(agentsCount <= 0)
  {
    agentsCount = 0;
    agents = NULL;
    return;
  }

  agents = new Agent[agentsCount];
  if(!agents)
  {
    agentsCount = 0;
    return;
  }
}

AgentManager::~AgentManager()
{
  if(agents)
    delete agents;
  agents = NULL;
}

bool AgentManager::getAgentCoord( int agentNum, int* coord )
{
  if(agentNum < 0 || agentNum >= agentsCount)
    return false;

  *coord = agents[agentNum].getX();
  *(coord + 1) = agents[agentNum].getY();
  *(coord + 2) = agents[agentNum].getZ();

  return true;
}

bool AgentManager::appendInfo( Map& app_map, int x, int y, int z, int rad )
{
  return subjMap.appendSubMap(app_map, x,y,z, rad);
}

void AgentManager::approveLastAgentPlan( int agentNum )
{
  if(agentNum < 0 || agentNum >= agentsCount)
    return;

  unsigned char plan = agents[agentNum].getPlan();

  plan = plan;

  // TODO: Place some funny code here
}
