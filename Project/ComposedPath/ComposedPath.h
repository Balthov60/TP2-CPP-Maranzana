/*************************************************************************
                           ComposedPath  -  description
                             -------------------
    début                : 27/09/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <ComposedPath> (fichier ComposedPath.h) ----------------
#if ! defined ( COMPOSEDPATH_H )
#define COMPOSEDPATH_H

//--------------------------------------------------- Interfaces utilisées

#include "../Path/Path.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ComposedPath>
//
//
//------------------------------------------------------------------------

class ComposedPath : public Path
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
//TODO: opérateur =


//-------------------------------------------- Constructeurs - destructeur
    ComposedPath ( const ComposedPath & unComposedPath );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    ComposedPath ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ComposedPath ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <ComposedPath>

#endif // COMPOSEDPATH_H

