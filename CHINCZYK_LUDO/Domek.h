#pragma once
#include "PoleSpecjalne.h"

/// <summary>
/// Klasa Domek b�d�ca szczeg�lnym przypadkiem Pola - w domku pionki s� ju� niezbijalne i ko�cz� gr�.
/// </summary>
class Domek :
    public PoleSpecjalne
{
public:
    Domek(int x, int y) { ustawWspolrzedne(x, y); }
};

