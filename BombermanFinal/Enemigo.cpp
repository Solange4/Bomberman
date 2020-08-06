#include "Enemigo.h"

CEnemigo::CEnemigo(int xM, int yM)
{
	this->xM = xM;
	this->yM = yM;
	x = xM * 45;
	y = yM * 45;
	dx = 45;
	dy = 45;
	dxM = 1;
	dyM = 1;
	contador = 0;
	muerto = false;

	indiceX=0;
	indiceY=0;
	this->Ancho = 96 / 6;
	this->Alto = 16;
}



CEnemigo::~CEnemigo()
{
}

int CEnemigo::Get_xM() { return xM; }
int CEnemigo::Get_yM() { return yM; }
int CEnemigo::Get_x() { return x; }
int CEnemigo::Get_y() { return y; }
int CEnemigo::Get_dx() { return dx; }
int CEnemigo::Get_dy() { return dy; }
bool CEnemigo::Get_Muerto() { return muerto; }

void CEnemigo::Set_xM(int value) { xM = value; }
void CEnemigo::Set_yM(int value) { yM = value; }
void CEnemigo::Set_x(int value) { x = value; }
void CEnemigo::Set_y(int value) { y = value; }
void CEnemigo::Set_dx(int value) { dx = value; }
void CEnemigo::Set_dy(int value) { dy = value; }
void CEnemigo::Set_Muerto(bool value) { muerto = value; }

void CEnemigo::Dibujar(BufferedGraphics^ buffer, int** matriz, Bitmap^ bmpEnemigo) {

	if (muerto == false) {
		Rectangle PorcionAUsar = Rectangle(indiceX * Ancho, indiceY * Alto, Alto, Ancho);
		Rectangle Aumento = Rectangle(x, y, 45, 45);
		buffer->Graphics->DrawImage(bmpEnemigo, Aumento, PorcionAUsar, GraphicsUnit::Pixel);
		Mover(matriz);
		contador++;
	}
}

void CEnemigo::Mover(int** matriz) {

	if (indiceX >= 0 && indiceX < 5) {
		indiceX++;
	}
	if (indiceX == 5) {
		while (indiceX != 0) {
			indiceX--;
		}
	}

	if ((matriz[yM][xM + 1] == 2 || matriz[yM][xM + 1] == 3 || matriz[yM][xM + 1] == 1) && (matriz[yM][xM - 1] == 2 || matriz[yM][xM - 1] == 3 || matriz[yM][xM - 1] == 1)) {
		dx = 0; dxM = 0;
	}
	else if (dxM == 0 && dx == 0) {
		dx = 45; dxM = 1;
	}

	if (dxM != 0 && dx != 0 && (matriz[yM][xM + 1] == 2 || matriz[yM][xM + 1] == 3 || matriz[yM][xM + 1] == 1)) {
		dx = -45; dxM = -1;
	}
	else if (dxM != 0 && dx != 0 && (matriz[yM][xM - 1] == 2 || matriz[yM][xM - 1] == 3 || matriz[yM][xM - 1] == 1)) {
		dx = 45; dxM = 1;
	}


	if (contador == 8) {
		x += dx; xM += dxM; contador = 0;
	}

}
