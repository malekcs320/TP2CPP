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
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetSimple::afficherTrajet() const
    {
        cout<< "de "<<depart<<" à "<<arrivee<<" en "<<transport;
    }

char * TrajetSimple::getTransport()
    {
        return transport;
    };
/*bool TrajetSimple::estEgal( TrajetSimple *t ){
    return strcmp(t->getDepart(), arrivee)&&strcmp(t->getArrivee(), arrivee)&&strcmp(t->getTransport(), transport);
    
}*/

//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple (const char* depart$, const char* arrivee$, const char* transport$ ):Trajet(depart$, arrivee$)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif

transport = new char[strlen(depart$)];
strcpy(transport, transport$);

} //----- Fin de Xxx


TrajetSimple::~TrajetSimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Xxx>" << endl;
#endif
delete []transport;
} //----- Fin de ~Xxx


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

