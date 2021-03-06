#include "pch.h"
#include "Plansza.h"
#include <algorithm>

/// <summary>
/// Metoda ruchPionka przeprowadza ruch wybranego pionka.
/// Pionek rozkodowywany jest z atrybutu kliknietePionki,
/// kt?ry jest 16 bitow? bezznakow? zmienn?. 1 na danym bicie oznacza odpowiedni pionek.
/// Przyk?ady:
/// 0000-0000-0001-0000 - Wybrany pionek nr 1 o kolorze zielonym,
/// 0100-0000-0000-0000 - Wybrany pionek nr 3 o kolorze niebieskim,
/// 0000-0000-0000-1000 - Wybrany pionek nr 4 o kolorze czerwonym.
/// </summary>
/// <param name="">true - Ruch wykonany, false - ruch niewykonany.</param>
bool Plansza::ruchPionka(bool & powtornyRzut)
{
	//ostatniRzutKostki = 6;
	uint16_t nr = kliknietePionki;

	while (!(nr & 0xf)) // liczba & 0xf to po prostu wydzielenie 4 bit?w liczby.
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
	bool czyWDomku = false;

	/*-------------------------------------*/
	// Sprawdzanie czy pionek jest w bazie:
	for (Baza& baza : polaBazy)
	{
		if (baza.pionkiNaPolu.empty()) continue;

		if (std::find(baza.pionkiNaPolu.begin(), baza.pionkiNaPolu.end(), pionekWykonujacyRuch) != baza.pionkiNaPolu.end()) {

			if (ostatniRzutKostki != 1 && ostatniRzutKostki != 6) return false;

			czyWBazie = true;
			baza.pionkiNaPolu.erase(std::remove(baza.pionkiNaPolu.begin(), baza.pionkiNaPolu.end(), pionekWykonujacyRuch), baza.pionkiNaPolu.end());
			break;
		}
	}

	/*-------------------------------------*/
	// Sprawdzanie czy pionek jest w domkach:
	for (int i = 0; i < polaDomkow.size(); i++)
	{
		for (int j = 0; j < polaDomkow[i].size(); j++)
		{
			if (polaDomkow[i][j].pionkiNaPolu.empty()) continue;

			if (std::find(polaDomkow[i][j].pionkiNaPolu.begin(), polaDomkow[i][j].pionkiNaPolu.end(), pionekWykonujacyRuch) != polaDomkow[i][j].pionkiNaPolu.end())
			{
				czyWDomku = true;
				polaDomkow[i][j].pionkiNaPolu.erase(std::remove(polaDomkow[i][j].pionkiNaPolu.begin(), polaDomkow[i][j].pionkiNaPolu.end(), pionekWykonujacyRuch), polaDomkow[i][j].pionkiNaPolu.end());
				break;
			}
		}
	}

	/*-------------------------------------*/
	// Wtj?cie z bazy:
	if (czyWBazie)
	{
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

		/*-------------------------------------*/
		// Ruch po zwyk?ej cz??ci planszy:
		if (!czyWDomku) {
			int i;
			for (i = 0; i < polaPlanszy.size(); i++)
			{
				if (polaPlanszy.at(i).pionkiNaPolu.empty()) continue;

				if (std::find(polaPlanszy.at(i).pionkiNaPolu.begin(), polaPlanszy.at(i).pionkiNaPolu.end(), pionekWykonujacyRuch) != polaPlanszy.at(i).pionkiNaPolu.end())
				{
					polaPlanszy.at(i).pionkiNaPolu.erase(std::remove(polaPlanszy.at(i).pionkiNaPolu.begin(), polaPlanszy.at(i).pionkiNaPolu.end(), pionekWykonujacyRuch), polaPlanszy.at(i).pionkiNaPolu.end());
					break;
				}
			}

			int numer_pola = (i + ostatniRzutKostki) % polaPlanszy.size();

			// Zbijanie i wsp?lne przebywanie na danym polu:
			std::vector<Pionek>* pionki_na_tym_polu = &polaPlanszy.at(numer_pola).pionkiNaPolu;
			if (!pionki_na_tym_polu->empty() && numer_pola != 0 && numer_pola != 13 && numer_pola != 26 && numer_pola != 39)
			{
				for (int j = 0; j < pionki_na_tym_polu->size(); j++)
				{
					if (pionki_na_tym_polu->at(j).zwrocKolorGracza() != pionekWykonujacyRuch.zwrocKolorGracza())
					{
						powtornyRzut = true;
						Baza* wolna_baza = znajdzWolnaBaze(pionki_na_tym_polu->at(j).zwrocKolorGracza());
						wolna_baza->pionkiNaPolu.push_back(pionki_na_tym_polu->at(j));
						pionki_na_tym_polu->erase(pionki_na_tym_polu->begin() + j);
					}
				}
			}

			int numer_pola2 = i + ostatniRzutKostki;
			int pole_startowe = getIdPolaStartowego(pionekWykonujacyRuch.zwrocKolorGracza());

			if (i <= pole_startowe - 2 && numer_pola2 > pole_startowe - 2)
			{
				int ile_krokow_w_domku = pole_startowe - i - 3;

				int numer_gracza = (int)pionekWykonujacyRuch.zwrocKolorGracza();

				polaDomkow[numer_gracza][ile_krokow_w_domku].pionkiNaPolu.push_back(pionekWykonujacyRuch);
				size_t dlugosc = polaDomkow[numer_gracza][ile_krokow_w_domku].pionkiNaPolu.size();
				cout << "pole na ktore wstawiamy: " << polaDomkow[numer_gracza][ile_krokow_w_domku].pozX() << ":" << polaDomkow[numer_gracza][ile_krokow_w_domku].pozY() << std::endl;
				return true;
			}

			polaPlanszy.at(numer_pola).pionkiNaPolu.push_back(pionekWykonujacyRuch);
			std::cout << "Ruch pionka na numer pola: " << numer_pola << std::endl;
		}

		/*-------------------------------------*/
		// Ruch po domkach ko?cowych:
		else {

			int numer_gracza = (int)pionekWykonujacyRuch.zwrocKolorGracza();

			std::vector<Domek>& polaDomkowGracza = polaDomkow.at(numer_gracza);
			int i = 0;
			for (; i < polaDomkowGracza.size() - 1; i++)
			{

				if (polaDomkowGracza.at(i).pionkiNaPolu.empty()) continue;

				auto iter = std::find(polaDomkowGracza.at(i).pionkiNaPolu.begin(), polaDomkowGracza.at(i).pionkiNaPolu.end(), pionekWykonujacyRuch);
				polaDomkowGracza.at(i).pionkiNaPolu.erase(iter);

				int nrNowegoPola = i + ostatniRzutKostki;
				if (nrNowegoPola > 5) nrNowegoPola = 5;

				polaDomkowGracza.at(nrNowegoPola).pionkiNaPolu.push_back(pionekWykonujacyRuch);
				break;
			}
		}

	}

	return true;
}
