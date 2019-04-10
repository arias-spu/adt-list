#include "object.h"

#include <string>
#include <sstream>
using std::string;
using std::stringstream;

Object::Object(){

}
Object::~Object(){

}
string Object::ToString()const{
	stringstream retVal;
	retVal << "Object @ " << this;
	return retVal.str();
}
bool Object::Equals(const Object& rhs)const{
	if (this == &rhs){
		return true;
	}else{
		return false;
	}
}
Object* Object::Clone()const{
	return new Object();
}
