test: test.o Trajet.o Catalogue.o ListeTrajets.o TrajetSimple.o Menu.o TrajetCompose.o
	g++ -o test test.o Trajet.o Catalogue.o ListeTrajets.o TrajetSimple.o Menu.o TrajetCompose.o

test.o: test.cpp
	g++ -c test.cpp 

Trajet.o: Trajet.cpp
	g++ -c Trajet.cpp

Catalogue.o: Catalogue.cpp
	g++ -c Catalogue.cpp 

ListeTrajets.o: ListeTrajets.cpp
	g++ -c ListeTrajets.cpp

TrajetSimple.o: TrajetSimple.cpp 
	g++ -c TrajetSimple.cpp

TrajetCompose.o: TrajetCompose.cpp 
	g++ -c TrajetCompose.cpp

Menu.o: Menu.cpp 
	g++ -c Menu.cpp