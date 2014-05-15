// oop.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "oop.h"
#include "Shapes.h"
int Shape::ShapeCount = 0;

int _tmain(int argc, _TCHAR* argv[])
{
	XList <Shape> *p = new XList<Shape>();
	//XList <int> *p = new XList<int>();
	int i1 = 1;
	/*int i2 = 2;
	int i3 = 3;
	int i4 = 4;
	int i5 = 5;
	int i6 = 6;
	int i7 = 7;
	(*p).AddLastElement(&i1);
	(*p).AddLastElement(&i2);
	(*p).AddLastElement(&i3);
	(*p).AddLastElement(&i4);
	(*p).AddLastElement(&i5);
	(*p).AddLastElement(&i6);
	(*p).AddLastElement(&i7);
	(*p).GoThrueElements();
	(*p).DeleteFirstElement();
	(*p).GoThrueElements();
	(*p).DeleteLastElement();
	(*p).GoThrueElements();
	//XListElement *q = (*p).firstElement;
	//std::cout << "This is the number of elements " << *((int*)(*p).GetLast()) <<"\n";

	std::cout << "This is the number of elements " << (*p).Count() <<"\n";*/

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
	Shape::GetCount();

	Circle* _circle = new Circle("Circle",0,0,5);

	Rect* _rect = new Rect("Rect",0,0,17,23);

	Square* _square1 = new Square("Square1",0,0,23,23);

	Square* _square2 = new Square("Square2",0,0,40,23);

	Shape::GetCount();

	
	std::cout<<*_poly<<"\n";
	std::cout<<*_circle<<"\n";
	std::cout<<*_rect<<"\n";
	std::cout<<*_square1<<"\n";
	std::cout<<*_square2<<"\n";
	std::cout<<*_point1<<"\n";
	std::cout<<*((Printable*)_point1)<<"\n";


	Shape::GetCount();
	(*p).AddLastElement(_poly);
	(*p).AddLastElement(_rect);
	(*p).AddFirstElement(_circle);
	(*p).AddLastElement(_square1);
	(*p).AddLastElement(_square2);

	/*int i, counter = (*p).Count();

	XListElement<Shape> *pointer;
	pointer = (*p).firstElement;
	for(i = 0; i < counter && pointer != 0; i++)
	{
		//(*((*pointer).element)).PrintShape();
		cout << (Shape*)((*pointer).element);
		pointer = (*pointer).nextElement;

	}*/

	(*p).GoThrueElements();
	(*p).ClearAll();
	Shape::GetCount();

	
	std::cin>>i1;
	return 0;
}

