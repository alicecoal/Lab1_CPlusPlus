//---------------------------------------------------------------------------

#ifndef PolygonH
#define PolygonH
//---------------------------------------------------------------------------
 #include <vcl.h>
#include "MyFigure.h"
 class Polygon:public MyFigure
 {
	public:
	  int vertex = 0; // ���������� ������
	  double X[100]; // ���������� � ������
	  double Y[100]; // ���������� � ������
	public:
	 Polygon(TImage *Image,int x, int rad);
	 Polygon(int x);
	 ~Polygon();
	 Polygon();
	 void draw(TImage *Image,int vertex); // ��������� ��������������
	 void copy(Polygon x); // �����������  ��������������
	 double Perimeter(); // ���������� ��������� ��������������
	 double Square(); // ���������� ������� ��������������
	 double Xcentre(); // ���������� ���������� � ������ ����
	 double Ycentre(); // ���������� ���������� � ������ ����
 };
 #endif
