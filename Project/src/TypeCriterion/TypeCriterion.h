/*************************************************************************
                           TypeCriterion  -  description
                             -------------------
    début                : 28/11/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TypeCriterion> (fichier TypeCriterion.h) ----------------
#if ! defined ( TypeCriterion_H )
#define TypeCriterion_H

//--------------------------------------------------- Interfaces utilisées
#include "../AbstractCriterion/AbstractCriterion.h"
#include "../Path/Path.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TypeCriterion>
// Critère de sélection selon le type du trajet (simple ou composé)
//------------------------------------------------------------------------

class TypeCriterion : public AbstractCriterion
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual const bool CheckMetadata(const char * line) const;
    
    virtual const bool CheckLine(const char * path) const;

    virtual const bool CheckPath(const Path * path) const;

//------------------------------------------------- Surcharge d'opérateurs
    TypeCriterion & operator = ( const TypeCriterion & other );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    TypeCriterion ( const TypeCriterion & other );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    TypeCriterion ( bool selecComposed );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~TypeCriterion ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    bool composed;
};

//-------------------------------- Autres définitions dépendantes de <TypeCriterion>

#endif // TypeCriterion_H

