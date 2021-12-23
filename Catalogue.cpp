/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Catalogue::ajouterTrajet(Trajet *t)
{
    liste->ajouter(t);
}

void Catalogue::afficher()
{
    cout << "----------------" << endl;
    cout << "Le catalogue contient " << liste->getTaille() << " trajets" << endl;
    for (uint i = 0; i < liste->getTaille(); i++)
    {
        cout << "Trajet " << i + 1 << " : ";
        liste->getElement(i)->afficherTrajet();
    }
    cout << "----------------" << endl;
}

void Catalogue::rechercheSimple(std::string depart, std::string arrivee)
{
    int nb = 0;
    for (uint i = 0; i < liste->getTaille(); i++)
    {
        if (liste->getElement(i)->getDepart().compare(depart) == 0 && liste->getElement(i)->getArrivee().compare(arrivee) == 0)
        {
            cout << "Trajet " << nb + 1 << " : ";
            liste->getElement(i)->afficherTrajet();
            nb++;
        }
    }
    cout << nb << " trajets trouvés dans le catalogue de " << depart << " vers " << arrivee << endl;
}

/*
void Catalogue::rechercheAvancee(const char *depart, const char *arrivee)
{
    cout << "Recherche Avancee de trajets de " << depart << " vers " << arrivee << "..." << endl;
    ListeTrajets *dejaVisite = new ListeTrajets();
    int nb = rechercheAux(depart, arrivee, dejaVisite);
    cout << nb << " trajets trouvés dans le catalogue de " << depart << " vers " << arrivee << endl;
    dejaVisite->vider();
    delete dejaVisite;
}

int Catalogue::rechercheAux(const char *depart, const char *arrivee, ListeTrajets *dejaVisite)
{
    // Algorithme
    // Exploration récursive en profondeur du graphe des trajets.
    // Chaque trajet visité est mis dans la liste dejaVisite et on visite tous ses voisins.
    // Aprés avoir visité tous les voisins du trajet, on le dépile.
    // A chaque recherche, on ne considère que les trajets ayant pour point de départs "depart",
    // cela nous évite de construire tout le graphe d'adjacence formé par nos trajets.
    //  Choix d'affichage au fur et à mesure de la recherche nous facilite la manipulation de la fonction récursivie

    int nbTrajets = 0;
    if (strcmp(depart, arrivee) == 0)
    {
        cout << "-----------------------" << endl;
        dejaVisite->afficher();
        return 1;
    }
    bool existe = false;
    for (uint i = 0; i < liste->getTaille(); i++)
    {
        Trajet *trajet = liste->getElement(i);

        if (strcmp(trajet->getDepart(), depart) == 0) //
        {
            existe = false;
            for (uint j = 0; j < dejaVisite->getTaille(); j++)
            {
                if (trajet->estEgal(dejaVisite->getElement(j)))
                {
                    existe = true;
                    break;
                }
            }
            // nouveau trajet considéré
            if (!existe)
            {

                dejaVisite->ajouter(trajet);

                nbTrajets += rechercheAux(trajet->getArrivee(), arrivee, dejaVisite);
                // suppression dernier elem (ex A->B, B->C ==> A->B) pour chercher d'autres possibilités à partir de B
                dejaVisite->supprimerTrajetRecherche(dejaVisite->getTaille() - 1);
            }
        }
    }
    return nbTrajets;
}*/

void Catalogue::supprimerTrajet(int i)
{
    liste->supprimerTrajet(i);
}

int Catalogue::getTaille() const
{
    return liste->getTaille();
}

ListeTrajets *Catalogue::getListe() const 
{
    return liste;
}

//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
    liste = new ListeTrajets();
} //----- Fin de Catalogue

Catalogue::~Catalogue()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
    delete liste;

} //----- Fin de ~Catalogue

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
