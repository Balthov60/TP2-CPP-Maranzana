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
// Représente le critère d'intervalle qui permet de sélectionner un intervalle
// de trajets
//------------------------------------------------------------------------

class IntervalCriterion : public AbstractCriterion
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual const bool CheckMetadata(const char * line);
    // Mode d'emploi :
    //  cf. AbstractCriterion
    
    virtual const bool CheckLine(const char * path);
    // Mode d'emploi :
    //  cf. AbstractCriterion

    virtual const bool CheckPath(const Path * path);
    // Mode d'emploi :
    //  cf. AbstractCriterion


//------------------------------------------------- Surcharge d'opérateurs
    IntervalCriterion & operator = ( IntervalCriterion other );
    // Mode d'emploi :
    //  cf. AbstractCriterion
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    IntervalCriterion ( const IntervalCriterion & other );
    // Mode d'emploi (constructeur de copie) :
    //  cf. AbstractCriterion
    // Contrat :
    //

    IntervalCriterion ( int startIndex, int endIndex = -1 );
    // Mode d'emploi :
    //  cf. AbstractCriterion
    // Contrat :
    //

    virtual ~IntervalCriterion ( );
    // Mode d'emploi :
    //  cf. AbstractCriterion
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

