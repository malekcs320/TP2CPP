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
    liste->ajouter(t3);
    liste->supprimerTrajet(2);
    liste->afficher();
    liste->getElement(0)->afficherTrajet();
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
    Trajet *t1 = new TrajetSimple("Clermont-Ferrand", "Lyon", "Train");
    c->ajouterTrajet(t1);
    c->afficher();
    c->getTaille();
    c->rechercheSimple("Paris", "Lyon");
    c->rechercheAvancee("Paris", "Lyon");
    c->afficher();
    c->supprimerTrajet(3);
    c->afficher();
    delete c;
}
void testSuppressionTeteTaille1() {
    // suppression de l'élément en tête pour une liste de taille 1
    cout << "suppression de l'élément en tête pour une liste de taille 1"<< endl;
    Catalogue *c = new Catalogue();
    c->ajouterTrajet(new TrajetSimple("Paris", "Lyon", "Train"));
    c->supprimerTrajet(1);
    delete c;
}
void testSuppressionTeteTaille2() {
    // suppression de l'élément en tête pour une liste de taille > 1
    cout << "suppression de l'élément en tête pour une liste de taille > 1"<< endl;
    Catalogue *c = new Catalogue();
    c->ajouterTrajet(new TrajetSimple("Paris", "Lyon", "Train"));
    c->ajouterTrajet(new TrajetSimple("Paris", "Marseille", "Bus"));
    c->supprimerTrajet(1);
    delete c;
}
void testSuppressionPasTeteTaille3() {
    // suppression d'un élément pas en tête pour une liste de taille > 1
    cout << "suppression d'un élément pas en tête pour une liste de taille > 1"<< endl;
    Catalogue *c = new Catalogue();
    c->ajouterTrajet(new TrajetSimple("Paris", "Lyon", "Train"));
    c->ajouterTrajet(new TrajetSimple("Paris", "Marseille", "Bus"));
    c->ajouterTrajet(new TrajetSimple("Paris", "Marseille", "Train"));
    c->supprimerTrajet(2);
    delete c;
}
void testMenu() {
    Menu * m = new Menu();
    m->afficherMenu();
    delete m;
}

int main()
{
/*
Cette classe a été notre bac à sable pour tester nos programmes.
Les tests unitaires permettent d'appeler toutes (ou presque) les méthodes, afin
d'éviter les erreurs d'exécution et de visualiser les fuites de mémoires.
*/


    /* test unitaires */
    /* testListeTrajets();
    testTrajetSimple();
    testTrajetCompose();
    testCatalogue();
    testMenu(); */
    /*testSuppressionTeteTaille1();
    testSuppressionTeteTaille2();
    testSuppressionPasTeteTaille3(); */

    testMenu(); // exécution du programme

    
    
    return 0;
}