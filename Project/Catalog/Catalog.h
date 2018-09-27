/*************************************************************************
            Catalog  -  Affichage & Manipulation des Trajets
                             -------------------
    début                : 27/09/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Catalog> (fichier Catalog.h) ----------------
#if ! defined ( Catalog_H )
#define Catalog_H

//--------------------------------------------------- Interfaces utilisées

#include "../PathArray/PathArray.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalog>
//
// "Catalog" permet à l'utilisateur d'intéragir avec la liste des trajets
//
//------------------------------------------------------------------------

class Catalog
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

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

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Catalog>

#endif // Catalog_H

