#include "Bomba.h"

CBomba::CBomba() {
	x = 0;
	y = 0;
	colocar = false;
	Indicex = 0;
	contador = 1;
	derecha = 1;
	izquierda = 1;
	arriba = 1;
	abajo = 1;
	IndiceY_E = 3;
}

CBomba::~CBomba() {

}

void CBomba::Bomba(BufferedGraphics^ Buffer, Bitmap^ BmpBomba, Bitmap^ BmpDetonar, int** Mapa, CEscenario* oEscenario, CJugador* oJugador, CJugador* oJugador2) {
	int Ancho = 59;
	int Alto = 100;
	System::Drawing::Rectangle Porcion = System::Drawing::Rectangle(Ancho * Indicex + 3, 0, Ancho, Alto);
	System::Drawing::Rectangle Aumento = System::Drawing::Rectangle(x + 3, y - 15, Ancho * 0.7, Alto * 0.7);
	Buffer->Graphics->DrawImage(BmpBomba, Aumento, Porcion, System::Drawing::GraphicsUnit::Pixel);

	Indicex++;
	contador++;
	if (Indicex >= 3) {
		Indicex = 1;
	}
	if (contador >= 30) {
		Indicex = 0; colocar = false; contador = 0; contador++;

		Colision_B(Buffer, BmpDetonar, Mapa, 0, 0, 0, 0, 32, 32, x, y, 0, oEscenario, oJugador, oJugador2);
		Colision_B(Buffer, BmpDetonar, Mapa, 0, 0, 0, 0, 32, 32, x + 45, y, 5, oEscenario, oJugador, oJugador2);
		Colision_B(Buffer, BmpDetonar, Mapa, 0, 0, 0, 0, 32, 32, x - 45, y, 6, oEscenario, oJugador, oJugador2);
		Colision_B(Buffer, BmpDetonar, Mapa, 0, 0, 0, 0, 32, 32, x, y + 45, 4, oEscenario, oJugador, oJugador2);
		Colision_B(Buffer, BmpDetonar, Mapa, 0, 0, 0, 0, 32, 32, x, y - 45, 3, oEscenario, oJugador, oJugador2);

		/*Colision_P(Buffer, BmpDetonar, Mapa, 0, 0, 0, 0, 32, 32, x, y, 0, oEscenario, oJugador, oJugador2);
		Colision_P(Buffer, BmpDetonar, Mapa, 0, 0, 0, 0, 32, 32, x + 45, y, 5, oEscenario, oJugador, oJugador2);
		Colision_P(Buffer, BmpDetonar, Mapa, 0, 0, 0, 0, 32, 32, x - 45, y, 6, oEscenario, oJugador, oJugador2);
		Colision_P(Buffer, BmpDetonar, Mapa, 0, 0, 0, 0, 32, 32, x, y + 45, 4, oEscenario, oJugador, oJugador2);
		Colision_P(Buffer, BmpDetonar, Mapa, 0, 0, 0, 0, 32, 32, x, y - 45, 3, oEscenario, oJugador, oJugador2);*/

		return;
	}

}

void CBomba::Colision_B(BufferedGraphics^ Buffer, Bitmap^ BmpDetonar, int** Mapa, int i, int j, int X, int Y, int Ancho, int Alto, int x,
	int y, int IndiceX_E, CEscenario* oEscenario, CJugador* oJugador, CJugador* oJugador2) {
	Random rand;
	if (i >= 15) { return; }
	else
	{
		if (j < 15) {
			System::Drawing::Rectangle  Jugador1 = System::Drawing::Rectangle(x, y, (Ancho - 17), (Alto - 20));
			Buffer->Graphics->FillRectangle(System::Drawing::Brushes::Transparent, Jugador1);

			System::Drawing::Rectangle  Rec1 = System::Drawing::Rectangle(X, Y, 45, 45);

			if (Mapa[i][j] == 0) {

				if (Jugador1.IntersectsWith(Rec1)) {
					System::Drawing::Rectangle Porcion = System::Drawing::Rectangle(Ancho * IndiceX_E, 0, Ancho, Alto);
					System::Drawing::Rectangle Aumento = System::Drawing::Rectangle(x, y, 45, 45);
					Buffer->Graphics->DrawImage(BmpDetonar, Aumento, Porcion, System::Drawing::GraphicsUnit::Pixel);

					if (oEscenario->Get_Enemigo(j, i) != NULL) {
						oEscenario->Get_Enemigo(j, i)->Set_Muerto(true);
					}

					if (oJugador != NULL) {
						if (oJugador->Get_xM() == j && oJugador->Get_yM() == i) {
							if (oJugador->Get_Vidas() == 0) { oJugador->Set_Vidas(-1); }
							else { oJugador->Respawn(); }
						}
					}
					if (oJugador2 != NULL) {
						if (oJugador2->Get_xM() == j && oJugador2->Get_yM() == i) {
							if (oJugador2->Get_Vidas() == 0) { oJugador2->Set_Vidas(-1); }
							else { oJugador2->Respawn(); }
						}
					}

				}
			}

			if (Mapa[i][j] == 3) {

				if (Jugador1.IntersectsWith(Rec1)) {

					System::Drawing::Rectangle Porcion = System::Drawing::Rectangle(Ancho * IndiceX_E, 0, Ancho, Alto);
					System::Drawing::Rectangle Aumento = System::Drawing::Rectangle(x, y, 45, 45);
					Buffer->Graphics->DrawImage(BmpDetonar, Aumento, Porcion, System::Drawing::GraphicsUnit::Pixel);

					if (oEscenario->Get_Poder(j, i) != NULL) {
						if (oEscenario->Get_Poder(j, i)->Get_Tipo() == 1)
						{
							Mapa[oEscenario->Get_Poder(j, i)->Get_Y()][oEscenario->Get_Poder(j, i)->Get_X()] = 10;
						}
						else if (oEscenario->Get_Poder(j, i)->Get_Tipo() == 2)
						{
							Mapa[oEscenario->Get_Poder(j, i)->Get_Y()][oEscenario->Get_Poder(j, i)->Get_X()] = 11;
						}
						else if (oEscenario->Get_Poder(j, i)->Get_Tipo() == 3)
						{
							Mapa[oEscenario->Get_Poder(j, i)->Get_Y()][oEscenario->Get_Poder(j, i)->Get_X()] = 12;
						}
					}
					else if (oEscenario->Get_XSalida() == j && oEscenario->Get_YSalida() == i) {
						Mapa[i][j] = 5;
					}
					else {
						Mapa[i][j] = 0;
					}
				}
			}

			Colision_B(Buffer, BmpDetonar, Mapa, i, j + 1, X + 45, Y, Ancho, Alto, x, y, IndiceX_E, oEscenario, oJugador, oJugador2);
		}
		else
		{
			Colision_B(Buffer, BmpDetonar, Mapa, i + 1, 0, 0, Y + 45, Ancho, Alto, x, y, IndiceX_E, oEscenario, oJugador, oJugador2);
		}
	}

}

/*void CBomba::Colision_P(BufferedGraphics^ Buffer, Bitmap^ BmpDetonar, int** Mapa, int i, int j, int X, int Y, int Ancho, int Alto, int x,
	int y, int IndiceX_E, CEscenario* oEscenario, CJugador* oJugador, CJugador* oJugador2) {
	Random rand;
	if (i >= 15) { return; }
	else
	{
		if (j < 15) {
			System::Drawing::Rectangle  Jugador1 = System::Drawing::Rectangle(x, y, (Ancho - 17), (Alto - 20));
			Buffer->Graphics->FillRectangle(System::Drawing::Brushes::Transparent, Jugador1);

			System::Drawing::Rectangle  Rec1 = System::Drawing::Rectangle(X, Y, 675, 675);
			Buffer->Graphics->FillRectangle(System::Drawing::Brushes::Pink, Rec1);

			if (Mapa[i][j] == 10 || Mapa[i][j] == 11 || Mapa[i][j] == 12) {

				if (Jugador1.IntersectsWith(Rec1)) {
					System::Drawing::Rectangle Porcion = System::Drawing::Rectangle(Ancho * IndiceX_E, 0, Ancho, Alto);
					System::Drawing::Rectangle Aumento = System::Drawing::Rectangle(x, y, 45, 45);
					Buffer->Graphics->DrawImage(BmpDetonar, Aumento, Porcion, System::Drawing::GraphicsUnit::Pixel);
					Mapa[i][j] = 0;
				}
			}

			Colision_B(Buffer, BmpDetonar, Mapa, i, j + 1, X + 45, Y, Ancho, Alto, x, y, IndiceX_E, oEscenario, oJugador, oJugador2);
		}
		else
		{
			Colision_B(Buffer, BmpDetonar, Mapa, i + 1, 0, 0, Y + 45, Ancho, Alto, x, y, IndiceX_E, oEscenario, oJugador, oJugador2);
		}
	}

}*/