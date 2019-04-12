CFLAGS = -std=c++11 -Wall

main:	main.o object.o fsarray.o list.o integer.o person.o
	g++ main.o object.o fsarray.o list.o integer.o person.o -o list $(CFLAGS)

main.o:	main.cpp fsarray.h list.h integer.h person.h object.h
	g++ -c main.cpp -o main.o $(CFLAGS)

object.o:	object.h object.cpp
	g++ -c object.cpp -o object.o $(CFLAGS)

fsarray.o:	list.h fsarray.cpp fsarray.h object.h
	g++ -c fsarray.cpp -o fsarray.o $(CFLAGS)

list.o:	list.h list.cpp object.h
	g++ -c list.cpp -o list.o $(CFLAGS)

integer.o:	object.h integer.h integer.cpp
	g++ -c integer.cpp -o integer.o $(CFLAGS)

person.o:	object.h person.h person.cpp
	g++ -c person.cpp -o person.o $(CFLAGS)

test:	test.o object.o fsarray.o list.o person.o integer.o 
	g++ test.o object.o fsarray.o list.o integer.o person.o -o list $(CFLAGS)

test.o:	test.cpp fsarray.h list.h integer.h person.h object.h
	g++ -c test.cpp -o test.o $(CFLAGS)

clean:
	rm list *.o
