/*************************************************************************
                           IntervalCriterion  -  description
                             -------------------
    début                : 28/11/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <IntervalCriterion> (fichier IntervalCriterion.h) ----------------
#if ! defined ( IntervalCriterion_H )
#define IntervalCriterion_H

//--------------------------------------------------- Interfaces utilisées
#include "../AbstractCriterion/AbstractCriterion.h"
#include "../Path/Path.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <IntervalCriterion>
//
//
//------------------------------------------------------------------------

class IntervalCriterion : public AbstractCriterion
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual const bool CheckMetadata(const char * line);
    
    virtual const bool CheckLine(const char * path);

    virtual const bool CheckPath(const Path * path);


//------------------------------------------------- Surcharge d'opérateurs
    IntervalCriterion & operator = ( IntervalCriterion other );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    IntervalCriterion ( const IntervalCriterion & other );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    IntervalCriterion ( int startIndex, int endIndex = -1 );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~IntervalCriterion ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    int startIndex;
    int endIndex;
    int pathCount;
    int lineCount;
};

//-------------------------------- Autres définitions dépendantes de <IntervalCriterion>

#endif // IntervalCriterion_H

