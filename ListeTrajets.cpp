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
}
bool ListeTrajets::ajouter(Trajet *unTrajet)
{
  // algorithme
  // ajout récursif à la fin de la liste

  bool reussite = false;
  // // vérifier qu'il n'y a pas de doublon
  if (trajet->estEgal(unTrajet))
  {
    cout << "chemin existe déjà";

    return false;
  }
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
// Pour le premier trajet, index = 0
{
  if (index <= 0)
    return trajet;
  else
    return trajetSuivant->getElement(index - 1);
}

void ListeTrajets::supprimerTrajet(int index)
// Algorithme
// supprimer le trajet d'indice index
// Pour le premier trajet, index = 0
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

void ListeTrajets::vider()
{
  // on souhaite casser les pointeurs sans supprimer les trajets...
  if (trajet != nullptr)
  {
    trajet = nullptr;
  }
  if (trajetSuivant != nullptr)
  {
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
// delete en chaîne des maillons
{
#ifdef MAP
  cout << "Appel au destructeur de <ListeTrajets>" << endl;
#endif

  // if (this != nullptr)
  delete this->trajet;
  // if (this->trajetSuivant != nullptr)
  delete this->trajetSuivant;
}

//----- Fin de ~ListeTrajets

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
