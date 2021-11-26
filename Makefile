test: test.o Trajet.o
	g++ -o test test.o Trajet.o

test.o: test.cpp
	g++ -c test.cpp 

Trajet.o: Trajet.cpp
	g++ -c Trajet.cpp

