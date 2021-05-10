#pragma once

enum class KolorGracza {
	
	czerwony = 0,
	zielony,
	zolty,
	niebieski,
	brak
};


class Gracz
{
	KolorGracza graczId = KolorGracza::brak;

public:

	void ustawKolor(KolorGracza nowyKolor) { if (graczId != KolorGracza::brak) graczId = nowyKolor; }

	inline KolorGracza zwrocKolor() { return graczId; }

};