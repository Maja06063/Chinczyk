#pragma once
#include "Gracz.h"

class Pionek
{
	KolorGracza graczId;

public:

	bool mozliwoscRuchu = false;

	Pionek(KolorGracza graczId) { this->graczId = graczId;	}

	inline const KolorGracza zwrocKolorGracza() { return graczId; }

	
};