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
        cout<<"chemain composé";
        Trajet::afficherTrajet();
        cout <<" : "<<endl;
        
        for(int i=0;i<liste->getTaille();i++)
        {
        cout<<"  ";
        liste->getElement(i)->afficherTrajet();
        }
        

    }

void TrajetCompose::ajouterTrajets( Trajet * unTrajet )
{   
    liste->ajouter(unTrajet);
}
// bool estEgal ( const Trajet &t )
// {


// }

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose ( const char* depart, const char* arrivee):
Trajet(depart, arrivee)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur" << endl;
#endif
liste = new ListeTrajets();

} 


TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Xxx>" << endl;
#endif
} 


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

