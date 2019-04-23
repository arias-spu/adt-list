#include "person.h"
#include "integer.h"
#include "list.h"
#include "fsarray.h"
#include "vsarray.h"
#include "linkedlist.h"
#include "dlinkedlist.h"

#include <cassert>
#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

void Test(List*, const string&, bool=true);


int main(int argc, char* argv[]){
	cout << "===================================" << endl;
	cout << endl << endl;
	cout << "There are 4 sets of unit tests:" << endl;
	cout << "	1. Fixed Size Array List	- 35" << endl;
	cout << "	2. Variable Size Array List	- 55" << endl;
	cout << "	3. Linked List			- 55" << endl;
	cout << "	4. Double Linked List		- 55" << endl;
	cout << "===================================" << endl;
	cout << "===================================" << endl;
	cout << endl << endl;
	cout << "Fixed Size Array List Tests" << endl;
	Test(new FSArray(5), "Fixed Size Array List");

	cout << "Variable Size List Tests" << endl;
	Test(new VSArray(5) , "Variable Size Array List", false);

	cout << "Linked List Tests" << endl;
	Test(new LinkedList(), "Linked List", false);

	cout << "Double Linked List Tests" << endl;
	Test(new DLinkedList(), "Double Linked List", false);

	return 0;
}

void Test(List* list, const string& message, bool fixedSize){
	cout << "TESTING: " << message << endl << endl;
	size_t passed = 0;

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

	if (fixedSize){
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

	}else{
		assert(list->Insert(new Person("Violet", 1),  list->Size()) == true);
		cout << "\t" << ++passed << "\tTests Passed" << endl;
		assert(list->Size() == 6);
		cout << "\t" << ++passed << "\tTests Passed" << endl;
		assert( (object = list->Remove(5)) != nullptr );
		cout << "\t" << ++passed << "\tTests Passed" << endl;
		assert(object->ToString() == "Person: {name: Violet, age: 1}");
		cout << "\t" << ++passed << "\tTests Passed" << endl;
		assert(list->Size() == 5);
		cout << "\t" << ++passed << "\tTests Passed" << endl;

		// Final Version Tests for ALL CODE
		stringstream inputData, insertedData;
		inputData.str(	// name age position | number position
			"Winston 55 0\n"
			"75 0\n"
			"Peter 43 3\n"
			"32 3\n"
			"Legolas 156 9\n"
			"99 1\n"
			"Patricia 21 0\n"
			"130 0\n"
			"Anna 23 1\n"
			"1304 14"
		);
		string name;
		size_t age, position, number;
		for (size_t i = 0; i < 5; i++) {
			inputData >> name >> age >> position;
			assert(list->Insert(new Person(name, age), position) == true);
			cout << "\t" << ++passed << "\tTests Passed" << endl;
			inputData >> number >> position;
			assert(list->Insert(new Integer(number), position) == true);
			cout << "\t" << ++passed << "\tTests Passed" << endl;
		}

		assert(list->Size() == 15);
		cout << "\t" << ++passed << "\tTests Passed" << endl;

		insertedData.str(	// name age position | number position
			"Winston 55 5\n"
			"75 3\n"
			"Peter 43 8\n"
			"32 7\n"
			"Legolas 156 13\n"
			"99 4\n"
			"Patricia 21 2\n"
			"130 0\n"
			"Anna 23 1\n"
			"1304 14"
		);

		for (size_t i = 0; i < 5; i++) {
			insertedData >> name >> age >> position;
			object = new Person(name, age);
			assert(list->IndexOf(object) == position);
			cout << "\t" << ++passed << "\tTests Passed" << endl;
			insertedData >> number >> position;
			delete object;
			object = nullptr;
			object = new Integer(number);
			assert(list->IndexOf(object) == position);
			cout << "\t" << ++passed << "\tTests Passed" << endl;
			delete object;
			object = nullptr;
		}
		assert( (object = list->Remove(4)) != nullptr);
		cout << "\t" << ++passed << "\tTests Passed" << endl;

		assert(list->Size() == 14);
		cout << "\t" << ++passed << "\tTests Passed" << endl;

		assert(object->ToString() == "99");
		cout << "\t" << ++passed << "\tTests Passed" << endl;
		delete object;
		object = nullptr;

		assert( (object = list->Get(7)) != nullptr);
		cout << "\t" << ++passed << "\tTests Passed" << endl;

		assert(object->ToString() == "Person: {name: Peter, age: 43}");
		cout << "\t" << ++passed << "\tTests Passed" << endl;

	}


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

}
