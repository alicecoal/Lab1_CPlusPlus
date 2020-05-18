//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Car.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

class Rect
{
	public:
	int xl;
	int yl;
	int xr;
    int yr;
	void Move(int horizontal,int vertical){
		xl += horizontal;
		xr += horizontal;
		yl += vertical;
		yr += vertical;
	}
	void draw(){
		Form2->Canvas->Brush->Color = clOlive;
		Form2->Canvas->Pen->Color = clBlack;
		Form2->Canvas->Rectangle(xl, yl, xr, yr);
	}
	void erase(){
		Form2->Canvas->Brush->Color = clOlive;
		Form2->Canvas->Pen->Color = clOlive;
		Form2->Canvas->Rectangle(xl,yl,xr,yr);
	}
};

class Door: public Rect{
public:
	Door(int x1,int y1, int x2,int y2)
	{
		xl = x1;
		yl = y1;
		xr = x2;
		yr = y2;
	}
};

Door *door = new Door(320,280,410,400);
int DoorIsOpen = 0, k = 0; //��������� �������� �����
int light = 0; //��������� ����� ���

void __fastcall TForm2::FormPaint(TObject *Sender)//���������� ������� ������
{
		Form2->Canvas->Brush->Color = clWhite;
		Form2->Canvas->FloodFill(0,0,clBlack,fsBorder);
		Form2->Canvas->MoveTo(400,200);
		Form2->Canvas->LineTo(240,280);
		Form2->Canvas->LineTo(80,320);
		Form2->Canvas->Rectangle(80,320,120,360);
		Form2->Canvas->LineTo(80,400);
		Form2->Canvas->LineTo(140,400);
		Form2->Canvas->Ellipse(140,340,260,460);
		Form2->Canvas->Ellipse(160,360,240,440);
		Form2->Canvas->MoveTo(260,400);
		Form2->Canvas->LineTo(500,400);
		Form2->Canvas->Ellipse(500,340,620,460);
		Form2->Canvas->Ellipse(520,360,600,440);
		Form2->Canvas->MoveTo(620,400);
		Form2->Canvas->LineTo(720,400);
		Form2->Canvas->LineTo(720,280);
		Form2->Canvas->Rectangle(680,280,720,320);
		Form2->Canvas->LineTo(640,280);
		Form2->Canvas->LineTo(520,200);
		Form2->Canvas->LineTo(400,200);
		Form2->Canvas->MoveTo(400,240);
		Form2->Canvas->LineTo(320,280);
		Form2->Canvas->LineTo(560,280);
		Form2->Canvas->LineTo(520,240);
		Form2->Canvas->LineTo(400,240);
		Form2->Canvas->Brush->Color = clAqua;
		Form2->Canvas->FloodFill(415,245,clBlack,fsBorder);
		Form2->Canvas->Brush->Color = clGray;
		Form2->Canvas->FloodFill(525,400,clBlack,fsBorder);
		Form2->Canvas->FloodFill(165,400,clBlack,fsBorder);
		Form2->Canvas->Brush->Color = clBlack;
		Form2->Canvas->FloodFill(145,400,clBlack,fsBorder);
		Form2->Canvas->FloodFill(505,400,clBlack,fsBorder);
		Form2->Canvas->MoveTo(410,240);
		Form2->Canvas->LineTo(410,280);
		Form2->Canvas->Brush->Color = clOlive;
		Form2->Canvas->FloodFill(400,205,clBlack,fsBorder);
		door->draw();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)  //�������� ���
{
	if (light == 0){
		Form2->Canvas->Brush->Color = clYellow;
		Form2->Canvas->Rectangle(80, 320, 120, 360);
		Form2->Canvas->Rectangle(680,280,720,320);
		light=1;
   }
   else {
		Form2->Canvas->Brush->Color = clWhite;
		Form2->Canvas->Rectangle(80, 320, 120, 360);
		Form2->Canvas->Rectangle(680,280,720,320);
		light = 0;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
	if (DoorIsOpen==0){ //���� ����� �������
		door->erase();
		k=1;
		for(int i=1;i<90000000;i++)
		{
			if(i%1000000==0){
				door->Move(k,0);
				door->draw();
			}
		}
		DoorIsOpen=1;
	}
	else {   //���� ����� �������
		k=-1;
		for(int i=1;i<90000000;i++)
		{
			if(i%1000000==0){
				door->erase();
				door->Move(k,0);
				door->draw();
			}
		}
		DoorIsOpen=0;
	}
}
//---------------------------------------------------------------------------
