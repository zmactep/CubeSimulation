#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <QString>
#include <QStringList>
#include <QList>
#include <QFile>

#include "cube.h"
#include "level.h"
#include "agentmanager.h"
#include "map.h"

class Environment
{
private:
  Map realWorld;
  AgentManager redTeam;
  AgentManager blueTeam;
public:
  Environment();
  ~Environment();

  // here will be AGENT API
  bool moveAgent ( Cube* whereTo ); //move agent to cube whereTo
  bool viewArea ( Cube* startPoint); // get a view around startPoint
  bool createAgent (Cube* whereTo, int teamColor);
  bool killAgent (Cube* whereTo );
};

#endif // ENVIRONMENT_H
