#include "person.h"
#include "integer.h"
#include "list.h"
#include "fsarray.h"

#include <cassert>
#include <iostream>
using std::cout;
using std::endl;


int main(int argc, char* argv[]){
	size_t passed = 0;
	List* list = new FSArray(5);

	assert(list->Size() == 0);
	cout << "\t" << ++passed << "\tTests Passed" << endl;

	assert(list->IsEmpty() == true);
	cout << "\t" << ++passed << "\tTests Passed" << endl;

	Person* person = nullptr;
	Integer* integer = nullptr;
	Object* object = nullptr;
	Person* GEORGE = new Person("George", 12);
	Integer* TEN = new Integer(10);
	Object* DUMMY = new Object();

	person = new Person("George", 12);
	assert(list->Insert(person, 2) == false);
	cout << "\t" << ++passed << "\tTests Passed" << endl;

	assert(list->IsEmpty() == true);
	cout << "\t" << ++passed << "\tTests Passed" << endl;

	assert(list->Insert(person, 0) == true);
	cout << "\t" << ++passed << "\tTests Passed" << endl;

	assert(list->Get(0)->ToString() == "Person: {name: George, age: 12}");
	cout << "\t" << ++passed << "\tTests Passed" << endl;

	assert(list->Size() == 1);
	cout << "\t" << ++passed << "\tTests Passed" << endl;

	assert(list->IndexOf(GEORGE) == 0);
	cout << "\t" << ++passed << "\tTests Passed" << endl;

	integer = new Integer(10);
	assert(list->Insert(integer, 0) == true);
	cout << "\t" << ++passed << "\tTests Passed" << endl;

	assert(list->Get(0)->ToString() == "10");
	cout << "\t" << ++passed << "\tTests Passed" << endl;

	assert(list->Get(1)->ToString() == "Person: {name: George, age: 12}");
	cout << "\t" << ++passed << "\tTests Passed" << endl;

	assert(list->Size() == 2);
	cout << "\t" << ++passed << "\tTests Passed" << endl;

	assert(list->IndexOf(TEN) == 0);
	cout << "\t" << ++passed << "\tTests Passed" << endl;

	assert(list->IndexOf(GEORGE) == 1);
	cout << "\t" << ++passed << "\tTests Passed" << endl;

	assert(list->IndexOf(DUMMY) == -1);
	cout << "\t" << ++passed << "\tTests Passed" << endl;

	person = new Person("Patrick", 1);
	assert(list->Insert(person, 1) == true);
	cout << "\t" << ++passed << "\tTests Passed" << endl;

	assert(list->Size() == 3);
	cout << "\t" << ++passed << "\tTests Passed" << endl;

	person = new Person("Natalia", 19);
	assert(list->Insert(person, 2) == true);
	cout << "\t" << ++passed << "\tTests Passed" << endl;

	assert(list->Size() == 4);
	cout << "\t" << ++passed << "\tTests Passed" << endl;

	integer = new Integer(4);
	assert(list->Insert(integer, 4) == true);
	cout << "\t" << ++passed << "\tTests Passed" << endl;

	assert(list->Size() == 5);
	cout << "\t" << ++passed << "\tTests Passed" << endl;

	for (size_t i = 0; i < list->Size(); i++) {
		assert(list->Insert(integer, i) == false);
		cout << "\t" << ++passed << "\tTests Passed" << endl;
	}

	assert( (object = list->Remove(0)) != nullptr );
	cout << "\t" << ++passed << "\tTests Passed" << endl;

	assert(list->Size() == 4);
	cout << "\t" << ++passed << "\tTests Passed" << endl;

	assert(object->ToString() == "10");
	cout << "\t" << ++passed << "\tTests Passed" << endl;
	delete object;
	object = nullptr;

	TEN->SetValue(4);
	assert(list->IndexOf(TEN) == 3);
	cout << "\t" << ++passed << "\tTests Passed" << endl;

	assert(list->IndexOf(GEORGE) == 2);
	cout << "\t" << ++passed << "\tTests Passed" << endl;

	TEN->SetValue(10);
	assert(list->IndexOf(TEN) == -1);
	cout << "\t" << ++passed << "\tTests Passed" << endl;

	list->Clear();
	assert(list->Size() == 0);
	cout << "\t" << ++passed << "\tTests Passed" << endl;

	assert(list->IsEmpty() == true);
	cout << "\t" << ++passed << "\tTests Passed" << endl;

	delete list;
	delete GEORGE;
	delete TEN;
	delete DUMMY;

	cout << "\t" << ++passed << "\tTests Passed" << endl;
	cout << "= = = = = = = = = = = = = = = = = = = = = " << endl;
	cout << endl << "F i n i s h e d   S u c c e s s f u l l y" << endl;
	return 0;
}
