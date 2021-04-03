#pragma once

namespace CHINCZYKLUDO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o Kontrolowa_widoku
	/// </summary>
	public ref class Kontrolowa_widoku : public System::Windows::Forms::Form
	{
	public:
		Kontrolowa_widoku(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~Kontrolowa_widoku()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Przycisk_kostka;
	protected:

	protected:
	private: System::Windows::Forms::Label^ tekst_rzut_kostka;

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Przycisk_kostka = (gcnew System::Windows::Forms::Button());
			this->tekst_rzut_kostka = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Przycisk_kostka
			// 
			this->Przycisk_kostka->Location = System::Drawing::Point(124, 495);
			this->Przycisk_kostka->Name = L"Przycisk_kostka";
			this->Przycisk_kostka->Size = System::Drawing::Size(101, 23);
			this->Przycisk_kostka->TabIndex = 0;
			this->Przycisk_kostka->Text = L"Rzuæ kostk¹";
			this->Przycisk_kostka->UseVisualStyleBackColor = true;
			this->Przycisk_kostka->Click += gcnew System::EventHandler(this, &Kontrolowa_widoku::Przycisk_kostka_Click);
			// 
			// tekst_rzut_kostka
			// 
			this->tekst_rzut_kostka->AutoSize = true;
			this->tekst_rzut_kostka->Location = System::Drawing::Point(373, 256);
			this->tekst_rzut_kostka->Name = L"tekst_rzut_kostka";
			this->tekst_rzut_kostka->Size = System::Drawing::Size(73, 17);
			this->tekst_rzut_kostka->TabIndex = 1;
			this->tekst_rzut_kostka->Text = L"Brak rzutu";
			// 
			// Kontrolowa_widoku
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1006, 721);
			this->Controls->Add(this->tekst_rzut_kostka);
			this->Controls->Add(this->Przycisk_kostka);
			this->Name = L"Kontrolowa_widoku";
			this->Text = L"Chiñczyk";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: void Przycisk_kostka_Click(System::Object^ sender, System::EventArgs^ e);



	};
}
