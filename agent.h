#ifndef AGENT_H
#define AGENT_H

#include "cube.h"

class Agent
{
private:
    int teamColor;
    Cube *position;
public:
    Agent();

    // action list - where should it be pushed?
    void Heal ( Cube *whereTo ); // for cubes
    void Infect ( Cube *whereTo ); //for cubes
    void Kill ( Cube *whereTo ); // for enemy agents
};

#endif // AGENT_H
