#pragma once

#include "CObjeto.h"
#include <vector>

using namespace std;

enum TypeObjeto { Logo_UPC, Rectangulo, Obstaculo1, Obstaculo2, Obstaculo3, Obstaculo4, Fondo };

class CVecObjeto
{
private:
	vector<CObjeto *>* arrObjeto;
	CObjeto *objObjeto;
public:
	CVecObjeto();
	~CVecObjeto();
	void Agregar_Objeto(TypeObjeto TipoObjeto, int X, int Y, int dX, int dY);
	void Dibujar(Graphics^ g, Bitmap ^imagen, Bitmap ^fondo);
	void Mover(Graphics^ g, int AnchoF, int LargoF, int dX, int dY);
	void Eliminar_Objeto(int Pos);
	int Buscar_Objeto(int X, int Y);
	bool HayColision(int X, int Y);
};

CVecObjeto::CVecObjeto()
{
	arrObjeto = new vector<CObjeto *>();
}

CVecObjeto::~CVecObjeto()
{
}

void CVecObjeto::Agregar_Objeto(TypeObjeto TipoObjeto, int X, int Y, int dX, int dY)
{
	Random^ r = gcnew Random((int)DateTime::Now.Ticks);
	//double X = X;
	//double Y = Y;
	double Ancho;
	double Largo;
	do {
		dX = r->Next(-1, 1);
		dY = dY;
	} while (dX == 0 || dY == 0);


	int R = r->Next(255);
	int G = r->Next(255);
	int B = r->Next(255);

	CObjeto* objObjeto;

	if (TipoObjeto == TypeObjeto::Logo_UPC)
		objObjeto = new CLogo_UPC(X, Y, Ancho, Largo, dX, dY, R, G, B);
	else if (TipoObjeto == TypeObjeto::Rectangulo)
		objObjeto = new CRectangulo(100, 150, 550, 300, 0, 0, 200, 200, 200);
	else if (TipoObjeto == TypeObjeto::Obstaculo1)
		objObjeto = new CObstaculo1(160, 210, 40, 40, 0, 0, 70, 200, 200);
	else if (TipoObjeto == TypeObjeto::Obstaculo2)
		objObjeto = new CObstaculo2(160, 210, 40, 40, 0, 0, 70, 200, 200);
	else if (TipoObjeto == TypeObjeto::Obstaculo3)
		objObjeto = new CObstaculo3(160, 210, 40, 40, 0, 0, 70, 200, 200);
	else if (TipoObjeto == TypeObjeto::Obstaculo4)
		objObjeto = new CObstaculo4(160, 210, 40, 40, 0, 0, 70, 200, 200);
	else if (TipoObjeto == TypeObjeto::Fondo)
		objObjeto = new CFondo(160, 210, 40, 40, 0, 0, 70, 200, 200);

	arrObjeto->push_back(objObjeto);
}

void CVecObjeto::Dibujar(Graphics^ g, Bitmap ^imagen, Bitmap ^fondo)
{
	for (int i = 0; i < arrObjeto->size(); i++)
		arrObjeto->at(i)->Dibujar(g, imagen, fondo);
}

void CVecObjeto::Mover(Graphics^ g, int AnchoF, int LargoF, int dX, int dY)
{
	for (int i = 0; i < arrObjeto->size(); i++)
		arrObjeto->at(i)->Mover(g, AnchoF, LargoF, dX, dY);
}

void CVecObjeto::Eliminar_Objeto(int Pos)
{
	arrObjeto->erase(arrObjeto->begin() + Pos);
}

int CVecObjeto::Buscar_Objeto(int X, int Y)
{
	for (int i = 0; i < arrObjeto->size(); i++)
		if (arrObjeto->at(i)->HayColision(X, Y))
			return i;

	return -1;
}

bool CVecObjeto::HayColision(int X, int Y)
{
	for (int i = 0; i < arrObjeto->size(); i++)
		if (arrObjeto->at(i)->HayColision(X, Y))
			return true;

	return false;
}