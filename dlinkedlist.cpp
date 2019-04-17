#include "object.h"
#include "dlinkedlist.h"

#include <string>
#include <sstream>
using std::string;
using std::stringstream;

DLinkedList::DLinkedList(const DLinkedList& list){

}
const DLinkedList& DLinkedList::operator=(const DLinkedList& rhs){
	return *this;
}

DLinkedList::DLinkedList(): _head(nullptr), _tail(nullptr){

}
DLinkedList::~DLinkedList(){

}

bool DLinkedList::Insert(Object* element, size_t position){
	return false;
}
int DLinkedList::IndexOf(Object* element)const{
	return -1;
}
Object* DLinkedList::Remove(size_t position){
	return nullptr;
}
Object* DLinkedList::Get(size_t position)const{
	return nullptr;
}
string DLinkedList::ToString()const{
	return "";
}
void DLinkedList::Clear(){

}
