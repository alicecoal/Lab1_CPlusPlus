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
	void draw(TImage *Image); //��������� �����
	void copy(Circle x); //����������� �����
	double Perimeter(); //���������� ��������� �����
	double Square(); // ���������� ������� �����
};
#endif
