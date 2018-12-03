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
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Catalog.h"
#include "../SimplePath/SimplePath.h"
#include "../ComposedPath/ComposedPath.h"
#include "../EmptyCriterion/EmptyCriterion.h"


using std::cout;
using std::endl;
//------------------------------------------------------------- Constantes
const int INPUT_MAX_SIZE = 50;
const int PATH_MAX_LENGTH = 256;
const char SEPARATOR[] = "=================================================\r\n";
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Catalog::Run()
{
    cout << "Bienvenue sur VoyageVoyage, L'app qui vous fera voyager !" << endl;
    displayMainMenu();

    char input[INPUT_MAX_SIZE];
    getInputWord(input);

    while (strcmp(input,"9") != 0 && strcmp(input,"Quit") != 0 && strcmp(input,"Quitter") != 0 && strcmp(input,"Q") != 0)
    {
        if (strcmp(input, "0") == 0)
        {
            displayMainMenu();
        }
        else if (strcmp(input,"1") == 0)
        {
            display();
        }
        else if (strcmp(input, "2") == 0)
        {
            addSimplePath();
        }
        else if (strcmp(input, "3") == 0)
        {
            addComposedPath();
        }
        else if (strcmp(input, "4") == 0)
        {
            //recherche simple
            searchForPath(false);
        }
        else if (strcmp(input, "5") == 0)
        {
            //recherche avancée
            searchForPath(true);
        }
        else if (strcmp(input, "7") == 0)
        {
            save();
        }
        else if (strcmp(input, "8") == 0)
        {
            load();
        }
        else
        {
            displayMainMenu();
        }
        cout << "Entrez une nouvelle commande (0 pour afficher le menu) : " << endl;
        getInputWord(input);
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
} //----- Fin de ~Catalog

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

/* File Linked Methods */

void Catalog::save() const
{
    char input[PATH_MAX_LENGTH];

    do { cout << "Choisir le chemin de votre sauvegarde (sans espace) : "; }
    while (!getInputWord(input));

    FileSerializer * fileSerializer = FileSerializer::getInstance();

    if ((fileSerializer->FileExist(input) && askForFileOverride()) || fileSerializer->FileCanBeCreated(input))
    {
        EmptyCriterion criterion; // TODO Menu criterion
        fileSerializer->Save(pathArray, input, criterion);
        cout << "La sauvegarde à bien été créé." << endl;
    }
    else
    {
        cout << "Impossible de sauvegarder le catalogue (chemin invalide)" << endl;
        displayMainMenu();
    }
}

void Catalog::load() const
{
    char input[PATH_MAX_LENGTH];

    do { cout << "Choisir le chemin de votre sauvegarde (sans espace) : "; }
    while (!getInputWord(input));

    FileSerializer * fileSerializer = FileSerializer::getInstance();

    if (fileSerializer->FileExist(input))
    {
        int previousSize = pathArray->GetSize();
        EmptyCriterion criterion; // TODO menu criterion
        if (fileSerializer->Load(pathArray, input, criterion))
            cout << "Vos données ont bien été chargées. " << (pathArray->GetSize() - previousSize) << " Trajet(s) ajouté(s)." << endl;
        else
        {
            cout << "Vos données n'ont pas pu être chargées dans leur totalité, le format du fichier n'est pas valide... "
                    << (pathArray->GetSize() - previousSize) << " Trajet(s) ajouté(s)." << endl;
        }
    }
    else
    {
        cout << "Votre fichier n'existe pas..." << endl;
        displayMainMenu();
    }
}

/* Edition Methods */

void Catalog::addSimplePath() const
{
    char startingCity[INPUT_MAX_SIZE];
    char endingCity[INPUT_MAX_SIZE];
    MeansOfTransport meansOfTransport;

    cout << SEPARATOR;
    cout << "Ajout d'un Trajet Simple..." << endl;

    askForStartingCity(startingCity);
    askForEndingCity(endingCity);
    meansOfTransport = displayAndAskForMeansOfTransport();

    addPathAndNotifyUser(new SimplePath(startingCity, endingCity, meansOfTransport));
}
void Catalog::addComposedPath() const
{
    ComposedPath *composedPath = new ComposedPath;
    char startingCity[INPUT_MAX_SIZE];
    char endingCity[INPUT_MAX_SIZE];
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
            strcpy(startingCity, endingCity);
            cout << startingCity << endl;
        }
        else
        {
            askForStartingCity(startingCity);
        }

        askForEndingCity(endingCity);
        meansOfTransport = displayAndAskForMeansOfTransport();

        composedPath->AddStage(new SimplePath(startingCity, endingCity, meansOfTransport));
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
    char startingCity[INPUT_MAX_SIZE];
    char endingCity[INPUT_MAX_SIZE];

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
    while (!getInputLine(endingCity));


    cout << endl << "Trajet(s) trouvé(s) :" << endl << endl;
    if (advanced)
    {
        searchEngine->AdvancedSearch(startingCity, endingCity);
    }
    else
    {
        searchEngine->SimpleSearch(startingCity, endingCity);
    }

    cout << SEPARATOR;
}

/* Input Methods */

void Catalog::askForStartingCity(char *startingCity) const
{
    do
    {
        cout << "\tVille de départ : ";
    }
    while (!getInputLine(startingCity));
}
void Catalog::askForEndingCity(char *endingCity) const
{
    do
    {
        cout << "\tVille d'arrivée : ";
    }
    while (!getInputLine(endingCity));
}
unsigned int Catalog::askForStageQty() const
{
    unsigned int stageQty;

    do
    {
        cout << "Nombre d'étapes du trajet (entre 2 et 10) : ";
        scanf("%ul", &stageQty);
        cleanInputStream();
    }
    while (stageQty <= 1 || stageQty > 10);

    return stageQty;
}

MeansOfTransport Catalog::displayAndAskForMeansOfTransport() const
{
    char transport[MEAN_OF_TRANSPORT_STRING_MAX_SIZE];

    for ( ; ; )
    {
        do
        {
            displayMeansOfTransport();
        }
        while (!getInputLine(transport));

        for (int i = 0; i < MEAN_OF_TRANSPORT_QTY; i++)
        {
            if (strcmp(transport, MEAN_OF_TRANSPORT_STRINGS[i]) == 0)
                return (MeansOfTransport) i;
        }

        cout << "Moyen de transport non valide...\n";
    }
}

bool Catalog::getInputLine(char *input) const
{
    if (fscanf(stdin, "%99[^\n]", input) != 1)
    {
        cleanInputStream();
        return false;
    }

    cleanInputStream();
    capitalizeFirstWordsLetter(input);

    return true;
}
bool Catalog::getInputWord(char *input) const
{
    if (fscanf(stdin, "%99s", input) != 1)
    {
        inputError();
    }

    cleanInputStream();
    capitalizeFirstWordsLetter(input);

    return true;
}

void Catalog::cleanInputStream() const
{
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF);
}
void Catalog::inputError() const
{
    cout << "input Error\n";
    exit(1);
}

void Catalog::capitalizeFirstWordsLetter(char *input) const
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
    char answer[INPUT_MAX_SIZE];

    for ( ; ; )
    {
        cout << "Le fichier existe déjà, voulez vous l'écraser, (o/n) : ";
        getInputWord(answer);

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