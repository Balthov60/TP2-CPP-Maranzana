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

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <EmptyCriterion>
//
//
//------------------------------------------------------------------------

class EmptyCriterion
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
    EmptyCriterion & operator = ( const EmptyCriterion & unEmptyCriterion );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    EmptyCriterion ( const EmptyCriterion & unEmptyCriterion );
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

