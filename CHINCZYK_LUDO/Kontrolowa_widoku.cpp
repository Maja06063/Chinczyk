#include "pch.h"
#include "Kontrolowa_widoku.h"
using namespace std;


namespace CHINCZYKLUDO {

	void Kontrolowa_widoku::UstawPolozenieIkonyPionka(System::Windows::Forms::PictureBox^ ikonaPionka, int poleX, int PoleY)
	{
		ikonaPionka->Location = System::Drawing::Point(poleX * 32, PoleY * 35);
	}
	void Kontrolowa_widoku::Przycisk_kostka_Click(System::Object^ sender, System::EventArgs^ e) {
		
		int oczka=plansza->rzut_k();
		tekst_rzut_kostka->Text = oczka.ToString();
	}

	void Kontrolowa_widoku::Kontrolowa_widoku_Load(System::Object^ sender, System::EventArgs^ e) {

		// Ustawienie ikon pionków czerwonych:
		obrazek_planszy->Controls->Add(pionek_c1);
		obrazek_planszy->Controls->Add(pionek_c2);
		obrazek_planszy->Controls->Add(pionek_c3);
		obrazek_planszy->Controls->Add(pionek_c4);

		UstawPolozenieIkonyPionka(pionek_c1, 1, 10);
		UstawPolozenieIkonyPionka(pionek_c2, 4, 10);
		UstawPolozenieIkonyPionka(pionek_c3, 1, 13);
		UstawPolozenieIkonyPionka(pionek_c4, 4, 13);

		// Ustawienie ikon pionków zielonych:
		obrazek_planszy->Controls->Add(pionek_zi1);
		obrazek_planszy->Controls->Add(pionek_zi2);
		obrazek_planszy->Controls->Add(pionek_zi3);
		obrazek_planszy->Controls->Add(pionek_zi4);

		UstawPolozenieIkonyPionka(pionek_zi1, 10, 10);
		UstawPolozenieIkonyPionka(pionek_zi2, 13, 10);
		UstawPolozenieIkonyPionka(pionek_zi3, 10, 13);
		UstawPolozenieIkonyPionka(pionek_zi4, 13, 13);

		// Ustawienie ikon pionków ¿ó³tych:
		obrazek_planszy->Controls->Add(pionek_zt1);
		obrazek_planszy->Controls->Add(pionek_zt2);
		obrazek_planszy->Controls->Add(pionek_zt3);
		obrazek_planszy->Controls->Add(pionek_zt4);

		UstawPolozenieIkonyPionka(pionek_zt1, 10, 1);
		UstawPolozenieIkonyPionka(pionek_zt2, 13, 1);
		UstawPolozenieIkonyPionka(pionek_zt3, 10, 4);
		UstawPolozenieIkonyPionka(pionek_zt4, 13, 4);

		// Ustawienie ikon pionków niebieskich:
		obrazek_planszy->Controls->Add(pionek_n1);
		obrazek_planszy->Controls->Add(pionek_n2);
		obrazek_planszy->Controls->Add(pionek_n3);
		obrazek_planszy->Controls->Add(pionek_n4);

		UstawPolozenieIkonyPionka(pionek_n1, 1, 1);
		UstawPolozenieIkonyPionka(pionek_n2, 4, 1);
		UstawPolozenieIkonyPionka(pionek_n3, 1, 4);
		UstawPolozenieIkonyPionka(pionek_n4, 4, 4);
	}
}