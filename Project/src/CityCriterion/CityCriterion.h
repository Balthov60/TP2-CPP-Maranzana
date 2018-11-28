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
#include "../AbstractCriterion/AbstractCriterion.h"
#include "../Path/Path.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <CityCriterion>
// Critère de sélection selon la ville de départ et/ou d'arrivée
//------------------------------------------------------------------------

class CityCriterion  : public AbstractCriterion
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual const bool CheckMetadata(const char * line) const;
    
    virtual const bool CheckLine(const char * path) const;

    virtual const bool CheckPath(const Path * path) const;


//------------------------------------------------- Surcharge d'opérateurs
    CityCriterion & operator = ( CityCriterion other );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CityCriterion ( const CityCriterion & other );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CityCriterion ( const char * startingCity = nullptr, const char * endingCity = nullptr );
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
    void create( const char * startingCity = nullptr, const char * endingCity = nullptr );
    void dispose();
//----------------------------------------------------- Attributs protégés
    char * startCity;
    char * endCity;
};

//-------------------------------- Autres définitions dépendantes de <CityCriterion>

#endif // CityCriterion_H

