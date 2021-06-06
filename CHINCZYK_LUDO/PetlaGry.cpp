#include "pch.h"
#include "KontrolaWidoku.h"
#include <msclr\marshal_cppstd.h>
#include <string>

using namespace System::Runtime::InteropServices;

namespace CHINCZYKLUDO {

	/// <summary>
	/// Główna pętla gry działająca na osobnym wątku - wykonuje się równolegle z obsługą planszy.
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
	/// Fragment pętli gry występujący podczas oczekiwania na rzut kostką przez odpowiedniego gracza.
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
	/// Fragment pętli gry występujący podczas oczekiwania na wybrania pionka wykonującego ruch przez gracza.
	/// </summary>
	/// <returns>true - pionek wybrany prawidłowo, false - Brak możliwości ruchu - nie ma sensu czekać na wybór pionka</returns>
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
	/// Fragment pętli gry występujący podczas trwania ruchu pionka.
	/// </summary>
	/// <returns>true - Należy powtórzyć wybór pionka, false - ruch zakończony</returns>
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

	/// <summary>
	/// Metoda która ma na celu sprawdzenie czy któryś gracz wygrał.
	/// </summary>

	int KontrolaWidoku::sprawdzCzyGraZakonczona() {
		for (int i = 0; i < plansza->getPolaDomkowPtr()->size(); i++) {
			if (plansza->getPolaDomkowPtr()->at(i).at(5).pionkiNaPolu.size() == 4) {
				return i;
			}
		}
		return -1;
	}

	/// <summary>
	/// Metoda która ma na celu pokazanie który gracz wygrał.
	/// </summary>

	void KontrolaWidoku::zakonczGre(int wygrany) {
		std::string s_wygrany = "czerwony";
		if (wygrany == 1) s_wygrany = "zielony";
		if (wygrany == 2) s_wygrany == "zolty";
		if (wygrany == 3) s_wygrany == "niebieski";

		std::cout << "Gra zakonczona. Wygral: " << s_wygrany << std::endl;
	}
}