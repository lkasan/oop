class XListElement{
public:
	XListElement* previousElement;
	XListElement* nextElement;
	void* element;
	XListElement(XListElement *prev, void * o, XListElement *next);
};

class XList{
	int number;
public:
	XListElement *firstElement;
	XListElement *lastElement;
	XList();
	~XList();
	void AddFirstElement( void *object );
	void AddLastElement(void *object);
	void DeleteFirstElement();
	void DeleteLastElement();
	void* GetFirst();
	void* GetLast();
	void XList::GoThrueElements();
	int XList::Count();
	bool XList::IsEmpty();
	void XList::ClearAll();
};
