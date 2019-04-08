#include "list.h"

List::List() : _size(0){

}
List::~List(){

}
size_t List::Size()const{
	return _size;
}
bool List::IsEmpty()const{
	return _size == 0;
}
