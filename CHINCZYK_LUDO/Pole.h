#pragma once
#include "Pionek.h"
#include <vector>

/// <summary>
/// 
/// </summary>
class Pole
{
protected:

	bool mozliwoscBicia = true;
	int x;
	int y;
	
	void ustawWspolrzedne(int x, int y);

public:

	Pole() { ; }
	Pole(int x, int y) { ustawWspolrzedne(x, y); }
	Pole(int x, int y, KolorGracza punktWejscia) { ustawWspolrzedne(x, y); this->punktWejscia = punktWejscia; }

	std::vector<Pionek> pionkiNaPolu;

	KolorGracza punktWejscia = KolorGracza::brak;
	int pozX() { return x; }
	int pozY() { return y; }

	char* ToString();
};