#include "pch.h"
#include "Pole.h"

void Pole::ustawWspolrzedne(int x, int y)
{
	this->x = x;
	this->y = y;
}

char* Pole::ToString()
{
	char dane[100];

	sprintf_s(dane, "\nJestem polem %dx%d, pionek nr %d\n",
		x, y, pionkiNaPolu.at(0).zwrocNr());

	return dane;
}
