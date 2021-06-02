#pragma once

/// <summary>
/// Klasa numerowana KolorGracza zawieraj�ca dost�pne kolory.
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
/// Klasa gracz zawieraj�ca atrybuty oraz metody s�u��ce do obs�ugi gracza w grze.
/// </summary>
class Gracz
{
	KolorGracza graczId = KolorGracza::brak;

	int idPolaStartowego;

public:

	void ustawKolor(KolorGracza nowyKolor) { if (graczId != KolorGracza::brak) graczId = nowyKolor; }

	inline KolorGracza zwrocKolor() { return graczId; }

	void ustawIdPolaStartowego();

};