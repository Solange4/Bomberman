#pragma once
#include <string>
#include "Jugador.h"

using namespace System::Drawing;
using namespace std;

class CMejora 
{
private:
	int xM;
	int yM;
	int Tipo;

public:
	CMejora(int tipo, int x, int y);
	~CMejora();
	int Get_Tipo();
	int Get_X();
	int Get_Y();
	void Poder_Muerte(CJugador* oJugador);
	void Poder_Bloques(CJugador* oJugador);
	void Poder_Corazon(CJugador* oJugador);
};