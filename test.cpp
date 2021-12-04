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
    Trajet * test = new Trajet("Paris", "Lyon");
    TrajetSimple * test2 = new TrajetSimple("Paris", "Lyon", "Train");
    //TrajetCompose * test3 = new TrajetCompose("Paris","Nantes");
    t->ajouterTrajet(test);
    t->ajouterTrajet(test2);
    //t->ajouterTrajet(test3);
    t->afficherTrajet();
    //delete test3;
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
void testCatalogue() {
    Catalogue * c = new Catalogue();
    c->ajouterTrajet(new TrajetSimple("Paris", "Lyon", "Train"));
    c->ajouterTrajet(new TrajetSimple("Paris", "Lyon", "Train"));
    TrajetCompose * t = new TrajetCompose("Paris","Lyon");
    t->ajouterTrajet(new TrajetSimple("Paris", "Clermont-Ferrand", "Train"));
    t->ajouterTrajet(new TrajetSimple("Clermont-Ferrand", "Lyon", "Bus"));
    c->ajouterTrajet(t);
    c->afficher();
    c->getTaille();
    delete c;
}


int main() {
    /* test unitaires */
    testListeTrajets();
    testTrajet();
    testTrajetSimple();
    testTrajetCompose();
    testCatalogue();



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