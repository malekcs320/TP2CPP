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
    Trajet * test = new Trajet("Paris", "Nantes");
    TrajetSimple * test2 = new TrajetSimple("Nantes", "Lyon", "Train");
    TrajetSimple * test3 = new TrajetSimple("Nantes", "Toulouse", "Train");
    t->ajouterTrajets(test);
    t->ajouterTrajets(test2);
    t->ajouterTrajets(test3);
    t->afficherTrajet();
    delete t;
}
void testListeTrajets() {
    Trajet * t1 = new TrajetSimple("Paris", "Lyon","fusee");
    Trajet * t2 = new Trajet("Paris", "Marseille");
    Trajet * t3 = new TrajetCompose("Paris", "Nantes");
    ListeTrajets * liste = new ListeTrajets;

    liste->ajouter(t1);
    liste->ajouter(t2);
    liste->ajouter(t3);
    
    //iste->supprimerTrajet(2);//marche pas pour index 0
    liste->afficher();
    //liste->getElement(0)->afficherTrajet();
    //erreur corrigée en commentant le code du destructeur de ListeTrajets( à voir )
    delete liste;
}


int main() {
    /* test unitaires */
     //testListeTrajets();
    // testTrajet();
    // testTrajetSimple();
    //testTrajetCompose();




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
    Trajet * t1 = new TrajetSimple("Paris", "Lyon","fusee");
    Trajet * t2 = new TrajetSimple("Marseille", "Nantes","vélo");
    TrajetCompose * t3 = new TrajetCompose("Paris", "Nantes");
    Trajet * t4 = new TrajetSimple("Paris", "Nantes","vélo");
    Trajet * t5 = new TrajetSimple("Lyon", "Marseille","vélo");

    Catalogue * c = new Catalogue();
    //t3->ajouterTrajets(t1); //pour que ça marche il faut déclarer t3 comme TrajetCompose *
    //t3->ajouterTrajets(t2);
    c->ajouterTrajet(t1);
    c->ajouterTrajet(t2);
    c->ajouterTrajet(t3);
    c->ajouterTrajet(t4);
    c->ajouterTrajet(t5);
    c->afficher();
    c->supprimerTrajet(0);
    c->afficher();
    //cout<<" recherche trajet Paris ---> Nantes"<<endl;
    //ListeTrajets* dejaVisite = new ListeTrajets;
    //c->rechercheSimple("Paris","Nantes")->afficher();
    //c->rechercheAvancee("Paris","Nantes",dejaVisite);
    
    //delete dejaVisite;
    delete c;
/*
    Menu * m = new Menu();
    m->afficherMenu();
    */


    return 0;
}