#include "object.h"
#include "linkedlist.h"

#include <string>
#include <sstream>
using std::string;
using std::stringstream;

LinkedList::LinkedList(const LinkedList& list): _head(nullptr){
	for (Node* tmp = list._head; tmp != nullptr; tmp = tmp->next){
		Insert(tmp->data->Clone(), _size);
	}
}
const LinkedList& LinkedList::operator=(const LinkedList& rhs){
	return *this;
}
LinkedList::LinkedList() : _head(nullptr){
}
LinkedList::~LinkedList(){
	while (_size != 0){
		Object* tmp = Remove(0);
		delete tmp;
	}
}
bool LinkedList::Insert(Object* element, size_t position){
	if (position > _size){
		return false;
	}
	Node* neo = new Node;
	neo->data = element;
	neo->next = nullptr;
	if (_size == 0){ // The list is empty
		_head = neo;
	}else if (position == 0){
		neo->next = _head;
		_head = neo;
	}else{
		Node* tmp = _head;
		for (size_t i = 0; i < position -1; i++){
			tmp = tmp->next;
		}
		neo->next = tmp->next;
		tmp->next = neo;
	}
	_size++;
	return true;
}
int LinkedList::IndexOf(Object* element)const{
	size_t index = 0;
	for (Node* tmp = _head; tmp != nullptr; tmp = tmp->next){
		if (tmp->data->Equals(*element)){
			return index;
		}
		index++;
	}
	return -1;
}
Object* LinkedList::Remove(size_t position){
	if (position >= _size){
		return nullptr;
	}
	Object* retVal = nullptr;
	Node* tmp = nullptr;
	if (position == 0){ // Want to remove the first element, _head
		retVal = _head->data;
		_head->data = nullptr;
		tmp = _head->next;
		_head->next = nullptr;
		delete _head;
		_head = tmp;
	}else {
		tmp = _head;
		for (size_t i = 0; i < position -1; i++){
			tmp = tmp->next;
		}
		Node* toRemove = tmp->next;
		retVal = toRemove->data;
		tmp->next = toRemove->next;
		toRemove->next = nullptr;
		toRemove->data = nullptr;
		delete toRemove;
	}
	_size--;
	return retVal;
}
Object* LinkedList::Get(size_t position)const{
	if (position >= _size){
		return nullptr;
	}
	Node* tmp = _head;
	for (size_t i = 0; i < position; i++) {
		tmp = tmp->next;
	}
	return tmp->data;
}
string LinkedList::ToString()const{
	stringstream retVal;
	retVal << "{";
	Node* tmp;
	for (tmp = _head; tmp->next != nullptr; tmp = tmp->next) {
		retVal << tmp->data->ToString() << ", ";
	}
	retVal << tmp->data->ToString() << "}";
	return retVal.str();
}
void LinkedList::Clear(){
	while (_size != 0){
		Object* tmp = Remove(0);
		delete tmp;
	}
	_head = nullptr;
}
