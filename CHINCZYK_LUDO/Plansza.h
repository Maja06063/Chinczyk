#pragma once
#include "Kostka.h"
#include "Gracz.h"
#include "Pole.h"
#include "Baza.h"
#include "Domek.h"
#include "MaszynaStan�w.h"

/// <summary>
/// Klasa Plansza zawiera wektory powi�zane z polami wyst�puj�cymi w grze oraz posiada metody zarz�dzaj�ce logik� gry.
/// </summary>
class Plansza
{
	Gracz gracze[4];
	
	std::vector<Baza> polaBazy;
	std::vector<std::vector<Domek>> polaDomkow;
	std::vector<Pole> polaPlanszy;

	void UstawGraczy();

	void UstawPola();
	void UstawZwyklePola();
	void UstawBazy();
	void UstawDomki();

public:

	uint16_t kliknietePionki = 0;
	int ostatniRzutKostki = 0;

	KolorGracza kolorAktywnegoGracza;
	MaszynaStanow stanPlanszy;

	Plansza();

	bool ruchPionka();
	bool CzyDobryPionekWybrano();
	bool CzyMozliwyRuch();

	Pole znajdzPole(KolorGracza kolor, int nr);
	Baza* znajdzWolnaBaze(KolorGracza kolor);

	int getIdPolaStartowego(KolorGracza kolor);

	std::vector<std::vector<Domek>>* getPolaDomkowPtr() { return &polaDomkow; }

	int RzutKostki();
};