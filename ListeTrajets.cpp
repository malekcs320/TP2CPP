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

//------------------------------------------------------ Include personnel
#include "ListeTrajets.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Xxx::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

int ListeTrajets::getTaille()
{
  return this->taille;
} // fin getTaille
bool ListeTrajets::ajouter(Trajet * unTrajet)
{
  // vérifier qu'il n'y a pas de doublon
  for(int i=0; i<this->taille; i++) {
    if((trajet+i)->trajet->estEgal(unTrajet)) {
      return false;
    }
  }
  // pas de doublon, on ajoute
  this->taille++;
  ListeTrajets * dernier = trajet+taille-1;
  dernier->trajetSuivant = new ListeTrajets();
  dernier->trajetSuivant->trajet = unTrajet;
  dernier->trajetSuivant->trajetSuivant = NULL;

  return true;
} // fin ajouter
void ListeTrajets::afficher()
{
  for(int i=0; i<this->taille; i++) {
    (trajet+i)->trajet->estEgal->afficherTrajet();
  }
} // fin afficher

Trajet * getElement(int i)
{
  if(i<taille) {
    return (trajet+i)->trajet;
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
} //----- Fin de ~Xxx


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
