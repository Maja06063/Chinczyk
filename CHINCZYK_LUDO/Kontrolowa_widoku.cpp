#include "pch.h"
#include "Kontrolowa_widoku.h"
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
	void Kontrolowa_widoku::UstawPolozenieIkonyPionka(System::Windows::Forms::PictureBox^ ikonaPionka, int poleX, int PoleY)
	{
		ikonaPionka->Location = System::Drawing::Point(poleX * 32, PoleY * 35);
	}

	/****************************************************************************************/

	/// <summary>
	/// 
	/// </summary>
	void Kontrolowa_widoku::UstawIkonyPionkow()
	{
		// Ustawienie ikon pionk�w czerwonych:
		obrazek_planszy->Controls->Add(pionek_c1);
		obrazek_planszy->Controls->Add(pionek_c2);
		obrazek_planszy->Controls->Add(pionek_c3);
		obrazek_planszy->Controls->Add(pionek_c4);

		UstawPolozenieIkonyPionka(pionek_c1, 1, 10);
		UstawPolozenieIkonyPionka(pionek_c2, 4, 10);
		UstawPolozenieIkonyPionka(pionek_c3, 1, 13);
		UstawPolozenieIkonyPionka(pionek_c4, 4, 13);

		// Ustawienie ikon pionk�w zielonych:
		obrazek_planszy->Controls->Add(pionek_zi1);
		obrazek_planszy->Controls->Add(pionek_zi2);
		obrazek_planszy->Controls->Add(pionek_zi3);
		obrazek_planszy->Controls->Add(pionek_zi4);

		UstawPolozenieIkonyPionka(pionek_zi1, 10, 10);
		UstawPolozenieIkonyPionka(pionek_zi2, 13, 10);
		UstawPolozenieIkonyPionka(pionek_zi3, 10, 13);
		UstawPolozenieIkonyPionka(pionek_zi4, 13, 13);

		// Ustawienie ikon pionk�w ��tych:
		obrazek_planszy->Controls->Add(pionek_zt1);
		obrazek_planszy->Controls->Add(pionek_zt2);
		obrazek_planszy->Controls->Add(pionek_zt3);
		obrazek_planszy->Controls->Add(pionek_zt4);

		UstawPolozenieIkonyPionka(pionek_zt1, 10, 1);
		UstawPolozenieIkonyPionka(pionek_zt2, 13, 1);
		UstawPolozenieIkonyPionka(pionek_zt3, 10, 4);
		UstawPolozenieIkonyPionka(pionek_zt4, 13, 4);

		// Ustawienie ikon pionk�w niebieskich:
		obrazek_planszy->Controls->Add(pionek_n1);
		obrazek_planszy->Controls->Add(pionek_n2);
		obrazek_planszy->Controls->Add(pionek_n3);
		obrazek_planszy->Controls->Add(pionek_n4);

		UstawPolozenieIkonyPionka(pionek_n1, 1, 1);
		UstawPolozenieIkonyPionka(pionek_n2, 4, 1);
		UstawPolozenieIkonyPionka(pionek_n3, 1, 4);
		UstawPolozenieIkonyPionka(pionek_n4, 4, 4);
	}

	/****************************************************************************************/

	/// <summary>
	/// 
	/// </summary>
	/// <param name="kolor"></param>
	/// <returns></returns>
	String^ Kontrolowa_widoku::KolorNaString(KolorGracza kolor)
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

	void Kontrolowa_widoku::SkanujGracza()
	{
		Przycisk_kostka->Enabled = true;
		std::cout << "Teraz gracz " << KolorNaString(plansza->kolorAktywnegoGracza)->ToCharArray() << " niech rzuci kostka!\n";

		aktualnyGraczTekst->Text = KolorNaString(plansza->kolorAktywnegoGracza);
	}

	/****************************************************************************************/

	/// <summary>
	/// 
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	void Kontrolowa_widoku::Przycisk_kostka_Click(System::Object^ sender, System::EventArgs^ e) {

		plansza->stanPlanszy = MaszynaStanow::oczekiwanieNaWyborPionka;
		std::cout << "Oczekiwanie na wybor pionka\n\n";

		int oczka = plansza->RzutKostki();
		tekst_rzut_kostka->Text = oczka.ToString();
		Przycisk_kostka->Enabled = false;
	}

	/****************************************************************************************/

	/// <summary>
	/// 
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	void Kontrolowa_widoku::Kontrolowa_widoku_Load(System::Object^ sender, System::EventArgs^ e) {

		UstawIkonyPionkow();
		SkanujGracza();
	}
}