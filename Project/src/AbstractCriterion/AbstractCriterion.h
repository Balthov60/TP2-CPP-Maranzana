/*************************************************************************
                           AbstractCriterion  -  description
                             -------------------
    début                : 28/11/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <AbstractCriterion> (fichier AbstractCriterion.h) ----------------
#if ! defined ( AbstractCriterion_H )
#define AbstractCriterion_H

//--------------------------------------------------- Interfaces utilisées
#include "../Path/Path.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <AbstractCriterion>
//
//
//------------------------------------------------------------------------

class AbstractCriterion
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual const bool CheckLine(const char * line) const = 0;

    virtual const bool CheckPath(const Path * path) const = 0;

    virtual const bool CheckMetadata(const char * line);

//------------------------------------------------- Surcharge d'opérateurs
    AbstractCriterion & operator = ( const AbstractCriterion & unAbstractCriterion );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    AbstractCriterion ( const AbstractCriterion & unAbstractCriterion );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    AbstractCriterion ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~AbstractCriterion ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <AbstractCriterion>

#endif // AbstractCriterion_H

