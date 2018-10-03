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
#include <iomanip>

//------------------------------------------------------ Include personnel
#include "Catalog.h"
#include "../SimplePath/SimplePath.h"
#include "../ComposedPath/ComposedPath.h"

using namespace std;
//------------------------------------------------------------- Constantes

const char SEPARATOR[] = "=================================================\r\n";

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Catalog::Run()
{
    cout << "Bienvenue sur VoyageVoyage, L'app qui vous fera voyager !" << endl;
    displayMainMenu();

    char input[100];
    getInputWord(input);

    while (strcmp(input,"9") != 0 && strcmp(input,"quit") != 0 && strcmp(input,"quitter") != 0)
    {
        if (strcmp(input, "0") == 0)
        {
            displayMainMenu();
        }
        if (strcmp(input,"1") == 0)
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
        else if (strcmp(input, "4") == 0)     //Chercher Trajets (version simple)
        {
            searchForPath();
        }
        else if (strcmp(input, "5") == 0)     //TODO: Chercher Trajets (version avancée)
        {
            cout << "Cette fonctionnalitée n'est pas encore implémenté..." << endl;
        }
        else
        {
            displayMainMenu();
        }

        getInputWord(input);
    }

    cout << "Merci d'avoir utilisé VoyageVoyage ! à Bientot !" << endl;
}

//-------------------------------------------- Constructeurs - destructeur

Catalog::Catalog ( )
{
    pathArray = new PathArray();

#ifdef MAP
    cout << "Appel au constructeur de <Catalog>" << endl;
#endif
} //----- Fin de Catalog


Catalog::~Catalog ( )
{
    delete pathArray;

#ifdef MAP
    cout << "Appel au destructeur de <Catalog>" << endl;
#endif
} //----- Fin de ~Catalog

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

/* Edition Methods */

void Catalog::addSimplePath() const
{
    char startingCity[100];
    char endingCity[100];
    MeansOfTransport meansOfTransport;

    cout << SEPARATOR;
    cout << "Ajout d'un Trajet Simple..." << endl;

    cout << "\tVille de départ : ";
    getInputLine(startingCity);

    cout << "\tVille d'arrivé : ";
    getInputLine(endingCity);

    meansOfTransport = displayAndAskForMeansOfTransport();

    addPathAndNotifyUser(new SimplePath(startingCity, endingCity, meansOfTransport));
}
void Catalog::addComposedPath() const
{
    ComposedPath *composedPath = new ComposedPath();
    char startingCity[100];
    char endingCity[100];
    MeansOfTransport meansOfTransport;

    cout << SEPARATOR;
    cout << "Ajout d'un Trajet Composé..." << endl;

    int stageQty = askForStageQty();

    for (int i = 1; i <= stageQty; i++)
    {
        cout << "Etape " << i << endl;

        cout << "\tVille de départ : ";

        if (i > 1)
        {
            strcpy(startingCity, endingCity);
            cout << startingCity << endl;
        }
        else
        {
            getInputLine(startingCity);
        }

        cout << "\tVille d'arrivé : ";
        getInputLine(endingCity);

        meansOfTransport = displayAndAskForMeansOfTransport();

        composedPath->AddStage(new SimplePath(startingCity, endingCity, meansOfTransport));
    }

    addPathAndNotifyUser(composedPath);
}

void Catalog::addPathAndNotifyUser(Path * path) const
{
    if (pathArray->Add(path) == ADDED)
    {
        cout << "Votre Trajet à bien été ajouté !" << endl;
    }
    else
    {
        cout << "Ce Trajet existe déjà !" << endl;
    }

    cout << SEPARATOR;
}

/* Search Methods */
void Catalog::searchForPath() const
{
    char startingCity[100];
    char endingCity[100];

    cout << SEPARATOR;
    cout << "Recherche d'un Trajet (Version Simple)..." << endl;

    cout << "\tVille de départ : ";
    getInputLine(startingCity);

    cout << "\tVille d'arrivé : ";
    getInputLine(endingCity);

    cout << endl << "Trajet(s) trouvé(s) :" << endl;

    for (int i = 0; i < pathArray->GetCurrentCard(); i++)
    {
        Path * temp = pathArray->Get(i);

        if (temp->StartFrom(startingCity) && temp->StopAt(endingCity))
        {
            cout << endl << *temp;
        }
    }

    cout << SEPARATOR;
}

/* Input Methods */

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

    do
    {
        displayMeansOfTransport();

        getInputWord(transport);

        for (int i = 0; i < MEAN_OF_TRANSPORT_QTY; i++)
        {
            if (strcmp(transport, MEAN_OF_TRANSPORT_STRINGS[i]) == 0)
                return (MeansOfTransport) i;
        }

        cout << "Moyen de transport non valide...\n";
    }
    while(1);
}

void Catalog::getInputLine(char *input) const
{
    if (fscanf(stdin, "%99[^\n]", input) != 1)
        inputError();

    cleanInputStream();
}
void Catalog::getInputWord(char *input) const
{
    if (fscanf(stdin, "%99s", input) != 1)
        inputError();

    cleanInputStream();
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
            << "Taper 9 pour quitter l'application \"Voyage Voyage\""   << endl
            << SEPARATOR
            <<                                                             endl;
}

void Catalog::display() const
{
    cout << SEPARATOR;
    cout << "Liste des Voyages Disponibles..."                      << endl;
    cout                                                            << endl;

    for (int i = 0; i < pathArray->GetCurrentCard(); i++)
    {
        cout << "#" << i << " " << *pathArray->Get(i) << endl;
    }

    cout << SEPARATOR;
}

void Catalog::displayMeansOfTransport() const
{
    cout << "\tMoyen de transport ( ";

    for (int i = 0; i < MEAN_OF_TRANSPORT_QTY; i++) {
        cout << MEAN_OF_TRANSPORT_STRINGS[i] << " ";
    }

    cout << ") : ";
}