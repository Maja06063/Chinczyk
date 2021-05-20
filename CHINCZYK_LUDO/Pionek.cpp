#include "pch.h"
#include "Pionek.h"

/// <summary>
/// Operator por�wnania dw�ch pionk�w.
/// </summary>
/// <param name="p">Pionek, z kt�rym por�wnujemy obecny pionek</param>
/// <returns>true - pionki maj� ten sam nr i kolor, false - pionki maj� r�ny nr lub kolor.</returns>
bool Pionek::operator==(const Pionek p)
{
    return (this->graczId == p.graczId && this->nr == p.nr);
}