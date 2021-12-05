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
    taille++;
    this->trajet = unTrajet;
    
  }
  else {
    if(this->trajetSuivant == NULL) {

      this->trajetSuivant = new ListeTrajets(); 
      this->trajetSuivant->trajet = unTrajet;
      this->trajetSuivant->taille++;
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
    if(taille ==0) 
    {cout<<"La liste est vide"<<endl;
    return;
    }
  if(this == NULL) return;
  if(this->trajet != NULL)this->trajet->afficherTrajet();
  if(this->trajetSuivant != NULL)this->trajetSuivant->afficher();
  return;
    
    
  
} // fin afficher

Trajet * ListeTrajets::getElement(int index)
{
  if(index<=0) return this->trajet;
  else return this->trajetSuivant->getElement(index-1);
  /*if(index<taille) {
    ListeTrajets * t = this;
    for(int i=0; i<index; i++) t = t->trajetSuivant;
    return t->trajet;
  }*/
  //return NULL;
}

void ListeTrajets::supprimerTrajet(int index)
// Algorithme
{

  ListeTrajets* head = this;
	ListeTrajets* temp = head;
	ListeTrajets* prev = NULL;
	

	
  if (head!=NULL && index == 0)
	{
        if(head->trajetSuivant == NULL)
        {head->trajet =NULL;
        taille --;
        return;}

        temp = head->trajetSuivant;
        head->trajet = temp->trajet; 
        head->trajetSuivant = temp->trajetSuivant;
        temp ->trajet = NULL;
        temp ->trajetSuivant = NULL;
	}
	else
	{
	while (temp != NULL && index--)
	{
		prev = temp;
		temp = temp->trajetSuivant;
    
	}

	if (temp == NULL)
		return;

	prev->trajetSuivant = temp->trajetSuivant;
  
	}
 
  while(head!=NULL)
    {head->taille --; 
    head = head->trajetSuivant;
    }
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
  taille = 0;
} //----- Fin de ListeTrajets


ListeTrajets::~ListeTrajets ( )
// Algorithme :
//
{
  #ifdef MAP
      cout << "Appel au destructeur de <ListeTrajets>" << endl;
  #endif

  if(this != NULL )delete this->trajet;
  if(this->trajetSuivant != NULL) delete this->trajetSuivant; // suppression en chaîne
 


}




    
   
   
//----- Fin de ~ListeTrajets


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
