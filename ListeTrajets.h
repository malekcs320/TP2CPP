/*************************************************************************
                           ListeTrajets  -  description
                             -------------------
    début                : novembre 2021
    copyright            : (C) 2021 par Male Mahjoub et Aurélie Abraham
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <ListeTrajets> (fichier ListeTrajets.h) ----------------
#if !defined(LISTETRAJETS_H)
#define LISTETRAJETS_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ListeTrajets>
//
//
//------------------------------------------------------------------------

class ListeTrajets
{
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques
  unsigned int getTaille();
  virtual bool ajouter(Trajet *);
  virtual void afficher();
  Trajet *getElement(int index);
  virtual void supprimerTrajet(int index);
  
  /*
  Cette méthode permet de ne plus faire pointer les ListeTrajets sur des Trajets.
  Cette méthode est en fait utilisée dans le cas de Catalogue::rechercherAvancée, 
  qui utilise une ListeTrajets temporaire que l'on souhaite delete à la fin de 
  l'algorithme, sans supprimer nos Trajet dans le tas.
  */
  void vider();
  

  //-------------------------------------------- Constructeurs - destructeur

  ListeTrajets();
  // Mode d'emploi :
  //
  // Contrat :
  //

  virtual ~ListeTrajets();
  // Mode d'emploi :
  //
  // Contrat :
  //

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  //----------------------------------------------------- Attributs protégés
  Trajet *trajet;
  unsigned int taille;
  ListeTrajets *trajetSuivant;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // ListeTrajets_H
