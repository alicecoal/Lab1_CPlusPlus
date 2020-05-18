//---------------------------------------------------------------------------

#ifndef CircleH
#define CircleH
//---------------------------------------------------------------------------
 #include <vcl.h>
#include "MyFigure.h"
class Circle:public MyFigure
{
	public:
	Circle(TImage *Image, int radius);
	Circle();
	~Circle();
	void draw(TImage *Image); //рисование круга
	void copy(Circle x); //копирование круга
	double Perimeter(); //нахождение периметра круга
	double Square(); // нахождение площади круга
};
#endif
