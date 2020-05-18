//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <stdlib.h>
#include "string"
#include <math.h>
#include "Main.h"
#include "MyFigure.h"
#include "Circle.h"
#include "Polygon.h"
#define pi 3.14
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
class Circle circle;
class Polygon polygon;
class Circle *Circ = NULL;
class Polygon *Pol = NULL;
int kol=0,vert=-1,FigureX[100],FigureY[100];
double angle = 0, main_a = 0, cur_a = 0;
bool a = false, b = false, move = false;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender) //перерисовка пол€
{
	Image1->Canvas->Rectangle(0, 0, 1000, 1000);
    Timer1->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ClearAllClick(TObject *Sender)  // очистка пол€
{
	Image1->Canvas->Rectangle(0, 0, 1000, 1000);
    Circ = NULL;
    Pol = NULL;
    kol = 0;
    ListBox1->Items->Clear();
    ListBox2->Items->Clear();
    ListBox3->Items->Clear();
    ListBox4->Items->Clear();
    Vertex->Clear();
    Angle->Clear();
    Side->Clear();
    Radius->Clear();
	move = false;
    vert = -1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RightPolygonClick(TObject *Sender) //вобор построени€ типа "правильный многоугольник"
{
    a = true;
    b = false;
    Side->Clear();
    Vertex->Clear();
    Radius->Clear();
    ListBox1->Items->Clear();
    ListBox2->Items->Clear();
    ListBox3->Items->Clear();
    ListBox4->Items->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CircleClick(TObject *Sender) // выбор построени€ типа "круг"
{
    b = true;
    a = false;
    Side->Clear();
    Vertex->Clear();
    Radius->Clear();
    ListBox1->Items->Clear();
    ListBox2->Items->Clear();
    ListBox3->Items->Clear();
    ListBox4->Items->Clear();
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    if (a == true) //если строитс€ многоугольник
    {
        int number;
        int rad;
		number = StrToInt(Vertex->Text); // количество вершин
		rad = StrToInt(Side->Text); //длина
        if (number >= 1)
        {
			Image1->Canvas->Rectangle(0, 0, 1000, 1000);
            Circ = NULL;
            class Polygon x(Image1, number, rad);
            polygon.copy(x);
            Pol = &polygon;
            ListBox1->Items->Clear(); ListBox1->Items->Add(Pol->Perimeter());
            ListBox2->Items->Clear(); ListBox2->Items->Add(Pol->Square());
            ListBox3->Items->Clear(); ListBox3->Items->Add(Pol->centreX);
			ListBox4->Items->Clear(); ListBox4->Items->Add(Pol->centreY);
			Image1->Canvas->Ellipse((Pol->centreX) - 8,(Pol->centreY) - 8,(Pol->centreX) + 8,(Pol->centreY) + 8);
		}
    }
	else if (b == true)  //если строитс€ круг
    {
		int rad;
		rad = StrToInt(Radius->Text);// радиус
		Image1->Canvas->Rectangle(0,0,1000,1000);
		class Circle x(Image1, rad);
		Pol = NULL;
		circle.copy(x);
        Circ = &circle;
        ListBox1->Items->Clear(); ListBox1->Items->Add(Circ->Perimeter());
        ListBox2->Items->Clear(); ListBox2->Items->Add(Circ->Square());
        ListBox3->Items->Clear(); ListBox3->Items->Add(Circ->centreX);
        ListBox4->Items->Clear(); ListBox4->Items->Add(Circ->centreY);
        Image1->Canvas->Ellipse((Circ->centreX) - 8,(Circ->centreY) - 8,(Circ->centreX) + 8,(Circ->centreY) + 8);
    }
}

//---------------------------------------------------------------------------
bool isIn(int a,int b,int x,int y)
{
    return ((abs(a-x) <= 8) && (abs(b-y) <= 8));
}

void __fastcall TForm1::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int x, int y)
{
	if (Circ != NULL) // если на поле построен круг
    {
        if (isIn(x,y,Circ->centreX,Circ->centreY))//обработка нажати€ на центр масс
        {
            move = true;
            vert = -1;
        }
        else if (move == true)//перемещение центра круга
        {
            Circ->centreX += x-Circ->centreX;
            Circ->centreY += y-Circ->centreY;
            Circ->draw(Image1);
            ListBox1->Items->Clear(); ListBox1->Items->Add(Circ->Perimeter());
            ListBox2->Items->Clear(); ListBox2->Items->Add(Circ->Square());
            ListBox3->Items->Clear(); ListBox3->Items->Add(Circ->centreX);
            ListBox4->Items->Clear(); ListBox4->Items->Add(Circ->centreY);
            Image1->Canvas->Ellipse((Circ->centreX) - 8,(Circ->centreY) - 8,(Circ->centreX) + 8,(Circ->centreY) + 8);
            move = false;
            vert = -1;
        }
    }
    else if (Pol != NULL) // если на поле построен многоугольник
    {
        if (isIn(x,y,Pol->centreX,Pol->centreY)) //обработка нажати€ на центр масс
        {
            move = true;
            vert = -1;
        }
		else if (move == true) // ѕеремещение центра многоугольника
        {
            for (int i = 0; i < Pol->vertex; i++)
			{
				Pol->X[i] += x-Pol->centreX;
				Pol->Y[i] += y-Pol->centreY;
			}
			ListBox3->Items->Clear(); ListBox3->Items->Add(Pol->Xcentre());
			ListBox4->Items->Clear(); ListBox4->Items->Add(Pol->Ycentre());
			Pol->draw(Image1,Pol->vertex);
			Image1->Canvas->Ellipse((Pol->centreX) - 8,(Pol->centreY) - 8,(Pol->centreX) + 8,(Pol->centreY) + 8);
            move = false;
            vert = -1;
        }
        else if (vert >= 0) //перемещение вершины, где vert - ее номер
        {
			Pol->X[vert] = x;
            Pol->Y[vert] = y;
            Pol->draw(Image1,(Pol->vertex));
            ListBox1->Items->Clear(); ListBox1->Items->Add(Pol->Perimeter());
            ListBox2->Items->Clear(); ListBox2->Items->Add(Pol->Square());
            ListBox3->Items->Clear(); ListBox3->Items->Add(Pol->Xcentre());
            ListBox4->Items->Clear(); ListBox4->Items->Add(Pol->Ycentre());
            Image1->Canvas->Ellipse((Pol->centreX) - 8,(Pol->centreY) - 8,(Pol->centreX) + 8,(Pol->centreY) + 8);
            vert = -1;
        }
        else  //ѕоиск нажатой вершины
        {
            for (int i = 0; i < Pol->vertex; i++)
            {
                if (isIn(x,y,Pol->X[i],Pol->Y[i]))
                {
                    vert = i;
                    break;
                }
            }
        }
    }
    else //если на поле строитс€ произвольна€ фигура
    {
		if ((kol == 0) || (!isIn(x,y,FigureX[0],FigureY[0]))) //ƒобавление новой точки произвольной фигуры
		{
			FigureX[kol] = x;//добавление в массив вершин
            FigureY[kol] = y;
            Image1->Canvas->Ellipse(FigureX[kol] - 8,FigureY[kol] - 8,FigureX[kol] + 8,FigureY[kol] + 8);
            kol++;
        }
		else if ((kol > 0) && (isIn(x,y,FigureX[0],FigureY[0]))) //замыкание произвольной фигуры
        {
			class Polygon x(kol);//создание класса пр€моугольник из производной фигуры
			for (int i = 0; i < kol; i++)
            {
                x.X[i] = FigureX[i];
                x.Y[i] = FigureY[i];
            }
            polygon.copy(x);
            Pol = &polygon;
            Pol->draw(Image1, kol);
            ListBox1->Items->Clear();ListBox1->Items->Add(Pol->Perimeter());
            ListBox2->Items->Clear();ListBox2->Items->Add(Pol->Square());
            ListBox3->Items->Clear();ListBox3->Items->Add(Pol->Xcentre());
            ListBox4->Items->Clear();ListBox4->Items->Add(Pol->Ycentre());
            Image1->Canvas->Ellipse((Pol->centreX) - 8,(Pol->centreY) - 8,(Pol->centreX) + 8,(Pol->centreY) + 8);
        }
    }
}

void __fastcall TForm1::Button2Click(TObject *Sender) //поворот
{
    main_a = 0;
    angle = 0;
	cur_a = 0;
	main_a = StrToInt(Angle->Text);//введенный угол
	angle = main_a/10; //промежуточный угол
    Form1->Timer2->Enabled = True;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseWheelUp(TObject *Sender, TShiftState Shift, TPoint &MousePos,
        bool &Handled)
{
	int x = 1; //увеличение радиуса дл€ круга
	double k = 1.1; //коэффициент раст€жени€ (увеличени€) дл€ многоугольника
    if (Circ != NULL)
    {
        Circ->r += x;
        Circ->draw(Image1);
	}
    else if (Pol != NULL)
    {
        for(int i = 0; i < Pol->vertex; i++)
        {
            Pol->X[i] = (Pol->X[i]-Pol->centreX) * k + Pol->centreX;
            Pol->Y[i] = (Pol->Y[i]-Pol->centreY) * k + Pol->centreY;
        }
		Pol->draw(Image1,Pol->vertex);
		Image1->Canvas->Ellipse((Pol->centreX) - 8,(Pol->centreY) - 8,(Pol->centreX) + 8,(Pol->centreY) + 8);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormMouseWheelDown(TObject *Sender, TShiftState Shift, TPoint &MousePos,
        bool &Handled)
{
	int x = 1; //уменьшение радиуса дл€ круга
    double k = 0.9;//коэффициент сужени€(уменьшени€) дл€ многоугольника
    if (Circ != NULL)
    {
        Circ->r -= x;
        Circ->draw(Image1);
    }
    else if (Pol != NULL)
    {
        for (int i = 0; i < Pol->vertex; i++)
        {
            Pol->X[i] = (Pol->X[i]-Pol->centreX) * k + Pol->centreX;
            Pol->Y[i] = (Pol->Y[i]-Pol->centreY) * k + Pol->centreY;
        }
		Pol->draw(Image1, Pol->vertex);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
    cur_a += angle;
    if (Pol != NULL)
    {
        for (int i = 0; i < Pol->vertex; i++)
		{
			Pol->X[i] = (Pol->X[i] - Pol->centreX) * cos((angle/180)*pi) - (Pol->Y[i] - Pol->centreY) * sin((angle/180)*pi) + Pol->centreX;
			Pol->Y[i] = (Pol->X[i] - Pol->centreX) * sin((angle/180)*pi) + (Pol->Y[i] - Pol->centreY) * cos((angle/180)*pi) + Pol->centreY;
		}
		Pol->centreX = Pol->Xcentre();
		Pol->centreY = Pol->Ycentre();
		ListBox3->Items->Clear(); ListBox3->Items->Add(Pol->centreX);
		ListBox4->Items->Clear(); ListBox4->Items->Add(Pol->centreY);
        Pol->draw(Image1,Pol->vertex);
        Image1->Canvas->Ellipse((Pol->centreX) - 8,(Pol->centreY) - 8,(Pol->centreX) + 8,(Pol->centreY) + 8);
    }
    if (abs(cur_a - main_a) < 2)
        Form1->Timer2->Enabled = False;
}
//---------------------------------------------------------------------------
