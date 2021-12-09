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

void testTrajet() // par définition, on ne peut pas construire un trajet pur : il faut préciser sa nature (trjaet classe abstraite)
{
    Trajet *t1 = new TrajetCompose("Paris", "Lyon");
    t1->afficherTrajet();
    t1->getArrivee();
    t1->getDepart();
    delete t1;
}
void testTrajetSimple()
{
    TrajetSimple *t1 = new TrajetSimple("Paris", "Lyon", "Train");
    t1->afficherTrajet();
    t1->getArrivee();
    t1->getDepart();
    t1->getTransport();
    delete t1;
}
void testTrajetCompose()
{
    TrajetCompose *t = new TrajetCompose("Paris", "Lyon");
    t->afficherTrajet();
    t->getArrivee();
    t->getDepart();
    Trajet *test = new TrajetCompose("Paris", "Nantes");
    TrajetSimple *test2 = new TrajetSimple("Nantes", "Lyon", "Train");
    TrajetSimple *test3 = new TrajetSimple("Nantes", "Toulouse", "Train");
    t->ajouterTrajet(test);
    t->ajouterTrajet(test2);
    t->ajouterTrajet(test3);
    t->afficherTrajet();
    delete t;
}
void testListeTrajets()
{
    Trajet *t1 = new TrajetSimple("Paris", "Lyon", "fusee");
    Trajet *t2 = new TrajetCompose("Paris", "Marseille");
    Trajet *t3 = new TrajetCompose("Paris", "Nantes");
    ListeTrajets *liste = new ListeTrajets;

    liste->ajouter(t1);
    liste->ajouter(t2);
    //liste->ajouter(t3);
    liste->ajouter(t3);
    // iste->supprimerTrajet(2);//marche pas pour index 0
    //liste->afficher();
    // liste->getElement(0)->afficherTrajet();
    // erreur corrigée en commentant le code du destructeur de ListeTrajets( à voir )
    delete liste;
}
void testCatalogue()
{
    Catalogue *c = new Catalogue();
    c->ajouterTrajet(new TrajetSimple("Paris", "Lyon", "Train"));
    c->ajouterTrajet(new TrajetSimple("Paris", "Lyon", "Train"));
    TrajetCompose *t = new TrajetCompose("Paris", "Lyon");
    t->ajouterTrajet(new TrajetSimple("Paris", "Clermont-Ferrand", "Train"));
    t->ajouterTrajet(new TrajetSimple("Clermont-Ferrand", "Lyon", "Bus"));
    c->ajouterTrajet(t);
    c->afficher();
    c->getTaille();
    c->rechercheSimple("Paris", "Lyon");
    c->rechercheAvancee("Paris", "Lyon");
    delete c;
}
void testMenu() {
    Menu * m = new Menu();
    m->afficherMenu();
    delete m;
}

int main()
{
    /* test unitaires */
    //   testListeTrajets();
    //   testTrajetSimple();
    //   testTrajetCompose();
    //   testCatalogue();
    testMenu();
    
    // Trajet *t1 = new TrajetSimple("Paris", "Lyon", "fusee");
    // TrajetCompose *t2 = new TrajetCompose("Paris", "Nantes");
    // t2->ajouterTrajet(new TrajetSimple("Paris", "Clermont-Ferrand", "Train"));
    // t2->ajouterTrajet(new TrajetSimple("Clermont-Ferrand", "Nantes", "Bus"));
    // Trajet *t3 = new TrajetSimple("Marseille", "Nantes", "vélo");
    // Trajet *t4 = new TrajetSimple("Paris", "Nantes", "vélo");
    // Trajet *t5 = new TrajetSimple("Lyon", "Marseille", "vélo");

    
    // Catalogue *c = new Catalogue;
    //  c->ajouterTrajet(t1);
    //  c->ajouterTrajet(t2);
    //  c->ajouterTrajet(t3);
    //  c->ajouterTrajet(t4);
    //  c->ajouterTrajet(t5);

    //  c->rechercheSimple("Paris", "Nantes");
    //  c->rechercheAvancee("Paris", "Nantes");

     //delete c;
        
        
    
    

    
    return 0;
}