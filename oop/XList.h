template <class Type>
class XListElement{
public:
	XListElement<Type> *previousElement;
	XListElement<Type> *nextElement;
	Type *element;
	XListElement<Type>(XListElement<Type> *prev, Type * o, XListElement<Type> *next){
		previousElement = prev;
		nextElement = next;
		element = o;
	};
};
template <class Type>
class XList{
	int number;
	public:
	XListElement<Type> *firstElement;
	XListElement<Type> *lastElement;
	XList<Type>(){
		number = 0;
		firstElement = 0;
		lastElement = 0;
	};
	~XList(){
		ClearAll();
	};
	void AddFirstElement( Type *object ){
		if( number==0 )
		{
			XListElement<Type> *e = new XListElement<Type>( 0 , object , 0 );
			firstElement = e;
			lastElement = e;
		}
		else
		{
			XListElement<Type> *e = new XListElement<Type>( 0 , object , firstElement );
			(*firstElement).previousElement = e;
			firstElement = e;	
		}
		number++;
	};
	void AddLastElement( Type *object){
		if( number==0 )
		{
			XListElement<Type> *e = new XListElement<Type>( 0 , object , 0 );
			firstElement = e;
			lastElement = e;
		}
		else
		{
			XListElement<Type> *e = new XListElement<Type>( lastElement , object , 0 );
			(*lastElement).nextElement = e;
			lastElement = e;	
		}
		number++;;
	};
	void DeleteFirstElement(){
		if( number==0 )
			throw invalid_argument("This list is empty");
		else
		{
			XListElement<Type> *p = firstElement;
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
			number--;
			delete (*p).element;
			delete p;
		}
	};
	void DeleteLastElement(){
		if( number==0 )
			std::cout << "This list is empty" << "\n";
		else
		{
			XListElement<Type> *p = lastElement;
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
			number--;
			delete (*p).element;
			delete p;
		}
	};
	Type* GetFirst(){
		return (*firstElement).element;
	};
	Type* GetLast(){
		return (*lastElement).element;
	};
	void GoThrueElements(){
		XListElement<Type> *p = firstElement;
		int i;
		for(i = 0; i < 1000 && p != 0; i++)
		{
			std::cout << *((Printable*)((*p).element)) <<"\n";
			//std::cout << "This is the " << i + 1 /**((*p).element)*/ <<"th element (going forward) \n";
			p = (*p).nextElement;
		}
		std::cout << "\n";/*
		p = lastElement;
		for(i = 0; i < 1000 && p != 0; i++)
		{	
			std::cout << "This is the " << number - i <<"th element (going backward)\n";
			p = (*p).previousElement;
		}*/
	};
	int Count(){
		return number;
	};
	bool IsEmpty(){
		if ( number == 0 )
			return true;
		else
			return false;
	};
	void ClearAll(){
		while( number > 0 )
			try
		{
			DeleteFirstElement();
		}
		catch(invalid_argument& e)
			{
			cerr << e.what() << endl;
				std::cout << "This list is empty" << "\n";
			}

	};
};
