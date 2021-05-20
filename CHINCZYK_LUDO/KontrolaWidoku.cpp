#include "pch.h"
#include "KontrolaWidoku.h"
using namespace std;

namespace CHINCZYKLUDO {

	/****************************************************************************************/

	/// <summary>
	/// Metoda UstawPolozenieIkonyPionka ustawia po�o�enie ikony pionka na danym polu.
	/// </summary>
	/// <param name="ikonaPionka">Zarz�dzana referencja na pionek, kt�ry nale�y ustawi�</param>
	/// <param name="pole">Pole na kt�rym ustawi� pionek</param>
	void KontrolaWidoku::UstawPolozenieIkonyPionka(System::Windows::Forms::PictureBox^ ikonaPionka, Pole pole)
	{
		int x = pole.pozX();
		int y = pole.pozY();

		ikonaPionka->Location = System::Drawing::Point(x * 32, y * 35);
	}

	/****************************************************************************************/

	/// <summary>
	/// Metoda PrzypiszIkonyPionkow przypisuje ikony pionk�w do obrazka planszy,
	/// przez co widoczna jest przezroczysto�� dooko�a pionk�w.
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
	/// Metoda AktualizujIkonyPionkow przemieszcza ikony pionk�w na odpowiednie pola.
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
	/// Metoda KolorNaString s�u�y do uzyskania nazwy koloru gracza.
	/// </summary>
	/// <param name="kolor">Kolor gracza do przekonwertowania na nazw�</param>
	/// <returns>Zarz�dzana referencja na stringa systemowego b�d�ca nazw� koloru</returns>
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

	/// <summary>
	/// Metoda Przycisk_kostka_Click obs�uguje przerwanie po klikni�ciu w przycisk rzutu kostk�.
	/// </summary>
	/// <param name="sender">Zarz�dzana referencja na obiekt wywo�uj�cy przerwanie</param>
	/// <param name="e">Parametry przerwania</param>
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
	/// <param name="sender">Zarz�dzana referencja na obiekt wywo�uj�cy przerwanie</param>
	/// <param name="e">Parametry przerwania</param>
	void KontrolaWidoku::Kontrolowa_widoku_Load(System::Object^ sender, System::EventArgs^ e) {

		PrzypiszIkonyPionkow();

		Thread^ watekPetliGry = gcnew Thread(gcnew ThreadStart(this, &KontrolaWidoku::PetlaGry));
		watekPetliGry->Start();
	}
}