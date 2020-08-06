#include "Escenario.h"

CEscenario::CEscenario()
{
	Ancho = 15;
	Alto = 15;
}

CEscenario::~CEscenario()
{
}

void CEscenario::Leer_Mapa_unJugador(int** mapa, int n, CJugador* oJ) {

	ifstream fn;

	for (int i = 0; i < Poderes.size(); ++i) {
		delete Poderes[i];
	}
	for (int i = 0; i < Enemigos.size(); ++i) {
		delete Enemigos[i];
	}
	Poderes.clear(); Enemigos.clear();

	switch (n)
	{
	case 1:
		fn.open("Escenarios\\Mapa1.txt"); break;
	case 2:
		fn.open("Escenarios\\Mapa2.txt"); break;
	case 3:
		fn.open("Escenarios\\Mapa3.txt"); break;
	case 4:
		fn.open("Escenarios\\Mapa4.txt"); break;
	case 5:
		fn.open("Escenarios\\Mapa5.txt"); break;
	case 6:
		fn.open("Escenarios\\Mapa6.txt"); break;
	case 7:
		fn.open("Escenarios\\Mapa7.txt"); break;
	case 8:
		fn.open("Escenarios\\Mapa8.txt"); break;
	case 9:
		fn.open("Escenarios\\Mapa9.txt"); break;
	case 10:
		fn.open("Escenarios\\Mapa10.txt"); break;
	}

	string linea, aux;

	//Lee Matriz
	for (int i = 0; i < Alto; ++i) {

		getline(fn, linea);
		stringstream ss(linea);
		for (int j = 0; j < Ancho; ++j) {
			getline(ss, aux, ',');
			mapa[i][j] = atoi(aux.c_str());
		}
	}

	if (n < 11) {
		//Lee Enemigos
		getline(fn, aux); Numero_Enemigos = atoi(aux.c_str());
		for (int i = 0; i < Numero_Enemigos; ++i) {
			int xtemp, ytemp;
			getline(fn, linea); stringstream ss(linea);
			getline(ss, aux, ','); xtemp = atoi(aux.c_str());
			getline(ss, aux, ','); ytemp = atoi(aux.c_str());
			Enemigos.push_back(new CEnemigo(xtemp, ytemp));
		}
	}

	//Lee Poderes
	getline(fn, aux); Numero_Poderes = atoi(aux.c_str());
	for (int i = 0; i < Numero_Poderes; ++i) {
		int xtemp, ytemp, tipotemp;
		getline(fn, linea); stringstream ss(linea);
		getline(ss, aux, ','); tipotemp = atoi(aux.c_str());
		getline(ss, aux, ','); xtemp = atoi(aux.c_str());
		getline(ss, aux, ','); ytemp = atoi(aux.c_str());
		Poderes.push_back(new CMejora(tipotemp, xtemp, ytemp));
	}

	getline(fn, linea); stringstream ss1(linea);
	getline(ss1, aux, ','); xSalida = atoi(aux.c_str());
	getline(ss1, aux, ','); ySalida = atoi(aux.c_str());

	getline(fn, linea); stringstream ss2(linea);
	getline(ss2, aux, ','); oJ->Set_xM(atoi(aux.c_str()));
	getline(ss2, aux, ','); oJ->Set_yM(atoi(aux.c_str()));
	getline(ss2, aux, ','); oJ->Set_X(atoi(aux.c_str()));
	getline(ss2, aux, ','); oJ->Set_Y(atoi(aux.c_str()));

	fn.close();
}
void CEscenario::Leer_Mapa_DosJugadores(int** mapa, int n, CJugador* oJ1, CJugador* oJ2) {

	ifstream fn;

	for (int i = 0; i < Poderes.size(); ++i) {
		delete Poderes[i];
	}
	for (int i = 0; i < Enemigos.size(); ++i) {
		delete Enemigos[i];
	}
	Poderes.clear(); Enemigos.clear();

	switch (n)
	{
	case 11:
		fn.open("Escenarios\\Mapa11.txt"); break;
	case 12:
		fn.open("Escenarios\\Mapa12.txt"); break;
	case 13:
		fn.open("Escenarios\\Mapa13.txt"); break;
	case 14:
		fn.open("Escenarios\\Mapa14.txt"); break;
	case 15:
		fn.open("Escenarios\\Mapa15.txt"); break;
	case 16:
		fn.open("Escenarios\\Mapa16.txt"); break;
	case 17:
		fn.open("Escenarios\\Mapa17.txt"); break;
	case 18:
		fn.open("Escenarios\\Mapa18.txt"); break;
	case 19:
		fn.open("Escenarios\\Mapa19.txt"); break;
	case 20:
		fn.open("Escenarios\\Mapa20.txt"); break;
	}

	string linea, aux;

	//Lee Matriz
	for (int i = 0; i < Alto; ++i) {

		getline(fn, linea);
		stringstream ss(linea);
		for (int j = 0; j < Ancho; ++j) {
			getline(ss, aux, ',');
			mapa[i][j] = atoi(aux.c_str());
		}
	}

	//Lee Enemigos
	getline(fn, aux); Numero_Enemigos = atoi(aux.c_str());
	for (int i = 0; i < Numero_Enemigos; ++i) {
		int xtemp, ytemp;
		getline(fn, linea); stringstream ss(linea);
		getline(ss, aux, ','); xtemp = atoi(aux.c_str());
		getline(ss, aux, ','); ytemp = atoi(aux.c_str());
		Enemigos.push_back(new CEnemigo(xtemp, ytemp));
	}

	//Lee Poderes
	getline(fn, aux); Numero_Poderes = atoi(aux.c_str());
	for (int i = 0; i < Numero_Poderes; ++i) {
		int xtemp, ytemp, tipotemp;
		getline(fn, linea); stringstream ss(linea);
		getline(ss, aux, ','); tipotemp = atoi(aux.c_str());
		getline(ss, aux, ','); xtemp = atoi(aux.c_str());
		getline(ss, aux, ','); ytemp = atoi(aux.c_str());
		Poderes.push_back(new CMejora(tipotemp, xtemp, ytemp));
	}

	getline(fn, linea); stringstream ss1(linea);
	getline(ss1, aux, ','); xSalida = atoi(aux.c_str());
	getline(ss1, aux, ','); ySalida = atoi(aux.c_str());

	getline(fn, linea); stringstream ss2(linea);
	getline(ss2, aux, ','); oJ1->Set_xM(atoi(aux.c_str()));
	getline(ss2, aux, ','); oJ1->Set_yM(atoi(aux.c_str()));
	getline(ss2, aux, ','); oJ1->Set_X(atoi(aux.c_str()));
	getline(ss2, aux, ','); oJ1->Set_Y(atoi(aux.c_str()));

	getline(fn, linea); stringstream ss3(linea);
	getline(ss3, aux, ','); oJ2->Set_xM(atoi(aux.c_str()));
	getline(ss3, aux, ','); oJ2->Set_yM(atoi(aux.c_str()));
	getline(ss3, aux, ','); oJ2->Set_X(atoi(aux.c_str()));
	getline(ss3, aux, ','); oJ2->Set_Y(atoi(aux.c_str()));

	fn.close();
}
void CEscenario::Dibujar_Mapa(int** mapa, BufferedGraphics^ buffer, Bitmap^ Bsolido, Bitmap^ BDestructible, Bitmap^ BBorde, Bitmap^ BPasto) {

	int xForm = 0; int yForm = 0;
	for (int i = 0; i < Alto; ++i) {
		for (int j = 0; j < Ancho; ++j) {

			if (mapa[i][j] == 0) { buffer->Graphics->DrawImage(BPasto, xForm, yForm, 45, 45); }
			else if (mapa[i][j] == 1) { buffer->Graphics->DrawImage(BBorde, xForm, yForm, 45, 45); }
			else if (mapa[i][j] == 2) { buffer->Graphics->DrawImage(Bsolido, xForm, yForm, 45, 45); }
			else if (mapa[i][j] == 3) { buffer->Graphics->DrawImage(BDestructible, xForm, yForm, 45, 45); }
			else if (mapa[i][j] == 5) { buffer->Graphics->DrawImage(Image::FromFile("Imagenes\\Salida.png"), xForm, yForm, 45, 45); }
			else if (mapa[i][j] == 10) { buffer->Graphics->DrawImage(Image::FromFile("Imagenes\\Poder_Muerte.png"), xForm, yForm, 45, 45); }
			else if (mapa[i][j] == 11) { buffer->Graphics->DrawImage(Image::FromFile("Imagenes\\Poder_Corazon.png"), xForm, yForm, 45, 45); }
			else if (mapa[i][j] == 12) { buffer->Graphics->DrawImage(Image::FromFile("Imagenes\\Poder_Bloques.png"), xForm, yForm, 45, 45); }
			xForm += 45;
		}
		yForm += 45;
		xForm = 0;
	}
}
int CEscenario::Get_NEnemigos() { return Numero_Enemigos; }
int CEscenario::Get_NPoderes() { return Numero_Poderes; }
vector<CEnemigo*> CEscenario::Get_Enemigos() { return Enemigos; }
vector<CMejora*> CEscenario::Get_Poderes() { return Poderes; }
int CEscenario::Get_XSalida() { return xSalida; }
int CEscenario::Get_YSalida() { return ySalida; }
CMejora* CEscenario::Get_Poder(int xM, int yM) {

	for (int i = 0; i < Poderes.size(); ++i) {
		if (Poderes[i]->Get_X() == xM && Poderes[i]->Get_Y() == yM) {
			return Poderes[i];
		}
	}
	return NULL;
}
CEnemigo* CEscenario::Get_Enemigo(int xM, int yM) {

	for (int i = 0; i < Enemigos.size(); ++i) {
		if (Enemigos[i]->Get_xM() == xM && Enemigos[i]->Get_yM() == yM) {
			if (Enemigos[i]->Get_Muerto() == false) {
				return Enemigos[i];
			}
		}
	}
	return NULL;
}
