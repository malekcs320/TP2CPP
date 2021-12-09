/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if !defined(TrajetSimple_H)
#define TrajetSimple_H

//--------------------------------------------------- Interfaces utilisées
#include "trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
//  Cette classe modélise une sorte de Trajet. Elle possède en plus un moyen de transport.
//
//------------------------------------------------------------------------
class TrajetSimple : public Trajet
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques

    void afficherTrajet() const;
    // Mode d'emploi :
    //  Affiche le trajet et son moyen de transport.
    // Contrat :
    //  Aucun.

    char *getTransport();
    // Mode d'emploi :
    //  Donne le moyen de transport du trajet.
    // Contrat :
    //  Aucun.

    bool estTrajetCompose() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool estEgal ( Trajet *t );
    // Mode d'emploi :
    //  Teste si le trajet passé en paramètre est exactement le même que celui-ci. 
    // Contrat :
    //  `t` ne devrait pas pointer le même Trajet que this.

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur

    TrajetSimple(const char *depart, const char *arivee, const char *transport);
    // Mode d'emploi :
    //  Crée un trajet à partir des paramètres : ville départ, ville arrivée, moyen de transport.
    // Contrat :
    //  Les villes de départ et d'arrivée ne devraient pas être les mêmes.

    virtual ~TrajetSimple();
    // Mode d'emploi :
    //  Détuit le trajet.
    // Contrat :
    //  Aucun.

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    char *transport;
};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TrajetSimple_H
