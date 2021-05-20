#include "pch.h"
#include "Pole.h"

/// <summary>
/// Metoda UstawWspolrzedne przypisuje danemu polu wsp�rz�dne po�o�enia podane w parametrach.
/// </summary>
/// <param name="x">wsp�rz�dna pozioma</param>
/// <param name="y">wsp�rz�dna pionowa</param>
void Pole::ustawWspolrzedne(int x, int y)
{
	this->x = x;
	this->y = y;
}

/****************************************************************************************/

/// <summary>
/// Metoda ToString s�u�y do zwracania tekstowych informacji o danym polu.
/// Powsta�a w celach debugowych.
/// </summary>
/// <returns>dane - tablica char�w z tekstem zawieraj�cym wsp�rz�dne po�o�enia pola oraz nr pionka na tym polu</returns>
char* Pole::ToString()
{
	char dane[100];

	sprintf_s(dane, "\nJestem polem %dx%d, pionek nr %d\n",
		x, y, pionkiNaPolu.at(0).zwrocNr());

	return dane;
}
