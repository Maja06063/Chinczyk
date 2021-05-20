#include "pch.h"
#include "Kostka.h"

/// <summary>
/// Metoda statyczna rzut losuje wynik rzutu kostk¹.
/// </summary>
/// <returns>los - liczba od 1 do 6.</returns>
int Kostka::Rzut()
{
	int los=rand()%6+1;
	return  los;

}
