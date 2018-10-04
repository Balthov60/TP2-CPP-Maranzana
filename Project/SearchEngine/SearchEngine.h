/*************************************************************************
                           SearchEngine  -  description
                             -------------------
    début                : 04/10/2018
    copyright            : (C) 2018 par WALLYN Valentin - FROLIN Balthazar
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <SearchEngine> (fichier SearchEngine.h) ----------------
#if ! defined ( SEARCHENGINE_H )
#define SEARCHENGINE_H

//--------------------------------------------------- Interfaces utilisées
#include "../Path/Path.h"
#include "../PathArray/PathArray.h"
//------------------------------------------------------------- Constantes
const int DEFAULT_MAX_SIZE = 1;
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <SearchEngine>
//
//
//------------------------------------------------------------------------

class SearchEngine
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    struct node 
    {
        unsigned int startIndex;
        unsigned int endIndex;
        node* previous;
        node* next;
    };

    void DisplayMatrix() const;

    void SimpleSearch(const char * startingCity, const  char * endingCity) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    void AdvancedSearch(const char * startingCity,const  char * endingCity) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    void AddPath(Path* path);
    // Mode d'emploi :
    //
    // Contrat :
    //



//------------------------------------------------- Surcharge d'opérateurs
    SearchEngine & operator = ( const SearchEngine & other );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    SearchEngine ( const SearchEngine & other );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    SearchEngine ( const unsigned int size = DEFAULT_MAX_SIZE);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~SearchEngine ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    unsigned int getStartCityIndex(const char * city) const;
    unsigned int getEndCityIndex(const char * city) const;
    bool recursiveSearch(node* node, unsigned int endIndex, bool * doneIndex) const;
//----------------------------------------------------- Attributs protégés
    PathArray*** adjacencyMatrix;
    char ** startCities;
    char ** endCities;
    unsigned int startCurrentSize;
    unsigned int endCurrentSize;
    unsigned int startMaxSize;
    unsigned int endMaxSize;

};

//-------------------------------- Autres définitions dépendantes de <SearchEngine>

#endif // SEARCHENGINE_H

