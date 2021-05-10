#pragma once
#include "Gracz.h"

class Pionek
{
	KolorGracza graczId;
	int poleId;

public:

	Pionek(int poleId);

	int zwrocPoleId(void) { return poleId; }
	
};