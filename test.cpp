#include <iostream>
#include "Trajet.h"
#include <typeinfo>
#include "Catalogue.h"

using namespace std;

#define MAP 1

int main() {
    Trajet * t1 = new Trajet("Paris", "Lyon");
    Trajet * t2 = new Trajet("Paris", "Lyon");

    ListeTrajets * liste = new ListeTrajets();
    liste->ajouter(t1);

    //Catalogue * c = new Catalogue();

    //c->ajouterTrajet(t1);
    //c->ajouterTrajet(t2);
    //c->afficher();

    //delete c;


    return 0;
}