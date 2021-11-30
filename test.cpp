#define MAP 1

#include <iostream>
#include <typeinfo>


#include "Trajet.h"
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "ListeTrajets.h"
#include "Menu.h"
#include "TrajetCompose.h"

using namespace std;

void testTrajet() {
    Trajet * t1 = new Trajet("Paris", "Lyon");
    t1->afficherTrajet();
    t1->getArrivee();
    t1->getDepart();
    delete t1;
}
void testTrajetSimple() {
    TrajetSimple * t1 = new TrajetSimple("Paris", "Lyon", "Train");
    t1->afficherTrajet();
    t1->getArrivee();
    t1->getDepart();
    t1->getTransport();
    delete t1;
}
void testTrajetCompose() {
    TrajetCompose * t = new TrajetCompose("Paris","Lyon");
    t->afficherTrajet();
    t->getArrivee();
    t->getDepart();
    delete t;
}
void testListeTrajets() {
    Trajet * t1 = new Trajet("Paris", "Lyon");
    Trajet * t2 = new Trajet("Paris", "Marseille");
    ListeTrajets * liste = new ListeTrajets();
    liste->ajouter(t1);
    liste->ajouter(t2);
    liste->afficher();
    delete liste;
}


int main() {
    /* test unitaires */
    testListeTrajets();
    testTrajet();
    testTrajetSimple();
    testTrajetCompose();




    //Trajet * t1 = new Trajet("Paris", "Lyon");
    /*t1->afficherTrajet();
    t1->getArrivee();
    t1->getDepart();
    delete t1;*/
    //TrajetSimple * t2 = new TrajetSimple("Paris", "Marseille", "Bus");

    /*ListeTrajets * liste = new ListeTrajets();
    liste->ajouter(t1);
    liste->ajouter(t2);
    liste->afficher();*/

   /* Catalogue * c = new Catalogue();

    c->ajouterTrajet(t1);
    c->ajouterTrajet(t2);
    c->afficher();

    delete c;*/
/*
    Menu * m = new Menu();
    m->afficherMenu();
    */


    return 0;
}