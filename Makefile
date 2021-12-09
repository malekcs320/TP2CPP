sejours: test.o Trajet.o Catalogue.o ListeTrajets.o TrajetSimple.o Menu.o TrajetCompose.o
	g++ -g -ansi -pedantic -Wall -std=c++11 -o sejours test.o Trajet.o Catalogue.o ListeTrajets.o TrajetSimple.o Menu.o TrajetCompose.o

sejoursmap: testmap.o Trajetmap.o Cataloguemap.o ListeTrajetsmap.o TrajetSimplemap.o Menumap.o TrajetComposemap.o
	g++ -ansi -pedantic -Wall -std=c++11 -o sejours test.o Trajet.o Catalogue.o ListeTrajets.o TrajetSimple.o Menu.o TrajetCompose.o

test.o: test.cpp
	g++ -ansi -pedantic -Wall -std=c++11 -c test.cpp 

testmap.o: test.cpp
	g++ -ansi -pedantic -Wall -std=c++11 -DMAP -c test.cpp 

Trajet.o: Trajet.cpp
	g++ -ansi -pedantic -Wall -std=c++11 -c Trajet.cpp

Trajetmap.o: Trajet.cpp
	g++ -ansi -pedantic -Wall -std=c++11 -DMAP -c Trajet.cpp

Catalogue.o: Catalogue.cpp
	g++ -ansi -pedantic -Wall -std=c++11 -c Catalogue.cpp 

Cataloguemap.o: Catalogue.cpp
	g++ -ansi -pedantic -Wall -std=c++11 -DMAP -c Catalogue.cpp 

ListeTrajets.o: ListeTrajets.cpp
	g++ -ansi -pedantic -Wall -std=c++11 -c ListeTrajets.cpp

ListeTrajetsmap.o: ListeTrajets.cpp
	g++ -ansi -pedantic -Wall -std=c++11 -DMAP -c ListeTrajets.cpp

TrajetSimple.o: TrajetSimple.cpp 
	g++ -ansi -pedantic -Wall -std=c++11 -c TrajetSimple.cpp

TrajetSimplemap.o: TrajetSimple.cpp 
	g++ -ansi -pedantic -Wall -std=c++11 -DMAP -c TrajetSimple.cpp

TrajetCompose.o: TrajetCompose.cpp 
	g++ -ansi -pedantic -Wall -std=c++11 -c TrajetCompose.cpp

TrajetComposemap.o: TrajetCompose.cpp 
	g++ -ansi -pedantic -Wall -std=c++11 -DMAP -c TrajetCompose.cpp

Menu.o: Menu.cpp 
	g++ -ansi -pedantic -Wall -std=c++11 -c Menu.cpp

Menumap.o: Menu.cpp 
	g++ -ansi -pedantic -Wall -std=c++11 -DMAP -c Menu.cpp