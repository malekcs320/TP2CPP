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

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Menu::afficherMenu()
{
    char *choix;
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
}
TrajetSimple *Menu::saisirTS()
{
    char *depart, *arrivee, *moyenTransport;
    const unsigned int taille_max = 30;
    depart = new char[taille_max];
    arrivee = new char[taille_max];
    moyenTransport = new char[taille_max];
    cout << "SAISIE D'UN TRAJET SIMPLE" << endl;
    cout << "Ville de départ : ";
    cin >> depart;
    cout << "Ville d'arrivée : ";
    cin >> arrivee;
    cout << "Moyen de transport : ";
    cin >> moyenTransport;
    return new TrajetSimple(depart, arrivee, moyenTransport);
}
TrajetCompose *Menu::saisirTC()
{
    char *depart, *arrivee, *moyenTransport, *choix;
    TrajetCompose *trajet;
    TrajetSimple *ts;
    int nbTrajets = 1;
    cout << "SAISIE D'UN TRAJET COMPOSE" << endl;
    cout << "Ville de départ : ";
    cin >> depart;
    cout << "Ville d'arrivée : ";
    cin >> arrivee;
    trajet = new TrajetCompose(arrivee, depart);
    do
    {
        cout << "Veuillez saisir les informations du sous-trajet " << nbTrajets << endl;
        ts = saisirTS();
        trajet->ajouterTrajet(ts);
        cout << "Souhaitez-vous ajouter un autre sous-trajet ? (O/n) ";
        cin >> choix;
    } while (strcmp(choix, "n") != 0);
    return trajet;
}
void Menu::rechercher()
{
}
void Menu::afficherCatalogue()
{
    c->afficher();
}
void Menu::ajouterTrajet()
{
    char *choix;
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
}

//-------------------------------------------- Constructeurs - destructeur

Menu::Menu()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Menu

Menu::~Menu()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Menu

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
