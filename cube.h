#ifndef CUBE_H
#define CUBE_H

#define MAX_INFECTION 5

class Cube
{
private:
  int infection;
  bool transparent;

public:
  Cube();

  void incInfection( void );
  void decInfection( void );

  void setTransparent( bool t );

  bool isTransparent( void );
  int getInfection( void );
};

#endif // CUBE_H
