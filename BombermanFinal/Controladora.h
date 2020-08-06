#pragma once
#include "Enemigo.h"
#include "Escenario.h"
#include "Jugador.h"
#include "Bomba.h"
#include <string>
#include <queue>

using namespace std;
using namespace System::Drawing;

class CControladora
{
private:

	CJugador* oJugador;
	CJugador* oJugador2;
	CEscenario* oEscenario;
	queue <CBomba*> oBomba;
	queue <CBomba*> oBomba2;
	int** Matriz;
	int Nivel;
	bool MapaCargado;
	int NJugadores;

public:

	CControladora(string Nombre, string Nombre2, int num, int nivel);
	~CControladora();
	int Get_Nivel();
	void Set_Nivel(int value);
	CEscenario* Get_Mapa();
	CJugador* Get_Jugador();
	CJugador* Get_Jugador2();
	bool Carga_Nivel_UnJugador();
	bool Carga_Nivel_Dos_Jugadores();
	int Get_NJugadores();
	void Dibuja_Nivel(BufferedGraphics^ buffer, Bitmap^ Bsolido, Bitmap^ BDestructible, Bitmap^ BBorde, Bitmap^ BPasto, Bitmap^ bmpJugador, Bitmap^ bmpEnemigo);
	void Plantar_Bomba(BufferedGraphics^ buffer, Bitmap^ bmp1, Bitmap^ bmp2);
	CBomba* Get_Bomba();
	void Plantar_Bomba2(BufferedGraphics^ buffer, Bitmap^ bmp1, Bitmap^ bmp2);
	CBomba* Get_Bomba2();
	bool Get_MapaCargado();
	void Set_MapaCargado(bool value);
	void Dibujar_Enemigos(BufferedGraphics^ buffer, Bitmap^bmpEnemigo);
	void Colision_Enemigo_Jugador(CJugador* oJ);
	void RecogePoderes(CJugador* oJ);
	void ColarBomba();
	void ColarBomba2();
};

