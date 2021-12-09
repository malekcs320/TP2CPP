/*************************************************************************
                           ListeTrajets  -  description
                             -------------------
    début                : novembre 2021
    copyright            : (C) 2021 par Malek Mahjoub et Aurélie Abraham
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
//  Classe permettant de définir une structure de données de type liste chaînée.
//  Cette classe stocke des éléments de type Trajet.
//------------------------------------------------------------------------

class ListeTrajets
{
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques
  unsigned int getTaille();
  // Mode d'emploi :
  //  Donne la taille de la liste (nombre de trajets qui la composent).
  // Contrat :
  //  Aucun.
  
  virtual bool ajouter(Trajet *);
  // Mode d'emploi :
  //  Permet d'ajouter un trajet passé en paramètre à la liste.
  // Contrat :
  //  Aucun.

  virtual void afficher();
  // Mode d'emploi :
  //  Affiche la liste, en affichant le détail de chaque trajet qui la compose.
  // Contrat :
  //  Aucun.

  Trajet *getElement(int index);
  // Mode d'emploi :
  //  Donne l'élément situé à la position `index` de la liste.
  // Contrat :
  //  index doit être un entier positif ou nul, inférieur strictement à la taille de la liste.

  virtual void supprimerTrajet(int index);
  // Mode d'emploi :
  //  Supprime le trajet situé à la position `index` de la liste.
  // Contrat :
  //  index doit être un entier positif ou nul, inférieur strictement à la taille de la liste.

  
  void vider();
  // Mode d'emploi :
  /*
  Cette méthode permet de ne plus faire pointer les ListeTrajets sur des Trajets.
  Cette méthode est en fait utilisée dans le cas de Catalogue::rechercherAvancée,
  qui utilise une ListeTrajets temporaire que l'on souhaite delete à la fin de
  l'algorithme, sans supprimer nos Trajet dans le tas.
  */
  // Contrat :
  //  Cette méthode ne devrait être utilisée QUE dans le cas décrit ci-dessus, sous peine d'avoir des pertes de mémoire.

  //-------------------------------------------- Constructeurs - destructeur

  ListeTrajets();
  // Mode d'emploi :
  //  Crée un objet ListeTrajets vierge.
  // Contrat :
  //  Aucun.

  virtual ~ListeTrajets();
  // Mode d'emploi :
  //  Détruit l'objet.
  // Contrat :
  //  Aucun.

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  //----------------------------------------------------- Attributs protégés
  Trajet *trajet;
  unsigned int taille;
  ListeTrajets *trajetSuivant;
};

//-------------------------------- Autres définitions dépendantes de <ListeTrajets>

#endif // ListeTrajets_H
