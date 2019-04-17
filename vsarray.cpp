#include "object.h"
#include "list.h"
#include "vsarray.h"

#include <string>
#include <iostream>
#include <sstream>
using std::string;
using std::istream;
using std::ostream;
using std::stringstream;

VSArray::VSArray(size_t capacity){
}
VSArray::VSArray(const VSArray& list){
}
VSArray::~VSArray(){
}
const VSArray& VSArray::operator=(const VSArray& rhs){
	return *this;
}

bool VSArray::Insert(Object* element, size_t position){
	return true;
}
int VSArray::IndexOf(Object* element)const{
	return -1;
}
Object* VSArray::Remove(size_t position){
	return nullptr;
}
Object* VSArray::Get(size_t position)const{
	return nullptr;
}
string VSArray::ToString()const{
	return "null";
}
void VSArray::Clear(){
}
