#include "pch.h"
#include "KontrolaWidoku.h"
using namespace std;

/// <summary>
/// 
/// </summary>
namespace CHINCZYKLUDO {

	/****************************************************************************************/

	/// <summary>
	/// 
	/// </summary>
	/// <param name="ikonaPionka"></param>
	/// <param name="poleX"></param>
	/// <param name="PoleY"></param>
	void KontrolaWidoku::UstawPolozenieIkonyPionka(System::Windows::Forms::PictureBox^ ikonaPionka, Pole pole)
	{
		int x = pole.pozX();
		int y = pole.pozY();

		ikonaPionka->Location = System::Drawing::Point(x * 32, y * 35);
	}

	/****************************************************************************************/

	/// <summary>
	/// 
	/// </summary>
	void KontrolaWidoku::PrzypiszIkonyPionkow()
	{
		// Ustawienie ikon pionk�w czerwonych:
		obrazek_planszy->Controls->Add(pionek_c1);
		obrazek_planszy->Controls->Add(pionek_c2);
		obrazek_planszy->Controls->Add(pionek_c3);
		obrazek_planszy->Controls->Add(pionek_c4);

		// Ustawienie ikon pionk�w zielonych:
		obrazek_planszy->Controls->Add(pionek_zi1);
		obrazek_planszy->Controls->Add(pionek_zi2);
		obrazek_planszy->Controls->Add(pionek_zi3);
		obrazek_planszy->Controls->Add(pionek_zi4);

		// Ustawienie ikon pionk�w ��tych:
		obrazek_planszy->Controls->Add(pionek_zt1);
		obrazek_planszy->Controls->Add(pionek_zt2);
		obrazek_planszy->Controls->Add(pionek_zt3);
		obrazek_planszy->Controls->Add(pionek_zt4);

		// Ustawienie ikon pionk�w niebieskich:
		obrazek_planszy->Controls->Add(pionek_n1);
		obrazek_planszy->Controls->Add(pionek_n2);
		obrazek_planszy->Controls->Add(pionek_n3);
		obrazek_planszy->Controls->Add(pionek_n4);
	}

	/****************************************************************************************/

	/// <summary>
	/// 
	/// </summary>
	void KontrolaWidoku::AktualizujIkonyPionkow()
	{
		Przycisk_kostka->Enabled = true;
		aktualnyGraczTekst->Text = KolorNaString(plansza->kolorAktywnegoGracza);

		// Aktualizacja ikon pionk�w czerwonych:
		UstawPolozenieIkonyPionka(pionek_c1, plansza->znajdzPole(KolorGracza::czerwony, 1));
		UstawPolozenieIkonyPionka(pionek_c2, plansza->znajdzPole(KolorGracza::czerwony, 2));
		UstawPolozenieIkonyPionka(pionek_c3, plansza->znajdzPole(KolorGracza::czerwony, 3));
		UstawPolozenieIkonyPionka(pionek_c4, plansza->znajdzPole(KolorGracza::czerwony, 4));

		// Aktualizacja ikon pionk�w zielonych:
		UstawPolozenieIkonyPionka(pionek_zi1, plansza->znajdzPole(KolorGracza::zielony, 1));
		UstawPolozenieIkonyPionka(pionek_zi2, plansza->znajdzPole(KolorGracza::zielony, 2));
		UstawPolozenieIkonyPionka(pionek_zi3, plansza->znajdzPole(KolorGracza::zielony, 3));
		UstawPolozenieIkonyPionka(pionek_zi4, plansza->znajdzPole(KolorGracza::zielony, 4));

		// Aktualizacja ikon pionk�w ��tych:
		UstawPolozenieIkonyPionka(pionek_zt1, plansza->znajdzPole(KolorGracza::zolty, 1));
		UstawPolozenieIkonyPionka(pionek_zt2, plansza->znajdzPole(KolorGracza::zolty, 2));
		UstawPolozenieIkonyPionka(pionek_zt3, plansza->znajdzPole(KolorGracza::zolty, 3));
		UstawPolozenieIkonyPionka(pionek_zt4, plansza->znajdzPole(KolorGracza::zolty, 4));

		// Aktualizacja ikon pionk�w niebieskich:
		UstawPolozenieIkonyPionka(pionek_n1, plansza->znajdzPole(KolorGracza::niebieski, 1));
		UstawPolozenieIkonyPionka(pionek_n2, plansza->znajdzPole(KolorGracza::niebieski, 2));
		UstawPolozenieIkonyPionka(pionek_n3, plansza->znajdzPole(KolorGracza::niebieski, 3));
		UstawPolozenieIkonyPionka(pionek_n4, plansza->znajdzPole(KolorGracza::niebieski, 4));
	}

	/****************************************************************************************/

	/// <summary>
	/// 
	/// </summary>
	/// <param name="kolor"></param>
	/// <returns></returns>
	String^ KontrolaWidoku::KolorNaString(KolorGracza kolor)
	{
		switch (kolor)
		{
		case KolorGracza::czerwony:		return "czerwony";
		case KolorGracza::zielony:		return "zielony";
		case KolorGracza::zolty:		return "��ty";
		case KolorGracza::niebieski:	return "niebieski";
		}

		return "b��d";
	}

	/****************************************************************************************/

	/*void KontrolaWidoku::SkanujGracza()
	{
		Przycisk_kostka->Enabled = true;
		cout << "Teraz gracz ";
		cout << KolorNaString(plansza->kolorAktywnegoGracza)->ToCharArray();
		cout << " niech rzuci kostka!\n";

		aktualnyGraczTekst->Text = KolorNaString(plansza->kolorAktywnegoGracza);
		AktualizujIkonyPionkow();
	}*/

	/****************************************************************************************/

	/// <summary>
	/// 
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	void KontrolaWidoku::Przycisk_kostka_Click(System::Object^ sender, System::EventArgs^ e) {

		int oczka = plansza->RzutKostki();
		tekst_rzut_kostka->Text = oczka.ToString();
		Przycisk_kostka->Enabled = false;

		plansza->stanPlanszy = MaszynaStanow::oczekiwanieNaWyborPionka;
	}

	/****************************************************************************************/

	/// <summary>
	/// 
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	void KontrolaWidoku::Kontrolowa_widoku_Load(System::Object^ sender, System::EventArgs^ e) {

		PrzypiszIkonyPionkow();

		Thread^ watekPetliGry = gcnew Thread(gcnew ThreadStart(this, &KontrolaWidoku::PetlaGry));
		watekPetliGry->Start();
	}
}