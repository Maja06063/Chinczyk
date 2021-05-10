#pragma once
#include <vector>
#include "Kostka.h"
#include "Gracz.h"


class Plansza
{
	Gracz gracze[4];

	void ustawGraczy();

public: 

	Plansza();

	int rzut_k();
};

