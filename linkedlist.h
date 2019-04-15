#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "object.h"
#include "list.h"

#include <string>
using std::string;

class LinkedList : public Object{
		struct Node{
			Object* data;
			Node* next;
		};
		Node* _head;
		LinkedList(const LinkedList&);
		const LinkedList& operator=(const LinkedList&);
	public:
		LinkedList();
		virtual ~LinkedList();

		virtual bool Insert(Object* element, size_t position);
		virtual int IndexOf(Object* element)const;
		virtual Object* Remove(size_t position);
		virtual Object* Get(size_t position)const;
		virtual string ToString()const;
		virtual void Clear();
};


#endif /* end of include guard: LINKEDLIST_H */
