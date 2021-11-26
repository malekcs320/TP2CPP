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
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Trajet::afficherTrajet() const
    {
        cout<< "de "<<depart<<" à "<<arrivee<<endl;
    }

bool Trajet::estEgal(const Trajet & t) {
    return (strcmp(this->depart, t.depart) == 0 
        && strcmp(this->arrivee, t.arrivee) == 0);
}

char * Trajet::getDepart() {
    return this->depart;
}
char * Trajet::getArrivee() {
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

depart = new char[strlen(depart$)];
arrivee = new char[strlen(arrivee$)];
strcpy(depart, depart$);
strcpy(arrivee, arrivee$);


} //----- Fin de Xxx


Trajet::~Trajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Xxx>" << endl;
#endif
delete []depart;
delete []arrivee;
} //----- Fin de ~Xxx


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

