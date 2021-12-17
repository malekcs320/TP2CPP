/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"
#include "Trajet.h"
#include "ListeTrajets.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::afficherTrajet() const
{
    cout << "Trajet composé ";
    Trajet::afficherTrajet();

    for (uint i = 0; i < liste->getTaille(); i++)
    {
        cout << "  - ";
        liste->getElement(i)->afficherTrajet();
    }
}

void TrajetCompose::ajouterTrajet(Trajet *unTrajet)
{
    liste->ajouter(unTrajet);
}

string TrajetCompose::getType() {
    return "TrajetCompose";
}

bool TrajetCompose::estEgal( Trajet* t ){
    if(t->getType() != "TrajetCompose") {
        return false;
    }
    else {
        TrajetCompose * ts = dynamic_cast<TrajetCompose*>(t);
        if (ts->getArrivee() != arrivee || ts->getDepart() != depart) {
            return false;
        }
        for(uint i=0;i<liste->getTaille();i++) {
            if(!liste->getElement(i)->estEgal(t)) return false;
        }
        return true;
    }
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose(const char *depart, const char *arrivee) : Trajet(depart, arrivee)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
    liste = new ListeTrajets;
}

TrajetCompose::~TrajetCompose()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
    delete liste;
    //liste = nullptr;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
