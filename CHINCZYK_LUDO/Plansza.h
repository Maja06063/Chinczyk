#pragma once
#include "Kostka.h"
#include "Gracz.h"
#include "Pole.h"

class Plansza
{
	Gracz gracze[4];

	std::vector<Pole> polaPlanszy;

	void UstawGraczy();

	void UstawPola();

public: 

	Plansza();

	int RzutKostki();
};