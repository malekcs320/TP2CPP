#include <iostream>
#include "Trajet.h"
#include <typeinfo>
#include "Catalogue.h"
#include "TrajetSimple.h"

using namespace std;

#define MAP 1

int main() {
    Trajet * t1 = new Trajet("Paris", "Lyon");
    TrajetSimple * t2 = new TrajetSimple("Paris", "Marseille", "Bus");

    /*ListeTrajets * liste = new ListeTrajets();
    liste->ajouter(t1);
    liste->ajouter(t2);
    liste->afficher();*/

    Catalogue * c = new Catalogue();

    c->ajouterTrajet(t1);
    c->ajouterTrajet(t2);
    c->afficher();

    delete c;
    


    return 0;
}