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
#include <string>
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

std::string TrajetSimple::getType() {
    return "TrajetSimple";
}

bool TrajetSimple::estEgal( Trajet* t ){
    if(t->getType() != "TrajetSimple") {
        return false;
    }
    else {
        TrajetSimple * ts = dynamic_cast<TrajetSimple*>(t);
        return ts->getArrivee() == arrivee && ts->getDepart() == depart && ts->getTransport() == transport;
        
    }
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
