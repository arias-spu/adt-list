#include "integer.h"

#include <string>
#include <sstream>
using std::string;
using std::stringstream;


Integer::Integer(int value): _value(value){

}
string Integer::ToString()const{
	stringstream retVal;
	retVal << _value;
	return retVal.str();
}
bool Integer::Equals(const Object& rhs)const{
	if (this == &rhs){
		return true;
	}
	// What happens if we take away the consts?
	const Integer* rhsPtr = dynamic_cast<const Integer*>(&rhs);
	if (rhsPtr == nullptr){
		return false;
	}
	return _value == rhsPtr->_value;

}

int Integer::GetValue()const{
	return _value;
}
void Integer::SetValue(int value){
	_value = value;
}
