/*************************************************************************
                           Menu  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Menu> (fichier Menu.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
//------------------------------------------------------ Include personnel
#include "Menu.h"

//------------------------------------------------------------- Constantes
const unsigned int TAILLE_MAX_NOM_VILLE = 40 + 1;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Menu::afficherMenu()
{
    char *choix = new char[2];
    do
    {
        cout << "-------------- MENU --------------" << endl;
        cout << "1 : Ajouter un trajet au catalogue" << endl;
        cout << "2 : Rechercher un trajet dans le catalogue" << endl;
        cout << "3 : Afficher le catalogue" << endl;
        cout << "Veuillez entrer votre choix (q pour quitter) : ";
        cin >> choix;
        while (strcmp(choix, "1") != 0 && strcmp(choix, "2") != 0 && strcmp(choix, "3") != 0 && strcmp(choix, "q") != 0)
        {
            cout << "Choix incorrect. Choix possibles : 1, 2, 3, q. Choix : ";
            cin >> choix;
        }
        if (strcmp(choix, "1") == 0)
        {
            this->ajouterTrajet();
        }
        else if (strcmp(choix, "2") == 0)
        {
            this->rechercher();
        }
        else if (strcmp(choix, "3") == 0)
        {
            this->afficherCatalogue();
        }

    } while (strcmp(choix, "q") != 0);
    delete[] choix;
}
TrajetSimple *Menu::saisirTS(const char *ville_depart)
{
    char *depart, *arrivee, *moyenTransport;
    depart = new char[TAILLE_MAX_NOM_VILLE];
    arrivee = new char[TAILLE_MAX_NOM_VILLE];
    moyenTransport = new char[TAILLE_MAX_NOM_VILLE];
    cout << ">> SAISIE D'UN TRAJET SIMPLE" << endl;
    cout << "Ville de départ : ";
    if (ville_depart == nullptr)
    {
        cin >> depart;
    }
    else
    {
        strcpy(depart, ville_depart);
        cout << ville_depart << endl;
    }
    cout << "Ville d'arrivée : ";
    cin >> arrivee;
    cout << "Moyen de transport : ";
    cin >> moyenTransport;
    TrajetSimple *t = new TrajetSimple(depart, arrivee, moyenTransport);
    delete[] depart;
    delete[] arrivee;
    delete[] moyenTransport;
    return t;
}
TrajetCompose *Menu::saisirTC()
{

    char *depart = new char[TAILLE_MAX_NOM_VILLE],
         *arrivee = new char[TAILLE_MAX_NOM_VILLE],
         *moyenTransport = new char[TAILLE_MAX_NOM_VILLE],
         *choix = new char[2],
         *derniereVille;
    TrajetCompose *trajet;
    TrajetSimple *ts;
    int nbTrajets = 1;
    cout << ">> SAISIE D'UN TRAJET COMPOSE" << endl;
    cout << "Ville de départ : ";
    cin >> depart;
    cout << "Ville d'arrivée : ";
    cin >> arrivee;
    trajet = new TrajetCompose(depart, arrivee);
    derniereVille = new char[TAILLE_MAX_NOM_VILLE];
    strcpy(derniereVille, depart);
    cout << "Saisie des sous-trajets (jusqu'à arriver à " << arrivee << ") : " << endl;
    do
    {
        cout << "> Veuillez saisir les informations du sous-trajet " << nbTrajets << endl;
        ts = saisirTS(derniereVille);
        strcpy(derniereVille, ts->getArrivee());
        trajet->ajouterTrajet(ts);
        nbTrajets++;
        /*cout << "Souhaitez-vous ajouter un autre sous-trajet ? (O/n) ";
        cin >> choix;*/
    } while (/*strcmp(choix, "n") != 0*/ strcmp(derniereVille, arrivee) != 0);
    delete[] depart;
    delete[] arrivee;
    delete[] moyenTransport;
    delete[] choix;
    delete[] derniereVille;
    return trajet;
}
void Menu::rechercher()
{
    char *choix = new char[2],
         *depart = new char[TAILLE_MAX_NOM_VILLE],
         *arrivee = new char[TAILLE_MAX_NOM_VILLE];
    cout << "Quelle recherche souhaitez-vous effectuer ? Simple ou Avancée ? (s/a) ";
    cin >> choix;
    while (strcmp(choix, "a") != 0 && strcmp(choix, "s") != 0)
    {
        cout << "Choix incorrect. Choix possibles : a, s. Choix : ";
        cin >> choix;
    }
    cout << "Ville de départ : ";
    cin >> depart;
    cout << "Ville d'arrivée : ";
    cin >> arrivee;

    if (strcmp(choix, "s") == 0)
    {
        c->rechercheSimple(depart, arrivee);
    }
    else
    {
        c->rechercheAvancee(depart, arrivee);
    }
    delete[] depart;
    delete[] arrivee;
    delete[] choix;
}
void Menu::afficherCatalogue()
{
    c->afficher();
}
void Menu::ajouterTrajet()
{
    char *choix = new char[2];
    cout << "Souhaitez-vous ajouter un trajet simple (s) ou composé (c) ? (s/c) Choix : ";
    cin >> choix;
    while (strcmp(choix, "s") != 0 && strcmp(choix, "c") != 0)
    {
        cout << "Choix incorrect. Choix possibles : s, c. Choix : ";
        cin >> choix;
    }
    if (strcmp(choix, "s") == 0)
    {
        c->ajouterTrajet(saisirTS());
    }
    else
    {
        c->ajouterTrajet(saisirTC());
    }
    delete[] choix;
}

//-------------------------------------------- Constructeurs - destructeur

Menu::Menu()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
    c = new Catalogue();
} //----- Fin de Menu

Menu::~Menu()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
    delete c;
} //----- Fin de ~Menu

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
