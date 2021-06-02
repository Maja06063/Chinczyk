#include "pch.h"
#include "KontrolaWidoku.h"
#include <msclr\marshal_cppstd.h>
#include <string>

using namespace System::Runtime::InteropServices;

namespace CHINCZYKLUDO {

	/// <summary>
	/// G��wna p�tla gry dzia�aj�ca na osobnym w�tku - wykonuje si� r�wnolegle z obs�ug� planszy.
	/// </summary>
	void KontrolaWidoku::PetlaGry()
	{
		while (1) {

			PetlaGryOczekiwanieNaRzut();

			while(1)
			{
				if (!PetlaGryOczekiwanieNaWyborPionka()) break;
				if (!PetlaGryTrwaRuch()) break;
			}

		}
	}

	/****************************************************************************************/

	/// <summary>
	/// Fragment p�tli gry wyst�puj�cy podczas oczekiwania na rzut kostk� przez odpowiedniego gracza.
	/// </summary>
	void KontrolaWidoku::PetlaGryOczekiwanieNaRzut()
	{
		cout << "Teraz gracz "
			<< msclr::interop::marshal_as<std::string>(KolorNaString(plansza->kolorAktywnegoGracza))
			<< " niech rzuci kostka!\n";

		plansza->stanPlanszy = MaszynaStanow::oczekiwanieNaRzut;
		Invoke(gcnew System::Action(this, &KontrolaWidoku::AktualizujIkonyPionkow));

		while (plansza->stanPlanszy == MaszynaStanow::oczekiwanieNaRzut);
	}

	/****************************************************************************************/

	/// <summary>
	/// Fragment p�tli gry wyst�puj�cy podczas oczekiwania na wybrania pionka wykonuj�cego ruch przez gracza.
	/// </summary>
	/// <returns>true - pionek wybrany prawid�owo, false - Brak mo�liwo�ci ruchu - nie ma sensu czeka� na wyb�r pionka</returns>
	bool KontrolaWidoku::PetlaGryOczekiwanieNaWyborPionka()
	{
		plansza->stanPlanszy = MaszynaStanow::oczekiwanieNaWyborPionka;

		if (!plansza->CzyMozliwyRuch())
		{
			cout << "Brak mozliwosci ruchu\n";
			plansza->kolorAktywnegoGracza = (KolorGracza)(((int)plansza->kolorAktywnegoGracza + 1) % 4);
			return false;
		}
		
		plansza->kliknietePionki = 0;
		cout << "Oczekiwanie na wybor pionka\n\n";
		while (plansza->kliknietePionki == 0);

		return true;
	}

	/****************************************************************************************/

	/// <summary>
	/// Fragment p�tli gry wyst�puj�cy podczas trwania ruchu pionka.
	/// </summary>
	/// <returns>true - Nale�y powt�rzy� wyb�r pionka, false - ruch zako�czony</returns>
	bool KontrolaWidoku::PetlaGryTrwaRuch()
	{
		bool powtornyRzutKostka = false;

		plansza->stanPlanszy = MaszynaStanow::trwaRuch;
		if (!plansza->CzyDobryPionekWybrano()) return true;
		if (!plansza->ruchPionka()) return true;

		if (!powtornyRzutKostka) plansza->kolorAktywnegoGracza = (KolorGracza)(((int)plansza->kolorAktywnegoGracza + 1) % 4);
		return false;
	}
}