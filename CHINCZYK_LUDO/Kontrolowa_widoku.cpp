#include "pch.h"
#include "Kontrolowa_widoku.h"
using namespace std;


namespace CHINCZYKLUDO {
	void Kontrolowa_widoku::UstawPolozenieIkonyPionka(System::Windows::Forms::PictureBox^ ikonaPionka, int poleX, int PoleY)
	{
		ikonaPionka->Location = System::Drawing::Point(poleX * 32, PoleY * 35);
	}
	void Kontrolowa_widoku::Przycisk_kostka_Click(System::Object^ sender, System::EventArgs^ e) {
		
		int oczka=plansza.rzut_k();
		tekst_rzut_kostka->Text = oczka.ToString();
	}

	void Kontrolowa_widoku::Kontrolowa_widoku_Load(System::Object^ sender, System::EventArgs^ e) {

		obrazek_planszy->Controls->Add(pionek_c1);
		obrazek_planszy->Controls->Add(pionek_c2);
		obrazek_planszy->Controls->Add(pionek_c3);
		obrazek_planszy->Controls->Add(pionek_c4);

		UstawPolozenieIkonyPionka(pionek_c1, 1, 10);
		UstawPolozenieIkonyPionka(pionek_c2, 4, 10);
		UstawPolozenieIkonyPionka(pionek_c3, 1, 13);
		UstawPolozenieIkonyPionka(pionek_c4, 4, 13);

		obrazek_planszy->Controls->Add(pionek_zi1);
		obrazek_planszy->Controls->Add(pionek_zi2);
		obrazek_planszy->Controls->Add(pionek_zi3);
		obrazek_planszy->Controls->Add(pionek_zi4);

		UstawPolozenieIkonyPionka(pionek_zi1, 10, 10);
		UstawPolozenieIkonyPionka(pionek_zi2, 13, 10);
		UstawPolozenieIkonyPionka(pionek_zi3, 10, 13);
		UstawPolozenieIkonyPionka(pionek_zi4, 13, 13);
	}
}