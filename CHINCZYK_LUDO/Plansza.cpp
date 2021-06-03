#include "pch.h"
#include "Plansza.h"
#include <algorithm>

/****************************************************************************************/

/// <summary>
/// Metoda UstawGraczy s³u¿y do ustawienia kolorów wszystkim czterem graczom w grze.
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
/// Metoda UstawPola wywo³uje pokolej seriê metod ustawiaj¹cych informacje o polach planszy.
/// </summary>
void Plansza::UstawPola()
{
	UstawBazy();
	UstawDomki();
	UstawZwyklePola();
	
	int dlugosc1 = polaDomkow.size();
	int dlugosc2 = polaDomkow[0].size();
	for (int i = 0; i < dlugosc1; i++) {
		for (int j = 0; j < dlugosc2; j++) {
			cout << polaDomkow[i][j].pozX() << ":" << polaDomkow[i][j].pozY() << std::endl;
		}

	}
}

/****************************************************************************************/

/// <summary>
/// Metoda ustawia wspó³rzêdne i inne w³aœciwoœci pól planszy.
/// </summary>
void Plansza::UstawZwyklePola()
{
	int i = 0;
	
	// Ko³o czerwonego:
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

	// Ko³o niebieskiego:
	for (; i < 18; i++)
	{
		Pole pole(i - 12, 6, i == 13 ? KolorGracza::niebieski : KolorGracza::brak);
		polaPlanszy.push_back(pole);
	}
	
	for (; i < 24; i++)
	{
		Pole pole(6, 23 - i);			//mo¿liwy b³¹d-naprawione
		polaPlanszy.push_back(pole);	//18 - (i + 6) + 11
	}

	for (; i < 25; i++)
	{
		Pole pole(7, 0);
		polaPlanszy.push_back(pole);
	}

	// Ko³o ¿ó³tego:
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

	// Ko³o zielonego:
	for (; i < 44; i++)
	{
		Pole pole(52 - i, 8, i == 39 ? KolorGracza::zielony : KolorGracza::brak);
		polaPlanszy.push_back(pole);
	}

	for (; i < 50; i++)
	{
		Pole pole(8, i - 35);	
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
/// Metoda ustawia wspó³rzêdne i inne w³aœciwoœci pól planszy bêd¹cych bazami.
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
/// Metoda ustawia wspó³rzêdne i inne w³aœciwoœci pól planszy bêd¹cych domkami.
/// </summary>
void Plansza::UstawDomki()
{
	std::vector<Domek> w1;
	std::vector<Domek> w2;
	std::vector<Domek> w3;
	std::vector<Domek> w4;
	polaDomkow.push_back(w1);
	polaDomkow.push_back(w2);
	polaDomkow.push_back(w3);
	polaDomkow.push_back(w4);
	int offsetX;
	int offsetY;
	for (int i = 0; i < 4; i++) {

		//offset do czerwonych domkow
		if (i == 0) {
			offsetX = 7;
			offsetY = 8;
		}

		//offset do zielonych domkow
		if (i == 1) {
			offsetX = 8;
			offsetY = 7;
		}

		//offset do zoltych domkow
		if (i == 2) {
			offsetX = 7;
			offsetY = 1;
		}

		//offset do niebieskich domkow
		if (i == 3) {
			offsetX = 1;
			offsetY = 7;
		}

		for (int j = 0; j < 6; j++) {

			if (i == 0) polaDomkow[i].push_back(Domek(offsetX, offsetY++));
			if (i == 1) polaDomkow[i].push_back(Domek(offsetX++, offsetY));
			if (i == 2) polaDomkow[i].push_back(Domek(offsetX, offsetY++));
			if (i == 3) polaDomkow[i].push_back(Domek(offsetX++, offsetY));
			
		}
	}
}

/****************************************************************************************/

/// <summary>
/// Konstruktor klasy plansza. Ustawia graczy, pola i zmienia stan planszy na oczekuj¹cy na rzut kostk¹
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
/// Metoda RzutKostki aktualizuje stan zmiennnej ostatni rzut kostki oraz zwraca iloœæ wyrzuconych oczek.
/// </summary>
int Plansza::RzutKostki()
{
	this->ostatniRzutKostki = Kostka::Rzut();
	return this->ostatniRzutKostki;
}

/****************************************************************************************/

/// <summary>
/// Metoda ruchPionka przeprowadza ruch wybranego pionka.
/// Pionek rozkodowywany jest z atrybutu kliknietePionki,
/// który jest 16 bitow¹ bezznakow¹ zmienn¹. 1 na danym bicie oznacza odpowiedni pionek.
/// Przyk³ady:
/// 0000-0000-0001-0000 - Wybrany pionek nr 1 o kolorze zielonym,
/// 0100-0000-0000-0000 - Wybrany pionek nr 3 o kolorze niebieskim,
/// 0000-0000-0000-1000 - Wybrany pionek nr 4 o kolorze czerwonym.
/// </summary>
/// <param name="">true - Ruch wykonany, false - ruch niewykonany.</param>
bool Plansza::ruchPionka()
{	
	//ostatniRzutKostki = 6;
	uint16_t nr = kliknietePionki;

	while (!(nr & 0xf)) // liczba & 0xf to po prostu wydzielenie 4 bitów liczby.
	{
		nr = nr >> 4;
	}

	int nrPionka = 1;

	while (!(nr & 0x01))
	{
		nrPionka++;
		nr = nr >> 1;
	}

	
	Pionek pionekWykonujacyRuch(kolorAktywnegoGracza, nrPionka); //[THINK] takie rzeczy generalnie powinny byæ pointerami, a nie tworzeniem nowych obiektów
	bool czyWBazie = false;
	bool czyWDomku = false;


	for (Baza& baza : polaBazy)
	{
		if (baza.pionkiNaPolu.empty()) continue;

		if (std::find(baza.pionkiNaPolu.begin(), baza.pionkiNaPolu.end(), pionekWykonujacyRuch) != baza.pionkiNaPolu.end()){
			czyWBazie = true;
			baza.pionkiNaPolu.erase(std::remove(baza.pionkiNaPolu.begin(), baza.pionkiNaPolu.end(), pionekWykonujacyRuch), baza.pionkiNaPolu.end());
		}
	}


	for (int i = 0; i < polaDomkow.size(); i++) {
		for (int j = 0; j < polaDomkow[i].size(); j++) {
			if (polaDomkow[i][j].pionkiNaPolu.empty()) continue;

			if (std::find(polaDomkow[i][j].pionkiNaPolu.begin(), polaDomkow[i][j].pionkiNaPolu.end(), pionekWykonujacyRuch) != polaDomkow[i][j].pionkiNaPolu.end()) {
				czyWDomku = true;
				polaDomkow[i][j].pionkiNaPolu.erase(std::remove(polaDomkow[i][j].pionkiNaPolu.begin(), polaDomkow[i][j].pionkiNaPolu.end(), pionekWykonujacyRuch), polaDomkow[i][j].pionkiNaPolu.end());
			}
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

			std::vector<Pionek>* pionki_na_tym_polu = &polaPlanszy.at(numer_pola).pionkiNaPolu;
			if (!pionki_na_tym_polu->empty() && numer_pola != 0 && numer_pola != 13 && numer_pola  != 26 && numer_pola != 39) {
				for (int j = 0; j < pionki_na_tym_polu->size(); i++) {
					if (pionki_na_tym_polu->at(j).zwrocKolorGracza() != pionekWykonujacyRuch.zwrocKolorGracza()) {
						Baza* wolna_baza = znajdzWolnaBaze(pionki_na_tym_polu->at(j).zwrocKolorGracza());
						wolna_baza->pionkiNaPolu.push_back(pionki_na_tym_polu->at(j));
						pionki_na_tym_polu->erase(pionki_na_tym_polu->begin() + j);
					}
				}
			}

			int numer_pola2 = i + ostatniRzutKostki;
			int pole_startowe = getIdPolaStartowego(pionekWykonujacyRuch.zwrocKolorGracza());
			if (i <= pole_startowe - 2 && numer_pola2 > pole_startowe - 2) {
				int ile_krokow_w_domku = pole_startowe - i - 2;
				
				int numer_gracza = 0;
				if (pionekWykonujacyRuch.zwrocKolorGracza() == KolorGracza::zielony) numer_gracza = 1;
				if (pionekWykonujacyRuch.zwrocKolorGracza() == KolorGracza::zolty) numer_gracza = 2;
				if (pionekWykonujacyRuch.zwrocKolorGracza() == KolorGracza::niebieski) numer_gracza = 3;

				polaDomkow[numer_gracza][ile_krokow_w_domku].pionkiNaPolu.push_back(pionekWykonujacyRuch);
				int dlugosc = polaDomkow[numer_gracza][ile_krokow_w_domku].pionkiNaPolu.size();
				cout << "pole na ktore wstawiamy: " << polaDomkow[numer_gracza][ile_krokow_w_domku].pozX() << ":" << polaDomkow[numer_gracza][ile_krokow_w_domku].pozY() << std::endl;
				return true;
			}


			polaPlanszy.at(numer_pola).pionkiNaPolu.push_back(pionekWykonujacyRuch);//[ADDED]
			std::cout << "Ruch pionka na numer pola: " << numer_pola << std::endl;
		}

		else {

			int numer_gracza = 0;
			if (pionekWykonujacyRuch.zwrocKolorGracza() == KolorGracza::zielony) numer_gracza = 1;
			if (pionekWykonujacyRuch.zwrocKolorGracza() == KolorGracza::zolty) numer_gracza = 2;
			if (pionekWykonujacyRuch.zwrocKolorGracza() == KolorGracza::niebieski) numer_gracza = 3;

			int i = 0;
			for (; i < polaDomkow[numer_gracza].size(); i++)
			{
				cout << "Czy pole w domku jest puste" << (polaDomkow[numer_gracza][i].pionkiNaPolu.empty()) << std::endl;
				if (polaDomkow[numer_gracza][i].pionkiNaPolu.empty()) continue; //naprawic

				/*for (int j = 0; j < polaDomkow[numer_gracza].size(); j++) {
					cout << "Ilosc pionkow na polu: " << polaDomkow[numer_gracza][j].pionkiNaPolu.size();
					if (polaDomkow[numer_gracza][j].pionkiNaPolu.size() == 0) continue;
				}*/

				if (std::find(polaDomkow[numer_gracza][i].pionkiNaPolu.begin(), polaDomkow[numer_gracza][i].pionkiNaPolu.end(), pionekWykonujacyRuch) != polaDomkow[numer_gracza][i].pionkiNaPolu.end())
				{
					polaDomkow[numer_gracza][i].pionkiNaPolu.erase(std::remove(polaDomkow[numer_gracza][i].pionkiNaPolu.begin(), polaDomkow[numer_gracza][i].pionkiNaPolu.end(), pionekWykonujacyRuch), polaDomkow[numer_gracza][i].pionkiNaPolu.end());
					break;
				}
			}

			if (i == 5) return true;

			int numer_pola = (i + ostatniRzutKostki);
			polaDomkow[numer_gracza][numer_pola].pionkiNaPolu.push_back(pionekWykonujacyRuch);

		}

	}

	return true;
}

/****************************************************************************************/

/// <summary>
/// Metoda CzyDobryPionekWybrano zwraca informacje o tym, czy kliknieto na pionek dobrego koloru.
/// </summary>
/// <returns>true - wybrano pionek dobrego koloru, false - pionek z³ego koloru</returns>
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
/// Metoda s³u¿¹ca do znalezienia, na którym polu znajduje siê pionek.
/// </summary>
/// <param name="kolor">kolor pionka</param>
/// <param name="nr">nr pionka</param>
/// <returns>Metoda zwraca znalezione pole</returns>
Pole Plansza::znajdzPole(KolorGracza kolor, int nr)
{
	Pionek szukanyPionek(kolor, nr);

	for (int i = 0; i < polaDomkow.size(); i++) {
		for (int j = 0; j < polaDomkow[i].size(); j++) {
			if (polaDomkow[i][j].pionkiNaPolu.empty()) continue;

			if (std::find(polaDomkow[i][j].pionkiNaPolu.begin(), polaDomkow[i][j].pionkiNaPolu.end(), szukanyPionek) != polaDomkow[i][j].pionkiNaPolu.end()) {
				return polaDomkow[i][j];
			}
		}
	}

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

		//if (pole.pionkiNaPolu.at(0) == szukanyPionek) //[BUG] tutaj jest coœ dziwnego - jeœli pionek wchodzi na pole jako drugi to wrzuca go na pole(0,0)
		//{
		//	return pole;
		//}

		if (std::find(pole.pionkiNaPolu.begin(), pole.pionkiNaPolu.end(), szukanyPionek) != pole.pionkiNaPolu.end()) { //[ADDED] to bêdzie zwracaæ true jeœli pionek wejdzie w dowolnej kolejnosci
			return pole;
		}
	}


	return Pole(0, 0);
}

/****************************************************************************************/

/// <summary>
/// Metoda CzyMozliwyRuch sprawdza, czy jest mo¿liwy ruch jakikolwiek pionkiem danego gracza.
/// </summary>
/// <returns>true - ruch mo¿liwy, false - ruch niemo¿liwy</returns>
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

Baza* Plansza::znajdzWolnaBaze(KolorGracza kolor) {//[ADDED]
	int i = 0;
	for (;i < polaBazy.size(); i++) {
		if (kolor == KolorGracza::czerwony) {
			if (polaBazy[i].pozX() == 1 && polaBazy[i].pozY() == 10) {
				if (polaBazy[i].pionkiNaPolu.empty()) break;
			}
			else if (polaBazy[i].pozX() == 1 && polaBazy[i].pozY() == 13) {
				if (polaBazy[i].pionkiNaPolu.empty()) break;
			}
			else if (polaBazy[i].pozX() == 4 && polaBazy[i].pozY() == 10) {
				if (polaBazy[i].pionkiNaPolu.empty()) break;
			}
			else if (polaBazy[i].pozX() == 4 && polaBazy[i].pozY() == 13) {
				if (polaBazy[i].pionkiNaPolu.empty()) break;
			}
		}
		//sprawdzanie baz zielonego
		if (kolor == KolorGracza::zielony) {
			if (polaBazy[i].pozX() == 10 && polaBazy[i].pozY() == 10) {
				if (polaBazy[i].pionkiNaPolu.empty()) break;
			}
			else if (polaBazy[i].pozX() == 13 && polaBazy[i].pozY() == 13) {
				if (polaBazy[i].pionkiNaPolu.empty()) break;
			}
			else if (polaBazy[i].pozX() == 10 && polaBazy[i].pozY() == 10) {
				if (polaBazy[i].pionkiNaPolu.empty()) break;
			}
			else if (polaBazy[i].pozX() == 13 && polaBazy[i].pozY() == 13) {
				if (polaBazy[i].pionkiNaPolu.empty()) break;
			}
		}

		//sprawdzanie baz zoltego
		if (kolor == KolorGracza::zolty) {
			if (polaBazy[i].pozX() == 10 && polaBazy[i].pozY() == 1) {
				if (polaBazy[i].pionkiNaPolu.empty()) break;
			}
			else if (polaBazy[i].pozX() == 13 && polaBazy[i].pozY() == 4) {
				if (polaBazy[i].pionkiNaPolu.empty()) break;
			}
			else if (polaBazy[i].pozX() == 10 && polaBazy[i].pozY() == 1) {
				if (polaBazy[i].pionkiNaPolu.empty()) break;
			}
			else if (polaBazy[i].pozX() == 13 && polaBazy[i].pozY() == 4) {
				if (polaBazy[i].pionkiNaPolu.empty()) break;
			}
		}

		//sprawdzanie baz niebieskiego
		if (kolor == KolorGracza::niebieski) {
			if (polaBazy[i].pozX() == 1 && polaBazy[i].pozY() == 1) {
				if (polaBazy[i].pionkiNaPolu.empty()) break;
			}
			else if (polaBazy[i].pozX() == 4 && polaBazy[i].pozY() == 4) {
				if (polaBazy[i].pionkiNaPolu.empty()) break;
			}
			else if (polaBazy[i].pozX() == 1 && polaBazy[i].pozY() == 1) {
				if (polaBazy[i].pionkiNaPolu.empty()) break;
			}
			else if (polaBazy[i].pozX() == 4 && polaBazy[i].pozY() == 4) {
				if (polaBazy[i].pionkiNaPolu.empty()) break;
			}
		}
	}

	if (i == 16) i = 15;
	return &polaBazy[i];
}

int Plansza::getIdPolaStartowego(KolorGracza kolor) {
	if (kolor == KolorGracza::czerwony) return 52;
	if (kolor == KolorGracza::zielony) return 39;
	if (kolor == KolorGracza::zolty) return 26;
	if (kolor == KolorGracza::niebieski) return 13;
}