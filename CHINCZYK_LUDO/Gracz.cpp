#include "pch.h"
#include "Gracz.h"

/// <summary>
/// Ustawianie konkretnego pola na planszy, które s³u¿y jako pole specjalne dla ka¿dego pionka. Ró¿ne kolory pionków maj¹ ró¿ne pola startowe.
/// </summary>

void Gracz::ustawIdPolaStartowego() {
	if (this->graczId == KolorGracza::czerwony) this->idPolaStartowego = 0;
	else if (this->graczId == KolorGracza::zielony) this->idPolaStartowego = 39;
	else if (this->graczId == KolorGracza::zolty) this->idPolaStartowego = 26;
	else if (this->graczId == KolorGracza::niebieski) this->idPolaStartowego = 13;
}
