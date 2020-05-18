//---------------------------------------------------------------------------
#pragma hdrstop
#include "math.h"
#include "Polygon.h"
#define pi 3.1416
//---------------------------------------------------------------------------
#pragma package(smart_init)

Polygon::Polygon(int x)
{
	vertex = x;
}

Polygon::Polygon(){}
Polygon::~Polygon(){}

Polygon::Polygon(TImage *Image, int x, int rad)
{
	vertex = x;
	r = rad;
	for(int i = 0; i < vertex; i++)
	{
		X[i] = centreX + r * cos(((double)((360 / vertex) * i)) / 180 * pi);
		Y[i] = centreY + r * sin(((double)((360 / vertex) * i)) / 180 * pi);
	}
	draw(Image, vertex);
}

void Polygon::draw(TImage *Image,int vertex)
{
	Image->Canvas->Rectangle(0, 0, 1000, 1000);
	Image->Canvas->MoveTo(X[0], Y[0]);
	Image->Canvas->Ellipse(X[0] - 8, Y[0] - 8, X[0] + 8, Y[0] + 8);
	for (int i = 1; i < vertex; i++)
	{
		Image->Canvas->Ellipse(X[i] - 8, Y[i] - 8, X[i] + 8, Y[i] + 8);
		Image->Canvas->LineTo(X[i], Y[i]);
	}
	Image->Canvas->LineTo(X[0], Y[0]);
}

void Polygon::copy(Polygon x)
{
	 vertex = x.vertex;
	 perimeter = x.perimeter;
	 square = x.square;
	 for (int i = 0; i<vertex; i++)
	 {
		 X[i] = x.X[i];
		 Y[i] = x.Y[i];
	 }
	 centreX = x.centreX;
	 centreY = x.centreY;
}

double Polygon::Perimeter()
{
	 double x = 0;
	 for(int i = 1; i < vertex; i++)
		x += sqrt((X[i] - X[i-1]) * (X[i] - X[i-1]) + (Y[i] - Y[i-1]) * (Y[i] - Y[i-1])); // рассто€ние от точки i до точки i-1
	 x += sqrt((X[0] - X[vertex-1]) * (X[0] - X[vertex - 1]) + (Y[0] - Y[vertex-1]) * (Y[0] - Y[vertex-1]));
	 return x;
}

double Polygon::Square() //триангул€ци€
{
	 double x = 0;
	 for(int i = 1; i < vertex; i++)
		x += ((Y[i] + Y[i-1])/2) * (X[i] - X[i-1]);
	 x += ((Y[0] + Y[vertex-1])/2) * (X[0] - X[vertex-1]);
	 return abs(x);
}

double Polygon::Xcentre() // оордината ’ центра масс (масса находитс€ в вершинах и они вес€т одинаково)
{
	double s = 0;
	for (int i = 0; i < vertex; i++)
		s += X[i];
	centreX = s/vertex;
	return s/vertex;
}
double Polygon::Ycentre() // оордината ” центра масс (масса находитс€ в вершинах и они вес€т одинаково)
{
	double s = 0;
	for (int i = 0; i < vertex; i++)
		s += Y[i];
	centreY = s/vertex;
	return s/vertex;
}

