/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Trajet::afficherTrajet() const
    {
        cout<< "De "<<depart<<" à "<<arrivee<<endl;
    }

bool Trajet::estEgal( Trajet * t) {
    return (strcmp(this->depart, t->depart) == 0 
        && strcmp(this->arrivee, t->arrivee) == 0);
}

char const* Trajet::getDepart() const {
    return this->depart;
}
char const* Trajet::getArrivee() const{
    return this->arrivee;
}


//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur

Trajet::Trajet (const char* depart$, const char* arrivee$ )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif

depart = new char[strlen(depart$)+1];
arrivee = new char[strlen(arrivee$)+1];
strcpy(depart, depart$);
strcpy(arrivee, arrivee$);


} //----- Fin de Trajet


Trajet::~Trajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
delete []depart;
delete []arrivee;
} //----- Fin de ~Trajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

