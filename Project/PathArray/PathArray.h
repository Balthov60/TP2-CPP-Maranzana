/*************************************************************************
                           PathArray  -  description
                             -------------------
    début                : 27/09/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <PathArray> (fichier PathArray.h) ----------------
#if ! defined ( PATHARRAY_H )
#define PATHARRAY_H

enum AddStatus { EXISTING, ADDED };
const int CARD_MAX = 5;
//--------------------------------------------------- Interfaces utilisées

#include "../Path/Path.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <PathArray>
//
//
//------------------------------------------------------------------------

class PathArray
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    
    void Display(void) const;
    // Mode d'emploi :
    //
    // Contrat :
    //
    bool Equals(const PathArray & otherPathArray) const;
    // Mode d'emploi :
    //
    // Contrat :
    //
    AddStatus Add(Path* pathToAdd);
    // Mode d'emploi :
    //
    // Contrat :
    //
    unsigned int Adjust(int delta);
    // Mode d'emploi :
    //
    // Contrat :
    //
    bool Remove(Path* element);
    // Mode d'emploi :
    //
    // Contrat :
    //
    unsigned int Remove(const PathArray & otherPathArray);
    // Mode d'emploi :
    //
    // Contrat :
    //
    bool Contains(Path* value) const;
    // Mode d'emploi :
    //
    // Contrat :
    //
    unsigned int GetCurrentCard(void) const;
    // Mode d'emploi :
    //
    // Contrat :
    //
    unsigned int GetMaxCard(void) const;
    // Mode d'emploi :
    //
    // Contrat :
    //
    Path* Get(int index) const;
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs

//TODO: opérateur =



//-------------------------------------------- Constructeurs - destructeur
    PathArray ( const PathArray & otherPathArray );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    PathArray (const unsigned int cardMax);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~PathArray ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    //PathArray(Path pathArray[], unsigned int nbElements);


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
Path ** elements;
unsigned int maxCard;
unsigned int currentCard;
};

//-------------------------------- Autres définitions dépendantes de <PathArray>

#endif // PATHARRAY_H

