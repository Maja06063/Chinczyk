#pragma once
#include "Pole.h"

/// <summary>
/// Klasa PoleSpecjalne dziedzicz¹ca po klasie Pole - zawiera po³¹czenie miêdzy polem zwyk³ym a baz¹ / domkiem.
/// </summary>
class PoleSpecjalne :
    public Pole
{
protected:
    bool mozliwoscBicia = false;
public:
    
    PoleSpecjalne() { ; }
    PoleSpecjalne(int x, int y) { ustawWspolrzedne(x, y); }

};