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
#include <fstream>
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

int Catalogue::readFile(std::string fileName) 
// Algorithme :
/*
    Lecture ligne à ligne du fichier dont le nom est passé en paramètre.
    Si une erreur survient lors de l'ouverture du fichier, on retourne false.
    Si on parvient à aller jusqu'à la fin du processus, on retourne true.
    On analyse d'abord le premier caractère, qui doit être soit 'S' soit 'C' (dans tous les autres cas,
    on affiche le numéro de la ligne, précisant qu'elle est de format invalide, dans la console). 
    Ensuite, on lit exactement 3 mots pour 'S' séparés par des virgules. Pour 'C', on lit exactement 2 mots, 
    puis on lit au moins 1 fois un ensemble de 3 mots (pour chaque sous-trajet) séparés par des virgules. 
*/
{
    std::ifstream file(fileName);

    if(!file) {
        cout << "Une erreur est survenue lors de l'ouverture du fichier " << fileName << endl;
        return -1;
    }
    std::string ligne("");
    char c;
    uint pointeurChar=0, compteurLigne=0, compteurTrajet=0;
    while(getline(file,ligne)) { // lecture ligne à ligne
        compteurLigne++;
        c = ligne.front();
        if(c == 'S') {
            compteurTrajet++;
            std::string infos[3];
            pointeurChar = 1;
            for(int i=0; i<3; i++) {
                pointeurChar++;
                c = ligne.at(pointeurChar);
                while(c != ',' && pointeurChar < ligne.size()) {
                    //cout << i << " : " <<  c << " pointeurChar : " << pointeurChar << "<" << ligne.size() << endl;
                    infos[i].append(1, c);
                    pointeurChar++;
                    if(pointeurChar < ligne.size()) c = ligne.at(pointeurChar);
                }
            }
            ajouterTrajet(new TrajetSimple(infos[0], infos[1], infos[2]));
        }
        else if(c == 'C') {
            compteurTrajet++;
            std::string infosCompose[2], infosSimple[3];
            pointeurChar = 1;

            /* lecture des informations du trajet composé (départ, arrivée) */
            for(int i=0; i<2; i++) {
                pointeurChar++;
                c = ligne.at(pointeurChar);
                while(c != ',' && pointeurChar < ligne.size()) {
                    infosCompose[i].append(1, c);
                    pointeurChar++;
                    if(pointeurChar < ligne.size()) c = ligne.at(pointeurChar);
                }
            }

            TrajetCompose *t = new TrajetCompose(infosCompose[0], infosCompose[1]);

            /* lecture des sous-trajets */
            while(pointeurChar < ligne.size()) {
                for(int i=0; i<3; i++) {
                    pointeurChar++;
                    c = ligne.at(pointeurChar);
                    while(c != ',' && pointeurChar < ligne.size()) {
                        infosSimple[i].append(1, c);
                        pointeurChar++;
                        if(pointeurChar < ligne.size()) c = ligne.at(pointeurChar);
                    }
                }
                t->ajouterTrajet(new TrajetSimple(infosSimple[0], infosSimple[1], infosSimple[2]));
                for(int i=0; i<3; i++) infosSimple[i] = "";

            }
            ajouterTrajet(t);
        }
        else {
            cout << "Ligne " << compteurLigne << " : format invalide" << endl;
        }
    }

    file.close();
    return compteurTrajet;
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
