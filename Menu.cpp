/*************************************************************************
                           Menu  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Menu> (fichier Menu.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <limits>

//------------------------------------------------------ Include personnel
#include "Menu.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Menu::afficherMenu()
{
    std::string choix;

    do
    {
        cout << "-------------- MENU PRINCIPAL --------------" << endl;
        cout << "1 : Ajouter un trajet au catalogue" << endl;
        cout << "2 : Rechercher un trajet dans le catalogue" << endl;
        cout << "3 : Afficher le catalogue" << endl;
        cout << "4 : Supprimer un trajet" << endl;
        cout << "5 : Sauvegarder le catalogue" << endl;
        cout << "6 : Charger le catalogue à partir d'un fichier" << endl;
        cout << "Veuillez entrer votre choix (q pour quitter) : ";
        cin >> choix;
        cout << endl;

        while (choix.compare("1") != 0 && choix.compare("2") != 0 && choix.compare("3") != 0
             && choix.compare("4") != 0 && choix.compare("5") != 0 && choix.compare("6") != 0 && choix.compare("q") != 0)
        {
            cout << "Choix incorrect. Choix possibles : 1, 2, 3, 4, 5, 6, q. Choix : ";
            cin >> choix;
            cout << endl;
        }

        if (choix.compare("1") == 0)
        {
            ajouterTrajet();
            cout << endl;
        }
        else if (choix.compare("2") == 0)
        {
            rechercher();
            cout << endl;
        }
        else if (choix.compare("3") == 0)
        {
            afficherCatalogue();
            cout << endl;
        }
        else if (choix.compare("4") == 0)
        {
            supprimerTrajet();
            cout << endl;
        }
        else if(choix.compare("5") == 0)
        {
            sauvegarderCatalogue();
            cout << endl;
        }
        else if(choix.compare("6") == 0)
        {
            chargerCatalogue();
            cout << endl;
        }
    } while (choix.compare("q") != 0);
}

TrajetSimple *Menu::saisirTS(std::string ville_depart)
{
    std::string depart = "", arrivee = "", moyenTransport = "";
    cout << ">> SAISIE D'UN TRAJET SIMPLE" << endl;
    cout << "Ville de départ : ";
    if (ville_depart.compare("") == 0)
    {
        cin >> depart;
    }
    else
    {
        depart = ville_depart;
        cout << ville_depart << endl;
    }
    cout << "Ville d'arrivée : ";
    cin >> arrivee;
    cout << "Moyen de transport : ";
    cin >> moyenTransport;
    TrajetSimple *t = new TrajetSimple(depart, arrivee, moyenTransport);
    return t;
}

TrajetCompose *Menu::saisirTC()
{
    std::string depart, arrivee, mTransport, derniereVille;
    
    TrajetCompose *trajet;
    TrajetSimple *ts;

    int nbTrajets = 1;

    cout << ">> SAISIE D'UN TRAJET COMPOSE" << endl;
    cout << "Ville de départ : ";
    cin >> depart;
    cout << "Ville d'arrivée : ";
    cin >> arrivee;
    trajet = new TrajetCompose(depart, arrivee);
    derniereVille = depart;
    cout << "Saisie des sous-trajets (jusqu'à arriver à " << arrivee << ") : " << endl;
    do
    {
        cout << "> Veuillez saisir les informations du sous-trajet " << nbTrajets << endl;
        ts = saisirTS(derniereVille);
        derniereVille = ts->getArrivee();
        trajet->ajouterTrajet(ts);
        nbTrajets++;
    } while (derniereVille != arrivee);
    return trajet;
}

void Menu::rechercher()
{
    string choix = "", depart = "", arrivee = "";
    cout << "Quelle recherche souhaitez-vous effectuer ? Simple ou avancée ? (s/a) ";
    cin >> choix;
    cout << endl;

    while (choix.compare("a") != 0 && choix.compare("s") != 0)
    {
        cout << "Choix incorrect. Choix possibles : a, s. Choix : ";
        cin >> choix;
    }

    if(choix.compare("s") == 0)
    {
        cout << ">> RECHERCHE SIMPLE" << endl;
        cout << "Ville de départ : ";
        cin >> depart;
        cout << "Ville d'arrivée : ";
        cin >> arrivee;
        c->rechercheSimple(depart, arrivee);
    }
    else
    {
        cout << "Pas pour le moment" << endl;
        // c->rechercheAvancee(depart, arrivee);
    }
}

void Menu::afficherCatalogue()
{
    c->afficher();
}

void Menu::ajouterTrajet()
{
    string choix;

    cout << "Souhaitez-vous ajouter un trajet simple (s) ou composé (c) ? (s/c) Choix : ";
    cin >> choix;
    cout << endl;
    while (choix.compare("s") && choix.compare("c"))
    {
        cout << "Choix incorrect. Choix possibles : s, c. Choix : ";
        cin >> choix;
    }
    if (choix.compare("s") == 0)
        c->ajouterTrajet(saisirTS());
    else
        c->ajouterTrajet(saisirTC());
}

void Menu::supprimerTrajet()
{

    afficherCatalogue();
    if (c->getTaille() == 0)
    {
        cout << "Il n'y a pas de trajet à supprimer" << endl;
        return;
    }
    int i;
    cout << "Entrez le numéro du trajet à supprimer : ";
    cin >> i;
    if (i > 0 && i < c->getTaille() + 1)
    {
        c->supprimerTrajet(i - 1);
        cout << "Le trajet a été supprimé du catalogue" << endl;
    }
    else
        cout << "L'indice entré ne correspond à aucun trajet du catalogue" << endl;
}

bool Menu::fichierExiste(std::string nomFichier) {
    ifstream test;
    test.open(nomFichier + ".txt");

    cout << endl;

    if(test) {
        return true;
    }

    return false;
}

std::string Menu::gestionNomSauvegarde() {
    std::string nomFichier;
    char choix;

    cout << ">> NOM DU FICHIER DE SAUVEGARDE " << endl;
    cout << "Quel nom souhaitez-vous donner à votre sauvegarde (sans l'extension) ?" << endl;
    cin >> nomFichier;

    while(fichierExiste(nomFichier)) {
        cout << "Le fichier existe déjà. Que souhaitez-vous faire ?" << endl;
        cout << "1 - Ecraser le fichier existant et sauvegarder sous ce nom." << endl;
        cout << "2 - Choisir un autre nom de fichier." << endl;
        cout << "3 - Annuler l'opération de sauvegarde." << endl;
        cin >> choix;
        cout << endl;

        switch(choix) {
            case '1':
                return nomFichier + ".txt";
            break;
            case '2':
                cout << "Veuillez choisir un nouveau nom de fichier (sans l'extension)" << endl;
                cin >> nomFichier;
            break;
            case '3':
                cout << "ANNULATION. RETOUR AU MENU PRINCIPAL." << endl;
                return "";
            break;
            default:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Veuillez faire un choix valide." << endl;
                cin >> choix;
            break;
        }
    }

    cout << "Pas de conflit avec le nom du fichier. \n" << endl;

    return nomFichier + ".txt";
}

void Menu::sauvegarderCatalogue() {
    ofstream fichier;
    std::string nomFichier; 

    cout << "----------------- MENU SAUVEGARDE -----------------\n" << endl;

    if(c->getTaille() < 1) // S'il n'y a pas de trajet dans le catalogue
    {
        cout << "Il n'y a pas de contenu dans le catalogue. Sauvegarde impossible." << endl << endl;
        cout << "Fin de l'opération de sauvegarde." << endl;
        cout << "<< RETOUR AU MENU PRINCIPAL" << endl;

        return;
    }

    nomFichier = gestionNomSauvegarde();

    if(nomFichier == "") // Si le nom du fichier est vide, l'utilisateur veut annuler
        return;

    fichier.open(nomFichier); // Ouverture du fichier
    int choix;
    bool fin = false;

    // Variables pour les cases

    char type;
    std::string villeDepart = "";
    std::string villeArrivee = "";
    int borneMin = 0;
    int borneMax = 0;

    cout << ">> CONTENU DE LA SAUVEGARDE" << endl;

    do 
    {
        cout << "Que souhaitez-vous sauvegarder ?" << endl;
        cout << "1 - Tout le catalogue courant." << endl;
        cout << "2 - Seulement certains trajets, selon leur type (simple ou composé)." << endl;
        cout << "3 - Seulement certains trajets, selon une ville de départ et/ou d'arrivée." << endl;
        cout << "4 - Une sélection de trajets selon leur index." << endl;
        cout << "5 - Annuler [x]" << endl;
        cin >> choix;
        cout << endl;

        switch(choix) {
            case 1: // enregistrement de tout le catalogue
                fichier << c->writeAllFile();
                fin = true;
            break;

            case 2: // choix entre sauvegarder les trajets simples OU les trajets composés
                cout << "Veuillez choisir le type de trajet, simple (s) ou composé (c) : " ;
                cin >> type;

                while(type != 's' && type != 'c') // vérification choix
                {
                    cout << "Choix incorrect. Veuillez choisir entre simple (s) et composé (c) : ";
                    cin >> type;
                }
                
                fichier << c->writeFileByType(type);
                fin = true;
            break;

            case 3: // Choix entre ville d'arrivée, de départ ou les deux

                cout << "Souhaitez-vous enregistrer les trajets depuis ";
                cout << "une ville de départ (d), une ville d'arrivée (a) ou les deux (m) ?" << endl;
                cin >> type; 

                switch(type) 
                {
                    case 'd':
                        cout << "Ville de départ : ";
                        cin >> villeDepart;

                        fichier << c->writeFileByCity(1, villeDepart);
                    break;

                    case 'a':
                        cout << "Ville d'arrivée : ";
                        cin >> villeArrivee;

                        fichier << c->writeFileByCity(2, "", villeArrivee);
                    break;

                    case 'm':
                        cout << "Ville de départ : ";
                        cin >> villeDepart;
                        cout << "Ville d'arrivée : ";
                        cin >> villeArrivee;    
                        
                        fichier << c->writeFileByCity(3, villeDepart, villeArrivee);
                    break;

                    default:
                        cout << "Choix incorrect. Veuillez choisir entre départ (d), arrivée (a) ou mixte (m)." << endl;
                        cin >> type;
                    break;
                }
                fin = true;
            break;

            case 4: // indices
                cout << "Veuillez choisir la borne minimum : ";
                cin >> borneMin;

                while(borneMin < 1 || borneMin > c->getTaille())
                {
                    cout << "La borne doit être comprise entre 1 et " << c->getTaille() << ". ";
                    cout << "Veuillez choisir une borne minimum valide : ";
                    cin >> borneMin;
                }

                cout << "Veuillez choisir la borne maximum : ";
                cin >> borneMax;

                while(borneMax < 1 || borneMax > c->getTaille() || borneMax < borneMin)
                {
                    cout << "La borne doit être comprise entre 1 et " << c->getTaille();
                    cout << " et être supérieure ou égale à la borne minimum. ";
                    cout << "Veuillez choisir une borne maximum valide : ";
                    cin >> borneMax;
                }

                fichier << c->writeFileByInterval(borneMin, borneMax);
                fin = true;
            break;

            default:
                cout << "Veuillez entrer un choix valide." << endl;
            break;
        }
    }while(choix != 5 && !fin);
    
    fichier.close(); // Fermeture du fichier

    cout << "Fin de l'opération de sauvegarde." << endl;
    cout << "<< RETOUR AU MENU PRINCIPAL" << endl;
}

void Menu::chargerCatalogue() {
    string nomFichier;
    cout << "Saisir le nom du fichier sans son extension : ";
    cin >> nomFichier;
    while(!fichierExiste(nomFichier)) {
        cout << "Le fichier n'existe pas. Veuillez saisir un nom de fichier existant sans son extension ou quitter en tapant q : ";
        cin >> nomFichier;
        if(nomFichier.compare("q") == 0) {
            cout << "Annulation. Retour au menu. " << endl;
            return;
        }
    }

    int choix, retour;
    char type;
    bool fin = false;
    do 
    {
        cout << "Que souhaitez-vous charger ?" << endl;
        cout << "1 - Tout le fichier." << endl;
        cout << "2 - Seulement certains trajets, selon leur type (simple ou composé)." << endl;
        cout << "3 - Seulement certains trajets, selon une ville de départ et/ou d'arrivée." << endl;
        cout << "4 - Une sélection de trajets selon leur index." << endl;
        cout << "5 - Annuler [x]" << endl;
        cin >> choix;
        cout << endl;

        switch(choix) {
            case 1: // enregistrement de tout le catalogue
                cout << "Chargement du fichier..." << endl;
                retour = c->readFile(nomFichier+".txt");
                if(retour >= 0) {
                    cout << retour << " trajets ont été chargés";
                }
                else {
                    cout << "Fichier non chargé";
                }
                fin = true;
            break;

            case 2: // choix entre sauvegarder les trajets simples OU les trajets composés
                cout << "Veuillez choisir le type de trajet, simple (s) ou composé (c) : " ;
                cin >> type;

                while(type != 's' && type != 'c') // vérification choix
                {
                    cout << "Choix incorrect. Veuillez choisir entre simple (s) et composé (c) : ";
                    cin >> type;
                }
                cout << "Chargement du fichier..." << endl;
                retour = c->readFile(nomFichier+".txt", type);
                if(retour >= 0) {
                    cout << retour << " trajets ont été chargés";
                }
                else {
                    cout << "Fichier non chargé";
                }
                fin = true;
            break;

            case 3: // Choix entre ville d'arrivée, de départ ou les deux

                
            break;

            case 4: // indices
                
            break;

            default:
                cout << "Veuillez entrer un choix valide." << endl;
            break;
        }
    }while(choix != 5 && !fin);



    
}

//-------------------------------------------- Constructeurs - destructeur

Menu::Menu()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Menu>" << endl;
#endif
    c = new Catalogue();
} //----- Fin de Menu

Menu::~Menu()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Menu>" << endl;
#endif
    delete c;
} //----- Fin de ~Menu

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
