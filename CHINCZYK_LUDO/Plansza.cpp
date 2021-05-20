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
	UstawBazy();
	UstawDomki();
	UstawZwyklePola();
}

/****************************************************************************************/

/// <summary>
/// 
/// </summary>
void Plansza::UstawZwyklePola()
{
	int i = 0;
	
	// Ko這 czerwonego:
	for (; i < 5; i++)
	{
		Pole pole(6, 13 - i, i == 0 ? KolorGracza::czerwony : KolorGracza::brak);
		polaPlanszy.push_back(pole);
	}
	
	for (; i < 11; i++)
	{
		Pole pole(10 - i, 8);
		polaPlanszy.push_back(pole);
	}

	for (; i < 12; i++)
	{
		Pole pole(0, 7);
		polaPlanszy.push_back(pole);
	}

	// Ko這 niebieskiego:
	for (; i < 18; i++)
	{
		Pole pole(i - 12, 6, i == 13 ? KolorGracza::niebieski : KolorGracza::brak);
		polaPlanszy.push_back(pole);
	}
	
	for (; i < 24; i++)
	{
		Pole pole(6, 18 - (i + 6));
		polaPlanszy.push_back(pole);
	}

	for (; i < 25; i++)
	{
		Pole pole(7, 0);
		polaPlanszy.push_back(pole);
	}

	// Ko這 鄴速ego:
	for (; i < 31; i++)
	{
		Pole pole(8, i - 25, i == 26 ? KolorGracza::zolty : KolorGracza::brak);
		polaPlanszy.push_back(pole);
	}

	for (; i < 37; i++)
	{
		Pole pole(i - 22, 6);
		polaPlanszy.push_back(pole);
	}

	for (; i < 38; i++)
	{
		Pole pole(14, 7);
		polaPlanszy.push_back(pole);
	}

	// Ko這 zielonego:
	for (; i < 44; i++)
	{
		Pole pole(52 - i, 8, i == 39 ? KolorGracza::zielony : KolorGracza::brak);
		polaPlanszy.push_back(pole);
	}

	for (; i < 50; i++)
	{
		Pole pole(8, i - 34);
		polaPlanszy.push_back(pole);
	}

	for (; i < 52; i++)
	{
		Pole pole(57 - i, 14);
		polaPlanszy.push_back(pole);
	}
	
}

/****************************************************************************************/

/// <summary>
/// 
/// </summary>
void Plansza::UstawBazy()
{
	int offsetX = 0;
	int offsetY = 0;

	for (size_t i = 0; i < 4; i++)
	{
		if (i == 1) offsetX += 9;
		if (i == 2) offsetY -= 9;
		if (i == 3) offsetX -= 9;
		
		int nr = 1;
		for (int x : {1 + offsetX, 4 + offsetX})
		{
			for (int y : {10 + offsetY, 13 + offsetY})
			{
				Baza poleBazy(x, y);
				Pionek pionek(KolorGracza(i), nr);
				nr++;

				poleBazy.pionkiNaPolu.push_back(pionek);

				polaBazy.push_back(poleBazy);
			}
		}
	}
	
}

/****************************************************************************************/

/// <summary>
/// 
/// </summary>
void Plansza::UstawDomki()
{
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
int Plansza::RzutKostki()
{
	this->ostatniRzutKostki = Kostka::Rzut();
	return this->ostatniRzutKostki;
}

/****************************************************************************************/

/// <summary>
/// 
/// </summary>
/// <param name="kolor"></param>
/// <param name="">true - Ruch wykonany, false - ruch niewykonany.</param>
bool Plansza::ruchPionka()
{
	uint16_t nr = kliknietePionki;

	while (!(nr & 0xf))
	{
		nr = nr >> 4;
	}

	int nrPionka = 1;

	while (!(nr & 0x01))
	{
		nrPionka++;
		nr = nr >> 1;
	}

	
	Pionek pionekWykonujacyRuch(kolorAktywnegoGracza, nrPionka);
	bool czyWBazie = false;

	for (Baza& baza : polaBazy)
	{
		if (baza.pionkiNaPolu.empty()) continue;

		if (baza.pionkiNaPolu.at(0) == pionekWykonujacyRuch)
		{
			czyWBazie = true;
			baza.pionkiNaPolu.pop_back();
		}
	}

	if (czyWBazie)
	{
		if (ostatniRzutKostki != 1 && ostatniRzutKostki != 6) return false;

		for (Pole& pole : polaPlanszy)
		{
			if (pole.punktWejscia == kolorAktywnegoGracza)
			{
				pole.pionkiNaPolu.push_back(pionekWykonujacyRuch);
				break;
			}
		}
	}
	else {

		int i;
		for (i = 0; i < polaPlanszy.size(); i++)
		{
			if (polaPlanszy.at(i).pionkiNaPolu.empty()) continue;

			if (polaPlanszy.at(i).pionkiNaPolu.at(0) == pionekWykonujacyRuch)
			{
				polaPlanszy.at(i).pionkiNaPolu.pop_back();
				break;
			}
		}

		polaPlanszy.at((i + ostatniRzutKostki) % polaPlanszy.size()).pionkiNaPolu.push_back(pionekWykonujacyRuch);
	}


	return true;
}

/****************************************************************************************/

/// <summary>
/// 
/// </summary>
/// <returns></returns>
bool Plansza::CzyDobryPionekWybrano()
{
	switch (kolorAktywnegoGracza)
	{
	case KolorGracza::czerwony:

		return kliknietePionki & 0xf;

	case KolorGracza::zielony:

		return (kliknietePionki >> 4) & 0xf;

	case KolorGracza::zolty:

		return (kliknietePionki >> 8) & 0xf;

	case KolorGracza::niebieski:

		return (kliknietePionki >> 12) & 0xf;
	}

	return false;
}

/****************************************************************************************/

/// <summary>
/// 
/// </summary>
/// <param name="kolor"></param>
/// <param name="nr"></param>
/// <returns></returns>
Pole Plansza::znajdzPole(KolorGracza kolor, int nr)
{
	Pionek szukanyPionek(kolor, nr);

	for (Baza baza : polaBazy)
	{
		if (baza.pionkiNaPolu.empty()) continue;

		if (baza.pionkiNaPolu.at(0) == szukanyPionek)
		{
			return baza;
		}
	}

	for (Pole pole : polaPlanszy)
	{
		if (pole.pionkiNaPolu.empty()) continue;

		if (pole.pionkiNaPolu.at(0) == szukanyPionek)
		{
			return pole;
		}
	}


	return Pole(0, 0);
}

/****************************************************************************************/

bool Plansza::CzyMozliwyRuch()
{
	int pionkiWBazie = 0;

	if (ostatniRzutKostki == 1 || ostatniRzutKostki == 6) return true;

	for (Baza baza : polaBazy)
	{
		if (baza.pionkiNaPolu.empty()) continue;

		if (baza.pionkiNaPolu.at(0).zwrocKolorGracza() == kolorAktywnegoGracza)
		{
			pionkiWBazie++;
		}
	}

	return (pionkiWBazie != 4);
}