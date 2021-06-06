#include "pch.h"
#include "KontrolaWidoku.h"
#include <msclr\marshal_cppstd.h>
#include <algorithm>
#include <vector>
using namespace std;

namespace CHINCZYKLUDO {

	/****************************************************************************************/

	/// <summary>
	/// Metoda UstawPolozenieIkonyPionka ustawia po³o¿enie ikony pionka na danym polu.
	/// </summary>
	/// <param name="ikonaPionka">Zarz¹dzana referencja na pionek, który nale¿y ustawiæ</param>
	/// <param name="pole">Pole na którym ustawiæ pionek</param>
	void KontrolaWidoku::UstawPolozenieIkonyPionka(System::Windows::Forms::PictureBox^ ikonaPionka, Pole pole, int ktory_pionek) //[CHANGED]
		//[GOOD]
	{	
		int x = pole.pozX();
		int y = pole.pozY();
		cout << "Polozenie pionka: " << x << ":" << y << endl;

		//[TODO] ustawic to w taki sposob aby dodatkowe pionki rysowaly sie w gore lub w bok zaleznie od 
		// tego jak w danym polu pasuje lepiej
		x = x * 32 + (ktory_pionek - 1) * 5;
		y = y * 35;

		
		ikonaPionka->Location = System::Drawing::Point(x, y);
	}

	/****************************************************************************************/

	/// <summary>
	/// Metoda PrzypiszIkonyPionkow przypisuje ikony pionków do obrazka planszy,
	/// przez co widoczna jest przezroczystoœæ dooko³a pionków.
	/// </summary>
	void KontrolaWidoku::PrzypiszIkonyPionkow()
	{
		// Ustawienie ikon pionków czerwonych:
		obrazek_planszy->Controls->Add(pionek_c1);
		obrazek_planszy->Controls->Add(pionek_c2);
		obrazek_planszy->Controls->Add(pionek_c3);
		obrazek_planszy->Controls->Add(pionek_c4);

		// Ustawienie ikon pionków zielonych:
		obrazek_planszy->Controls->Add(pionek_zi1);
		obrazek_planszy->Controls->Add(pionek_zi2);
		obrazek_planszy->Controls->Add(pionek_zi3);
		obrazek_planszy->Controls->Add(pionek_zi4);

		// Ustawienie ikon pionków ¿ó³tych:
		obrazek_planszy->Controls->Add(pionek_zt1);
		obrazek_planszy->Controls->Add(pionek_zt2);
		obrazek_planszy->Controls->Add(pionek_zt3);
		obrazek_planszy->Controls->Add(pionek_zt4);

		// Ustawienie ikon pionków niebieskich:
		obrazek_planszy->Controls->Add(pionek_n1);
		obrazek_planszy->Controls->Add(pionek_n2);
		obrazek_planszy->Controls->Add(pionek_n3);
		obrazek_planszy->Controls->Add(pionek_n4);
	}

	/****************************************************************************************/

	/// <summary>
	/// Metoda AktualizujIkonyPionkow przemieszcza ikony pionków na odpowiednie pola.
	/// </summary>
	void KontrolaWidoku::AktualizujIkonyPionkow()
	{
		Przycisk_kostka->Enabled = true;
		aktualnyGraczTekst->Text = KolorNaString(plansza->kolorAktywnegoGracza);

		//[CHANGED] tutaj mozna dodac rysowanie pionkow na jednym polu
		//[GOOD]

		std::vector<Pole> pola;
		std::vector<int> ile_pionkow;
		Pole pole;
		int ilosc_pionkow;

		//czerwone
		pole = plansza->znajdzPole(KolorGracza::czerwony, 1);
		ilosc_pionkow = sprawdzIloscPionkow(pola, ile_pionkow, pole);
		UstawPolozenieIkonyPionka(pionek_c1, pole, ilosc_pionkow);

		pole = plansza->znajdzPole(KolorGracza::czerwony, 2);
		ilosc_pionkow = sprawdzIloscPionkow(pola, ile_pionkow, pole);
		UstawPolozenieIkonyPionka(pionek_c2, pole, ilosc_pionkow);

		pole = plansza->znajdzPole(KolorGracza::czerwony, 3);
		ilosc_pionkow = sprawdzIloscPionkow(pola, ile_pionkow, pole);
		UstawPolozenieIkonyPionka(pionek_c3, pole, ilosc_pionkow);

		pole = plansza->znajdzPole(KolorGracza::czerwony, 4);
		ilosc_pionkow = sprawdzIloscPionkow(pola, ile_pionkow, pole);
		UstawPolozenieIkonyPionka(pionek_c4, pole, ilosc_pionkow);


		//zielone
		pole = plansza->znajdzPole(KolorGracza::zielony, 1);
		ilosc_pionkow = sprawdzIloscPionkow(pola, ile_pionkow, pole);
		UstawPolozenieIkonyPionka(pionek_zi1, pole, ilosc_pionkow);

		pole = plansza->znajdzPole(KolorGracza::zielony, 2);
		ilosc_pionkow = sprawdzIloscPionkow(pola, ile_pionkow, pole);
		UstawPolozenieIkonyPionka(pionek_zi2, pole, ilosc_pionkow);

		pole = plansza->znajdzPole(KolorGracza::zielony, 3);
		ilosc_pionkow = sprawdzIloscPionkow(pola, ile_pionkow, pole);
		UstawPolozenieIkonyPionka(pionek_zi3, pole, ilosc_pionkow);

		pole = plansza->znajdzPole(KolorGracza::zielony, 4);
		ilosc_pionkow = sprawdzIloscPionkow(pola, ile_pionkow, pole);
		UstawPolozenieIkonyPionka(pionek_zi4, pole, ilosc_pionkow);

		//zolte
		pole = plansza->znajdzPole(KolorGracza::zolty, 1);
		ilosc_pionkow = sprawdzIloscPionkow(pola, ile_pionkow, pole);
		UstawPolozenieIkonyPionka(pionek_zt1, pole, ilosc_pionkow);

		pole = plansza->znajdzPole(KolorGracza::zolty, 2);
		ilosc_pionkow = sprawdzIloscPionkow(pola, ile_pionkow, pole);
		UstawPolozenieIkonyPionka(pionek_zt2, pole, ilosc_pionkow);

		pole = plansza->znajdzPole(KolorGracza::zolty, 3);
		ilosc_pionkow = sprawdzIloscPionkow(pola, ile_pionkow, pole);
		UstawPolozenieIkonyPionka(pionek_zt3, pole, ilosc_pionkow);

		pole = plansza->znajdzPole(KolorGracza::zolty, 4);
		ilosc_pionkow = sprawdzIloscPionkow(pola, ile_pionkow, pole);
		UstawPolozenieIkonyPionka(pionek_zt4, pole, ilosc_pionkow);

		//niebieskie

		pole = plansza->znajdzPole(KolorGracza::niebieski, 1);
		ilosc_pionkow = sprawdzIloscPionkow(pola, ile_pionkow, pole);
		UstawPolozenieIkonyPionka(pionek_n1, pole, ilosc_pionkow);

		pole = plansza->znajdzPole(KolorGracza::niebieski, 2);
		ilosc_pionkow = sprawdzIloscPionkow(pola, ile_pionkow, pole);
		UstawPolozenieIkonyPionka(pionek_n2, pole, ilosc_pionkow);

		pole = plansza->znajdzPole(KolorGracza::niebieski, 3);
		ilosc_pionkow = sprawdzIloscPionkow(pola, ile_pionkow, pole);
		UstawPolozenieIkonyPionka(pionek_n3, pole, ilosc_pionkow);

		pole = plansza->znajdzPole(KolorGracza::niebieski, 4);
		ilosc_pionkow = sprawdzIloscPionkow(pola, ile_pionkow, pole);
		UstawPolozenieIkonyPionka(pionek_n4, pole, ilosc_pionkow);


		
	}

	/****************************************************************************************/

	/// <summary>
	/// Metoda KolorNaString s³u¿y do uzyskania nazwy koloru gracza.
	/// </summary>
	/// <param name="kolor">Kolor gracza do przekonwertowania na nazwê</param>
	/// <returns>Zarz¹dzana referencja na stringa systemowego bêd¹ca nazw¹ koloru</returns>
	String^ KontrolaWidoku::KolorNaString(KolorGracza kolor)
	{
		switch (kolor)
		{
		case KolorGracza::czerwony:		return "czerwony";
		case KolorGracza::zielony:		return "zielony";
		case KolorGracza::zolty:		return "¿ó³ty";
		case KolorGracza::niebieski:	return "niebieski";
		}

		return "b³¹d";
	}

	/****************************************************************************************/

	/// <summary>
	/// Metoda Przycisk_kostka_Click obs³uguje przerwanie po klikniêciu w przycisk rzutu kostk¹.
	/// </summary>
	/// <param name="sender">Zarz¹dzana referencja na obiekt wywo³uj¹cy przerwanie</param>
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
	/// <param name="sender">Zarz¹dzana referencja na obiekt wywo³uj¹cy przerwanie</param>
	/// <param name="e">Parametry przerwania</param>
	void KontrolaWidoku::Kontrolowa_widoku_Load(System::Object^ sender, System::EventArgs^ e) {

		PrzypiszIkonyPionkow();

		Thread^ watekPetliGry = gcnew Thread(gcnew ThreadStart(this, &KontrolaWidoku::PetlaGry));
		watekPetliGry->Start();
	}

	/// <summary>
	/// Metoda która sprawdza iloœæ pionków na danym polu.
	/// </summary>
	int KontrolaWidoku::sprawdzIloscPionkow(std::vector<Pole>& pola, std::vector<int>& ilosc_pionkow, Pole pole) { //[ADDED]
		//[GOOD]
		for (int i = 0; i < pola.size(); i++) {
			if (pola[i] == pole) {
				ilosc_pionkow[i]++;
				return ilosc_pionkow[i];
			}
		}
		pola.push_back(pole);
		ilosc_pionkow.push_back(1);
		return 1;
	}

}