#pragma once
#include "Kostka.h"
#include "Gracz.h"
#include "Pole.h"
#include "Baza.h"
#include "Domek.h"
#include "MaszynaStanów.h"

/// <summary>
/// 
/// </summary>
class Plansza
{
	Gracz gracze[4];
	
	std::vector<Baza> polaBazy;
	std::vector<Domek> polaDomkow;
	std::vector<Pole> polaPlanszy;

	void UstawGraczy();

	void UstawPola();
	void UstawZwyklePola();
	void UstawBazy();
	void UstawDomki();

public: 

	KolorGracza kolorAktywnegoGracza;
	MaszynaStanow stanPlanszy;

	Plansza();

	bool ruchPionka(KolorGracza kolor, int nr);

	Pole znajdzPole(KolorGracza kolor, int nr);

	int RzutKostki();
};