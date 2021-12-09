/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetSimple::afficherTrajet() const
{
    cout << "de " << depart << " à " << arrivee << " en " << transport << endl;
}

char *TrajetSimple::getTransport()
{
    return transport;
}

bool TrajetSimple::estTrajetCompose() const
{
    return false;
}

bool TrajetSimple::estEgal( Trajet* t ){
    return (!(t->estTrajetCompose()))&& (strcmp(depart, t->getDepart()) == 0 && strcmp(arrivee, t->getArrivee()) == 0) &&strcmp(t->getTransport(), transport);

}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple(const char *depart$, const char *arrivee$, const char *transport$) : Trajet(depart$, arrivee$)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif

    transport = new char[strlen(transport$) + 1];
    strcpy(transport, transport$);

} //----- Fin de TrajetSimple

TrajetSimple::~TrajetSimple()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
    delete[] transport;
} //----- Fin de ~TrajetSimple

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
