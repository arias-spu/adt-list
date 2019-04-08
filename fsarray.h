#ifndef FSARRAY_H
#define FSARRAY_H

#include "object.h"
#include "list.h"

#include <string>
#include <iostream>
using std::string;
using std::istream;
using std::ostream;

class FSArray : public List{
		Object** _data;
		size_t _capacity;
	public:
		FSArray(size_t capacity);
		FSArray(const FSArray&);
		virtual ~FSArray();
		const FSArray& operator=(const FSArray&);

		virtual bool Insert(Object* element, size_t position);
		virtual int IndexOf(Object* element)const;
		virtual Object* Remove(size_t position);
		virtual Object* Get(size_t position);
		virtual string ToString()const;
		virtual ostream& Write(ostream&)const;
		virtual istream& Read(istream&);
		virtual void Clear();

};


#endif
