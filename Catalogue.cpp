/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Catalogue::ajouterTrajet(Trajet * t) {
    this->liste->ajouter(t);
}
void Catalogue::afficher() {
    cout << "----------------" << endl;
    cout << "Le catalogue contient " << this->liste->getTaille() << " trajets : " << endl;
    for(int i=0; i<this->liste->getTaille(); i++) {
        cout << "Trajet " << i+1 << " : " << liste->getElement(i) << endl;
    }
    cout << "----------------" << endl;
}
ListeTrajets * Catalogue::rechercheSimple(const char* depart, const char* arrivee) {

    ListeTrajets* l= new ListeTrajets();
    for (int i = 0;i<l->getTaille();i++)
        if (strcmp(liste->getElement(i)->getDepart(),depart) && strcmp(liste->getElement(i)->getArrivee(),arrivee))
            l->ajouter(liste->getElement(i));
    return l;

}

ListeTrajets * Catalogue::rechercheAvancee(char*, char*) {

}
int Catalogue::getTaille() {
    return this->liste->getTaille();
}

//-------------------------------------------- Constructeurs - destructeur


Catalogue::Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
liste = new ListeTrajets();
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
delete liste;
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

