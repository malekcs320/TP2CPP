test: test.o Trajet.o Catalogue.o ListeTrajets.o
	g++ -o test test.o Trajet.o Catalogue.o ListeTrajets.o

test.o: test.cpp
	g++ -c test.cpp 

Trajet.o: Trajet.cpp
	g++ -c Trajet.cpp

Catalogue.o: Catalogue.cpp
	g++ -c Catalogue.cpp 

ListeTrajets.o: ListeTrajets.cpp
	g++ -c ListeTrajets.cpp

