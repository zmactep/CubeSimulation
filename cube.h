#ifndef CUBE_H
#define CUBE_H

#define MAX_INFECTION 10

class Cube
{
private:
  bool transparent;
  int infection;
public:
    Cube(){}

    inline void setTransparent( bool t )
    {
      transparent = t;
    }

    inline bool isTransparent( void )
    {
      return transparent;
    }

    inline void incInfection( void )
    {
      if(infection < MAX_INFECTION)
        infection++;
    }

    inline void decInfection( void )
    {
      if(infection > 0)
        infection--;
    }

    inline void setInfection( int i )
    {
      if(i <= MAX_INFECTION && i > 0)
        infection = i;
    }

    inline int getInfection( void )
    {
      return infection;
    }
};

#endif // CUBE_H
