/*************************************************************************
               Catalog  -  Affichage & Manipulation des Trajets
                             -------------------
    début                : 27/09/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Catalog> (fichier Catalog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <cstring>
//------------------------------------------------------ Include personnel
#include "Catalog.h"
#include "../SimplePath/SimplePath.h"
#include "../ComposedPath/ComposedPath.h"
#include "../EmptyCriterion/EmptyCriterion.h"
#include "../AbstractCriterion/AbstractCriterion.h"
#include "../TypeCriterion/TypeCriterion.h"
#include "../CityCriterion/CityCriterion.h"
#include "../IntervalCriterion/IntervalCriterion.h"
#include<limits>

using namespace std;
//------------------------------------------------------------- Constantes
const char SEPARATOR[] = "=================================================\r\n";
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Catalog::Run()
{
    cout << "Bienvenue sur VoyageVoyage, L'app qui vous fera voyager !" << endl;
    displayMainMenu();

    string input;
    getStringInput(input);

    while (input != "9" && input != "Quit" && input != "Quitter" && input != "Q")
    {
        if (input ==  "0")
        {
            displayMainMenu();
        }
        else if (input == "1")
        {
            display();
        }
        else if (input ==  "2")
        {
            addSimplePath();
        }
        else if (input ==  "3")
        {
            addComposedPath();
        }
        else if (input ==  "4")
        {
            //recherche simple
            searchForPath(false);
        }
        else if (input ==  "5")
        {
            //recherche avancée
            searchForPath(true);
        }
        else if (input ==  "7")
        {
            if (pathArray->GetSize() == 0)
            {
                cout << "Il n'y a rien à sauvegarder..." << endl << endl;
            }
            else
            {
                save();
            }
        }
        else if (input ==  "8")
        {
            load();
        }
        else
        {
            displayMainMenu();
        }

        cout << "Entrez une nouvelle commande (0 pour afficher le menu) : " << endl;
        getStringInput(input);
    }

    cout << "Merci d'avoir utilisé VoyageVoyage ! à Bientot !" << endl;
}

//-------------------------------------------- Constructeurs - destructeur

Catalog::Catalog ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalog>" << endl;
#endif

    pathArray = new PathArray;
    searchEngine = new SearchEngine;
} //----- Fin de Catalog


Catalog::~Catalog ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalog>" << endl;
#endif

    delete pathArray;
    delete searchEngine;
    FileSerializer::Dispose();
} //----- Fin de ~Catalog

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

/* File Linked Methods */

void Catalog::save() const
{
    string input;

    do { cout << "Choisir le chemin de votre sauvegarde : "; }
    while (!getStringInput(input));

    cout << endl;

    FileSerializer * fileSerializer = FileSerializer::GetInstance();

    if ((fileSerializer->FileExist(input) && askForFileOverride()) || fileSerializer->FileCanBeCreated(input))
    {
        AbstractCriterion * criterion = askForCriterion();
        if (criterion == nullptr)
        {
            displayMainMenu();
            return;
        }
        fileSerializer->Save(pathArray, input, criterion);
        cout << "La sauvegarde à bien été créée." << endl;
        delete criterion;
    }
    else
    {
        cout << endl << "Impossible de sauvegarder le catalogue. Le fichier n'existe pas ou vous avez choisi de ne pas l'écraser." << endl;
    }
    cout << endl;
}

void Catalog::load() const
{
    string input;

    do { cout << "Choisir le chemin de votre sauvegarde : "; }
    while (!getStringInput(input));

    FileSerializer * fileSerializer = FileSerializer::GetInstance();

    if (fileSerializer->FileExist(input))
    {
        int previousSize = pathArray->GetSize();
        AbstractCriterion * criterion = askForCriterion();
        if (criterion == nullptr)
        {
            displayMainMenu();
            return;
        }
        if (fileSerializer->Load(pathArray, input, criterion))
            cout << "Vos données ont bien été chargées. " << (pathArray->GetSize() - previousSize) << " Trajet(s) ajouté(s)." << endl;
        else
        {
            cout << "Vos données n'ont pas pu être chargées dans leur totalité : le format du fichier n'est pas valide."
                    << endl << (pathArray->GetSize() - previousSize) << " Trajet(s) ajouté(s)." << endl;
        }
        delete criterion;
    }
    else
    {
        cout << endl << "Le fichier ne semble pas exister. Retour au menu principal..." << endl;
    }
    cout << endl;
}

/* Edition Methods */

void Catalog::addSimplePath() const
{
    string startingCity;
    string endingCity;
    MeansOfTransport meansOfTransport;

    cout << SEPARATOR;
    cout << "Ajout d'un Trajet Simple..." << endl;

    askForStartingCity(startingCity);
    askForEndingCity(endingCity);
    meansOfTransport = displayAndAskForMeansOfTransport();

    addPathAndNotifyUser(new SimplePath(startingCity.c_str(), endingCity.c_str(), meansOfTransport));
}
void Catalog::addComposedPath() const
{
    ComposedPath *composedPath = new ComposedPath;
    string startingCity;
    string endingCity;
    MeansOfTransport meansOfTransport;

    cout << SEPARATOR;
    cout << "Ajout d'un Trajet Composé..." << endl;

    int stageQty = askForStageQty();

    for (int i = 1; i <= stageQty; i++)
    {
        cout << "Etape " << i << endl;

        if (i > 1)
        {
            cout << "\tVille de départ : ";
            startingCity = endingCity;
            cout << startingCity << endl;
        }
        else
        {
            askForStartingCity(startingCity);
        }

        askForEndingCity(endingCity);
        meansOfTransport = displayAndAskForMeansOfTransport();

        composedPath->AddStage(new SimplePath(startingCity.c_str(), endingCity.c_str(), meansOfTransport));
    }

    addPathAndNotifyUser(composedPath);
}

void Catalog::addPathAndNotifyUser(Path * path) const
{
    if (pathArray->Add(path))
    {
        searchEngine->AddPath(path);
        cout << "Votre Trajet à bien été ajouté !" << endl;
    }
    else
    {
        cout << "Ce Trajet existe déjà !" << endl;
    }

    cout << SEPARATOR;
}

/* Search Methods */
void Catalog::searchForPath(const bool advanced) const
{
    string startingCity;
    string endingCity;

    cout << SEPARATOR;
    if (advanced)
    {
        cout << "Recherche d'un trajet (Version avancée)..." << endl;
    }
    else
    {
        cout << "Recherche d'un trajet (Version simple)..." << endl;
    }

    askForStartingCity(startingCity);

    do
    {
        cout << "\tVille d'arrivée : ";
    }
    while (!getStringInput(endingCity));


    cout << endl << "Trajet(s) trouvé(s) :" << endl << endl;
    if (advanced)
    {
        searchEngine->AdvancedSearch(startingCity.c_str(), endingCity.c_str());
    }
    else
    {
        searchEngine->SimpleSearch(startingCity.c_str(), endingCity.c_str());
    }

    cout << SEPARATOR;
}

/* Input Methods */

void Catalog::askForStartingCity(string & startingCity) const
{
    do
    {
        cout << "\tVille de départ : ";
    }
    while (!getStringInput(startingCity));
}
void Catalog::askForEndingCity(string & endingCity) const
{
    do
    {
        cout << "\tVille d'arrivée : ";
    }
    while (!getStringInput(endingCity));
}
unsigned int Catalog::askForStageQty() const
{
    int stageQty;

    do
    {
        cout << "Nombre d'étapes du trajet (entre 2 et 10) : ";
        getNumberInput(stageQty);
    }
    while (stageQty <= 1 || stageQty > 10);

    return (unsigned int)stageQty;
}

AbstractCriterion * Catalog::askForCriterion() const
{
    cout    <<                                                             endl
            << SEPARATOR
            << "Taper 0 pour sélectionner tous les trajets"                                          << endl
            << "Taper 1 pour sélectionner les trajets par type."                                     << endl
            << "Taper 2 pour sélectionner les trajets par ville de départ ou d'arrivée."             << endl
            << "Taper 3 pour sélectionner un intervalle de trajet."                                  << endl
            <<                                                                                          endl
            << "Taper 4 revenir au menu principal"                                                   << endl
            << SEPARATOR
            <<                                                             endl;

    string input;
    getStringInput(input);

    if (input ==  "0")
    {
        return new EmptyCriterion;
    }
    else if (input == "1")
    {
        string type; 
        do
        {
            cout    <<                                                             endl
            << SEPARATOR
            << "Taper 0 pour sélectionner tous les trajets simples."                                 << endl
            << "Taper 1 pour sélectionner les trajets composés."                                     << endl
            <<                                                                                          endl
            << "Taper 2 revenir au menu principal"                                                   << endl
            << SEPARATOR
            <<                                                             endl;
        }
        while (!getStringInput(type));
        if (type == "0")
        {
            return new TypeCriterion(false);
        }
        else if (type == "1")
        {
            return new TypeCriterion(true);
        }
        else if (type == "2")
        {
            return nullptr;
        } 
        else
        {
            return askForCriterion();
        }

    }
    else if (input ==  "2")
    {
        string start;
        string end;
        do
        {
            cout << "\tVille de départ (entrez \"-\" pour ne pas filtrer sur les villes de départ) : ";
        }
        while (!getStringInput(start));

        do
        {
            cout << "\tVille d'arrivée (entrez \"-\" pour ne pas filtrer sur les villes d'arrivée) : ";
        }
        while (!getStringInput(end));

        const char * startParam = start.c_str();
        const char * endParam = end.c_str();
        if (start == "-" && end == "-")
        {
            cout << "Aucun filtre de ville détecté ; tous les trajets seront sélectionnés.";
            return new EmptyCriterion;
        }
        return new CityCriterion((start == "-") ? (nullptr) : (startParam), (end == "-") ? (nullptr) : (endParam));
    }
    else if (input ==  "3")
    {
        int startInterval;
        int endInterval;
        bool correct = false;
        do 
        {
            do
            {
                cout << "\tBorne inférieure : ";
            }
            while (!getNumberInput(startInterval));

            do
            {
                cout << "\tBorne supérieure : ";
            }
            while (!getNumberInput(endInterval));

            correct = (startInterval < endInterval) && (endInterval > 0);
            if (!correct)
            {
                cout << "Les bornes ne forment pas un intervalle correct. Vérifiez que votre borne inférieure soit bien inférieure à votre borne supérieure et " << endl;
                cout << "que au moins une de vos bornes soit positive." << endl << endl;
            }
        } while (!correct);
        return new IntervalCriterion(startInterval, endInterval);
    }
    else if (input ==  "4")
    {
        return nullptr;
    }
    else
    {
        return askForCriterion();
    }
    return nullptr;
}

MeansOfTransport Catalog::displayAndAskForMeansOfTransport() const
{
    string transport;

    for ( ; ; )
    {
        do
        {
            displayMeansOfTransport();
        }
        while (!getStringInput(transport));

        for (int i = 0; i < MEAN_OF_TRANSPORT_QTY; i++)
        {
            if (transport == MEAN_OF_TRANSPORT_STRINGS[i])
                return (MeansOfTransport) i;
        }

        cout << "Moyen de transport non valide...\n";
    }
}

bool Catalog::getStringInput(string & input) const
{
    getline(cin >> std::ws, input);
    if(cin.eof() || cin.bad() || cin.fail())
    {
        cerr << "Erreur, saisie incorrecte." << endl;
        return false;
    }
    cin.clear();
    capitalizeFirstWordsLetter(input);
    return true;
}

bool Catalog::getNumberInput(int & input) const
{
    while (!(cin >> input))
    {
        cerr << "Erreur, saisie incorrecte." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    cin.clear();
    return true;
}


void Catalog::capitalizeFirstWordsLetter(string & input) const
// Algorithme :
// Change la première lettre et toutes les lettres après un espace par des majuscule (si ce sont des lettres).
// Change les autres lettres en majuscule en lettre minuscule.
{
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (i == 0) // First Letter
        {
            if (input[i] >= 'a' && input[i] <= 'z')
                input[i] -= 32;

            continue;
        }
        if(input[i]==' ') // Check Space
        {
            i++;

            if(input[i] >= 'a' && input[i] <= 'z')
            {
                input[i] -= 32;
                continue;
            }
        }
        else
        {
            if(input[i] >= 'A' && input[i] <= 'Z')
                input[i] += 32;
        }
    }
}

bool Catalog::askForFileOverride() const
{
    string answer;
    for ( ; ; )
    {
        cout << "Le fichier existe déjà, voulez vous l'écraser, (o/n) : ";
        getStringInput(answer);

        if (answer[0] == 'O')
            return true;

        if (answer[0] == 'N')
            return false;
    }
}

/* Output Methods */

void Catalog::displayMainMenu() const
{
    cout    <<                                                             endl
            << SEPARATOR
            << "Taper 0 pour Consulter ce menu."                        << endl
            << "Taper 1 pour Consulter tous les trajets."               << endl
            <<                                                             endl
            << "Taper 2 pour Ajouter un trajet simple."                 << endl
            << "Taper 3 pour Ajouter un trajet composé."                << endl
            <<                                                             endl
            << "Taper 4 pour chercher un trajet (version simple)."      << endl
            << "Taper 5 pour chercher un trajet (version avancée)."     << endl
            <<                                                             endl
            << "Taper 7 pour sauvegarder votre catalogue."              << endl
            << "Taper 8 pour charger un catalogue."                     << endl
            <<                                                             endl
            << "Taper 9 pour quitter l'application \"Voyage Voyage\""   << endl
            << SEPARATOR
            <<                                                             endl;
}

void Catalog::display() const
{
    cout << SEPARATOR;
    cout << "Liste des Voyages Disponibles..."                      << endl;
    cout                                                            << endl;

    for (unsigned int i = 0; i < pathArray->GetSize(); i++)
    {
        cout << "#" << i + 1 << " " << *pathArray->Get(i) << endl;
    }

    cout << SEPARATOR;
}

void Catalog::displayMeansOfTransport() const
{
    cout << "\tMoyen de transport ( ";

    for (int i = 0; i < MEAN_OF_TRANSPORT_QTY; i++)
    {
        cout << MEAN_OF_TRANSPORT_STRINGS[i] << " ";
    }

    cout << ") : ";
}