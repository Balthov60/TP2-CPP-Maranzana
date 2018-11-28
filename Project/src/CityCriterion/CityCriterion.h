/*************************************************************************
                           CityCriterion  -  description
                             -------------------
    début                : 28/11/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <CityCriterion> (fichier CityCriterion.h) ----------------
#if ! defined ( CityCriterion_H )
#define CityCriterion_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <CityCriterion>
//
//
//------------------------------------------------------------------------

class CityCriterion
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
    CityCriterion & operator = ( const CityCriterion & unCityCriterion );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CityCriterion ( const CityCriterion & unCityCriterion );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CityCriterion ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CityCriterion ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <CityCriterion>

#endif // CityCriterion_H

