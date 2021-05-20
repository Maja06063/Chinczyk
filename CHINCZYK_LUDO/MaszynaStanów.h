#pragma once

/// <summary>
/// Klasa numerowana MaszynaStanów posiada stany, które wystêpuj¹ naprzemiennie w pêtli gry.
/// </summary>
enum class MaszynaStanow
{
	oczekiwanieNaRzut,
	oczekiwanieNaWyborPionka,
	trwaRuch,
};