#include "pch.h"
#include "Pionek.h"

/// <summary>
/// 
/// </summary>
/// <param name="p"></param>
/// <returns></returns>
bool Pionek::operator==(const Pionek p)
{
    return (this->graczId == p.graczId && this->nr == p.nr);
}