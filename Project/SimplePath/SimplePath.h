/*************************************************************************
                           SimplePath  -  description
                             -------------------
    début                : 27/09/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <SimplePath> (fichier SimplePath.h) ----------------
#if ! defined ( SIMPLEPATH_H )
#define SIMPLEPATH_H

//--------------------------------------------------- Interfaces utilisées

#include "../Path/Path.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <SimplePath>
//
//
//------------------------------------------------------------------------

class SimplePath : public Path
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
SimplePath& operator=(SimplePath& other) 
{
    //TODO: opérateur =
    //swap(*this, other); 

    return *this;
}


//-------------------------------------------- Constructeurs - destructeur
    SimplePath ( const SimplePath & unSimplePath );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    SimplePath ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~SimplePath ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    virtual std::ostream& print(std::ostream& os) const;
//----------------------------------------------------- Attributs protégés

private:
    virtual bool equals(const Path& other) const;
};

//-------------------------------- Autres définitions dépendantes de <SimplePath>

#endif // SIMPLEPATH_H

