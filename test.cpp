#define MAP 1

#include <iostream>
#include <fstream>
#include <typeinfo>

#include "Trajet.h"
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "ListeTrajets.h"
#include "Menu.h"
#include "TrajetCompose.h"

using namespace std;

void testSauvegardeComplete() {
    Catalogue *c = new Catalogue();

    TrajetSimple *ts1 = new TrajetSimple("Paris", "Lyon", "Train");
    c->ajouterTrajet(ts1);
    TrajetSimple *ts2 = new TrajetSimple("Nantes", "Lille", "Bus");
    c->ajouterTrajet(ts2);
    TrajetCompose *tc1 = new TrajetCompose("Paris", "Lyon");
    tc1->ajouterTrajet(new TrajetSimple("Paris", "Clermont-Ferrand", "Train"));
    tc1->ajouterTrajet(new TrajetSimple("Clermont-Ferrand", "Lyon", "Bus"));
    c->ajouterTrajet(tc1);
    TrajetCompose *tc2 = new TrajetCompose("Nice", "Marseille");
    tc2->ajouterTrajet(new TrajetSimple("Nice", "Cannes", "Avion"));
    tc2->ajouterTrajet(new TrajetSimple("Cannes", "Marseille", "Bus"));
    c->ajouterTrajet(tc2);

    c->writeAllFile("testSauvegardeComplete.txt");
    delete c;
}
void testSauvegardeTS()
{
    Catalogue *c = new Catalogue();

    TrajetSimple *ts1 = new TrajetSimple("Paris", "Lyon", "Train");
    c->ajouterTrajet(ts1);
    TrajetSimple *ts2 = new TrajetSimple("Nantes", "Lille", "Bus");
    c->ajouterTrajet(ts2);
    TrajetCompose *tc1 = new TrajetCompose("Paris", "Lyon");
    tc1->ajouterTrajet(new TrajetSimple("Paris", "Clermont-Ferrand", "Train"));
    tc1->ajouterTrajet(new TrajetSimple("Clermont-Ferrand", "Lyon", "Bus"));
    c->ajouterTrajet(tc1);
    TrajetCompose *tc2 = new TrajetCompose("Nice", "Marseille");
    tc2->ajouterTrajet(new TrajetSimple("Nice", "Cannes", "Avion"));
    tc2->ajouterTrajet(new TrajetSimple("Cannes", "Marseille", "Bus"));
    c->ajouterTrajet(tc2);

    c->writeFileByType("testSauvegardeTS.txt", 's');
    delete c;
}

void testSauvegardeTC()
{
    Catalogue *c = new Catalogue();

    TrajetSimple *ts1 = new TrajetSimple("Paris", "Lyon", "Train");
    c->ajouterTrajet(ts1);
    TrajetSimple *ts2 = new TrajetSimple("Nantes", "Lille", "Bus");
    c->ajouterTrajet(ts2);
    TrajetCompose *tc1 = new TrajetCompose("Paris", "Lyon");
    tc1->ajouterTrajet(new TrajetSimple("Paris", "Clermont-Ferrand", "Train"));
    tc1->ajouterTrajet(new TrajetSimple("Clermont-Ferrand", "Lyon", "Bus"));
    c->ajouterTrajet(tc1);
    TrajetCompose *tc2 = new TrajetCompose("Nice", "Marseille");
    tc2->ajouterTrajet(new TrajetSimple("Nice", "Cannes", "Avion"));
    tc2->ajouterTrajet(new TrajetSimple("Cannes", "Marseille", "Bus"));
    c->ajouterTrajet(tc2);

    c->writeFileByType("testSauvegardeTC.txt", 'c');
    delete c;
}

void testSauvegardeVilleDepart()
{
    Catalogue *c = new Catalogue();

    TrajetSimple *ts1 = new TrajetSimple("Paris", "Lyon", "Train");
    c->ajouterTrajet(ts1);
    TrajetSimple *ts2 = new TrajetSimple("Nantes", "Lille", "Bus");
    c->ajouterTrajet(ts2);
    TrajetCompose *tc1 = new TrajetCompose("Paris", "Lyon");
    tc1->ajouterTrajet(new TrajetSimple("Paris", "Clermont-Ferrand", "Train"));
    tc1->ajouterTrajet(new TrajetSimple("Clermont-Ferrand", "Lyon", "Bus"));
    c->ajouterTrajet(tc1);
    TrajetCompose *tc2 = new TrajetCompose("Nice", "Marseille");
    tc2->ajouterTrajet(new TrajetSimple("Nice", "Cannes", "Avion"));
    tc2->ajouterTrajet(new TrajetSimple("Cannes", "Marseille", "Bus"));
    c->ajouterTrajet(tc2);

    c->writeFileByCity("testSauvegardeVilleDepart.txt", 1, "Paris");
    delete c;
}

void testSauvegardeVilleArrivee()
{
    Catalogue *c = new Catalogue();

    TrajetSimple *ts1 = new TrajetSimple("Paris", "Lyon", "Train");
    c->ajouterTrajet(ts1);
    TrajetSimple *ts2 = new TrajetSimple("Nantes", "Lille", "Bus");
    c->ajouterTrajet(ts2);
    TrajetCompose *tc1 = new TrajetCompose("Paris", "Lyon");
    tc1->ajouterTrajet(new TrajetSimple("Paris", "Clermont-Ferrand", "Train"));
    tc1->ajouterTrajet(new TrajetSimple("Clermont-Ferrand", "Lyon", "Bus"));
    c->ajouterTrajet(tc1);
    TrajetCompose *tc2 = new TrajetCompose("Nice", "Marseille");
    tc2->ajouterTrajet(new TrajetSimple("Nice", "Cannes", "Avion"));
    tc2->ajouterTrajet(new TrajetSimple("Cannes", "Marseille", "Bus"));
    c->ajouterTrajet(tc2);

    c->writeFileByCity("testSauvegardeVilleArrivee.txt", 2, "", "Lyon");
    delete c;
}

void testSauvegardeIntervalle() {
    Catalogue *c = new Catalogue();

    TrajetSimple *ts1 = new TrajetSimple("Paris", "Lyon", "Train");
    c->ajouterTrajet(ts1);
    TrajetSimple *ts2 = new TrajetSimple("Nantes", "Lille", "Bus");
    c->ajouterTrajet(ts2);
    TrajetCompose *tc1 = new TrajetCompose("Paris", "Lyon");
    tc1->ajouterTrajet(new TrajetSimple("Paris", "Clermont-Ferrand", "Train"));
    tc1->ajouterTrajet(new TrajetSimple("Clermont-Ferrand", "Lyon", "Bus"));
    c->ajouterTrajet(tc1);
    TrajetCompose *tc2 = new TrajetCompose("Nice", "Marseille");
    tc2->ajouterTrajet(new TrajetSimple("Nice", "Cannes", "Avion"));
    tc2->ajouterTrajet(new TrajetSimple("Cannes", "Marseille", "Bus"));
    c->ajouterTrajet(tc2);

    c->writeFileByInterval("testSauvegardeIntervalle.txt", 3, 4);
    delete c;
}

void testChargementComplet() {
    // On se base sur le fichier testSauvegardeComplete.txt

    Catalogue *c = new Catalogue();
    c->readFile("testSauvegardeComplete.txt");
    c->afficher();
    delete c;
}

void testChargementTS() {
    // On se base sur le fichier testSauvegardeComplete.txt

    Catalogue *c = new Catalogue();
    c->readFile("testSauvegardeComplete.txt", 's');
    c->afficher();
    delete c;
}

void testChargementTC() {
    // On se base sur le fichier testSauvegardeComplete.txt

    Catalogue *c = new Catalogue();
    c->readFile("testSauvegardeComplete.txt", 'c');
    c->afficher();
    delete c;
}

void testChargementVilleDepart() {
    // On se base sur le fichier testSauvegardeComplete.txt

    Catalogue *c = new Catalogue();
    c->readFileByCity("testSauvegardeComplete.txt", "Paris", "");
    c->afficher();
    delete c;
}

void testChargementVilleArrivee() {
    // On se base sur le fichier testSauvegardeComplete.txt

    Catalogue *c = new Catalogue();
    c->readFileByCity("testSauvegardeComplete.txt", "", "Marseille");
    c->afficher();
    delete c;
}

void testChargementIntervalle() {
    // On se base sur le fichier testSauvegardeComplete.txt

    Catalogue *c = new Catalogue();
    c->readFileByIndex("testSauvegardeComplete.txt", 2, 4);
    c->afficher();
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

ATTENTION : Comme Menu vérifie les saisies, les saisies doivent être correctes
dans les tests unitaires
*/

    testSauvegardeComplete();
    testSauvegardeTS();
    testSauvegardeTC();
    testSauvegardeVilleDepart();
    testSauvegardeVilleArrivee();
    testSauvegardeIntervalle();

    testChargementComplet();
    testChargementTS();
    testChargementTC();
    testChargementVilleDepart();
    testChargementVilleArrivee();
    testChargementIntervalle();

    // testMenu(); // exécution du programme en mode utilisateur
    
    return 0;
}