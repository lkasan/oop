#include <cmath>
#include <string.h>
#include "XList.h"
#include <iostream>
using namespace std;
class Named{

public:
	char name[20];
	Named(char* name1)
	{
		strcpy_s(name, name1); 
	}
	Named(){}
};

 
class Printable;
ostream& operator<<(ostream& ost, const Printable& ls);

class Printable: public Named{
public:

	Printable(char* name):Named(name){
	};
	friend ostream& operator<<(ostream& output, const Printable &p){
		output<<"____"<< p.name <<"____"<<endl;
        return output;
	};  
};


class Shape: public Named{
static int ShapeCount;
public:
	Shape():Named()
	{
		ShapeCount++;
	}
	virtual ~Shape()
	{
		ShapeCount--;
	}
static void GetCount()
{
	cout << "There are about "<< ShapeCount <<" shapes\n";
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
	Point(char* name1,int x1, int y1):Shape(),Printable(name1)
	{
		x = x1;
		y = y1;
	}
	friend ostream& operator<<(ostream& output, const Point &p1){

		output<<"____"<< ((Printable)p1).name <<"____ X=" << p1.x <<" Y=" << p1.y << std::endl;
        return output;
	};  
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
	Circle(char* name1,int x1, int y1, int radius1):Shape(),Printable(name1)
	{
		radius = radius1;
		center = new Point("Center",x1,y1);
		ShapeCountSub();
	}
	~Circle(){
		delete center;
		Shape::ShapeCountAdd();
	}
	friend ostream& operator<<(ostream& output, const Circle &p){
		output<<"____"<< ((Printable)p).name <<"____ " << *(p.center) << std::endl;
        return output;
	};  
};
class Rect:public Shape, public Printable{
	public:
	Point* d1;
	Point* d2;
	Rect(char* name1,int x1, int y1, int x2, int y2):Shape(),Printable(name1)
	{
		d1 = new Point("Diag1",x1,y1);
		ShapeCountSub();
		d2 = new Point("Diag2",x2,y2);
		ShapeCountSub();
	}
	~Rect(){
		delete d1;
		delete d2;
		Shape::ShapeCountAdd();
		Shape::ShapeCountAdd();
	}
	friend ostream& operator<<(ostream& output, const Rect &p){
		output<<"____"<< ((Printable)p).name <<"____ " << *(p.d1) << *(p.d2) << " Area=" << abs(((*(p.d1)).GetX() - (*(p.d2)).GetX())*((*(p.d1)).GetY() - (*(p.d2)).GetY())) << std::endl;
        return output;
	};  
	

};
class Square:public Rect
{
	public:
	Square(char* name1,int x1, int y1, int x2, int y2):Rect(name1,x1,y1,x2,y2)
	{
		if( abs(x1-x2) != abs(y1-y2))
		cout << "Input parameters do not correspond to the square\n";
	}
};
class Polyline:public Shape, public Printable{
		XList<Point> *polylist;
		int x,y;
		long double length;
	public:
		Polyline(char* name1):Shape(),Printable(name1)
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

		}
	friend ostream& operator<<(ostream& output, const Polyline &p){
		output<<"____"<< ((Printable)p).name <<"____ Length=" << p.length << std::endl;
        return output;
	};  
};