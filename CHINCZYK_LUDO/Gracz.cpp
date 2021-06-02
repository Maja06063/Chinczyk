#include "pch.h"
#include "Gracz.h"

void Gracz::ustawIdPolaStartowego() {
	if (this->graczId == KolorGracza::czerwony) this->idPolaStartowego = 0;
	if (this->graczId == KolorGracza::zielony) this->idPolaStartowego = 39;
	if (this->graczId == KolorGracza::zolty) this->idPolaStartowego = 26;
	if (this->graczId == KolorGracza::niebieski) this->idPolaStartowego = 13;
}
