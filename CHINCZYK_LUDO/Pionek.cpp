#include "pch.h"
#include "Pionek.h"

/// <summary>
/// Operator porównania dwóch pionków.
/// </summary>
/// <param name="p">Pionek, z którym porównujemy obecny pionek</param>
/// <returns>true - pionki maj¹ ten sam nr i kolor, false - pionki maj¹ ró¿ny nr lub kolor.</returns>
bool Pionek::operator==(const Pionek p)
{
    return (this->graczId == p.graczId && this->nr == p.nr);
}