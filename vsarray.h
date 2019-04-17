#ifndef VSARRAY_H
#define VSARRAY_H

#include "object.h"
#include "list.h"

#include <string>
#include <iostream>
using std::string;
using std::istream;
using std::ostream;

class VSArray : public List{
		Object** _data;
		size_t _capacity;
		VSArray(const VSArray&);
		const VSArray& operator=(const VSArray&);
		void Resize();
	public:
		VSArray(size_t capacity);
		virtual ~VSArray();

		virtual bool Insert(Object* element, size_t position);
		virtual int IndexOf(Object* element)const;
		virtual Object* Remove(size_t position);
		virtual Object* Get(size_t position)const;
		virtual string ToString()const;
		virtual void Clear();

};


#endif
