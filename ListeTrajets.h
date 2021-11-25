/*************************************************************************
                           ListeTrajets  -  description
                             -------------------
    début                : novembre 2021
    copyright            : (C) 2021 par Male Mahjoub et Aurélie Abraham
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <ListeTrajets> (fichier ListeTrajets.h) ----------------
#if ! defined ( LISTETRAJETS_H )
#define LISTETRAJETS_H

//--------------------------------------------------- Interfaces utilisées

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
    int getTaille();
    bool ajouter(Trajet *);
    void afficher();
    Trajet * getElement(int index);
    // Mode d'emploi : renvoie le (index+1)ième élément de la liste chaînée
    //
    // Contrat : index doit être positif
    //


//-------------------------------------------- Constructeurs - destructeur

    ListeTrajets ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ListeTrajets ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
  Trajet * trajet;
  unsigned int taille;
  ListeTrajets * trajetSuivant;

};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // ListeTrajets_H
