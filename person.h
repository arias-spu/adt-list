#ifndef PERSON
#define PERSON

#include "object.h"
#include <string>
using std::string;

class Person : public Object{
		char* _name;
		size_t _age;
	public:
		Person(const string& name, size_t age);
		Person(const Person& person);
		const Person& operator=(const Person& rhs);
		virtual ~Person();
		virtual string ToString()const;
		virtual bool Equals(const Object& rhs)const;
		void Birthday();
};

#endif /* end of include guard: PERSON */
