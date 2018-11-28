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

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TypeCriterion>
//
//
//------------------------------------------------------------------------

class TypeCriterion
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
    TypeCriterion & operator = ( const TypeCriterion & unTypeCriterion );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    TypeCriterion ( const TypeCriterion & unTypeCriterion );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    TypeCriterion ( );
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

};

//-------------------------------- Autres définitions dépendantes de <TypeCriterion>

#endif // TypeCriterion_H

