#pragma once
#include "Escenario.h"
using namespace System::Drawing;
using namespace std;
using namespace System;


class CBomba
{
public:
	//Tamaño
	int x;
	int y;
	//Validacion
	bool colocar;
	//Posicion
	int Indicex;
	//Explosion
	int contador;
	//Dibujar la exposion
	int derecha;
	int izquierda;
	int arriba;
	int abajo;
	int IndiceY_E;

public:
	CBomba();
	~CBomba();
	bool setColocar(bool colocar) { return(this->colocar = colocar); }
	int setX(int x) { return(this->x = x); }
	int setY(int y) { return(this->y = y); }
	bool getColocar() { return colocar; }
	int setcontador(int contador) { return(this->contador = contador); }
	int getContador() { return contador; }
	void Bomba(BufferedGraphics^ Buffer, Bitmap^ BmpBomba, Bitmap^ BmpDetonar, int** Mapa, CEscenario* oEscenario, CJugador* oJugador, CJugador* oJugador2);
	void Colision_B(BufferedGraphics^ Buffer, Bitmap^ BmpDetonar, int** Mapa, int i, int j, int X, int Y, int Ancho,
		int Alto, int x, int y, int IndiceX, CEscenario* oEscenario, CJugador* oJugador, CJugador* oJugador2);
};

