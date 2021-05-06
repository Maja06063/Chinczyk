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
			srand((unsigned int)time(0));
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
	private: System::Windows::Forms::PictureBox^ pionek_c2;
	private: System::Windows::Forms::PictureBox^ pionek_c3;
	private: System::Windows::Forms::PictureBox^ pionek_c4;
	private: System::Windows::Forms::PictureBox^ pionek_zi1;
	private: System::Windows::Forms::PictureBox^ pionek_zi2;
	private: System::Windows::Forms::PictureBox^ pionek_zi3;
	private: System::Windows::Forms::PictureBox^ pionek_zi4;









	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container^ components;

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
			this->pionek_c2 = (gcnew System::Windows::Forms::PictureBox());
			this->pionek_c3 = (gcnew System::Windows::Forms::PictureBox());
			this->pionek_c4 = (gcnew System::Windows::Forms::PictureBox());
			this->pionek_zi1 = (gcnew System::Windows::Forms::PictureBox());
			this->pionek_zi2 = (gcnew System::Windows::Forms::PictureBox());
			this->pionek_zi3 = (gcnew System::Windows::Forms::PictureBox());
			this->pionek_zi4 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->obrazek_planszy))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_c1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_c2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_c3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_c4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_zi1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_zi2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_zi3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_zi4))->BeginInit();
			this->SuspendLayout();
			// 
			// Przycisk_kostka
			// 
			this->Przycisk_kostka->Location = System::Drawing::Point(889, 473);
			this->Przycisk_kostka->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
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
			this->tekst_rzut_kostka->Location = System::Drawing::Point(917, 517);
			this->tekst_rzut_kostka->Name = L"tekst_rzut_kostka";
			this->tekst_rzut_kostka->Size = System::Drawing::Size(73, 17);
			this->tekst_rzut_kostka->TabIndex = 1;
			this->tekst_rzut_kostka->Text = L"Brak rzutu";
			// 
			// obrazek_planszy
			// 
			this->obrazek_planszy->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"obrazek_planszy.Image")));
			this->obrazek_planszy->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"obrazek_planszy.InitialImage")));
			this->obrazek_planszy->Location = System::Drawing::Point(16, 15);
			this->obrazek_planszy->Margin = System::Windows::Forms::Padding(4);
			this->obrazek_planszy->Name = L"obrazek_planszy";
			this->obrazek_planszy->Size = System::Drawing::Size(640, 640);
			this->obrazek_planszy->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->obrazek_planszy->TabIndex = 2;
			this->obrazek_planszy->TabStop = false;
			// 
			// pionek_c1
			// 
			this->pionek_c1->AccessibleName = L"";
			this->pionek_c1->BackColor = System::Drawing::Color::Transparent;
			this->pionek_c1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pionek_c1.Image")));
			this->pionek_c1->Location = System::Drawing::Point(64, 574);
			this->pionek_c1->Margin = System::Windows::Forms::Padding(4);
			this->pionek_c1->Name = L"pionek_c1";
			this->pionek_c1->Size = System::Drawing::Size(32, 32);
			this->pionek_c1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pionek_c1->TabIndex = 3;
			this->pionek_c1->TabStop = false;
			// 
			// pionek_c2
			// 
			this->pionek_c2->AccessibleName = L"";
			this->pionek_c2->BackColor = System::Drawing::Color::Transparent;
			this->pionek_c2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pionek_c2.Image")));
			this->pionek_c2->Location = System::Drawing::Point(64, 447);
			this->pionek_c2->Margin = System::Windows::Forms::Padding(4);
			this->pionek_c2->Name = L"pionek_c2";
			this->pionek_c2->Size = System::Drawing::Size(32, 32);
			this->pionek_c2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pionek_c2->TabIndex = 4;
			this->pionek_c2->TabStop = false;
			// 
			// pionek_c3
			// 
			this->pionek_c3->AccessibleName = L"";
			this->pionek_c3->BackColor = System::Drawing::Color::Transparent;
			this->pionek_c3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pionek_c3.Image")));
			this->pionek_c3->Location = System::Drawing::Point(191, 447);
			this->pionek_c3->Margin = System::Windows::Forms::Padding(4);
			this->pionek_c3->Name = L"pionek_c3";
			this->pionek_c3->Size = System::Drawing::Size(32, 32);
			this->pionek_c3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pionek_c3->TabIndex = 5;
			this->pionek_c3->TabStop = false;
			// 
			// pionek_c4
			// 
			this->pionek_c4->AccessibleName = L"";
			this->pionek_c4->BackColor = System::Drawing::Color::Transparent;
			this->pionek_c4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pionek_c4.Image")));
			this->pionek_c4->Location = System::Drawing::Point(191, 574);
			this->pionek_c4->Margin = System::Windows::Forms::Padding(4);
			this->pionek_c4->Name = L"pionek_c4";
			this->pionek_c4->Size = System::Drawing::Size(32, 32);
			this->pionek_c4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pionek_c4->TabIndex = 6;
			this->pionek_c4->TabStop = false;
			// 
			// pionek_zi1
			// 
			this->pionek_zi1->AccessibleName = L"";
			this->pionek_zi1->BackColor = System::Drawing::Color::Transparent;
			this->pionek_zi1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pionek_zi1.Image")));
			this->pionek_zi1->Location = System::Drawing::Point(448, 447);
			this->pionek_zi1->Margin = System::Windows::Forms::Padding(4);
			this->pionek_zi1->Name = L"pionek_zi1";
			this->pionek_zi1->Size = System::Drawing::Size(32, 32);
			this->pionek_zi1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pionek_zi1->TabIndex = 7;
			this->pionek_zi1->TabStop = false;
			// 
			// pionek_zi2
			// 
			this->pionek_zi2->AccessibleName = L"";
			this->pionek_zi2->BackColor = System::Drawing::Color::Transparent;
			this->pionek_zi2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pionek_zi2.Image")));
			this->pionek_zi2->Location = System::Drawing::Point(577, 447);
			this->pionek_zi2->Margin = System::Windows::Forms::Padding(4);
			this->pionek_zi2->Name = L"pionek_zi2";
			this->pionek_zi2->Size = System::Drawing::Size(32, 32);
			this->pionek_zi2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pionek_zi2->TabIndex = 8;
			this->pionek_zi2->TabStop = false;
			// 
			// pionek_zi3
			// 
			this->pionek_zi3->AccessibleName = L"";
			this->pionek_zi3->BackColor = System::Drawing::Color::Transparent;
			this->pionek_zi3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pionek_zi3.Image")));
			this->pionek_zi3->Location = System::Drawing::Point(448, 574);
			this->pionek_zi3->Margin = System::Windows::Forms::Padding(4);
			this->pionek_zi3->Name = L"pionek_zi3";
			this->pionek_zi3->Size = System::Drawing::Size(32, 32);
			this->pionek_zi3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pionek_zi3->TabIndex = 9;
			this->pionek_zi3->TabStop = false;
			// 
			// pionek_zi4
			// 
			this->pionek_zi4->AccessibleName = L"";
			this->pionek_zi4->BackColor = System::Drawing::Color::Transparent;
			this->pionek_zi4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pionek_zi4.Image")));
			this->pionek_zi4->Location = System::Drawing::Point(577, 574);
			this->pionek_zi4->Margin = System::Windows::Forms::Padding(4);
			this->pionek_zi4->Name = L"pionek_zi4";
			this->pionek_zi4->Size = System::Drawing::Size(32, 32);
			this->pionek_zi4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pionek_zi4->TabIndex = 10;
			this->pionek_zi4->TabStop = false;
			// 
			// Kontrolowa_widoku
			// 
			this->AccessibleName = L"";
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1005, 721);
			this->Controls->Add(this->pionek_zi4);
			this->Controls->Add(this->pionek_zi3);
			this->Controls->Add(this->pionek_zi2);
			this->Controls->Add(this->pionek_zi1);
			this->Controls->Add(this->pionek_c4);
			this->Controls->Add(this->pionek_c3);
			this->Controls->Add(this->pionek_c2);
			this->Controls->Add(this->pionek_c1);
			this->Controls->Add(this->obrazek_planszy);
			this->Controls->Add(this->tekst_rzut_kostka);
			this->Controls->Add(this->Przycisk_kostka);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"Kontrolowa_widoku";
			this->Text = L"Chiñczyk";
			this->Load += gcnew System::EventHandler(this, &Kontrolowa_widoku::Kontrolowa_widoku_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->obrazek_planszy))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_c1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_c2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_c3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_c4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_zi1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_zi2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_zi3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_zi4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		private: void UstawPolozenieIkonyPionka(System::Windows::Forms::PictureBox^ ikonaPionka, int poleX, int PoleY);



	private: void Przycisk_kostka_Click(System::Object^ sender, System::EventArgs^ e);

	private: void Kontrolowa_widoku_Load(System::Object^ sender, System::EventArgs^ e);
	};
}
