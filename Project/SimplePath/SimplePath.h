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
    SimplePath& operator=(SimplePath& other);


//-------------------------------------------- Constructeurs - destructeur
    SimplePath ( const SimplePath & other );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    SimplePath ( char * startingCity, char * endingCity, MeansOfTransport vehicle);
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
    virtual bool equals(const Path& other) const;
    friend void swap(SimplePath& first, SimplePath& second);
//----------------------------------------------------- Attributs protégés
    char * startCity;
    char * endCity;
    MeansOfTransport meanOfTransport;
    
private:
    
    
};

//-------------------------------- Autres définitions dépendantes de <SimplePath>

#endif // SIMPLEPATH_H

