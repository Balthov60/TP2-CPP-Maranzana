/*************************************************************************
            Catalog  -  Affichage & Manipulation des Trajets
                             -------------------
    début                : 27/09/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Catalog> (fichier Catalog.h) ----------------
#if ! defined ( CATALOG_H )
#define CATALOG_H

//--------------------------------------------------- Interfaces utilisées

#include <iostream>

#include "../PathArray/PathArray.h"
#include "../SearchEngine/SearchEngine.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalog>
//
// //TODO documentation
// Permet à l'utilisateur d'intéragir avec la liste des trajets
//
//------------------------------------------------------------------------

class Catalog
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void Run();

    Catalog ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Catalog ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées

    void addSimplePath() const;
    void addComposedPath() const;
    void addPathAndNotifyUser(Path * path) const;

    void searchForPath(const bool advanced) const;

    unsigned int askForStageQty() const;
    MeansOfTransport displayAndAskForMeansOfTransport() const;

    void getInputLine(char input[]) const;
    void getInputWord(char input[]) const;

    void cleanInputStream() const;
    void inputError() const;

    void displayMainMenu() const;
    void display() const;
    void displayMeansOfTransport() const;

//----------------------------------------------------- Attributs protégés

    PathArray * pathArray;
    SearchEngine * searchEngine;

};

//-------------------------------- Autres définitions dépendantes de <Catalog>

#endif // CATALOG_H