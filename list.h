#ifndef LIST_H
#define LIST_H

#include "object.h"

#include <string>
#include <iostream>
using std::string;
using std::istream;
using std::ostream;

class List : public Object{
protected:
	size_t _size;
public:
	List();
	virtual ~List();
	virtual bool Insert(Object* element, size_t position) = 0;
	virtual int IndexOf(Object* element)const = 0;
	virtual Object* Remove(size_t position) = 0;
	virtual Object* Get(size_t position)const = 0;
	virtual string ToString()const = 0;
	size_t Size()const;
	bool IsEmpty()const;
	virtual void Clear() = 0;

};


#endif
