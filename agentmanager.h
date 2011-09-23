#ifndef AGENTMANAGER_H
#define AGENTMANAGER_H

#include "agent.h"
#include "map.h"

//! AgentManager class.
/*!
  AgentManager is the base Agent controller system. It may be upgraded by
  extending and rewriting the makeStrategy() method.
*/
class AgentManager
{
protected:
  //! Manager`s Agents.
  /*!
    The Agents, that this AgentManager can controll.
  */
  Agent *agents;

  //! Agents count.
  /*!
    Thenumber of Agents, that this AgentManager can controll.
  */
  int agentsCount;

  //! Subjective Map.
  /*!
    The Map, that all the Agent`s of this AgentManager use.
  */
  Map subjMap;

public:
  //! Constructor.
  /*!
    Creates the Agents.
    \param num the number of Agents to create
  */
  AgentManager( int num = 0 );

  //! Destructor.
  /*!
    Deletes all used memory when the object`s live ends.
  */
  ~AgentManager();

  //! Set subjective Map method.
  /*!
    Sets the subjective Map for this AgentManager.
    \param map the pointer to the Map to copy.
  */
  inline void setSubjMap( Map *map )
  {
    subjMap.copyOf(map);
  }

  //! Get Agent`s count method.
  /*!
    \return number of Agents in this AgentManager
  */
  inline int getAgentsCount( void )
  {
    return agentsCount;
  }

  //! Get Agent`s plan method.
  /*!
    \param agenNum the number of Agent in this AgentManager
    \return Agent`s plan for the next iteration
  */
  inline unsigned char getAgentPlan( int agentNum )
  {
    if(agentNum < 0 || agentNum >= agentsCount)
      return 0;

    return agents[agentNum].getPlan();
  }

  //! Get Agent`s health method.
  /*!
    \param agenNum the number of Agent in this AgentManager
    \return Agent`s health for the next iteration
  */
  inline int getAgentHealth( int agentNum )
  {
    if(agentNum < 0 || agentNum >= agentsCount)
      return 0;

    return agents[agentNum].getHealth();
  }

  //! Get Agent`s coordinates method.
  /*!
    \param agenNum the number of Agent in this AgentManager
    \param coord the array, where the Agent`s coordinates will be put,
                 must be 1x3
    \return true, if Agent with this number exists in this AgentManager,
            false if not
  */
  bool getAgentCoord( int, int* );

  //! Append submap method.
  /*!
    Appends submap to subjective Map by given reference point and radius around it.
    \param app_map a submap to append
    \param x an integer x-coordinate of reference Cube
    \param y an integer y-coordinate of reference Cube
    \param z an integer z-coordinate of reference Cube
    \param rad an integer radius
    \return true if there were not any errors and
            false if something wrong had happend
  */
  bool appendInfo( Map&, int, int, int, int );


  //! Approve Agent`s plan method.
  /*!
    Make with Agent all the things, that it wanted to do.
    \param agentNum the number of Agent in this AgentManager
  */
  void approveLastAgentPlan( int );

  //! Make strategy method.
  /*!
    Creates strategy for all the Agents of this AgentManager.
  */
  virtual void makeStrategy( void )
  {
    for( int i = 0; i < agentsCount; i++ )
      agents[i].setPlan(0);
  }
};

#endif // AGENTMANAGER_H
