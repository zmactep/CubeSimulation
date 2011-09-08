#include "cube.h"

Cube::Cube()
{
}

void Cube::incInfection( void )
{
  infection = infection < MAX_INFECTION ? infection + 1 : MAX_INFECTION;
}

void Cube::decInfection( void )
{
  infection = infection > 0 ? infection - 1 : 0;
}

void Cube::setTransparent( bool t )
{
  transparent = t;
}

bool Cube::isTransparent( void )
{
  return transparent;
}

int Cube::getInfection( void )
{
  return infection;
}
