test: test.o Trajet.o Catalogue.o ListeTrajets.o TrajetSimple.o Menu.o TrajetCompose.o
	g++ -ansi -pedantic -Wall -std=c++11 -DMAP -o test test.o Trajet.o Catalogue.o ListeTrajets.o TrajetSimple.o Menu.o TrajetCompose.o

test.o: test.cpp
	g++ -ansi -pedantic -Wall -std=c++11 -DMAP -c test.cpp 

Trajet.o: Trajet.cpp
	g++ -ansi -pedantic -Wall -std=c++11 -DMAP -c Trajet.cpp

Catalogue.o: Catalogue.cpp
	g++ -ansi -pedantic -Wall -std=c++11 -DMAP -c Catalogue.cpp 

ListeTrajets.o: ListeTrajets.cpp
	g++ -ansi -pedantic -Wall -std=c++11 -DMAP -c ListeTrajets.cpp

TrajetSimple.o: TrajetSimple.cpp 
	g++ -ansi -pedantic -Wall -std=c++11 -DMAP -c TrajetSimple.cpp

TrajetCompose.o: TrajetCompose.cpp 
	g++ -ansi -pedantic -Wall -std=c++11 -DMAP -c TrajetCompose.cpp

Menu.o: Menu.cpp 
	g++ -ansi -pedantic -Wall -std=c++11 -DMAP -c Menu.cpp