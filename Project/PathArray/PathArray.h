/*************************************************************************
                           PathArray  -  description
                             -------------------
    début                : 27/09/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <PathArray> (fichier PathArray.h) ----------------
#if ! defined ( PathArray_H )
#define PathArray_H

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
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    PathArray & operator = ( const PathArray & unPathArray );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    PathArray ( const PathArray & unPathArray );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    PathArray ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~PathArray ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <PathArray>

#endif // PathArray_H

