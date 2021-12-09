/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Xxx> (fichier Xxx.cpp) ------------

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

    for (int i = 0; i < liste->getTaille(); i++)
    {
        cout << "  - ";
        liste->getElement(i)->afficherTrajet();
    }
}

void TrajetCompose::ajouterTrajet(Trajet *unTrajet)
{
    liste->ajouter(unTrajet);
}
// bool estEgal ( const Trajet &t )
// {

// }
bool TrajetCompose::estTrajetCompose() const
{
    return true;
}

bool TrajetCompose::estEgal( Trajet* t ){
    if (!(t->estTrajetCompose())) return false;
    bool test = true;
    for(int i=0;i<liste->getTaille();i++){
    test = (liste->getElement(i))->estEgal(t);
    if (!test) return false;
    }
    return true;
}
char *TrajetCompose::getTransport()
{
    cout<<"Veuillez voir le mode de transport de chaque trajet simple qui compose ce trajet"<<endl;
    return 0;
}
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose(const char *depart, const char *arrivee) : Trajet(depart, arrivee)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur" << endl;
#endif
    liste = new ListeTrajets;
}

TrajetCompose::~TrajetCompose()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Xxx>" << endl;
#endif
    delete liste;
    liste = nullptr;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
