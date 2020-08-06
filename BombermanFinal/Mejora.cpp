#include "Mejora.h"

CMejora::CMejora(int type, int x, int y)
{
	this->xM = x;
	this->yM = y;
	this->Tipo = type;
}

CMejora::~CMejora()
{

}
int CMejora::Get_Tipo() {
	return Tipo;
}
int CMejora::Get_X() { return xM; }
int CMejora::Get_Y() { return yM; }
void CMejora::Poder_Muerte(CJugador* oJugador) {
	if (oJugador->Get_Vidas() == 0) { oJugador->Set_Vidas(-1); }
	else {
		oJugador->Respawn();
	}
}
void CMejora::Poder_Bloques(CJugador* oJugador) {
	oJugador->Set_Bloques(true);
}

void CMejora::Poder_Corazon(CJugador* oJugador) {
	oJugador->Set_Vidas(oJugador->Get_Vidas() + 1);
}
