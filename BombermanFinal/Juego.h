#pragma once
#include "Controladora.h"

namespace BombermanFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Juego
	/// </summary>
	public ref class Juego : public System::Windows::Forms::Form
	{
	public:

		Bitmap^ Bsolido = gcnew Bitmap("Imagenes\\bmpSolido.png");
		Bitmap^ BDestructible = gcnew Bitmap("Imagenes\\bmpDestruible.png");
		Bitmap^ BBorde = gcnew Bitmap("Imagenes\\bmpSolido.png");
		Bitmap^ BPasto = gcnew Bitmap("Imagenes\\bmpSuelo.png");
		Bitmap^ bmpJugador = gcnew Bitmap("Imagenes\\Jugador.png");
		Bitmap^ BmpDetonar = gcnew Bitmap("Imagenes\\explosion.png");
		Bitmap^ BmpBomba = gcnew Bitmap("Imagenes\\bomba.png");
		Bitmap^ bmpEnemigo = gcnew Bitmap("Imagenes\\bmpEnemigo.png");
		
		CControladora* oJuego;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lblNivel;


	private: System::Windows::Forms::PictureBox^ PBGameOver;
	private: System::Windows::Forms::Label^ lblVidas;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ lblJ2;
	private: System::Windows::Forms::Label^ lblV2;
	private: System::Windows::Forms::Label^ lblJ1;
	private: System::Windows::Forms::Label^ lblV1;
	private: System::Windows::Forms::PictureBox^ pbGanaste;
	public:


	private: System::Windows::Forms::Timer^ timer1;	   
	public:

		Juego(string nom1, string nom2, int njugadores)
		{
			InitializeComponent();
			if (njugadores == 1) {
				oJuego = new CControladora(nom1, nom2, njugadores, 1);
			}
			else {
				oJuego = new CControladora(nom1, nom2, njugadores, 11);
			}
			BmpBomba->MakeTransparent(BmpBomba->GetPixel(0, 0));
			bmpJugador->MakeTransparent(bmpJugador->GetPixel(0, 0));
			bmpEnemigo->MakeTransparent(bmpEnemigo->GetPixel(0, 0));
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Juego()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Juego::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblNivel = (gcnew System::Windows::Forms::Label());
			this->PBGameOver = (gcnew System::Windows::Forms::PictureBox());
			this->lblVidas = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lblJ2 = (gcnew System::Windows::Forms::Label());
			this->lblV2 = (gcnew System::Windows::Forms::Label());
			this->lblJ1 = (gcnew System::Windows::Forms::Label());
			this->lblV1 = (gcnew System::Windows::Forms::Label());
			this->pbGanaste = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PBGameOver))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbGanaste))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Juego::timer1_Tick);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(676, -2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(344, 681);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Elephant", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label1.Image")));
			this->label1->Location = System::Drawing::Point(759, 54);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(121, 49);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Nivel";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblNivel
			// 
			this->lblNivel->Font = (gcnew System::Drawing::Font(L"Elephant", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblNivel->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lblNivel.Image")));
			this->lblNivel->Location = System::Drawing::Point(871, 54);
			this->lblNivel->Name = L"lblNivel";
			this->lblNivel->Size = System::Drawing::Size(67, 49);
			this->lblNivel->TabIndex = 2;
			this->lblNivel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// PBGameOver
			// 
			this->PBGameOver->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PBGameOver.Image")));
			this->PBGameOver->Location = System::Drawing::Point(-2, -11);
			this->PBGameOver->Name = L"PBGameOver";
			this->PBGameOver->Size = System::Drawing::Size(1022, 690);
			this->PBGameOver->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->PBGameOver->TabIndex = 3;
			this->PBGameOver->TabStop = false;
			this->PBGameOver->Visible = false;
			// 
			// lblVidas
			// 
			this->lblVidas->Font = (gcnew System::Drawing::Font(L"Elephant", 102.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblVidas->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lblVidas.Image")));
			this->lblVidas->Location = System::Drawing::Point(725, 233);
			this->lblVidas->Name = L"lblVidas";
			this->lblVidas->Size = System::Drawing::Size(255, 257);
			this->lblVidas->TabIndex = 4;
			this->lblVidas->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblVidas->Visible = false;
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Elephant", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label2.Image")));
			this->label2->Location = System::Drawing::Point(732, 189);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(229, 77);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Vidas";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label2->Visible = false;
			// 
			// lblJ2
			// 
			this->lblJ2->Font = (gcnew System::Drawing::Font(L"Elephant", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblJ2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lblJ2.Image")));
			this->lblJ2->Location = System::Drawing::Point(737, 387);
			this->lblJ2->Name = L"lblJ2";
			this->lblJ2->Size = System::Drawing::Size(229, 77);
			this->lblJ2->TabIndex = 6;
			this->lblJ2->Text = L"Jugador 2:\r\nVidas";
			this->lblJ2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblJ2->Visible = false;
			// 
			// lblV2
			// 
			this->lblV2->Font = (gcnew System::Drawing::Font(L"Elephant", 71.99999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblV2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lblV2.Image")));
			this->lblV2->Location = System::Drawing::Point(753, 450);
			this->lblV2->Name = L"lblV2";
			this->lblV2->Size = System::Drawing::Size(196, 165);
			this->lblV2->TabIndex = 7;
			this->lblV2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblV2->Visible = false;
			// 
			// lblJ1
			// 
			this->lblJ1->Font = (gcnew System::Drawing::Font(L"Elephant", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblJ1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lblJ1.Image")));
			this->lblJ1->Location = System::Drawing::Point(736, 129);
			this->lblJ1->Name = L"lblJ1";
			this->lblJ1->Size = System::Drawing::Size(229, 77);
			this->lblJ1->TabIndex = 8;
			this->lblJ1->Text = L"Jugador 1:\r\nVidas";
			this->lblJ1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblJ1->Visible = false;
			// 
			// lblV1
			// 
			this->lblV1->Font = (gcnew System::Drawing::Font(L"Elephant", 71.99999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblV1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lblV1.Image")));
			this->lblV1->Location = System::Drawing::Point(753, 190);
			this->lblV1->Name = L"lblV1";
			this->lblV1->Size = System::Drawing::Size(196, 165);
			this->lblV1->TabIndex = 9;
			this->lblV1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblV1->Visible = false;
			// 
			// pbGanaste
			// 
			this->pbGanaste->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbGanaste.Image")));
			this->pbGanaste->Location = System::Drawing::Point(-70, -2);
			this->pbGanaste->Name = L"pbGanaste";
			this->pbGanaste->Size = System::Drawing::Size(1126, 681);
			this->pbGanaste->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbGanaste->TabIndex = 10;
			this->pbGanaste->TabStop = false;
			this->pbGanaste->Visible = false;
			// 
			// Juego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1019, 676);
			this->Controls->Add(this->pbGanaste);
			this->Controls->Add(this->lblJ1);
			this->Controls->Add(this->lblJ2);
			this->Controls->Add(this->lblV1);
			this->Controls->Add(this->lblV2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lblVidas);
			this->Controls->Add(this->lblNivel);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->PBGameOver);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"Juego";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Bomberman";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Juego::Juego_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Juego::Juego_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PBGameOver))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbGanaste))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		bool cargado = false; int inicioTimer = 0, inicioTimer2 = 0;

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::Black);

		if (oJuego->Get_NJugadores() == 1) {

			if (oJuego->Get_MapaCargado() == false) { oJuego->Carga_Nivel_UnJugador(); oJuego->Set_MapaCargado(true); }
			oJuego->Dibuja_Nivel(buffer, Bsolido, BDestructible, BBorde, BPasto,bmpJugador,bmpEnemigo);
			if (oJuego->Get_Bomba()->getColocar() == true && oJuego->Get_Bomba()->getContador() != 0) {
				oJuego->Plantar_Bomba(buffer, BmpBomba, BmpDetonar);
				if (inicioTimer != 28) {
					inicioTimer++;
				}
				else {
					oJuego->ColarBomba();
					inicioTimer = 0;
				}
			}
			lblVidas->Visible = true; label2->Visible = true; label2->BringToFront();
			lblNivel->Text = "" + oJuego->Get_Nivel();
			lblVidas->Text = "" + oJuego->Get_Jugador()->Get_Vidas();

			if (oJuego->Get_Jugador()->Get_Vidas() == -1) {
				lblNivel->Visible = false; lblVidas->Visible = false; label1->Visible = false; label2->Visible = false;
				pictureBox1->Visible = false; timer1->Enabled = false;
				PBGameOver->BringToFront(); PBGameOver->Visible = true;
			}

			if (oJuego->Get_Nivel() == 11) {
				pbGanaste->Visible = true; pbGanaste->BringToFront(); timer1->Enabled = false;
			}
		}
		else {
			if (oJuego->Get_MapaCargado() == false) { oJuego->Carga_Nivel_Dos_Jugadores(); oJuego->Set_MapaCargado(true); }
			oJuego->Dibuja_Nivel(buffer, Bsolido, BDestructible, BBorde, BPasto, bmpJugador,bmpEnemigo);

			if (oJuego->Get_Bomba()->getColocar() == true && oJuego->Get_Bomba()->getContador() != 0) {
				oJuego->Plantar_Bomba(buffer, BmpBomba, BmpDetonar);
				if (inicioTimer != 28) {
					inicioTimer++;
				}
				else {
					oJuego->ColarBomba();
					inicioTimer = 0;
				}
			}
			if (oJuego->Get_Bomba2()->getColocar() == true && oJuego->Get_Bomba2()->getContador() != 0) {
				oJuego->Plantar_Bomba2(buffer, BmpBomba, BmpDetonar);
				if (inicioTimer2 != 28) {
					inicioTimer2++;
				}
				else {
					oJuego->ColarBomba2();
					inicioTimer2 = 0;
				}
			}
			lblJ1->Visible = true; lblJ2->Visible = true; lblV1->Visible = true; lblV2->Visible = true;
			lblNivel->Text = "" + (oJuego->Get_Nivel() - 10);
			lblV1->Text = (oJuego->Get_Jugador()->Get_Vidas() == -1) ? "X" : "" + oJuego->Get_Jugador()->Get_Vidas();
			lblV2->Text = (oJuego->Get_Jugador2()->Get_Vidas() == -1) ? "X" : "" + oJuego->Get_Jugador2()->Get_Vidas();

			if (oJuego->Get_Jugador()->Get_Vidas() == -1 && oJuego->Get_Jugador2()->Get_Vidas() == -1) {
				lblNivel->Visible = false; lblVidas->Visible = false; label1->Visible = false; label2->Visible = false;
				pictureBox1->Visible = false; timer1->Enabled = false;
				PBGameOver->BringToFront(); PBGameOver->Visible = true;
			}

			if (oJuego->Get_Nivel() == 21) {
				pbGanaste->Visible = true; pbGanaste->BringToFront(); timer1->Enabled = false;
			}
		}

		buffer->Render(g);
		delete buffer, espacio, g;
	}
	private: System::Void Juego_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::Up:
			oJuego->Get_Jugador()->Direccion = Direcciones::Arriba;
			break;
		case Keys::Down:
			oJuego->Get_Jugador()->Direccion = Direcciones::Abajo;
			break;
		case Keys::Left:
			oJuego->Get_Jugador()->Direccion = Direcciones::Izquierda;
			break;
		case Keys::Right:
			oJuego->Get_Jugador()->Direccion = Direcciones::Derecha;
			break;
		case Keys::Space:
			if (oJuego->Get_Bomba()->getColocar() == false && oJuego->Get_Jugador()->Get_Vidas() != -1) {
				oJuego->Get_Bomba()->setColocar(true);
				oJuego->Get_Bomba()->setX(oJuego->Get_Jugador()->Get_X());
				oJuego->Get_Bomba()->setY(oJuego->Get_Jugador()->Get_Y());
			}
			break;
		case Keys::Q:
			oJuego->Set_Nivel(oJuego->Get_Nivel() + 1); oJuego->Set_MapaCargado(false);
			break;
		}
		if (oJuego->Get_NJugadores() == 2) {
			switch (e->KeyCode)
			{
			case Keys::W:
				oJuego->Get_Jugador2()->Direccion = Direcciones::Arriba;
				break;
			case Keys::S:
				oJuego->Get_Jugador2()->Direccion = Direcciones::Abajo;
				break;
			case Keys::A:
				oJuego->Get_Jugador2()->Direccion = Direcciones::Izquierda;
				break;
			case Keys::D:
				oJuego->Get_Jugador2()->Direccion = Direcciones::Derecha;
				break;
			case Keys::F:
				if (oJuego->Get_Bomba2()->getColocar() == false && oJuego->Get_Jugador2()->Get_Vidas() != -1) {
					oJuego->Get_Bomba2()->setColocar(true);
					oJuego->Get_Bomba2()->setX(oJuego->Get_Jugador2()->Get_X());
					oJuego->Get_Bomba2()->setY(oJuego->Get_Jugador2()->Get_Y());
				}
				break;
			}
		}
	}
	private: System::Void Juego_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		oJuego->Get_Jugador()->Direccion = Direcciones::Ninguna;
		oJuego->Get_Jugador2()->Direccion = Direcciones::Ninguna;
	}
};
}
