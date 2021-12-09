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

unsigned int ListeTrajets::getTaille()
{
  return taille;
} // fin getTaille
bool ListeTrajets::ajouter(Trajet *unTrajet)
{
  bool reussite = false;
  // // vérifier qu'il n'y a pas de doublon
   /*if(trajet->estEgal(unTrajet))
    {cout<<"chemin existe déjà";
     
     return false;
   }*/
  // pas de doublon, on ajoute
  if (taille == 0)
  {
    taille++;
    trajet = unTrajet;
  }
  else
  {
    if (this->trajetSuivant == nullptr)
    {

      trajetSuivant = new ListeTrajets();
      trajetSuivant->trajet = unTrajet;
      trajetSuivant->taille++;
      taille++;
    }
    else
    {
      reussite = trajetSuivant->ajouter(unTrajet);
      if (reussite)
      {
        taille++;
      }
    }
  }

  return true;
} // fin ajouter
void ListeTrajets::afficher()
{
  if (taille == 0)
  {
    cout << "La liste est vide" << endl;
    return;
  }
  if (this == nullptr)
    return;
  if (trajet != nullptr)
    trajet->afficherTrajet();
  if (trajetSuivant != nullptr)
    trajetSuivant->afficher();
  return;

} // fin afficher

Trajet *ListeTrajets::getElement(int index)
{
  if (index <= 0)
    return trajet;
  else
    return trajetSuivant->getElement(index - 1);
  /*if(index<taille) {
    ListeTrajets * t = this;
    for(int i=0; i<index; i++) t = t->trajetSuivant;
    return t->trajet;
  }*/
  // return nullptr;
}

void ListeTrajets::supprimerTrajet(int index)
// Algorithme
{

  ListeTrajets *head = this;
  ListeTrajets *temp = head;
  ListeTrajets *prev = nullptr;

  if (head != nullptr && index == 0)
  {
    if (head->trajetSuivant == nullptr)
    {
      head->trajet = nullptr;
      taille--;
      return;
    }

    temp = head->trajetSuivant;
    head->trajet = temp->trajet;
    head->trajetSuivant = temp->trajetSuivant;
    temp->trajet = nullptr;
    temp->trajetSuivant = nullptr;
  }
  else
  {
    while (temp != nullptr && index--)
    {
      prev = temp;
      temp = temp->trajetSuivant;
    }

    if (temp == nullptr)
      return;

    prev->trajetSuivant = temp->trajetSuivant;
  }

  while (head != nullptr)
  {
    head->taille--;
    head = head->trajetSuivant;
  }
}

void ListeTrajets::vider() {
  // on souhaite casser les pointeurs sans delete les trajets...
  if(trajet != nullptr) {
    trajet = nullptr;
  }
  if(trajetSuivant != nullptr) {
    trajetSuivant->vider();
  }
}

//-------------------------------------------- Constructeurs - destructeur
ListeTrajets::ListeTrajets()
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au constructeur de <ListeTrajets>" << endl;
#endif
  trajet = nullptr;
  trajetSuivant = nullptr;
  taille = 0;
} //----- Fin de ListeTrajets

ListeTrajets::~ListeTrajets()
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au destructeur de <ListeTrajets>" << endl;
#endif

   if (this != NULL)
    delete this->trajet;
  if (this->trajetSuivant != NULL)
    delete this->trajetSuivant;
}

//----- Fin de ~ListeTrajets

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
