#pragma once

/// <summary>
/// 
/// </summary>
enum class KolorGracza
{	
	czerwony = 0,
	zielony,
	zolty,
	niebieski,
	brak
};


/****************************************************************************************/

/// <summary>
/// 
/// </summary>
class Gracz
{
	KolorGracza graczId = KolorGracza::brak;

public:

	void ustawKolor(KolorGracza nowyKolor) { if (graczId != KolorGracza::brak) graczId = nowyKolor; }

	inline KolorGracza zwrocKolor() { return graczId; }

};