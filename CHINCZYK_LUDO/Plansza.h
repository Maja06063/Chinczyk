#pragma once
#include "Kostka.h"
#include "Gracz.h"
#include "Pole.h"
#include "MaszynaStanów.h"

/// <summary>
/// 
/// </summary>
class Plansza
{
	Gracz gracze[4];
	
	std::vector<Pole> polaPlanszy;

	void UstawGraczy();

	void UstawPola();

public: 

	KolorGracza kolorAktywnegoGracza;
	MaszynaStanow stanPlanszy;

	Plansza();

	bool ruchPionka(KolorGracza kolor, int nr);

	int RzutKostki();
};