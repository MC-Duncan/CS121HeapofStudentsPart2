heapStudents: main.o dates.o address.o student.o
	g++ -g main.o dates.o address.o student.o -o heapStudents

main.o: main.cpp dates.h address.h
	g++ -g -c main.cpp

dates.o: dates.h dates.cpp
	g++ -g -c dates.cpp

address.o: address.h address.cpp
	g++ -g -c address.cpp

run: heapStudents
	./heapStudents

clean:
	rm heapStudents
	rm *.o

debug: heapStudents
	gdb heapStudents

valgrind: heapStudents
	valgrind --leak-check=full ./heapStudents
