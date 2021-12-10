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
  // if (trajet->estEgal(unTrajet))
  // {
  //   cout << "chemin existe déjà";

  //   return false;
  // }
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

void ListeTrajets::supprimerTrajet(uint index)
// Algorithme
// supprimer le trajet d'indice index
// Pour le premier trajet, index = 0
//Pour supprimer un nœud de la liste chaînée, nous devons suivre les étapes suivantes.
//1) Trouvez le nœud précédent du nœud à supprimer.
//2) Changer "le prochain" du nœud précédent au suivant du noeud à supprimer.
//3) liberer la mémoire
//Pour le premier Noeud, comme on peut pas faire la suppression de l'objet pointé par this,
//this devient égal au noeud suivant qu'on supprime.

{
  if (index >= taille) return;

  ListeTrajets *head = this;
  ListeTrajets *temp = head;
  ListeTrajets *prev = nullptr;

  if (index == 0) // suppression en tête 
  {
    if (head->trajetSuivant == nullptr) // 1 seul élément dans la liste
    {
      delete head->trajet;
      head->trajet = nullptr;
      taille--;
      return;
    }
    else { 
      // plus d'un élément dans la liste
      if(taille == 2) { // exactement 2
        delete head->trajet;
        head->trajet = head->trajetSuivant->trajet;
        head->trajetSuivant->trajet = nullptr;
        delete head->trajetSuivant;
        head->trajetSuivant = nullptr;
        taille--;
      }
      else { // plus de 2
        delete head->trajet;
        head->trajet = head->trajetSuivant->trajet;
        temp = head->trajetSuivant;
        head->trajetSuivant = temp->trajetSuivant;
        temp->trajetSuivant = nullptr;
        temp->trajet = nullptr;
        delete temp;
        while (head != nullptr) // maj tailles de liste
        {
          head->taille--;
          head = head->trajetSuivant;
        }
      }
    }
    
  }
  else // suppression ailleurs
  {
    while (temp != nullptr && index--)
    {
      prev = temp;
      temp = temp->trajetSuivant;
      prev->taille--;
    }


    prev->trajetSuivant = temp->trajetSuivant;
    temp->trajetSuivant = nullptr; // contre la suppression en chaine 
    delete temp;
    
  }


  cout << "fin" << endl;
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
  cout << "destructeur de liste taille = " << taille<< endl;
  cout << "trajet qui est supprimé : ";
  if(trajet == nullptr) {
    cout << "nullptr" << endl;
  }
  else {
    trajet->afficherTrajet();
  }
  if (trajet != nullptr)
    delete this->trajet;
  if (this->trajetSuivant != nullptr) {
    cout<<"appel au destructeur suivant"<<endl;
    delete this->trajetSuivant;
  }
    
}

//----- Fin de ~ListeTrajets

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
