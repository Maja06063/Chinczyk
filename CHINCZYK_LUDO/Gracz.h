#pragma once

/// <summary>
/// Klasa numerowana KolorGracza zawieraj¹ca dostêpne kolory.
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
/// Klasa gracz zawieraj¹ca atrybuty oraz metody s³u¿¹ce do obs³ugi gracza w grze.
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