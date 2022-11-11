#pragma once
#include "math.h"

using namespace System;
using namespace System::Drawing;

class CObjeto // CLASE PADRE
{
protected:

	double X, Y;

	int dX, dY;

	double XI, XII, XIII, XIV;
	double YI, YII, YIII, YIV;

	int XR, XRA, YR, YRL;

	double Ancho, Largo;

	double AnchoR, LargoR;

	double OAncho, OLargo;

	double AnchoN, LargoN;

	int R, G, B;
	int N;
	int Objeto;

	double KX, KY;

	double XINICIAL, YINICIAL;

	double teta;

	double decision;

	int colision;
	int homotecia;

	double velocidadX;
	double velocidadY;

	int primera;

	

public:
	int getdX(int dX);
	CObjeto();
	CObjeto(double X, double Y, double Ancho, double Largo, int dX, int dY, int R, int G, int B);
	~CObjeto();
	virtual void Dibujar(Graphics^ g, Bitmap ^imagen, Bitmap ^fondo) {};
	void Mover(Graphics^ g, double AnchoF, double LargoF, int dX, int dY);
	bool HayColision(int pX, int pY);
};

CObjeto::CObjeto()
{
}

CObjeto::CObjeto(double X, double Y, double Ancho, double Largo, int dX, int dY, int R, int G, int B)
{
	Random r;
	this->X = X;

	this->Y = Y;

	this->Ancho = Ancho;
	this->Largo = Largo;

	this->AnchoR = 0;
	this->LargoR = 0;


	this->dX = r.Next(-1, 2);
	this->dY = r.Next(-1, 2);
	this->R = R;
	this->G = G;
	this->B = B;
	this->Objeto = 0;

	this->teta = 0;
	this->decision = 0;

	this->colision = 0;

	this->XR = 100;
	this->YR = 150;
	this->XRA = 900;
	this->YRL = 400;

	this->XI = 200;
	this->YI = 270;

	this->XII = 800;
	this->YII = 270;

	this->XIII = 200;
	this->YIII = 420;

	this->XIV = 800;
	this->YIV = 420;

	this->OAncho = 60;
	this->OLargo = 30;

	this->XINICIAL = X;
	this->YINICIAL = Y;
	this->KX = X / XINICIAL;
	this->KY = Y / YINICIAL;

	this->primera = 1;

	this->velocidadX = dX;
	this->velocidadY = dY;
	this->AnchoN = 0;
	this->LargoN = 0;
}

CObjeto::~CObjeto()
{
}

void CObjeto::Mover(Graphics^ g, double AnchoF, double LargoF, int dXX, int dYY)
{
	Random r;

	if (dX == 0)
	{
		dX = r.Next(-1, 1);
	}
	if (dY == 0)
	{
		dY = r.Next(-1, 1);
	}
	

	if (X + velocidadX < XR || X + Ancho + velocidadX > XR + XRA)
	{

		if (X + velocidadX <= XR)
		{
			dX = 1;
			X = XR;
		}
		if (X + Ancho + velocidadX >= XRA + XR)
		{
			dX = -1;
			X = XRA + XR - Ancho;
		}

		
		colision = 1;
		

	}
	if (Y + velocidadY < YR || Y + Largo + velocidadY > YR + YRL)
	{

		

		if (Y + velocidadY < YR)
		{
			dY = 1;
			Y = YR;
		}
		if (Y + Largo + velocidadY > YR+YRL)
		{
			dY = -1;
			Y = YR+YRL - Largo;
		}
		colision = 1;
		
	}

	//OBSTACULO 1

	if (X + Ancho + velocidadX >= XI && X + velocidadX <= XI + OAncho
		&& Y + Largo + velocidadY >= YI && Y + velocidadY <= YI + OLargo)
	{
		//Choque vertical
		if (Y + Largo + velocidadY >= YI && Y + velocidadY <= YI + OLargo)
		{
			//Chocar arriba
			if (velocidadY > 0 && Y <= YI)
			{
				dY = -1;
				Y = YI - Largo;
			}
			//Chocar abajo
			if (velocidadY < 0 && Y >= YI + OLargo)
			{
				dY = 1;
				Y = YI + OLargo;
			}
		}

		//Choque horizontal
		if (X + Ancho + velocidadX >= XI && X + velocidadX <= XI + OAncho)
		{
			//Chocar izquierda
			if (velocidadX > 0 && X <= XI)
			{
				dX = -1;
				X = XI - Ancho;
			}
			//Chocar derecha
			if (velocidadX < 0 && X >= XI + OAncho)
			{
				dX = 1;
				X = XI + OAncho;
			}

		}
		colision = 1;
	}



	if (colision == 1)
	{
		decision = r.Next(0, 3);
		if (decision == 1)
		{
				XINICIAL = X;
				YINICIAL = Y;
		}
		colision = 0;
	}

	//OBSTACULO 1

	if (X + Ancho + velocidadX >= XII && X + velocidadX <= XII + OAncho
		&& Y + Largo + velocidadY >= YII && Y + velocidadY <= YII + OLargo)
	{
		//Choque vertical
		if (Y + Largo + velocidadY >= YII && Y + velocidadY <= YII + OLargo)
		{
			//Chocar arriba
			if (velocidadY > 0 && Y <= YII)
			{
				dY = -1;
				Y = YII - Largo;
			}
			//Chocar abajo
			if (velocidadY < 0 && Y >= YII + OLargo)
			{
				dY = 1;
				Y = YII + OLargo;
			}
		}

		//Choque horizontal
		if (X + Ancho + velocidadX >= XII && X + velocidadX <= XII + OAncho)
		{
			//Chocar izquierda
			if (velocidadX > 0 && X <= XII)
			{
				dX = -1;
				X = XII - Ancho;
			}
			//Chocar derecha
			if (velocidadX < 0 && X >= XII + OAncho)
			{
				dX = 1;
				X = XII + OAncho;
			}

		}
		colision = 1;
	}

	//OBSTACULO 3

	if (X + Ancho + velocidadX >= XIII && X + velocidadX <= XIII + OAncho
		&& Y + Largo + velocidadY >= YIII && Y + velocidadY <= YIII + OLargo)
	{
		//Choque vertical
		if (Y + Largo + velocidadY >= YIII && Y + velocidadY <= YIII + OLargo)
		{
			//Chocar arriba
			if (velocidadY > 0 && Y <= YIII)
			{
				dY = -1;
				Y = YIII - Largo;
			}
			//Chocar abajo
			if (velocidadY < 0 && Y >= YIII + OLargo)
			{
				dY = 1;
				Y = YIII + OLargo;
			}
		}

		//Choque horizontal
		if (X + Ancho + velocidadX >= XIII && X + velocidadX <= XIII + OAncho)
		{
			//Chocar izquierda
			if (velocidadX > 0 && X <= XIII)
			{
				dX = -1;
				X = XIII - Ancho;
			}
			//Chocar derecha
			if (velocidadX < 0 && X >= XIII + OAncho)
			{
				dX = 1;
				X = XIII + OAncho;
			}

		}
		colision = 1;
	}

	//OBSTACULO 4

	if (X + Ancho + velocidadX >= XIV && X + velocidadX <= XIV + OAncho
		&& Y + Largo + velocidadY >= YIV && Y + velocidadY <= YIV + OLargo)
	{
		//Choque vertical
		if (Y + Largo + velocidadY >= YIV && Y + velocidadY <= YIV + OLargo)
		{
			//Chocar arriba
			if (velocidadY > 0 && Y <= YIV)
			{
				dY = -1;
				Y = YIV - Largo;
			}
			//Chocar abajo
			if (velocidadY < 0 && Y >= YIV + OLargo)
			{
				dY = 1;
				Y = YIV + OLargo;
			}
		}

		//Choque horizontal
		if (X + Ancho + velocidadX >= XIV && X + velocidadX <= XIV + OAncho)
		{
			//Chocar izquierda
			if (velocidadX > 0 && X <= XIV)
			{
				dX = -1;
				X = XIV - Ancho;
			}
			//Chocar derecha
			if (velocidadX < 0 && X >= XIV + OAncho)
			{
				dX = 1;
				X = XIV + OAncho;
			}

		}
		colision = 1;
	}

	//HOMOTECIA
	if (decision == 1)
	{

		if (X >= XINICIAL)
		{
			KX = X / XINICIAL;
			Ancho = (25 * KX);
			Largo = (25 * KX);
		}
		else
		{
			KX = XINICIAL/X;
			Ancho = (25 * KX)*-1;
			Largo = (25 * KX) * -1;
		}

		X = X + dX;
		Y = Y + dY;

		velocidadX = dX;
		velocidadY = dY;

	}

	//ROTACION
	if (decision == 2)
	{
		//x' = xcos(θ) - ysin(θ)
		//y' = xsin(θ) + ycos(θ)

		X += dX * cos(teta) - dY * sin(teta);
		Y += dX * sin(teta) + dY * cos(teta);

		Ancho = 23;
		Largo = 23;

		velocidadX = dX * cos(teta) - dY * sin(teta);
		velocidadY = dX * sin(teta) + dY * cos(teta);
	}

	//TRASLACION
	if (decision == 0||decision == 3)
	{
		Ancho = 23;
		Largo = 23;
		//		   →
		//A' = A + U

		X = X + dX;
		Y = Y + dY;

		velocidadX = dX;
		velocidadY = dY;
	}

	if (Ancho < 0)
	{
		AnchoR = Ancho;
	}
	if (Ancho >= 0)
	{
		AnchoR = 0;
	}
	if (Largo < 0)
	{
		LargoR = Largo;
	}
	if (Largo >= 0)
	{
		LargoR = 0;
	}

	if (teta < 360)
	{
		teta += 0.005;
	}

	if (teta >= 360)
	{
		teta = 0;
	}
	if (Ancho < 0)
	{
		AnchoN = Ancho;
	}
	else
	{
		AnchoN = 0;
	}

	if (Largo < 0)
	{
		LargoN = Largo;
	}
	else
	{
		LargoN = 0;
	}

}



bool CObjeto::HayColision(int pX, int pY)
{
	return pX >= X && pX <= X + Ancho &&
		pY >= Y && pY <= Y + Largo;
}

int CObjeto::getdX( int dX)
{
	return dX;
}
class CLogo_UPC : public CObjeto // CLASE HIJA
{
private:
public:
	CLogo_UPC();
	CLogo_UPC(double X, double Y, double Ancho, double Largo, int dX, int dY, int R, int G, int B);
	~CLogo_UPC();
	void Dibujar(Graphics^ g, Bitmap^ imagen, Bitmap ^fondo);
};

CLogo_UPC::CLogo_UPC()
{
}

CLogo_UPC::CLogo_UPC(double X, double Y, double Ancho, double Largo, int dX, int dY, int R, int G, int B) :
	CObjeto(X, Y, Ancho, Largo, dX, dY, R, G, B)
{
}

CLogo_UPC::~CLogo_UPC()
{
}

void CLogo_UPC::Dibujar(Graphics^ g, Bitmap^ imagen, Bitmap ^fondo)
{
		g->DrawImage(imagen, (int)X, Y, Ancho, Largo);
}

class CRectangulo : public CObjeto // CLASE HIJA
{
private:
public:
	CRectangulo();
	CRectangulo(int X, int Y, int Ancho, int Largo, int dX, int dY, int R, int G, int B);
	~CRectangulo();
	void Dibujar(Graphics^ g, Bitmap ^imagen, Bitmap ^fondo);
};

CRectangulo::CRectangulo()
{
}

CRectangulo::CRectangulo(int X, int Y, int Ancho, int Largo, int dX, int dY, int R, int G, int B) :
	CObjeto(X, Y, Ancho, Largo, dX, dY, R, G, B)
{
}

CRectangulo::~CRectangulo()
{
}

void CRectangulo::Dibujar(Graphics^ g, Bitmap ^imagen, Bitmap ^fondo)
{
	SolidBrush^ objSolidBrush = gcnew SolidBrush(Color::FromArgb(200, 200, 200));
	g->FillRectangle(objSolidBrush, XR, YR, XRA, YRL);
}

class CObstaculo1 : public CObjeto // CLASE HIJA
{
private:
public:
	CObstaculo1();
	CObstaculo1(int X, int Y, int Ancho, int Largo, int dX, int dY, int R, int G, int B);
	~CObstaculo1();
	void Dibujar(Graphics^ g, Bitmap ^imagen, Bitmap ^fondo);
};

CObstaculo1::CObstaculo1()
{
}

CObstaculo1::CObstaculo1(int X, int Y, int Ancho, int Largo, int dX, int dY, int R, int G, int B) :
	CObjeto(X, Y, Ancho, Largo, dX, dY, R, G, B)
{
}

CObstaculo1::~CObstaculo1()
{
}

void CObstaculo1::Dibujar(Graphics^ g, Bitmap ^imagen, Bitmap ^fondo)
{
	SolidBrush^ objSolidBrush = gcnew SolidBrush(Color::FromArgb(70, 200, 200));
	g->FillRectangle(objSolidBrush, (int)XI, YI, OAncho, OLargo);
}

class CObstaculo2 : public CObjeto // CLASE HIJA
{
private:
public:
	CObstaculo2();
	CObstaculo2(int X, int Y, int Ancho, int Largo, int dX, int dY, int R, int G, int B);
	~CObstaculo2();
	void Dibujar(Graphics^ g, Bitmap ^imagen, Bitmap ^fondo);
};

CObstaculo2::CObstaculo2()
{
}

CObstaculo2::CObstaculo2(int X, int Y, int Ancho, int Largo, int dX, int dY, int R, int G, int B) :
	CObjeto(X, Y, Ancho, Largo, dX, dY, R, G, B)
{
}

CObstaculo2::~CObstaculo2()
{
}

void CObstaculo2::Dibujar(Graphics^ g, Bitmap ^imagen, Bitmap ^fondo)
{
	SolidBrush^ objSolidBrush = gcnew SolidBrush(Color::FromArgb(200, 70, 200));
	g->FillRectangle(objSolidBrush, (int)XII, YII, OAncho, OLargo);
}

class CObstaculo3 : public CObjeto // CLASE HIJA
{
private:
public:
	CObstaculo3();
	CObstaculo3(int X, int Y, int Ancho, int Largo, int dX, int dY, int R, int G, int B);
	~CObstaculo3();
	void Dibujar(Graphics^ g, Bitmap ^imagen, Bitmap ^fondo);
};

CObstaculo3::CObstaculo3()
{
}

CObstaculo3::CObstaculo3(int X, int Y, int Ancho, int Largo, int dX, int dY, int R, int G, int B) :
	CObjeto(X, Y, Ancho, Largo, dX, dY, R, G, B)
{
}

CObstaculo3::~CObstaculo3()
{
}

void CObstaculo3::Dibujar(Graphics^ g, Bitmap ^imagen, Bitmap ^fondo)
{
	SolidBrush^ objSolidBrush = gcnew SolidBrush(Color::FromArgb(70, 120, 100));
	g->FillRectangle(objSolidBrush, (int)XIII, YIII, OAncho, OLargo);
}

class CObstaculo4 : public CObjeto // CLASE HIJA
{
private:
public:
	CObstaculo4();
	CObstaculo4(int X, int Y, int Ancho, int Largo, int dX, int dY, int R, int G, int B);
	~CObstaculo4();
	void Dibujar(Graphics^ g, Bitmap ^imagen, Bitmap ^fondo);
};

CObstaculo4::CObstaculo4()
{
}

CObstaculo4::CObstaculo4(int X, int Y, int Ancho, int Largo, int dX, int dY, int R, int G, int B) :
	CObjeto(X, Y, Ancho, Largo, dX, dY, R, G, B)
{
}

CObstaculo4::~CObstaculo4()
{
}

void CObstaculo4::Dibujar(Graphics^ g, Bitmap ^imagen, Bitmap ^fondo)
{
	SolidBrush^ objSolidBrush = gcnew SolidBrush(Color::FromArgb(120, 100, 200));
	g->FillRectangle(objSolidBrush, (int)XIV, YIV, OAncho, OLargo);
}



class CFondo : public CObjeto // CLASE HIJA
{
private:
public:
	CFondo();
	CFondo(int X, int Y, int Ancho, int Largo, int dX, int dY, int R, int G, int B);
	~CFondo();
	void Dibujar(Graphics^ g, Bitmap ^imagen, Bitmap ^fondo);
};

CFondo::CFondo()
{
}

CFondo::CFondo(int X, int Y, int Ancho, int Largo, int dX, int dY, int R, int G, int B) :
	CObjeto(X, Y, Ancho, Largo, dX, dY, R, G, B)
{
}

CFondo::~CFondo()
{
}

void CFondo::Dibujar(Graphics^ g, Bitmap ^imagen, Bitmap ^fondo)
{
	g->DrawImage(fondo, 0, 0, 1200, 1000);
}