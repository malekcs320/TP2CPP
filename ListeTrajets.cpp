/*************************************************************************
                           ListeTrajets  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <ListeTrajets> (fichier ListeTrajets.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "ListeTrajets.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


int ListeTrajets::getTaille()
{
  return this->taille;
} // fin getTaille
bool ListeTrajets::ajouter(Trajet * unTrajet)
{
  // vérifier qu'il n'y a pas de doublon
  /*for(int i=0; i<this->taille; i++) {
    if((trajetSuivant+i)->trajet->estEgal(unTrajet)) {
      return false;
    }
  }*/
  // pas de doublon, on ajoute
  this->taille++;
  ListeTrajets * dernier = this;
  for(int i=0; i<taille; i++) dernier = dernier->trajetSuivant;
  dernier->trajetSuivant = new ListeTrajets();
  dernier->trajetSuivant->trajet = unTrajet;
  dernier->trajetSuivant->trajetSuivant = NULL;

  return true;
} // fin ajouter
void ListeTrajets::afficher()
{
  this->trajet->afficherTrajet();
  this->trajetSuivant->afficher();
} // fin afficher

Trajet * ListeTrajets::getElement(int index)
{
  if(index<taille) {
    ListeTrajets * t = this;
    for(int i=0; i<index; i++) t = t->trajetSuivant;
    return t->trajet;
  }
  return NULL;
}

//-------------------------------------------- Constructeurs - destructeur
ListeTrajets::ListeTrajets ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ListeTrajets>" << endl;
#endif
  this->taille=0;
} //----- Fin de ListeTrajets


ListeTrajets::~ListeTrajets ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ListeTrajets>" << endl;
#endif
} //----- Fin de ~ListeTrajets


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
