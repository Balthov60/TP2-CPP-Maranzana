/*************************************************************************
                           EmptyCriterion  -  description
                             -------------------
    début                : 28/11/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <EmptyCriterion> (fichier EmptyCriterion.h) ----------------
#if ! defined ( EmptyCriterion_H )
#define EmptyCriterion_H

//--------------------------------------------------- Interfaces utilisées
#include "../AbstractCriterion/AbstractCriterion.h"
#include "../Path/Path.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <EmptyCriterion>
// Représente le critère vide ie. qui valide toutes les entrées
//------------------------------------------------------------------------

class EmptyCriterion  : public AbstractCriterion
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual const bool CheckMetadata(const char * line);

    virtual const bool CheckLine(const char * line);

    virtual const bool CheckPath(const Path * path);

//------------------------------------------------- Surcharge d'opérateurs
    EmptyCriterion & operator = ( const EmptyCriterion & other );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    EmptyCriterion ( const EmptyCriterion & other );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    EmptyCriterion ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~EmptyCriterion ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <EmptyCriterion>

#endif // EmptyCriterion_H

