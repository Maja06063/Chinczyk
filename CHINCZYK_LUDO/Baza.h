#pragma once
#include "PoleSpecjalne.h"

/// <summary>
/// klasa Baza bêd¹ca szczególnym przypadkiem klasy Pole. W Bazie pionki czekaj¹ zanim wyjd¹ na planszê.
/// </summary>
class Baza :
    public PoleSpecjalne
{
public:

    Baza(int x, int y) { ustawWspolrzedne(x, y); }
};