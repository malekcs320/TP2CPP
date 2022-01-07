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
    //  Pour la cohérence, le trajet ne doit pas avoir été déjà inséré dans le catalogue.

    void afficher();
    // Mode d'emploi :
    //  Affiche le catalogue, avec la liste des trajets (départ, arrivée, moyen de transport, sous-trajets).
    // Contrat :
    //  Aucun.

    void rechercheSimple(std::string depart, std::string arrivee);
    // Mode d'emploi :
    //  Effectue une recherche simple sur le catalogue, en fonction des paramètres.
    //  depart est le lieu de départ, arrivee est le lieu d'arrivée. On recherche les
    //  trajets ayant exactement ces lieux de départ et d'arrivée (on ne recherche pas dans les sous-trajets).
    // Contrat :
    //  Aucun.

    int rechercheAux(const std::string depart, const std::string arrivee, ListeTrajets *dejaVisite);
    // Mode d'emploi :
    //  Implemente l'algorithme de la recherche en profondeur en partant de depart
    //  et en s'appelant récursivement sur les trajets ayant pour point de départ l'arrivée du trajet
    //  La liste dejaVisite assure qu'on affiche pas plus qu'une fois chaque chemin trouvé.
    // Contrat :
    // Aucun.

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
    // Mode d'emploi :
    //  Renvoie la ListeTrajets du catalogue.
    // Contrat :
    //  Aucun.

    int writeAllFile(std::string nomFichier);
    // Mode d'emploi :
    //  Ecrit tout le catalogue dans le fichier de nom nomFichier.
    // Renvoie le nombre de trajets sauvegardés, -1 en cas d'erreur.
    // Contrat :
    //  Aucun.

    int writeFileByType(std::string nomFichier, char type);
    // Mode d'emploi :
    //  Ecrit dans le fichier de nom nomFichier les trajets dont le type correspond à celui choisi.
    // Renvoie le nombre de trajets sauvegardés, -1 en cas d'erreur.
    // Contrat :
    //  La validité du paramètre type a été vérifiée dans Menu. 

    int writeFileByCity(std::string nomFichier, int option, std::string villeDepart, std::string villeArrivee = "");
    // Mode d'emploi :
    // Ecrit dans le fichier de nom "nomFichier" les trajets selon l'option choisie 
    // dans le Menu par l'utilisateur. Les paramètres villeDepart et villeArrivee dépendent du choix. 
    // Le paramètre ville Arrivee n'est pas employé dans l'option 1 (depuis une villeDepart uniquement)
    // Renvoie le nombre de trajets sauvegardés, -1 en cas d'erreur.
    // Contrat :
    //  La validité du paramètre type a été vérifiée dans Menu. 

    int writeFileByInterval(std::string nomFichier, int borneMin, int borneMax);
    // Mode d'emploi :
    //  Ecrit dans le fichier de nom "nomFichier" les trajets dans l'intervalle [borneMin, borneMax].
    // Renvoie le nombre de trajets sauvegardés, -1 en cas d'erreur.
    // Contrat :
    // La cohérence des bornes a été vérifiée dans Menu.

    int readFile(std::string fileName, char type = 'a');
    // Mode d'emploi :
    //  Lit le fichier dont le nom est passé en paramètre pour remplir le catalogue.
    //  En cas de succès, le nombre de trajets chargés est retourné ; en cas d'échec, on retourne -1.
    // Contrat :
    //  Le fichier doit correspondre au format imposé par le logiciel, à savoir :
    //  Les trajets simples sont décrits de cette façon : S,villeDepart,villeArrivee,moyenTransport 
    //  Les trajets composés sont décrits de cette façon : C,villeDepartGlobale,villeArriveeGlobale,villeDepart1,villeArrivee1,moyen1,villeDepart2,villeArrivee2,moyen2 
    //  Les trajets sont séparés par des retours à la ligne.
    //  Les trajets composés contiennent au moins 1 sous-trajet simple.
    //  Le type de trajet doit être précisé par 's' (simple) ou 'c' (composé) ou 'a' (all, par défaut).

    int readFileByCity(std::string fileName, std::string depart, std::string arrivee);
    // Mode d'emploi :
    //  Lit le fichier dont le nom est passé en paramètre pour remplir le catalogue.
    //  N'importe que les trajets dont la ville de départ correspond à `depart` si ce champ n'est pas vide, 
    //  et dont la ville d'arrivée correspond à `arrivee` si ce champ n'est pas vide.
    //  En cas de succès, le nombre de trajets chargés est retourné ; en cas d'échec, on retourne -1.
    // Contrat :
    //  Le fichier doit correspondre au format imposé par le logiciel, à savoir :
    //  Les trajets simples sont décrits de cette façon : S,villeDepart,villeArrivee,moyenTransport 
    //  Les trajets composés sont décrits de cette façon : C,villeDepartGlobale,villeArriveeGlobale,villeDepart1,villeArrivee1,moyen1,villeDepart2,villeArrivee2,moyen2 
    //  Les trajets sont séparés par des retours à la ligne.
    //  Les trajets composés contiennent au moins 1 sous-trajet simple.
    //  Si l'un des deux champs (depart et arrivee) est vide, l'autre doit être renseigné.

    int readFileByIndex(std::string fileName, int depart, int arrivee);
    // Mode d'emploi :
    //  Lit le fichier dont le nom est passé en paramètre pour remplir le catalogue.
    //  Les index indiquent le premier et le dernier trajet à considérer (en numéro de ligne).
    //  En cas de succès, le nombre de trajets chargés est retourné ; en cas d'échec, on retourne -1.
    // Contrat :
    //  Le fichier doit correspondre au format imposé par le logiciel, à savoir :
    //  Les trajets simples sont décrits de cette façon : S,villeDepart,villeArrivee,moyenTransport 
    //  Les trajets composés sont décrits de cette façon : C,villeDepartGlobale,villeArriveeGlobale,villeDepart1,villeArrivee1,moyen1,villeDepart2,villeArrivee2,moyen2 
    //  Les trajets sont séparés par des retours à la ligne.
    //  Les trajets composés contiennent au moins 1 sous-trajet simple.
    //  L'index d'arrivée doit être supérieur ou égal à l'index de départ.
    //  Les deux index doivent être inférieurs ou égaux au nombre de lignes du fichier.

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    /*Les méthodes suivantes sont protégées car elles ne sont utilisées qu'au sein de la classe*/
    Trajet * readLigne(const std::string ligne) const;
    // Mode d'emploi :
    //  Renvoie un trajet en lisant une chaine de caractères (correspondant au format de sauvegarde).
    // Contrat :
    //  La ligne doit commencer par 'S' ou 'C'. Dans le cas contraite, un nullptr est retourné.

    //----------------------------------------------------- Attributs protégés
    ListeTrajets *liste;

};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H