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
#include <cstring>
//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Catalogue::ajouterTrajet(Trajet *t)
{
    this->liste->ajouter(t);
}
void Catalogue::afficher()
{
    cout << "----------------" << endl;
    cout << "Le catalogue contient " << this->liste->getTaille() << " trajets : " << endl;
    for (int i = 0; i < this->liste->getTaille(); i++)
    {
        cout << "Trajet " << i + 1 << " : " /*<< liste->getElement(i)->toString() << endl*/;
        liste->getElement(i)->afficherTrajet();
    }
    cout << "----------------" << endl;
}
ListeTrajets *Catalogue::rechercheSimple(const char *depart, const char *arrivee)
{

    ListeTrajets *l = new ListeTrajets();
    for (int i = 0; i < l->getTaille(); i++)
        if (strcmp(liste->getElement(i)->getDepart(), depart) == 0 && strcmp(liste->getElement(i)->getArrivee(), arrivee) == 0)
            l->ajouter(liste->getElement(i));
    return l;
}

void Catalogue::rechercheAvancee(const char *depart, const char *arrivee, ListeTrajets *dejaVisite)
{
    
        if (strcmp(depart, arrivee) == 0)
        {
            if (dejaVisite->getTaille() == 0)
                cout << "Catalogue vide" << endl;
            else
            {
                dejaVisite->afficher(); // on affiche le parcours (choix d'affichage maintenant pour pouvoir utiliser le void et permettre la récursivité)
                dejaVisite->supprimerTrajet(dejaVisite->getTaille() - 1); //suppression dernier elem ex A->B, B->C ==> A->B pour voir d'autres possibilités à partir de B
                
            }
            return ;
        }
            for (int i = 0; i < liste->getTaille(); i++)
            {
                Trajet *trajet = liste->getElement(i);
                if (strcmp(trajet->getDepart(), depart) == 0) //on ne considère que les trajets ayant pour point de départs "depart"
                {
                    bool existe = false; //existence dans dejaVisite
                    for (int j = 0; j < dejaVisite->getTaille(); j++)
                    {
                        if (trajet->estEgal(dejaVisite->getElement(j))) //trajet déjà utilisé
                            existe = true;
                    }
                    if (!existe) //nouveau trajet
                    {
                        dejaVisite->ajouter(trajet); //on l'ajoute à la pile
                        rechercheAvancee(trajet->getArrivee(), arrivee, dejaVisite); //on recherche l'arrivée récursivement à partir de l'arrivée du trajet courant
                    }
                }
            
        }
    
}
int Catalogue::getTaille()
{
    return this->liste->getTaille();
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
