/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : novembre 2021
    copyright            : (C) 2021 par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if !defined(CATALOGUE_H)
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "ListeTrajets.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
/*
Cette classe modélise le catalogue. 
*/
//------------------------------------------------------------------------

class Catalogue : public ListeTrajets
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques

    //-------------------------------------------- Constructeurs - destructeur

    Catalogue();
    // Mode d'emploi :
    //  Construit un catalogue vierge.
    // Contrat :
    //  Aucun.

    virtual ~Catalogue();
    // Mode d'emploi :
    //  Détruit un catalogue.
    // Contrat :
    //  Aucun.

    void ajouterTrajet(Trajet *);
    // Mode d'emploi :
    //  Ajoute un trajet au catalogue.
    // Contrat :
    //  Pour de la cohérence, le trajet ne doit pas avoir été déjà inséré dans le catalogue.

    void afficher();
    // Mode d'emploi :
    //  Affiche le catalogue, avec la liste des trajets (départ, arrivée, moyen de transport, sous-trajets).
    // Contrat :
    //  Aucun.

    void rechercheSimple(std::string depart, std::string arrivee);
    // Mode d'emploi :
    //  Effectue une recherche simple sur le catalogue, en fonction des paramètres.
    //  `depart` est le lieu de départ, `arrivee` est le lieu d'arrivée. On recherche les
    //  trajets ayant exactement ces lieux de départ et d'arrivée (on ne recherche pas dans les sous-trajets).
    // Contrat :
    //  Aucun.

    int rechercheAux(const std::string depart, const std::string arrivee, ListeTrajets *dejaVisite);
    // Mode d'emploi :
    //  
    // Contrat :
    //

    void rechercheAvancee(const std::string depart, const std::string arrivee);
    // Mode d'emploi :
    //  Effectue une recherche avancée sur le catalogue. Cette fois on recherche en profondeur également, 
    //  parmi les sous-trajet des trajets composés. `depart` est le lieu de départ, `arrivee` est le lieu d'arrivée. 
    // Contrat :
    //  Aucun.

    void supprimerTrajet(int i);
    // Mode d'emploi :
    //  Supprime le trajet situé à la position passée en paramètre.
    // Contrat :
    //  index doit être un entier positif ou nul.

    int getTaille() const;
    // Mode d'emploi :
    //  Donne le nombre de trajets qui composent le catalogue.
    // Contrat :
    //  Aucun.

    ListeTrajets *getListe() const;

    int readFile(std::string fileName);
    // Mode d'emploi :
    //  Lit le fichier dont le nom est passé en paramètre pour remplir le catalogue.
    //  En cas de succès, le nombre de trajets chargés est retourné ; en cas d'échec, on retourne -1.
    // Contrat :
    //  Le fichier doit correspondre au format imposé par le logiciel, à savoir :
    //  Les trajets simples sont décrits de cette façon : S,villeDepart,villeArrivee,moyenTransport 
    //  Les trajets composés sont décrits de cette façon : C,villeDepartGlobale,villeArriveeGlobale,villeDepart1,villeArrivee1,moyen1,villeDepart2,villeArrivee2,moyen2 
    //  Les trajets sont séparés par des retours à la ligne.
    //  Les trajets composés contiennent au moins 1 sous-trajet simple.

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    ListeTrajets *liste;
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H

