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
	private:Plansza* plansza = new Plansza();

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
	private: System::Windows::Forms::PictureBox^ pionek_zt1;
	private: System::Windows::Forms::PictureBox^ pionek_zt2;
	private: System::Windows::Forms::PictureBox^ pionek_zt3;
	private: System::Windows::Forms::PictureBox^ pionek_zt4;
	private: System::Windows::Forms::PictureBox^ pionek_n1;
	private: System::Windows::Forms::PictureBox^ pionek_n2;
	private: System::Windows::Forms::PictureBox^ pionek_n3;
	private: System::Windows::Forms::PictureBox^ pionek_n4;
	private: System::Windows::Forms::Label^ aktualnyGraczTytul;
	private: System::Windows::Forms::Label^ aktualnyGraczTekst;









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
			this->pionek_zt1 = (gcnew System::Windows::Forms::PictureBox());
			this->pionek_zt2 = (gcnew System::Windows::Forms::PictureBox());
			this->pionek_zt3 = (gcnew System::Windows::Forms::PictureBox());
			this->pionek_zt4 = (gcnew System::Windows::Forms::PictureBox());
			this->pionek_n1 = (gcnew System::Windows::Forms::PictureBox());
			this->pionek_n2 = (gcnew System::Windows::Forms::PictureBox());
			this->pionek_n3 = (gcnew System::Windows::Forms::PictureBox());
			this->pionek_n4 = (gcnew System::Windows::Forms::PictureBox());
			this->aktualnyGraczTytul = (gcnew System::Windows::Forms::Label());
			this->aktualnyGraczTekst = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->obrazek_planszy))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_c1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_c2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_c3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_c4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_zi1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_zi2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_zi3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_zi4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_zt1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_zt2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_zt3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_zt4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_n1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_n2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_n3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_n4))->BeginInit();
			this->SuspendLayout();
			// 
			// Przycisk_kostka
			// 
			this->Przycisk_kostka->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->Przycisk_kostka->Location = System::Drawing::Point(715, 260);
			this->Przycisk_kostka->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Przycisk_kostka->Name = L"Przycisk_kostka";
			this->Przycisk_kostka->Size = System::Drawing::Size(155, 38);
			this->Przycisk_kostka->TabIndex = 0;
			this->Przycisk_kostka->Text = L"Rzuæ kostk¹";
			this->Przycisk_kostka->UseVisualStyleBackColor = true;
			this->Przycisk_kostka->Click += gcnew System::EventHandler(this, &Kontrolowa_widoku::Przycisk_kostka_Click);
			// 
			// tekst_rzut_kostka
			// 
			this->tekst_rzut_kostka->AutoSize = true;
			this->tekst_rzut_kostka->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->tekst_rzut_kostka->Location = System::Drawing::Point(875, 266);
			this->tekst_rzut_kostka->Name = L"tekst_rzut_kostka";
			this->tekst_rzut_kostka->Size = System::Drawing::Size(100, 25);
			this->tekst_rzut_kostka->TabIndex = 1;
			this->tekst_rzut_kostka->Text = L"Brak rzutu";
			// 
			// obrazek_planszy
			// 
			this->obrazek_planszy->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"obrazek_planszy.Image")));
			this->obrazek_planszy->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"obrazek_planszy.InitialImage")));
			this->obrazek_planszy->Location = System::Drawing::Point(16, 15);
			this->obrazek_planszy->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
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
			this->pionek_c1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pionek_c1->Name = L"pionek_c1";
			this->pionek_c1->Size = System::Drawing::Size(32, 32);
			this->pionek_c1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pionek_c1->TabIndex = 3;
			this->pionek_c1->TabStop = false;
			this->pionek_c1->Click += gcnew System::EventHandler(this, &Kontrolowa_widoku::pionek_c1_Click);
			// 
			// pionek_c2
			// 
			this->pionek_c2->AccessibleName = L"";
			this->pionek_c2->BackColor = System::Drawing::Color::Transparent;
			this->pionek_c2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pionek_c2.Image")));
			this->pionek_c2->Location = System::Drawing::Point(64, 447);
			this->pionek_c2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pionek_c2->Name = L"pionek_c2";
			this->pionek_c2->Size = System::Drawing::Size(32, 32);
			this->pionek_c2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pionek_c2->TabIndex = 4;
			this->pionek_c2->TabStop = false;
			this->pionek_c2->Click += gcnew System::EventHandler(this, &Kontrolowa_widoku::pionek_c2_Click);
			// 
			// pionek_c3
			// 
			this->pionek_c3->AccessibleName = L"";
			this->pionek_c3->BackColor = System::Drawing::Color::Transparent;
			this->pionek_c3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pionek_c3.Image")));
			this->pionek_c3->Location = System::Drawing::Point(191, 447);
			this->pionek_c3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pionek_c3->Name = L"pionek_c3";
			this->pionek_c3->Size = System::Drawing::Size(32, 32);
			this->pionek_c3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pionek_c3->TabIndex = 5;
			this->pionek_c3->TabStop = false;
			this->pionek_c3->Click += gcnew System::EventHandler(this, &Kontrolowa_widoku::pionek_c3_Click);
			// 
			// pionek_c4
			// 
			this->pionek_c4->AccessibleName = L"";
			this->pionek_c4->BackColor = System::Drawing::Color::Transparent;
			this->pionek_c4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pionek_c4.Image")));
			this->pionek_c4->Location = System::Drawing::Point(191, 574);
			this->pionek_c4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pionek_c4->Name = L"pionek_c4";
			this->pionek_c4->Size = System::Drawing::Size(32, 32);
			this->pionek_c4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pionek_c4->TabIndex = 6;
			this->pionek_c4->TabStop = false;
			this->pionek_c4->Click += gcnew System::EventHandler(this, &Kontrolowa_widoku::pionek_c4_Click);
			// 
			// pionek_zi1
			// 
			this->pionek_zi1->AccessibleName = L"";
			this->pionek_zi1->BackColor = System::Drawing::Color::Transparent;
			this->pionek_zi1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pionek_zi1.Image")));
			this->pionek_zi1->Location = System::Drawing::Point(448, 447);
			this->pionek_zi1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pionek_zi1->Name = L"pionek_zi1";
			this->pionek_zi1->Size = System::Drawing::Size(32, 32);
			this->pionek_zi1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pionek_zi1->TabIndex = 7;
			this->pionek_zi1->TabStop = false;
			this->pionek_zi1->Click += gcnew System::EventHandler(this, &Kontrolowa_widoku::pionek_zi1_Click);
			// 
			// pionek_zi2
			// 
			this->pionek_zi2->AccessibleName = L"";
			this->pionek_zi2->BackColor = System::Drawing::Color::Transparent;
			this->pionek_zi2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pionek_zi2.Image")));
			this->pionek_zi2->Location = System::Drawing::Point(577, 447);
			this->pionek_zi2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pionek_zi2->Name = L"pionek_zi2";
			this->pionek_zi2->Size = System::Drawing::Size(32, 32);
			this->pionek_zi2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pionek_zi2->TabIndex = 8;
			this->pionek_zi2->TabStop = false;
			this->pionek_zi2->Click += gcnew System::EventHandler(this, &Kontrolowa_widoku::pionek_zi2_Click);
			// 
			// pionek_zi3
			// 
			this->pionek_zi3->AccessibleName = L"";
			this->pionek_zi3->BackColor = System::Drawing::Color::Transparent;
			this->pionek_zi3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pionek_zi3.Image")));
			this->pionek_zi3->Location = System::Drawing::Point(448, 574);
			this->pionek_zi3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pionek_zi3->Name = L"pionek_zi3";
			this->pionek_zi3->Size = System::Drawing::Size(32, 32);
			this->pionek_zi3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pionek_zi3->TabIndex = 9;
			this->pionek_zi3->TabStop = false;
			this->pionek_zi3->Click += gcnew System::EventHandler(this, &Kontrolowa_widoku::pionek_zi3_Click);
			// 
			// pionek_zi4
			// 
			this->pionek_zi4->AccessibleName = L"";
			this->pionek_zi4->BackColor = System::Drawing::Color::Transparent;
			this->pionek_zi4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pionek_zi4.Image")));
			this->pionek_zi4->Location = System::Drawing::Point(577, 574);
			this->pionek_zi4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pionek_zi4->Name = L"pionek_zi4";
			this->pionek_zi4->Size = System::Drawing::Size(32, 32);
			this->pionek_zi4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pionek_zi4->TabIndex = 10;
			this->pionek_zi4->TabStop = false;
			this->pionek_zi4->Click += gcnew System::EventHandler(this, &Kontrolowa_widoku::pionek_zi4_Click);
			// 
			// pionek_zt1
			// 
			this->pionek_zt1->AccessibleName = L"";
			this->pionek_zt1->BackColor = System::Drawing::Color::Transparent;
			this->pionek_zt1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pionek_zt1.Image")));
			this->pionek_zt1->Location = System::Drawing::Point(448, 63);
			this->pionek_zt1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pionek_zt1->Name = L"pionek_zt1";
			this->pionek_zt1->Size = System::Drawing::Size(32, 32);
			this->pionek_zt1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pionek_zt1->TabIndex = 11;
			this->pionek_zt1->TabStop = false;
			this->pionek_zt1->Click += gcnew System::EventHandler(this, &Kontrolowa_widoku::pionek_zt1_Click);
			// 
			// pionek_zt2
			// 
			this->pionek_zt2->AccessibleName = L"";
			this->pionek_zt2->BackColor = System::Drawing::Color::Transparent;
			this->pionek_zt2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pionek_zt2.Image")));
			this->pionek_zt2->Location = System::Drawing::Point(577, 63);
			this->pionek_zt2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pionek_zt2->Name = L"pionek_zt2";
			this->pionek_zt2->Size = System::Drawing::Size(32, 32);
			this->pionek_zt2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pionek_zt2->TabIndex = 12;
			this->pionek_zt2->TabStop = false;
			this->pionek_zt2->Click += gcnew System::EventHandler(this, &Kontrolowa_widoku::pionek_zt2_Click);
			// 
			// pionek_zt3
			// 
			this->pionek_zt3->AccessibleName = L"";
			this->pionek_zt3->BackColor = System::Drawing::Color::Transparent;
			this->pionek_zt3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pionek_zt3.Image")));
			this->pionek_zt3->Location = System::Drawing::Point(448, 191);
			this->pionek_zt3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pionek_zt3->Name = L"pionek_zt3";
			this->pionek_zt3->Size = System::Drawing::Size(32, 32);
			this->pionek_zt3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pionek_zt3->TabIndex = 13;
			this->pionek_zt3->TabStop = false;
			this->pionek_zt3->Click += gcnew System::EventHandler(this, &Kontrolowa_widoku::pionek_zt3_Click);
			// 
			// pionek_zt4
			// 
			this->pionek_zt4->AccessibleName = L"";
			this->pionek_zt4->BackColor = System::Drawing::Color::Transparent;
			this->pionek_zt4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pionek_zt4.Image")));
			this->pionek_zt4->Location = System::Drawing::Point(577, 191);
			this->pionek_zt4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pionek_zt4->Name = L"pionek_zt4";
			this->pionek_zt4->Size = System::Drawing::Size(32, 32);
			this->pionek_zt4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pionek_zt4->TabIndex = 14;
			this->pionek_zt4->TabStop = false;
			this->pionek_zt4->Click += gcnew System::EventHandler(this, &Kontrolowa_widoku::pionek_zt4_Click);
			// 
			// pionek_n1
			// 
			this->pionek_n1->AccessibleName = L"";
			this->pionek_n1->BackColor = System::Drawing::Color::Transparent;
			this->pionek_n1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pionek_n1.Image")));
			this->pionek_n1->Location = System::Drawing::Point(64, 63);
			this->pionek_n1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pionek_n1->Name = L"pionek_n1";
			this->pionek_n1->Size = System::Drawing::Size(32, 32);
			this->pionek_n1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pionek_n1->TabIndex = 15;
			this->pionek_n1->TabStop = false;
			this->pionek_n1->Click += gcnew System::EventHandler(this, &Kontrolowa_widoku::pionek_n1_Click);
			// 
			// pionek_n2
			// 
			this->pionek_n2->AccessibleName = L"";
			this->pionek_n2->BackColor = System::Drawing::Color::Transparent;
			this->pionek_n2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pionek_n2.Image")));
			this->pionek_n2->Location = System::Drawing::Point(191, 63);
			this->pionek_n2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pionek_n2->Name = L"pionek_n2";
			this->pionek_n2->Size = System::Drawing::Size(32, 32);
			this->pionek_n2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pionek_n2->TabIndex = 16;
			this->pionek_n2->TabStop = false;
			this->pionek_n2->Click += gcnew System::EventHandler(this, &Kontrolowa_widoku::pionek_n2_Click);
			// 
			// pionek_n3
			// 
			this->pionek_n3->AccessibleName = L"";
			this->pionek_n3->BackColor = System::Drawing::Color::Transparent;
			this->pionek_n3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pionek_n3.Image")));
			this->pionek_n3->Location = System::Drawing::Point(64, 191);
			this->pionek_n3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pionek_n3->Name = L"pionek_n3";
			this->pionek_n3->Size = System::Drawing::Size(32, 32);
			this->pionek_n3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pionek_n3->TabIndex = 17;
			this->pionek_n3->TabStop = false;
			this->pionek_n3->Click += gcnew System::EventHandler(this, &Kontrolowa_widoku::pionek_n3_Click);
			// 
			// pionek_n4
			// 
			this->pionek_n4->AccessibleName = L"";
			this->pionek_n4->BackColor = System::Drawing::Color::Transparent;
			this->pionek_n4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pionek_n4.Image")));
			this->pionek_n4->Location = System::Drawing::Point(191, 191);
			this->pionek_n4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pionek_n4->Name = L"pionek_n4";
			this->pionek_n4->Size = System::Drawing::Size(32, 32);
			this->pionek_n4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pionek_n4->TabIndex = 18;
			this->pionek_n4->TabStop = false;
			this->pionek_n4->Click += gcnew System::EventHandler(this, &Kontrolowa_widoku::pionek_n4_Click);
			// 
			// aktualnyGraczTytul
			// 
			this->aktualnyGraczTytul->AutoSize = true;
			this->aktualnyGraczTytul->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->aktualnyGraczTytul->Location = System::Drawing::Point(741, 96);
			this->aktualnyGraczTytul->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->aktualnyGraczTytul->Name = L"aktualnyGraczTytul";
			this->aktualnyGraczTytul->Size = System::Drawing::Size(187, 29);
			this->aktualnyGraczTytul->TabIndex = 19;
			this->aktualnyGraczTytul->Text = L"Aktualny gracz:";
			// 
			// aktualnyGraczTekst
			// 
			this->aktualnyGraczTekst->AutoSize = true;
			this->aktualnyGraczTekst->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->aktualnyGraczTekst->Location = System::Drawing::Point(784, 140);
			this->aktualnyGraczTekst->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->aktualnyGraczTekst->Name = L"aktualnyGraczTekst";
			this->aktualnyGraczTekst->Size = System::Drawing::Size(81, 29);
			this->aktualnyGraczTekst->TabIndex = 20;
			this->aktualnyGraczTekst->Text = L"label2";
			// 
			// Kontrolowa_widoku
			// 
			this->AccessibleName = L"";
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1005, 721);
			this->Controls->Add(this->aktualnyGraczTekst);
			this->Controls->Add(this->aktualnyGraczTytul);
			this->Controls->Add(this->pionek_n4);
			this->Controls->Add(this->pionek_n3);
			this->Controls->Add(this->pionek_n2);
			this->Controls->Add(this->pionek_n1);
			this->Controls->Add(this->pionek_zt4);
			this->Controls->Add(this->pionek_zt3);
			this->Controls->Add(this->pionek_zt2);
			this->Controls->Add(this->pionek_zt1);
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
			this->MaximizeBox = false;
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_zt1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_zt2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_zt3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_zt4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_n1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_n2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_n3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pionek_n4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		/*****************************************************************************************************************/
		/****************************************************************************************************************/
		/***************************************************************************************************************/
	private:

		void UstawPolozenieIkonyPionka(System::Windows::Forms::PictureBox^ ikonaPionka, Pole pole);

		void UstawIkonyPionkow();
		void AktualizujIkonyPionkow();

		String^ KolorNaString(KolorGracza kolor);

		void SkanujGracza();



		void Przycisk_kostka_Click(System::Object^ sender, System::EventArgs^ e);

		void Kontrolowa_widoku_Load(System::Object^ sender, System::EventArgs^ e);
		


		/***************************************************************************************************************/
		
		// Obs³uga klikniêæ ikon pionków:
		void pionek_c1_Click(System::Object^ sender, System::EventArgs^ e) { if (plansza->ruchPionka(KolorGracza::czerwony, 1)) SkanujGracza(); }
		void pionek_c2_Click(System::Object^ sender, System::EventArgs^ e) { if (plansza->ruchPionka(KolorGracza::czerwony, 2)) SkanujGracza(); }
		void pionek_c3_Click(System::Object^ sender, System::EventArgs^ e) { if (plansza->ruchPionka(KolorGracza::czerwony, 3)) SkanujGracza(); }
		void pionek_c4_Click(System::Object^ sender, System::EventArgs^ e) { if (plansza->ruchPionka(KolorGracza::czerwony, 4)) SkanujGracza(); }

		void pionek_zi1_Click(System::Object^ sender, System::EventArgs^ e) { if (plansza->ruchPionka(KolorGracza::zielony, 1)) SkanujGracza(); }
		void pionek_zi2_Click(System::Object^ sender, System::EventArgs^ e) { if (plansza->ruchPionka(KolorGracza::zielony, 2)) SkanujGracza(); }
		void pionek_zi3_Click(System::Object^ sender, System::EventArgs^ e) { if (plansza->ruchPionka(KolorGracza::zielony, 3)) SkanujGracza(); }
		void pionek_zi4_Click(System::Object^ sender, System::EventArgs^ e) { if (plansza->ruchPionka(KolorGracza::zielony, 4)) SkanujGracza(); }

		void pionek_zt1_Click(System::Object^ sender, System::EventArgs^ e) { if (plansza->ruchPionka(KolorGracza::zolty, 1)) SkanujGracza(); }
		void pionek_zt2_Click(System::Object^ sender, System::EventArgs^ e) { if (plansza->ruchPionka(KolorGracza::zolty, 2)) SkanujGracza(); }
		void pionek_zt3_Click(System::Object^ sender, System::EventArgs^ e) { if (plansza->ruchPionka(KolorGracza::zolty, 3)) SkanujGracza(); }
		void pionek_zt4_Click(System::Object^ sender, System::EventArgs^ e) { if (plansza->ruchPionka(KolorGracza::zolty, 4)) SkanujGracza(); }

		void pionek_n1_Click(System::Object^ sender, System::EventArgs^ e) { if (plansza->ruchPionka(KolorGracza::niebieski, 1)) SkanujGracza(); }
		void pionek_n2_Click(System::Object^ sender, System::EventArgs^ e) { if (plansza->ruchPionka(KolorGracza::niebieski, 2)) SkanujGracza(); }
		void pionek_n3_Click(System::Object^ sender, System::EventArgs^ e) { if (plansza->ruchPionka(KolorGracza::niebieski, 3)) SkanujGracza(); }
		void pionek_n4_Click(System::Object^ sender, System::EventArgs^ e) { if (plansza->ruchPionka(KolorGracza::niebieski, 4)) SkanujGracza(); }

};
}
