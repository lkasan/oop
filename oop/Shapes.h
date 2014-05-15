#include <cmath>
#include <string.h>
#include <stdio.h>
#include "XList.h"
#include <iostream>
class Named{

public:
	char name[20];
	Named(char* name1)
	{
		strcpy_s(name, name1); 
	}
};
class Printable: public Named{
public:
	Printable(char* name):Named(name){};
	//Printable(){};
	void PrintShape()
	{
		std::cout << "Not an actual shape yet \n";
	}

};


class Shape: public Named{
static int ShapeCount;
public:
	Shape(char* name):Named(name)
	{
		ShapeCount++;
	}
	virtual ~Shape()
	{
		ShapeCount--;
	}
static void GetCount()
{
	std::cout << "There are about "<< ShapeCount <<" shapes\n";
}
static void ShapeCountAdd()
{
	ShapeCount++;
}
static void ShapeCountSub()
{
	ShapeCount--;
}
};

class Point:public Shape, public Printable{
	int x, y ;
public:
	Point(char* name1,int x1, int y1):Shape(name1),Printable(name1)
	{
		x = x1;
		y = y1;
	}
	//~Point(){Shape::ShapeCountSub();}//:Shape(){}
	void PrintShape()
	{
		std::cout << Named::name <<": X=" << GetX() << " Y=" << GetY() <<"\n";
	}
	int GetX()
	{
		return Point::x;
	}
	int GetY()
	{
		return Point::y;
	}

};
class Circle:public Shape, public Printable{
	int radius;
	Point *center;
	public:
	Circle(char* name1,int x1, int y1, int radius1):Shape(name1),Printable(name1)
	{
		radius = radius1;
		center = new Point("Center",x1,y1);
		ShapeCountSub();
	}
//	~Circle(){Shape::ShapeCountSub();}
	void PrintShape()
	{
		std::cout << "____" << Named::name << "____\n";
		(*center).PrintShape();
		std::cout << "Radius=" << radius << " Area=" << 3.14*radius*radius <<"\n";
	}
};
class Rect:public Shape, public Printable{
	public:
	Point* d1;
	Point* d2;
	Rect(char* name1,int x1, int y1, int x2, int y2):Shape(name1),Printable(name1)
	{
		d1 = new Point("Diag1",x1,y1);
		ShapeCountSub();
		d2 = new Point("Diag2",x2,y2);
		ShapeCountSub();
	}
//	~Rect(){Shape::ShapeCountSub();}
	void PrintShape()
	{
		std::cout << "____" << Named::name << "____\n";
		(*d1).PrintShape();
		(*d2).PrintShape();
		std::cout << " Area=" << abs(((*d1).GetX()-(*d2).GetX())*((*d1).GetY()-(*d2).GetY())) <<"\n";
	}
};
class Square:public Rect
{
	public:
	Square(char* name1,int x1, int y1, int x2, int y2):Rect(name1,x1,y1,x2,y2)
	{
		if( abs(x1-x2) != abs(y1-y2))
		std::cout << "Input parameters do not correspond to the square\n";
	}
	//~Square(){Shape::ShapeCountSub();}
};
class Polyline:public Shape, public Printable{
		XList<Point> *polylist;
		int x,y;
		long double length;
	public:
		Polyline(char* name1):Shape(name1),Printable(name1)
		{
			polylist = new XList<Point>();
			length = 0;
			x = 0;
			y = 0;
		}
		~Polyline(){
				(*polylist).ClearAll();
				delete polylist;
			}
		void AddPoint( Point* const _point ){
			if(!(*polylist).IsEmpty())
				length += sqrt( (long double)(( x - ( *_point ).GetX() ) * ( x - ( *_point ).GetX() )+( y - ( *_point ).GetY() ) * ( y - ( *_point ).GetY() )));
			(*polylist).AddLastElement(_point);
			x = ( *_point ).GetX();
			y = ( *_point ).GetY();
			//(*( (Point*) ((void*)_point) )).PrintShape();
		}
		void PrintShape(){
			XListElement<Point> *pointer;
			int count = (*polylist).Count(),i;
			std::cout << "Elements number of polyline is " << count << "\n";
			pointer = (*polylist).firstElement;//(XListElement*)((*polylist).GetFirst());
		//	_point = (Point*)((*pointer).element);
		//	(*_point).PrintShape();
			for( i = 0 ; i < count && pointer != 0; i++)//посмотреть, возможно последний элемент не учел
			{
				(*((*pointer).element)).PrintShape();
				pointer = (*pointer).nextElement;
			}
			std::cout << "Length of polyline is " << length << "\n";
		}

};