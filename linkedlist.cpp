#include "object.h"
#include "linkedlist.h"

#include <string>
using std::string;

LinkedList::LinkedList(const LinkedList& list){

}
const LinkedList& LinkedList::operator=(const LinkedList& rhs){

}
LinkedList::LinkedList(){
	_head = nullptr;
}
LinkedList::~LinkedList(){
	while (_size != 0){
		Object* tmp = Remove(0);
		delete tmp;
	}
}
bool LinkedList::Insert(Object* element, size_t position){
	// Done in class
	return true;
}
int LinkedList::IndexOf(Object* element)const{
	// TODO
}
Object* LinkedList::Remove(size_t position){
	// Left as assignment
	return nullptr;
}
Object* LinkedList::Get(size_t position)const{
	if (position >= _size){
		return nullptr;
	}
	Node* tmp = nullptr;
	for (size_t i = 0; i < position; i++) {
		tmp = tmp->next;
	}
	return tmp->data;
}
string LinkedList::ToString()const{
	// TODO, it should output just like FSArray::ToString()
}
void LinkedList::Clear(){
	while (_size != 0){
		Object* tmp = Remove(0);
		delete tmp;
	}
	_head = nullptr;
}
