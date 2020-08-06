#pragma once
#include <string>

enum Direcciones { Ninguna, Arriba, Abajo, Izquierda, Derecha };
using namespace System::Drawing;
using namespace std;


class CJugador
{
	int Vidas;
	string Nombre;
	int Numero_Bombas;
	int Items;
	int Poder;
	//Posiones del jugador
	int x;
	int y;
	//Posiciones iniciales
	int xMInicio; 
	int yMInicio;
	//Movimiento del Jugador
	int dx; 
	int dy;
	int Velocidad;
	int Ancho;
	int Alto;
	//Animacion
	int indiceX;
	int indiceY;
	
	int xM;
	int yM;
	bool Bloques;
	
	Direcciones Ultima;

public:
	Direcciones Direccion;
	CJugador(int x, int y, string Nickname);
	~CJugador();
	void Dibujar(BufferedGraphics^ buffer,Bitmap^bmpJugador);
	void Mover(BufferedGraphics^ buffer, Bitmap^ bmpJugador, int** matriz, bool& cargado, int& nivel);
	int Get_X();
	int Get_Y();
	void Set_X(int x);
	void Set_Y(int y);
	int Get_xM();
	int Get_yM();
	void Set_xM(int xM);
	void Set_yM(int yM);
	bool Get_Bloques();
	void Set_Bloques(bool value);
	int Get_Vidas();
	void Set_Vidas(int value);
	void Set_NBombas(int bombas);
	int Get_NBombas();
	void Set_Velocidad(int velocidad);
	int Get_Velocidad();
	void Respawn();
};

