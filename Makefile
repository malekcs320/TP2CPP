test: test.o Trajet.o Catalogue.o ListeTrajets.o TrajetSimple.o Menu.o TrajetCompose.o
	g++ -ansi -pedantic -Wall -std=c++11 -o test test.o Trajet.o Catalogue.o ListeTrajets.o TrajetSimple.o Menu.o TrajetCompose.o

test.o: test.cpp
	g++ -ansi -pedantic -Wall -std=c++11 -c test.cpp 

Trajet.o: Trajet.cpp
	g++ -ansi -pedantic -Wall -std=c++11 -c Trajet.cpp

Catalogue.o: Catalogue.cpp
	g++ -ansi -pedantic -Wall -std=c++11 -c Catalogue.cpp 

ListeTrajets.o: ListeTrajets.cpp
	g++ -ansi -pedantic -Wall -std=c++11 -c ListeTrajets.cpp

TrajetSimple.o: TrajetSimple.cpp 
	g++ -ansi -pedantic -Wall -std=c++11 -c TrajetSimple.cpp

TrajetCompose.o: TrajetCompose.cpp 
	g++ -ansi -pedantic -Wall -std=c++11 -c TrajetCompose.cpp

Menu.o: Menu.cpp 
	g++ -ansi -pedantic -Wall -std=c++11 -c Menu.cpp