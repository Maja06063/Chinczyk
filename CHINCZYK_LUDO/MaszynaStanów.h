#pragma once

/// <summary>
/// Klasa numerowana MaszynaStan�w posiada stany, kt�re wyst�puj� naprzemiennie w p�tli gry.
/// </summary>
enum class MaszynaStanow
{
	oczekiwanieNaRzut,
	oczekiwanieNaWyborPionka,
	trwaRuch,
};