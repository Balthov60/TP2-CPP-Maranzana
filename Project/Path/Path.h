/*************************************************************************
                           Path  -  description
                             -------------------
    début                : 27/09/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Path> (fichier Path.h) ----------------
#if ! defined ( Path_H )
#define Path_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Path>
//
//
//------------------------------------------------------------------------

class Path
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
    Path ( const Path & unPath );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Path ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Path ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Path>

#endif // Path_H

