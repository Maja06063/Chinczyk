#pragma once
#include "Gracz.h"

/// <summary>
/// Klasa Pionek zawieraj¹ca potrzebne metody oraz atrybuty u³atwiaj¹ce zarz¹dzanie pionkiem w grze.
/// </summary>
class Pionek
{
	KolorGracza graczId;
	int nr;


public:

	bool mozliwoscRuchu = false;
	int przebytePola = 0;

	Pionek(KolorGracza graczId, int nr) { this->graczId = graczId; this->nr = nr; }

	inline const KolorGracza zwrocKolorGracza() { return graczId; }
	inline const int zwrocNr() { return nr; }

	bool operator ==(const Pionek p);
};