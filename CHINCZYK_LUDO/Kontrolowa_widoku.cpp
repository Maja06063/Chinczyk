#include "pch.h"
#include "Kontrolowa_widoku.h"
using namespace std;
namespace CHINCZYKLUDO {

	void Kontrolowa_widoku::Przycisk_kostka_Click(System::Object^ sender, System::EventArgs^ e) {
		int oczka=plansza.rzut_k();
		tekst_rzut_kostka->Text = oczka.ToString();
		
	}
}