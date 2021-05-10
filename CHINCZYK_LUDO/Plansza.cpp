#include "pch.h"
#include "Plansza.h"

void Plansza::ustawGraczy()
{
	for (size_t i = 0; i < 4; i++)
	{
		this->gracze[i].ustawKolor((KolorGracza)i);
	}
}

Plansza::Plansza()
{
	ustawGraczy();

	
}

int Plansza::rzut_k()
{
	return Kostka::rzut();
}
