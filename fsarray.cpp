#include "object.h"
#include "list.h"
#include "fsarray.h"

#include <string>
#include <iostream>
using std::string;
using std::istream;
using std::ostream;

FSArray::FSArray(size_t capacity) : _capacity(capacity){
	_data = new Object*[_capacity];
	for (size_t i = 0; i < _capacity; i++) {
		_data[i] = nullptr;
	}
}
FSArray::FSArray(const FSArray& list) : _capacity(list._capacity){
	// Is there a bug here?
	_size = list._size;
	_data = new Object*[_capacity];
	for (size_t i = 0; i < _capacity; i++) {
		_data[i] = list.Get(i)->Clone();
	}
}
FSArray::~FSArray(){
	for (size_t i = 0; i < Size(); i++) {
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
	return false;
}
int FSArray::IndexOf(Object* element)const{
	return -1;
}
Object* FSArray::Remove(size_t position){
	return nullptr;
}
Object* FSArray::Get(size_t position)const{
	return nullptr;
}
string FSArray::ToString()const{
	return "";
}
ostream& FSArray::Write(ostream& output)const{
	return output;
}
istream& FSArray::Read(istream& input){
	return input;
}
void FSArray::Clear(){
	for (size_t i = 0; i < Size(); i++) {
		delete _data[i];
		_data[i] = nullptr;
	}
	// Something missing here?
}
