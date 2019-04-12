#include "person.h"

#include <cstring>
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

Person::Person(const string& name, size_t age) : _age(age){
	_name = new char[name.length() + 1];
	strcpy(_name, name.c_str());
}
Person::Person(const Person& person) : _age(person._age){
	_name = new char[strlen(person._name) + 1];
	strcpy(_name, person._name);
}
const Person& Person::operator=(const Person& rhs){
	if (strlen(_name) != strlen(rhs._name)){
		delete[] _name;
		_name = new char[strlen(rhs._name) + 1];
	}
	strcpy(_name, rhs._name);
	return *this;
}
Person::~Person(){
	delete[] _name;
}
string Person::ToString()const{
	stringstream retVal;
	retVal << "Person: {name: " << _name << ", age: " << _age << "}";
	return retVal.str();
}
bool Person::Equals(const Object& rhs)const{
	if (this == &rhs){
		return true;
	}
	const Person* rhsPtr = dynamic_cast<const Person*>(&rhs);
	if (rhsPtr == nullptr){
		return false;
	}
	return strcmp(rhsPtr->_name, _name) == 0 && rhsPtr->_age == _age;

}
void Person::Birthday(){
	_age++;
}
