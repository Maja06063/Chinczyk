#include "pch.h"
#include "Plansza.h"

/****************************************************************************************/

/// <summary>
/// 
/// </summary>
void Plansza::UstawGraczy()
{
	for (size_t i = 0; i < 4; i++)
	{
		this->gracze[i].ustawKolor((KolorGracza)i);
	}
}

/****************************************************************************************/

/// <summary>
/// 
/// </summary>
void Plansza::UstawPola()
{
	for (size_t i = 0; i < 92; i++)
	{
		Pole nowePole;

		if (i < 4) 
		{
			Pionek nowyPionek(KolorGracza::czerwony);
			nowePole.pionkiNaPolu.push_back(nowyPionek);
		}
		else if (i < 8)
		{
			Pionek nowyPionek(KolorGracza::zielony);
			nowePole.pionkiNaPolu.push_back(nowyPionek);
		}
		else if (i < 12)
		{
			Pionek nowyPionek(KolorGracza::zolty);
			nowePole.pionkiNaPolu.push_back(nowyPionek);
		}
		else if (i < 16)
		{
			Pionek nowyPionek(KolorGracza::niebieski);
			nowePole.pionkiNaPolu.push_back(nowyPionek);
		}


		polaPlanszy.push_back(nowePole);
	}
}

/****************************************************************************************/

/// <summary>
/// 
/// </summary>
Plansza::Plansza()
{
	UstawGraczy();
	UstawPola();

}

/****************************************************************************************/

/// <summary>
/// 
/// </summary>
/// <returns></returns>
int Plansza::RzutKostki()
{
	return Kostka::rzut();
}
