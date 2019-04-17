#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include "object.h"
#include "list.h"

#include <string>
using std::string;

class DLinkedList : public List{
		struct Node{
			Object* data;
			Node* next;
			Node* prev;
		};
		Node* _head;
		Node* _tail;
		DLinkedList(const DLinkedList&);
		const DLinkedList& operator=(const DLinkedList&);
	public:
		DLinkedList();
		virtual ~DLinkedList();

		virtual bool Insert(Object* element, size_t position);
		virtual int IndexOf(Object* element)const;
		virtual Object* Remove(size_t position);
		virtual Object* Get(size_t position)const;
		virtual string ToString()const;
		virtual void Clear();
};


#endif /* end of include guard: DLINKEDLIST_H */
