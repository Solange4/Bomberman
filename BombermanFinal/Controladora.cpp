#include "Controladora.h"


CControladora::CControladora(string Nombre, string Nombre2, int num, int nivel)
{
	oJugador = new CJugador(45, 45, Nombre);
	oEscenario = new CEscenario();
	Matriz = new int* [15];
	for (int i = 0; i < 15; ++i) {
		Matriz[i] = new int[15];
	}
	for (int i = 0; i < 3; i++) {
		oBomba.push(new CBomba());
		oBomba2.push(new CBomba());
	}
	Nivel = nivel;
	MapaCargado = false;
	oJugador2 = new CJugador(45, 45, Nombre2);
	NJugadores = num;
}

CControladora::~CControladora()
{
}

int CControladora::Get_Nivel() { return Nivel; }
void CControladora::Set_Nivel(int value) { Nivel = value; }
CEscenario* CControladora::Get_Mapa() { return oEscenario; }
CJugador* CControladora::Get_Jugador() { return oJugador; }
CJugador* CControladora::Get_Jugador2() { return oJugador2; }
int CControladora::Get_NJugadores() { return NJugadores; }
bool CControladora::Carga_Nivel_UnJugador() {
	if (Nivel <= 10) {
		Get_Bomba()->setcontador(1); Get_Bomba()->setColocar(false);
		oEscenario->Leer_Mapa_unJugador(Matriz, Nivel, oJugador);
		return true;
	}
	return false;
}
bool CControladora::Carga_Nivel_Dos_Jugadores() {
	if (Nivel <= 20) {
		Get_Bomba()->setcontador(1); Get_Bomba()->setColocar(false);
		Get_Bomba2()->setcontador(1); Get_Bomba2()->setColocar(false);
		oEscenario->Leer_Mapa_DosJugadores(Matriz, Nivel, oJugador, oJugador2);
		return true;
	}
	return false;
}
void CControladora::Dibuja_Nivel(BufferedGraphics^ buffer, Bitmap^ Bsolido, Bitmap^ BDestructible, Bitmap^ BBorde, Bitmap^ BPasto, Bitmap^bmpJugador, Bitmap^bmpEnemigo) {
	oEscenario->Dibujar_Mapa(Matriz, buffer, Bsolido, BDestructible, BBorde, BPasto);
	Dibujar_Enemigos(buffer,bmpEnemigo);
	if (NJugadores == 1) {
		Colision_Enemigo_Jugador(oJugador); RecogePoderes(oJugador);
		oJugador->Mover(buffer,bmpJugador, Matriz, MapaCargado, Nivel);
	}
	else {
		if (oJugador->Get_Vidas() != -1) {
			Colision_Enemigo_Jugador(oJugador); RecogePoderes(oJugador);
			oJugador->Mover(buffer, bmpJugador, Matriz, MapaCargado, Nivel);
		}
		if (oJugador2->Get_Vidas() != -1) {
			Colision_Enemigo_Jugador(oJugador2); RecogePoderes(oJugador2);
			oJugador2->Mover(buffer, bmpJugador, Matriz, MapaCargado, Nivel);
		}
	}

}
void CControladora::Plantar_Bomba(BufferedGraphics^ buffer, Bitmap^ bmp1, Bitmap^ bmp2) {

	if (!oBomba.empty()) {
		CBomba* bombaFront = oBomba.front();
		if (NJugadores == 1) {
			bombaFront->Bomba(buffer, bmp1, bmp2, Matriz, oEscenario, oJugador, NULL);
		}
		else {
			bombaFront->Bomba(buffer, bmp1, bmp2, Matriz, oEscenario, oJugador, oJugador2);
		}
	}
}
CBomba* CControladora::Get_Bomba() {
	return oBomba.front();
}
void CControladora::Plantar_Bomba2(BufferedGraphics^ buffer, Bitmap^ bmp1, Bitmap^ bmp2) {

	if (!oBomba2.empty()) {
		CBomba* bombaFront = oBomba2.front();
		bombaFront->Bomba(buffer, bmp1, bmp2, Matriz, oEscenario, oJugador2, oJugador);
	}
}
CBomba* CControladora::Get_Bomba2() {
	return oBomba2.front();
}
bool CControladora::Get_MapaCargado() { return MapaCargado; }
void CControladora::Set_MapaCargado(bool value) { MapaCargado = value; }
void CControladora::Dibujar_Enemigos(BufferedGraphics^ buffer, Bitmap^bmpEnemigo) {
	for (int i = 0; i < oEscenario->Get_NEnemigos(); ++i) {
		oEscenario->Get_Enemigos()[i]->Dibujar(buffer, Matriz,bmpEnemigo);
	}
}
void CControladora::Colision_Enemigo_Jugador(CJugador* oJ) {

	int xMaux = oJ->Get_xM(), yMaux = oJ->Get_yM();
	if (oEscenario->Get_Enemigo(xMaux, yMaux) != NULL) {
		if (oJ->Get_Vidas() == 0) { oJ->Set_Vidas(-1); }
		else { oJ->Respawn(); }
	}
}
void CControladora::RecogePoderes(CJugador* oJ) {
	if (Matriz[oJ->Get_yM()][oJ->Get_xM()] == 10) {
		Matriz[oJ->Get_yM()][oJ->Get_xM()] = 0;
		oEscenario->Get_Poder(oJ->Get_xM(), oJ->Get_yM())->Poder_Muerte(oJ);
	}
	else if (Matriz[oJ->Get_yM()][oJ->Get_xM()] == 11) {
		Matriz[oJ->Get_yM()][oJ->Get_xM()] = 0;
		oEscenario->Get_Poder(oJ->Get_xM(), oJ->Get_yM())->Poder_Corazon(oJ);
	}
	else if (Matriz[oJ->Get_yM()][oJ->Get_xM()] == 12) {
		Matriz[oJ->Get_yM()][oJ->Get_xM()] = 0;
		oEscenario->Get_Poder(oJ->Get_xM(), oJ->Get_yM())->Poder_Bloques(oJ);
	}
}
void CControladora::ColarBomba() {
	oBomba.pop();
	if (oBomba.size() == 0) {
		oBomba.push(new CBomba());
		oBomba.push(new CBomba());
		oBomba.push(new CBomba());
	}
}
void CControladora::ColarBomba2() {
	oBomba2.pop();
	if (oBomba2.size() == 0) {
		oBomba2.push(new CBomba());
		oBomba2.push(new CBomba());
		oBomba2.push(new CBomba());
	}
}