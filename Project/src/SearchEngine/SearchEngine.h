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
const int DEFAULT_MAX_SIZE = 10;
//------------------------------------------------------------------ Types
struct Node
{
    unsigned int startIndex;
    unsigned int endIndex;
    Node* previous;
    Node* next;
};

//------------------------------------------------------------------------
// Rôle de la classe <SearchEngine>
//
// Le search engine permet de chercher des trajets entre 2 villes dans tout 
// le catalogue avec ou sans composition.
//
//------------------------------------------------------------------------

class SearchEngine
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    

    void SimpleSearch(const char * startingCity, const  char * endingCity) const;
    // Mode d'emploi :
    //      Cherche et affiche le(s) trajet(s) directs correspondant(s) du catalogue pour
    // se rendre de la ville "startingCity" à la ville "endingCity"
    //      > startingCity : ville de départ
    //      > endingCity : ville d'arrivée
    // Contrat :
    //

    void AdvancedSearch(const char * startingCity,const  char * endingCity) const;
    // Mode d'emploi :
    //      Cherche et affiche le(s) trajet(s) pour se rendre de la
    // ville "startingCity" à la ville "endingCity" en effectuant une
    // composition de plusieurs sous-trajets du catalogue
    //      > startingCity : ville de départ
    //      > endingCity : ville d'arrivée
    // Contrat :
    //

    void AddPath(Path* path);
    // Mode d'emploi :
    //      Ajoute un trajet au moteur de recherche
    //      > path : pointeur sur le trajet à ajouter
    // Contrat :
    //      path est un pointeur sur trajet valide



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

private:
//----------------------------------------------------- Méthodes protégées

    unsigned int getStartCityIndex(const char * city) const;
    unsigned int getEndCityIndex(const char * city) const;
    bool recursiveSearch(Node* node, unsigned int endIndex, bool * doneIndex) const;

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

