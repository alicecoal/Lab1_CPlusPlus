//---------------------------------------------------------------------------
#include <vcl.h>
#ifndef MyFigureH
#define MyFigureH
//---------------------------------------------------------------------------

class MyFigure
{
	public:
		double r; // ����� �������\�������
		double centreX = 150, centreY = 150;//���������� ������ ����
		double perimeter = 0, square = 0; // �������� � ������� ������
	public :
		~MyFigure();
};
#endif
