//---------------------------------------------------------------------------

#ifndef PolygonH
#define PolygonH
//---------------------------------------------------------------------------
 #include <vcl.h>
#include "MyFigure.h"
 class Polygon:public MyFigure
 {
	public:
	  int vertex = 0; // количество вершин
	  double X[100]; // координаты ’ вершин
	  double Y[100]; // координаты ” вершин
	public:
	 Polygon(TImage *Image,int x, int rad);
	 Polygon(int x);
	 ~Polygon();
	 Polygon();
	 void draw(TImage *Image,int vertex); // рисование многоугольника
	 void copy(Polygon x); // копирование  многоугольника
	 double Perimeter(); // нахождение периметра многоугольника
	 double Square(); // нахождение площади многоугольника
	 double Xcentre(); // нахождение координаты ’ центра масс
	 double Ycentre(); // нахождение координаты ” центра масс
 };
 #endif
