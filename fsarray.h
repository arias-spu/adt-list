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
		FSArray(const FSArray&);
		const FSArray& operator=(const FSArray&);
	public:
		FSArray(size_t capacity);
		virtual ~FSArray();

		virtual bool Insert(Object* element, size_t position);
		virtual int IndexOf(Object* element)const;
		virtual Object* Remove(size_t position);
		virtual Object* Get(size_t position)const;
		virtual string ToString()const;
		virtual void Clear();

};


#endif
