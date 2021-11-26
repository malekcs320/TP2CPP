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
  bool reussite = false;
  // vérifier qu'il n'y a pas de doublon
  /*if(this->trajet->estEgal(unTrajet)) {
    return false;
  }
  */
  // pas de doublon, on ajoute
  if(taille == 0) {
    this->trajet=unTrajet;
    this->taille++;
  }
  else {
    if(this->trajetSuivant == NULL) {
      this->trajetSuivant = new ListeTrajets();
      this->trajetSuivant->trajet = unTrajet;
      this->trajetSuivant->trajetSuivant = NULL;
      this->taille++;
    }
    else {
      reussite = this->trajetSuivant->ajouter(unTrajet);
      if(reussite) {
        this->taille++;
      }
    }
  }

  return true;
} // fin ajouter
void ListeTrajets::afficher()
{
  if(this->trajet != NULL) {
    this->trajet->afficherTrajet();
    if(this->trajetSuivant !=NULL) this->trajetSuivant->afficher();
  }
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
  trajet = NULL;
  trajetSuivant = NULL;
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
