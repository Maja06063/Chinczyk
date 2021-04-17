#pragma once
#include"Plansza.h"
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
	private:Plansza plansza;

	public:
		Kontrolowa_widoku(void)
		{
			InitializeComponent();
			srand(time(0));
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
	private: System::Windows::Forms::PictureBox^ obrazek_planszy;
	private: System::Windows::Forms::PictureBox^ pionek_c1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Kontrolowa_widoku::typeid));
			this->Przycisk_kostka = (gcnew System::Windows::Forms::Button());
			this->tekst_rzut_kostka = (gcnew System::Windows::Forms::Label());
			this->obrazek_planszy = (gcnew System::Windows::Forms::PictureBox());
			this->pionek_c1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->obrazek_planszy))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_c1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// Przycisk_kostka
			// 
			this->Przycisk_kostka->Location = System::Drawing::Point(667, 384);
			this->Przycisk_kostka->Margin = System::Windows::Forms::Padding(2);
			this->Przycisk_kostka->Name = L"Przycisk_kostka";
			this->Przycisk_kostka->Size = System::Drawing::Size(76, 19);
			this->Przycisk_kostka->TabIndex = 0;
			this->Przycisk_kostka->Text = L"Rzuæ kostk¹";
			this->Przycisk_kostka->UseVisualStyleBackColor = true;
			this->Przycisk_kostka->Click += gcnew System::EventHandler(this, &Kontrolowa_widoku::Przycisk_kostka_Click);
			// 
			// tekst_rzut_kostka
			// 
			this->tekst_rzut_kostka->AutoSize = true;
			this->tekst_rzut_kostka->Location = System::Drawing::Point(688, 420);
			this->tekst_rzut_kostka->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->tekst_rzut_kostka->Name = L"tekst_rzut_kostka";
			this->tekst_rzut_kostka->Size = System::Drawing::Size(55, 13);
			this->tekst_rzut_kostka->TabIndex = 1;
			this->tekst_rzut_kostka->Text = L"Brak rzutu";
			// 
			// obrazek_planszy
			// 
			this->obrazek_planszy->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"obrazek_planszy.Image")));
			this->obrazek_planszy->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"obrazek_planszy.InitialImage")));
			this->obrazek_planszy->Location = System::Drawing::Point(12, 12);
			this->obrazek_planszy->Name = L"obrazek_planszy";
			this->obrazek_planszy->Size = System::Drawing::Size(480, 481);
			this->obrazek_planszy->TabIndex = 2;
			this->obrazek_planszy->TabStop = false;
			// 
			// pionek_c1
			// 
			this->pionek_c1->BackColor = System::Drawing::Color::Transparent;
			this->pionek_c1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pionek_c1.Image")));
			this->pionek_c1->Location = System::Drawing::Point(234, 265);
			this->pionek_c1->Name = L"pionek_c1";
			this->pionek_c1->Size = System::Drawing::Size(32, 32);
			this->pionek_c1->TabIndex = 3;
			this->pionek_c1->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(667, 329);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(32, 32);
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(621, 291);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(32, 32);
			this->pictureBox2->TabIndex = 5;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(667, 291);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(32, 32);
			this->pictureBox3->TabIndex = 6;
			this->pictureBox3->TabStop = false;
			// 
			// Kontrolowa_widoku
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(754, 586);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pionek_c1);
			this->Controls->Add(this->obrazek_planszy);
			this->Controls->Add(this->tekst_rzut_kostka);
			this->Controls->Add(this->Przycisk_kostka);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Kontrolowa_widoku";
			this->Text = L"Chiñczyk";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->obrazek_planszy))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_c1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: void Przycisk_kostka_Click(System::Object^ sender, System::EventArgs^ e);



	
};
}
