// oop.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "oop.h"
//#include "XList.h"
#include "Shapes.h"
#include <iostream>
//#include <stdexcept>
int Shape::ShapeCount = 0;

int _tmain(int argc, _TCHAR* argv[])
{
	XList *p = new XList();
	int i1 = 1;
	/*
	int i2 = 2;
	int i3 = 3;
	int i4 = 4;
	int i5 = 5;
	int i6 = 6;
	int i7 = 7;
	(*p).AddFirstElement((void*)&i1);
	(*p).AddFirstElement((void*)&i2);
	(*p).AddFirstElement((void*)&i3);
	(*p).AddFirstElement((void*)&i4);
	(*p).AddFirstElement((void*)&i5);
	(*p).AddFirstElement((void*)&i6);
	(*p).AddFirstElement((void*)&i7);
	(*p).GoThrueElements();
	(*p).DeleteFirstElement();
	(*p).GoThrueElements();
	(*p).DeleteLastElement();
	(*p).GoThrueElements();
	//XListElement *q = (*p).firstElement;
	//std::cout << "This is the number of elements " << *((int*)(*p).GetLast()) <<"\n";

	std::cout << "This is the number of elements " << (*p).Count() <<"\n";
*/
	Point *_point1 = new Point("Point1",1,0);
	Point *_point2 = new Point("Point2",0,1);
	Point *_point3 = new Point("Point3",2,1);
	Point *_point4 = new Point("Point4",1,2);
	Point *_point5 = new Point("Point5",3,2);
	Point *_point6 = new Point("Point6",2,3);
	Point *_point7 = new Point("Point7",4,3);
	Point *_point8 = new Point("Point8",3,4);
	//Shape::GetCount();

	Polyline *_poly = new Polyline("Polyline");
	(*_poly).AddPoint(_point1);
	(*_poly).AddPoint(_point2);
	(*_poly).AddPoint(_point3);
	(*_poly).AddPoint(_point4);
	(*_poly).AddPoint(_point5);
	(*_poly).AddPoint(_point6);
	(*_poly).AddPoint(_point7);
	(*_poly).AddPoint(_point8);
	//Shape::GetCount();

	Circle* _circle = new Circle("Circle",0,0,5);

	Rect* _rect = new Rect("Rect",0,0,17,23);

	Square* _square1 = new Square("Square1",0,0,23,23);

	Square* _square2 = new Square("Square2",0,0,40,23);

	//Shape::GetCount();

/*
	(*_point1).PrintShape();
	(*_poly).PrintShape();
	(*_rect).PrintShape();
	(*_square1).PrintShape();
	(*_square2).PrintShape();
*/

	Shape::GetCount();
//	try
//	{
		(*p).AddLastElement((void*)_poly);
//	}
//	catch(invalid_argument& e)
//	{
//      cerr << e.what() << endl;
//      return -1;
//	}
	(*p).AddLastElement((void*)_rect);
	(*p).AddLastElement((void*)_square1);
	(*p).AddLastElement((void*)_square2);
	(*p).AddLastElement((void*)_point3);

	int i, counter = (*p).Count();

	XListElement *pointer;
	pointer = (XListElement*)((*p).firstElement);

	for(i = 0; i < counter && pointer != 0; i++)
	{
		(*((Printable*)((*pointer).element))).PrintShape();
		pointer = (XListElement*)((*pointer).nextElement);
	}
	//(*p).ClearAll();
	delete _square2;
	Shape::GetCount();

	
	std::cin>>i1;
	return 0;
}

