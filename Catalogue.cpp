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
ListeTrajets * Catalogue::rechercheSimple(const char *depart, const char *arrivee)
{
    cout <<"Recherhce simple de trajets de "<< depart<< " vers "<<arrivee<<"..."<<endl;
    ListeTrajets *l = new ListeTrajets();
    for (int i = 0; i < liste->getTaille(); i++){
        //liste->getElement(i)->afficherTrajet();
        if (strcmp(liste->getElement(i)->getDepart(), depart) == 0 && strcmp(liste->getElement(i)->getArrivee(), arrivee) == 0)
         l->ajouter(liste->getElement(i));
    }
    return l;
}
void Catalogue::rechercheAvancee(const char *depart, const char *arrivee){
    cout <<"Recherhce Avancee de trajets de "<< depart<< " vers "<<arrivee<<"..."<<endl; 
    ListeTrajets* dejaVisite = new ListeTrajets;
    int nb = rechercheAux("Paris","Nantes",dejaVisite);
    cout<<nb<<" trajets trouvés dans le catalogue de "<<depart<<" vers "<<arrivee<<endl;
}
int Catalogue::rechercheAux(const char *depart, const char *arrivee,ListeTrajets* dejaVisite)
{
        int nbTrajets = 0;
        if (strcmp(depart, arrivee) == 0)
        {
                //cout<<"test "<<endl;
                cout<<"-----------------------"<<endl;
                dejaVisite->afficher(); // on affiche le parcours (choix d'affichage maintenant pour pouvoir utiliser le void et permettre la récursivité)
                return 1;
                //cout<<"--------";
                //dejaVisite->afficher();
            
        }
           bool existe =false; //existence dans dejaVisite
            for (int i = 0; i < liste->getTaille(); i++)
            {
                Trajet *trajet = liste->getElement(i);
                //cout<<"trajet : ";
                //trajet->afficherTrajet();
                
                //cout<<"test 2"<<endl;
                if (strcmp(trajet->getDepart(), depart) == 0) //on ne considère que les trajets ayant pour point de départs "depart"
                {
                     existe =false;
                    for (int j = 0; j < dejaVisite->getTaille(); j++)
                    {
                        if (trajet->estEgal(dejaVisite->getElement(j))) //trajet déjà utilisé
                            {//cout<<"test -----------------";
                            existe = true;
                            break;
                            }
                    }
                    if (!existe) //nouveau trajet
                    {
                        
                        dejaVisite->ajouter(trajet); //on l'ajoute à la pile
                        //cout<<"ajout ";
                        //trajet->afficherTrajet();
                        nbTrajets+=rechercheAux(trajet->getArrivee(), arrivee, dejaVisite); //on recherche l'arrivée récursivement à partir de l'arrivée du trajet courant
                        dejaVisite->supprimerTrajet(dejaVisite->getTaille() - 1);//suppression dernier elem ex A->B, B->C ==> A->B pour voir d'autres possibilités à partir de B
                        //cout<<"--------";
                        //dejaVisite->afficher();
                    }
                    
                }
            
        }
    return nbTrajets;
}

void Catalogue::supprimerTrajet(int index)
{
    liste->supprimerTrajet(index);
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
