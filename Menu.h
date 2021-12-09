/*************************************************************************
                           Menu  -  description
                             -------------------
    début                : novembre 2021
    copyright            : (C) 2021 par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Menu> (fichier Menu.h) ----------------
#if !defined(MENU_H)
#define MENU_H

//--------------------------------------------------- Interfaces utilisées
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Menu>
//
//
//------------------------------------------------------------------------

class Menu
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    void afficherMenu();
    TrajetSimple *saisirTS(const char *ville_depart = nullptr);
    TrajetCompose *saisirTC();
    void rechercher();
    void afficherCatalogue();
    void ajouterTrajet();

    //-------------------------------------------- Constructeurs - destructeur

    Menu();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Menu();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    Catalogue *c;
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // MENU_H
