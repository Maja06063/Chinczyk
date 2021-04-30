#include "pch.h"
#include "Kontrolowa_widoku.h"
using namespace std;


namespace CHINCZYKLUDO {

	void Kontrolowa_widoku::Przycisk_kostka_Click(System::Object^ sender, System::EventArgs^ e) {
		
		int oczka=plansza.rzut_k();
		tekst_rzut_kostka->Text = oczka.ToString();
	}

	void Kontrolowa_widoku::Kontrolowa_widoku_Load(System::Object^ sender, System::EventArgs^ e) {

		obrazek_planszy->Controls->Add(pionek_c1);
		obrazek_planszy->Controls->Add(pionek_c2);
		obrazek_planszy->Controls->Add(pionek_c3);
		obrazek_planszy->Controls->Add(pionek_c4);
	}
}