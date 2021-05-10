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
			Pionek nowyPionek(KolorGracza::czerwony, (i%4)+1 );
			nowePole.pionkiNaPolu.push_back(nowyPionek);
		}
		else if (i < 8)
		{
			Pionek nowyPionek(KolorGracza::zielony, (i % 4) + 1);
			nowePole.pionkiNaPolu.push_back(nowyPionek);
		}
		else if (i < 12)
		{
			Pionek nowyPionek(KolorGracza::zolty, (i % 4) + 1);
			nowePole.pionkiNaPolu.push_back(nowyPionek);
		}
		else if (i < 16)
		{
			Pionek nowyPionek(KolorGracza::niebieski, (i % 4) + 1);
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

	stanPlanszy = MaszynaStanow::oczekiwanieNaRzut;
	kolorAktywnegoGracza = KolorGracza::czerwony;
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

/****************************************************************************************/

/// <summary>
/// 
/// </summary>
/// <param name="kolor"></param>
/// <param name=""></param>
bool Plansza::ruchPionka(KolorGracza kolor, int nr)
{
	if (stanPlanszy == MaszynaStanow::oczekiwanieNaWyborPionka && kolorAktywnegoGracza == kolor) {

		kolorAktywnegoGracza = (KolorGracza)(((int)kolorAktywnegoGracza + 1)%4);
		stanPlanszy = MaszynaStanow::oczekiwanieNaRzut;
		return true;
	}

	return false;
}
