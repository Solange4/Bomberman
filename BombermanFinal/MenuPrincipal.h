#pragma once
#include "Juego.h"

namespace BombermanFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MenuPrincipal
	/// </summary>
	public ref class MenuPrincipal : public System::Windows::Forms::Form
	{
	public:
		MenuPrincipal(void) //Forminicio
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MenuPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::Button^ btnUnJugador;
	private: System::Windows::Forms::Button^ btnDosJugadores;
	protected:


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuPrincipal::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->btnUnJugador = (gcnew System::Windows::Forms::Button());
			this->btnDosJugadores = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(396, 173);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(389, 0);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(341, 535);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(252)), static_cast<System::Int32>(static_cast<System::Byte>(244)),
				static_cast<System::Int32>(static_cast<System::Byte>(163)));
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(478, 299);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(177, 142);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 2;
			this->pictureBox3->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = false;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(252)), static_cast<System::Int32>(static_cast<System::Byte>(244)),
				static_cast<System::Int32>(static_cast<System::Byte>(163)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(524, 299);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(90, 23);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Arriba(W)";
			// 
			// label2
			// 
			this->label2->AutoSize = false;
			this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(252)), static_cast<System::Int32>(static_cast<System::Byte>(244)),
				static_cast<System::Int32>(static_cast<System::Byte>(163)));
			this->label2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Bold));
			this->label2->Location = System::Drawing::Point(432, 345);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(107, 23);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Izquierda(A)";
			// 
			// label3
			// 
			this->label3->AutoSize = false;
			this->label3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(252)), static_cast<System::Int32>(static_cast<System::Byte>(244)),
				static_cast<System::Int32>(static_cast<System::Byte>(163)));
			this->label3->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Bold));
			this->label3->Location = System::Drawing::Point(594, 345);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(98, 23);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Derecha(D)";
			// 
			// label4
			// 
			this->label4->AutoSize = false;
			this->label4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(252)), static_cast<System::Int32>(static_cast<System::Byte>(244)),
				static_cast<System::Int32>(static_cast<System::Byte>(163)));
			this->label4->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Bold));
			this->label4->Location = System::Drawing::Point(536, 418);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(78, 23);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Abajo(S)";
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(-19, 209);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(258, 314);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox4->TabIndex = 7;
			this->pictureBox4->TabStop = false;
			// 
			// btnUnJugador
			// 
			this->btnUnJugador->BackColor = System::Drawing::Color::Red;
			this->btnUnJugador->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnUnJugador->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnUnJugador->ForeColor = System::Drawing::Color::Black;
			this->btnUnJugador->Location = System::Drawing::Point(200, 325);
			this->btnUnJugador->Name = L"btnUnJugador";
			this->btnUnJugador->Size = System::Drawing::Size(183, 43);
			this->btnUnJugador->TabIndex = 1;
			this->btnUnJugador->Text = L"Un Jugador";
			this->btnUnJugador->UseVisualStyleBackColor = false;
			this->btnUnJugador->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnUnJugador_Click);
			// 
			// btnDosJugadores
			// 
			this->btnDosJugadores->BackColor = System::Drawing::Color::Red;
			this->btnDosJugadores->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnDosJugadores->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDosJugadores->ForeColor = System::Drawing::Color::Black;
			this->btnDosJugadores->Location = System::Drawing::Point(200, 398);
			this->btnDosJugadores->Name = L"btnDosJugadores";
			this->btnDosJugadores->Size = System::Drawing::Size(183, 43);
			this->btnDosJugadores->TabIndex = 2;
			this->btnDosJugadores->Text = L"Dos Jugadores";
			this->btnDosJugadores->UseVisualStyleBackColor = false;
			this->btnDosJugadores->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnDosJugadores_Click);
			// 
			// MenuPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(730, 535);
			this->Controls->Add(this->btnDosJugadores);
			this->Controls->Add(this->btnUnJugador);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox2);
			this->MaximumSize = System::Drawing::Size(746, 574);
			this->MinimumSize = System::Drawing::Size(746, 574);
			this->Name = L"MenuPrincipal";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Bomberman";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnUnJugador_Click(System::Object^ sender, System::EventArgs^ e) {
		Juego^ Form1 = gcnew Juego("Jugador1", "", 1);
		this->Hide();  Form1->ShowDialog(); this->Close();

	}
	private: System::Void btnDosJugadores_Click(System::Object^ sender, System::EventArgs^ e) {

		Juego^ Form1 = gcnew Juego("Jugador1", "Jugador2", 2);
		this->Hide();  Form1->ShowDialog(); this->Close();
	}
private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
