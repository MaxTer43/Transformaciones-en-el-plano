#pragma once
#include "CVecObjeto.h"


namespace Project3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	int Tiempo;

	double X, Y;
	int dX, dY;
	int AnchoF, LargoF;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		CVecObjeto* objVecObjeto;
		Graphics^ g;





		Bitmap ^imagen;
		Bitmap ^fondo;
		Bitmap ^imagen2;





	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1; BufferedGraphics^buffer;
	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1134, 661);
			this->Name = L"MyForm";
			this->Text = L"Transformaciones";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseClick);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) 
	
	{
		Random r;

		imagen = gcnew Bitmap("upc_logo.png");
		fondo = gcnew Bitmap("upc_fondo.png");
		imagen2 = gcnew Bitmap("upc_logo2.png");

		X = r.Next(200, 550);
		Y = r.Next(200, 400);

		dX = r.Next(-1, 1);
		dY = r.Next(-1, 1);

		do {
			dX = r.Next(-1, 1);
			dY = r.Next(-1, 1);
		} while (dX == 0 || dY == 0);

		Tiempo = 100;
		objVecObjeto = new CVecObjeto();
		g = this->CreateGraphics();
		BufferedGraphicsContext^ context =
			BufferedGraphicsManager::Current;
		buffer = context->Allocate(g, this->ClientRectangle);
		objVecObjeto->Agregar_Objeto(TypeObjeto::Fondo, X, Y, dX, dY);
		objVecObjeto->Agregar_Objeto(TypeObjeto::Rectangulo, X, Y, dX, dY);
		objVecObjeto->Agregar_Objeto(TypeObjeto::Obstaculo1, X, Y, dX, dY);
		objVecObjeto->Agregar_Objeto(TypeObjeto::Obstaculo2, X, Y, dX, dY);
		objVecObjeto->Agregar_Objeto(TypeObjeto::Obstaculo3, X, Y, dX, dY);
		objVecObjeto->Agregar_Objeto(TypeObjeto::Obstaculo4, X, Y, dX, dY);
		objVecObjeto->Agregar_Objeto(TypeObjeto::Logo_UPC, X, Y, dX, dY);
	
	
	}


	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		buffer->Graphics->Clear(Color::Black);

		Tiempo -= 1;

		if (Tiempo <= 0)
		{
			Tiempo = 100;
		}
		if (Tiempo > 50)
		{
			objVecObjeto->Dibujar(buffer->Graphics, imagen, fondo);
		}
		if (Tiempo <= 50)
		{
			objVecObjeto->Dibujar(buffer->Graphics, imagen2, fondo);
		}


		objVecObjeto->Mover(g, this->ClientRectangle.Width,
			this->ClientRectangle.Height, dX, dY);
		buffer->Render(g);
		
	}
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		if (e->KeyData == Keys::C)
		{
			Random r;
			X = r.Next(280, 600);
			Y = r.Next(280, 400);

			dX = r.Next(-1, 1);
			dY = r.Next(-1, 1);

			do {
				dX = r.Next(-1, 1);
				dY = r.Next(-1, 1);
			} while (dX == 0 || dY == 0);
			objVecObjeto->Agregar_Objeto(TypeObjeto::Logo_UPC, X, Y, dX, dY);

		}
	}


private: System::Void MyForm_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	int Pos = objVecObjeto->Buscar_Objeto(e->X, e->Y);

	if (Pos != -1)
	{
		objVecObjeto->Eliminar_Objeto(Pos);
	}


}

};
}
