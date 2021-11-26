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
    {
        if (strcmp(depart, arrivee) == 0)
        {
            if (dejaVisite->getTaille() == 0)
                cout << "parcours non trouvé" << endl;
            if (dejaVisite->getTaille() > 0)
            {
                dejaVisite->afficher();
                dejaVisite->supprimerTrajet(dejaVisite->getTaille() - 1); // A->B, B->C ==> A->B pour voir autres possibilités à partir de B
                return;
            }
            for (int i = 0; i < liste->getTaille(); i++)
            {
                Trajet *trajet = liste->getElement(i);
                if (strcmp(trajet->getDepart(), depart) == 0)
                {
                    bool existe = false;
                    for (int j = 0; j < dejaVisite->getTaille(); j++)
                    {
                        if (trajet->estEgal(dejaVisite->getElement(j)))
                            existe = true;
                    }
                    if (!existe)
                    {
                        dejaVisite->ajouter(trajet);
                        rechercheAvancee(trajet->getDepart(), arrivee, dejaVisite);
                    }
                }
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
