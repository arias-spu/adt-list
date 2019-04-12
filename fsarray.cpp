#include "object.h"
#include "list.h"
#include "fsarray.h"

#include <string>
#include <iostream>
#include <sstream>
using std::string;
using std::istream;
using std::ostream;
using std::stringstream;

FSArray::FSArray(size_t capacity) : _capacity(capacity){
	_data = new Object*[_capacity];
	for (size_t i = 0; i < _capacity; i++) {
		_data[i] = nullptr;
	}
}
FSArray::FSArray(const FSArray& list) : _capacity(list._capacity){
	// Is there a bug here? --> Solved by setting _size to be protected
	_size = list._size;
	_data = new Object*[_capacity];
	for (size_t i = 0; i < _size; i++) { // Issa correction to the _capacity
		_data[i] = list.Get(i)->Clone();
	}
	for (size_t i = _size; i < _capacity; i++){
		_data[i] = nullptr;
	}
}
FSArray::~FSArray(){
	for (size_t i = 0; i < _size; i++) {
		delete _data[i];
	}
	delete[] _data;
}
const FSArray& FSArray::operator=(const FSArray& rhs){
	if (&rhs == this){
		return *this;
	}
	if (_capacity != rhs._capacity){
		Clear();
		delete[] _data;
		_capacity = rhs._capacity;
		_data = new Object*[_capacity];
		for (size_t i = 0; i < _capacity; i++) {
			_data[i] = nullptr;
		}
	}
	for (size_t i = 0; i < rhs.Size(); i++) {
		_data[i] = rhs.Get(i)->Clone();
	}
	return *this;
}

bool FSArray::Insert(Object* element, size_t position){
	// Check if the position is valid
	if (position > _size)
		return false;
	// Check if there is enough space
	if (_capacity == _size)
		return false;

	if (position < _size){ // We need to shift
		// WARNING WILL ROBINSON : Lost in Space Reference
		// Be careful with size_t when subtracting
		for (size_t i = _size; i > position; i--){
			_data[i] = _data[i - 1];
		}
	}
	_data[position] = element;
	_size++;
	return true;
}
int FSArray::IndexOf(Object* element)const{
	for (size_t i = 0; i < _size; i++) {
		if (_data[i]->Equals(*element)){
			return i;
		}
	}
	return -1;
}
Object* FSArray::Remove(size_t position){
	if (position >= _size){
		return nullptr;
	}
	Object* retVal = _data[position];
	for (size_t i = position; i < _size - 1; i++) {
		_data[i] = _data[i + 1];
	}
	_data[_size - 1] = nullptr;
	_size--;
	return retVal;
}
Object* FSArray::Get(size_t position)const{
	if (position >= _size)
		return nullptr;
	else
		return _data[position];
}
string FSArray::ToString()const{
	stringstream retVal;
	retVal << "{";
	for (size_t i = 0; i < _size - 1; i++) {
		retVal << _data[i]->ToString() << ", ";
	}
	retVal << _data[_size - 1]->ToString() << "}";
	return retVal.str();
}
void FSArray::Clear(){
	for (size_t i = 0; i < _size; i++) {
		delete _data[i];
		_data[i] = nullptr;
	}
	_size = 0;
}
