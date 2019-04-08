#include "object.h"
#include "list.h"
#include "fsarray.h"

#include <string>
#include <iostream>
using std::string;
using std::istream;
using std::ostream;

FSArray::FSArray(size_t capacity){

}
FSArray::FSArray(const FSArray& list){

}
FSArray::~FSArray(){

}
const FSArray& FSArray::operator=(const FSArray& rhs){

}

bool FSArray::Insert(Object* element, size_t position){

}
int FSArray::IndexOf(Object* element)const{

}
Object* FSArray::Remove(size_t position){

}
Object* FSArray::Get(size_t position){

}
string FSArray::ToString()const{

}
ostream& FSArray::Write(ostream&)const{

}
istream& FSArray::Read(istream&){

}
void FSArray::Clear(){

}
