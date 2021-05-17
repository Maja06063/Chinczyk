#include "pch.h"
#include "KontrolaWidoku.h"
#include <msclr\marshal_cppstd.h>
#include <string>

using namespace System::Runtime::InteropServices;

namespace CHINCZYKLUDO {

	/// <summary>
	/// 
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
	/// 
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
	/// 
	/// </summary>
	/// <returns></returns>
	bool KontrolaWidoku::PetlaGryOczekiwanieNaWyborPionka()
	{
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
	/// 
	/// </summary>
	/// <returns>true - Nale¿y powtórzyæ wybór pionka, false - ruch zakoñczony</returns>
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