#include "pch.h"
#include "KontrolaWidoku.h"
#include <msclr\marshal_cppstd.h>
#include <string>

using namespace System::Runtime::InteropServices;

namespace CHINCZYKLUDO {

	/// <summary>
	/// G³ówna pêtla gry dzia³aj¹ca na osobnym w¹tku - wykonuje siê równolegle z obs³ug¹ planszy.
	/// </summary>
	void KontrolaWidoku::PetlaGry()
	{
		while (1)
		{
			PetlaGryOczekiwanieNaRzut();

			while(1)
			{	
				int wygrany = sprawdzCzyGraZakonczona();
				if (wygrany != -1) {
					zakonczGre(wygrany);
					return;
				}

				if (!PetlaGryOczekiwanieNaWyborPionka()) break;
				if (!PetlaGryTrwaRuch()) break;
			}

		}
	}

	/****************************************************************************************/

	/// <summary>
	/// Fragment pêtli gry wystêpuj¹cy podczas oczekiwania na rzut kostk¹ przez odpowiedniego gracza.
	/// </summary>
	void KontrolaWidoku::PetlaGryOczekiwanieNaRzut() //[CHANGED]
	{
		std::string obecny_gracz = msclr::interop::marshal_as<std::string>(KolorNaString(plansza->kolorAktywnegoGracza));
		cout << "Teraz gracz "
			<< obecny_gracz
			<< " niech rzuci kostka!\n";

		plansza->stanPlanszy = MaszynaStanow::oczekiwanieNaRzut;
		Invoke(gcnew System::Action(this, &KontrolaWidoku::AktualizujIkonyPionkow));

		while (plansza->stanPlanszy == MaszynaStanow::oczekiwanieNaRzut);
	}

	/****************************************************************************************/

	/// <summary>
	/// Fragment pêtli gry wystêpuj¹cy podczas oczekiwania na wybrania pionka wykonuj¹cego ruch przez gracza.
	/// </summary>
	/// <returns>true - pionek wybrany prawid³owo, false - Brak mo¿liwoœci ruchu - nie ma sensu czekaæ na wybór pionka</returns>
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
	/// Fragment pêtli gry wystêpuj¹cy podczas trwania ruchu pionka.
	/// </summary>
	/// <returns>true - Nale¿y powtórzyæ wybór pionka, false - ruch zakoñczony</returns>
	bool KontrolaWidoku::PetlaGryTrwaRuch()
	{
		bool powtornyRzutKostka = false;

		plansza->stanPlanszy = MaszynaStanow::trwaRuch;
		if (!plansza->CzyDobryPionekWybrano()) return true;
		if (!plansza->ruchPionka()) return true;

		if (plansza->ostatniRzutKostki == 6) powtornyRzutKostka = true;

		if (!powtornyRzutKostka) plansza->kolorAktywnegoGracza = (KolorGracza)(((int)plansza->kolorAktywnegoGracza + 1) % 4);
		return false;
	}

	/****************************************************************************************/

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	int KontrolaWidoku::sprawdzCzyGraZakonczona() {
		for (int i = 0; i < plansza->getPolaDomkowPtr()->size(); i++) {
			if (plansza->getPolaDomkowPtr()->at(i).at(5).pionkiNaPolu.size() == 4) {
				return i;
			}
		}
		return -1;
	}

	/****************************************************************************************/

	/// <summary>
	/// 
	/// </summary>
	/// <param name="wygrany"></param>
	void KontrolaWidoku::zakonczGre(int wygrany) {
		std::string s_wygrany = "czerwony";
		if (wygrany == 1) s_wygrany = "zielony";
		if (wygrany == 2) s_wygrany == "zolty";
		if (wygrany == 3) s_wygrany == "niebieski";

		std::cout << "Gra zakonczona. Wygral: " << s_wygrany << std::endl;
	}
}