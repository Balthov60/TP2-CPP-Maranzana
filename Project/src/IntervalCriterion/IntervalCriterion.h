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

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <IntervalCriterion>
//
//
//------------------------------------------------------------------------

class IntervalCriterion
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
    IntervalCriterion & operator = ( const IntervalCriterion & unIntervalCriterion );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    IntervalCriterion ( const IntervalCriterion & unIntervalCriterion );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    IntervalCriterion ( );
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

};

//-------------------------------- Autres définitions dépendantes de <IntervalCriterion>

#endif // IntervalCriterion_H

