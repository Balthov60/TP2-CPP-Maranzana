/*************************************************************************
                           SimplePath  -  description
                             -------------------
    début                : 27/09/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <SimplePath> (fichier SimplePath.h) ----------------
#if ! defined ( SimplePath_H )
#define SimplePath_H

//--------------------------------------------------- Interfaces utilisées

#include "../Path/Path.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <SimplePath>
//
//
//------------------------------------------------------------------------

class SimplePath : public Path
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
    SimplePath & operator = ( const SimplePath & unSimplePath );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    SimplePath ( const SimplePath & unSimplePath );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    SimplePath ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~SimplePath ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <SimplePath>

#endif // SimplePath_H

