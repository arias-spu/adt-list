#ifndef OBJECT_H
#define OBJECT_H

#include <string>
using std::string;

class Object{

public:
	Object();
	virtual ~Object();
	virtual string ToString()const;
	virtual bool Equals(const Object& rhs)const;
};

#endif
