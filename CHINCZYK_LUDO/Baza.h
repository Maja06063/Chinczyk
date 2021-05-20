#pragma once
#include "PoleSpecjalne.h"

/// <summary>
/// klasa Baza b�d�ca szczeg�lnym przypadkiem klasy Pole. W Bazie pionki czekaj� zanim wyjd� na plansz�.
/// </summary>
class Baza :
    public PoleSpecjalne
{
public:

    Baza(int x, int y) { ustawWspolrzedne(x, y); }
};