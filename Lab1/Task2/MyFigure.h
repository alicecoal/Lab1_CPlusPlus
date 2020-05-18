//---------------------------------------------------------------------------
#include <vcl.h>
#ifndef MyFigureH
#define MyFigureH
//---------------------------------------------------------------------------

class MyFigure
{
	public:
		double r; // длина стороны\радиуса
		double centreX = 150, centreY = 150;//координаты центра масс
		double perimeter = 0, square = 0; // периметр и площадь фигуры
	public :
		~MyFigure();
};
#endif
