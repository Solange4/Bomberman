#pragma once
using namespace System::Drawing;

class CEnemigo
{
private:

	int xM;
	int yM;
	int x;
	int y;
	int dx;
	int dy;
	int dxM;
	int dyM;
	int contador;
	bool muerto;
	//Animacion
	int indiceX;
	int indiceY;
	int Ancho;
	int Alto;

public:

	CEnemigo(int xM, int yM);
	~CEnemigo();

	int Get_xM();
	int Get_yM();
	int Get_x();
	int Get_y();
	int Get_dx();
	int Get_dy();
	bool Get_Muerto();

	void Set_xM(int value);
	void Set_yM(int value);
	void Set_x(int value);
	void Set_y(int value);
	void Set_dx(int value);
	void Set_dy(int value);
	void Set_Muerto(bool value);

	void Mover(int** matriz);
	void Dibujar(BufferedGraphics^ buffer, int** matriz, Bitmap^ bmpEnemigo);
};

