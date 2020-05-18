//---------------------------------------------------------------------------
#pragma hdrstop
#include "math.h"
#include "Circle.h"
#define pi 3.14
//---------------------------------------------------------------------------
#pragma package(smart_init)
Circle::Circle(TImage *Image, int radius)
{
	r = radius;
	Image->Canvas->Rectangle(0, 0, 1000, 1000);
	Image->Canvas->Ellipse(centreX - r/2,centreY - r/2,centreX + r/2,centreY + r/2);
}

Circle::Circle(){}
Circle::~Circle(){}

void Circle::draw(TImage *Image)
{
	Image->Canvas->Rectangle(0, 0, 1000, 1000);
	Image->Canvas->Ellipse(centreX - r/2, centreY - r/2, centreX + r/2, centreY + r/2);
	Image->Canvas->Ellipse(centreX - 8, centreY - 8, centreX + 8, centreY + 8);
}
void Circle::copy(Circle x)
{
	 r = x.r;
	 perimeter = x.perimeter;
	 square = x.square;
	 centreX = x.centreX;
	 centreY = x.centreY;
}
double Circle::Perimeter()
{
	 return r * pi;
}
double Circle::Square()
{
	 return (pi * r * r)/4;
}
