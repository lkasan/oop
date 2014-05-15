#include "stdafx.h"
#include "XList.h"
#include <iostream>
#include <stdexcept>


XListElement::XListElement(XListElement *prev, void * o, XListElement *next)
{
	previousElement = prev;
	nextElement = next;
	element = o;
}
XList::XList(){
	number = 0;
	firstElement = 0;
	lastElement = 0;
}
XList::~XList(){
	ClearAll();
}
void XList::AddFirstElement( void* const object ){
//	if(sizeof(object)!=sizeof(void*))
//		throw invalid_argument("The wrong type of an element");
	if( number==0 )
	{
		XListElement *e = new XListElement( 0 , object , 0 );
		firstElement = e;
		lastElement = e;
	}
	else
	{
		XListElement* e = new XListElement( 0 , object , firstElement );
		(*firstElement).previousElement = e;
		firstElement = e;
		
	}
	number++;
}
void XList::AddLastElement(void* const object){
//	if(sizeof(object)!=sizeof(void*))
//		throw invalid_argument("The wrong type of an element");
	if( number==0 )
	{
		XListElement* e = new XListElement( 0 , object , 0 );
		firstElement = e;
		lastElement = e;
	}
	else
	{
		XListElement* e = new XListElement( lastElement , object , 0 );
		(*lastElement).nextElement = e;
		lastElement = e;	
	}
	number++;;
	
}
void XList::DeleteFirstElement(){
	if( number==0 )
		std::cout << "This list is empty" << "\n";
	else
	{
		XListElement *p = firstElement;
		if( number == 1 )
		{
			firstElement = 0;
			lastElement = 0;
		}
		else
		{
			firstElement = (*p).nextElement;
			(*firstElement).previousElement = 0;
		}
	//	delete ((Shape*)((*p).element));
		delete p->element;
		//delete (XListElement*)p;
		//delete p;
		number--;
	}
}
void XList::DeleteLastElement(){
	if( number==0 )
		std::cout << "This list is empty" << "\n";
	else
	{
		XListElement *p = lastElement;
		if( number == 1 )
		{
			firstElement = 0;
			lastElement = 0;
		}
		else
		{
			lastElement = (*p).previousElement;
			(*lastElement).nextElement = 0;
		}
		delete p;
		number--;
	}
}
void* XList::GetFirst(){
	return (*firstElement).element;
}
void* XList::GetLast(){
	return (*lastElement).element;
}
void XList::GoThrueElements()
{
	XListElement *p = firstElement;
	int i;
	for(i = 0; i < 1000 && p != 0; i++)
	{
		std::cout << "This is the " << i+1 <<"th element (going forward) \n";
		p = (*p).nextElement;
	}
	std::cout << "\n";
	p = lastElement;
	for(i = 0; i < 1000 && p != 0; i++)
	{	
		std::cout << "This is the " << number - i <<"th element (going backward)\n";
		p = (*p).previousElement;
	}

}
int XList::Count(){
	return number;
}
bool XList::IsEmpty(){
	if ( number == 0 )
		return true;
	else
		return false;
}
void XList::ClearAll(){
	while( number > 0 )
	DeleteFirstElement();
	std::cout << "This list is empty" << "\n";
}

