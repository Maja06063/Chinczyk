#pragma once
#include "Gracz.h"

/// <summary>
/// 
/// </summary>
class Pionek
{
	KolorGracza graczId;
	int nr;

public:

	bool mozliwoscRuchu = false;

	Pionek(KolorGracza graczId, int nr) { this->graczId = graczId; this->nr = nr; }

	inline const KolorGracza zwrocKolorGracza() { return graczId; }
	inline const int zwrocNr() { return nr; }

	bool operator ==(const Pionek p);
};