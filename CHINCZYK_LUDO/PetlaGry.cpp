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
			PetlaGryOczekiwanieNaWyborPionka();
			PetlaGryTrwaRuch();
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

		Invoke(gcnew System::Action(this, &KontrolaWidoku::AktualizujIkonyPionkow));

		plansza->stanPlanszy = MaszynaStanow::oczekiwanieNaRzut;

		while (plansza->stanPlanszy == MaszynaStanow::oczekiwanieNaRzut);
	}

	/****************************************************************************************/

	/// <summary>
	/// 
	/// </summary>
	void KontrolaWidoku::PetlaGryOczekiwanieNaWyborPionka()
	{
		plansza->kliknietePionki = 0;
		cout << "Oczekiwanie na wybor pionka\n\n";
		while (plansza->kliknietePionki == 0);
	}

	/****************************************************************************************/

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	bool KontrolaWidoku::PetlaGryTrwaRuch()
	{
		plansza->stanPlanszy = MaszynaStanow::trwaRuch;
		//plansza->ruchPionka();

		plansza->kolorAktywnegoGracza = (KolorGracza)(((int)plansza->kolorAktywnegoGracza + 1) % 4);

		return true;
	}
}