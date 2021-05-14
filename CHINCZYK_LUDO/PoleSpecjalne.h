#pragma once
#include "Pole.h"

class PoleSpecjalne :
    public Pole
{
protected:

public:
    
    PoleSpecjalne() { ; }
    PoleSpecjalne(int x, int y) { ustawWspolrzedne(x, y); }

};