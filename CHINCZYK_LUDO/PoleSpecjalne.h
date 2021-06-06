#pragma once
#include "Pole.h"

/// <summary>
/// Klasa PoleSpecjalne dziedzicz�ca po klasie Pole - zawiera po��czenie mi�dzy polem zwyk�ym a baz� / domkiem.
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