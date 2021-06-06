#include "pch.h"
#include "Pole.h"

/// <summary>
/// Metoda UstawWspolrzedne przypisuje danemu polu wspó³rzêdne po³o¿enia podane w parametrach.
/// </summary>
/// <param name="x">wspó³rzêdna pozioma</param>
/// <param name="y">wspó³rzêdna pionowa</param>
void Pole::ustawWspolrzedne(int x, int y)
{
	this->x = x;
	this->y = y;
}

/****************************************************************************************/

/// <summary>
/// Metoda ToString s³u¿y do zwracania tekstowych informacji o danym polu.
/// Powsta³a w celach debugowych.
/// </summary>
/// <returns>dane - tablica charów z tekstem zawieraj¹cym wspó³rzêdne po³o¿enia pola oraz nr pionka na tym polu</returns>
string Pole::ToString()
{
	string dane;

	dane += "\nJestem polem ";
	dane += std::to_string(x);
	dane += std::to_string(y);
	dane += std::to_string(pionkiNaPolu.at(0).zwrocNr());
	

	return dane;
}

bool Pole::operator==(const Pole p)
{
	return (this->x == p.x && this->y == p.y); //[ADDED]
}

