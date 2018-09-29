/*************************************************************************
                           ComposedPath  -  description
                             -------------------
    début                : 27/09/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <ComposedPath> (fichier ComposedPath.h) ----------------
#if ! defined ( COMPOSEDPATH_H )
#define COMPOSEDPATH_H

//--------------------------------------------------- Interfaces utilisées
#include "../Path/Path.h"
#include "../PathArray/PathArray.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ComposedPath>
//
//
//------------------------------------------------------------------------

class ComposedPath : public Path
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    PathArray* GetElements ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    ComposedPath& operator=(ComposedPath& other);


//-------------------------------------------- Constructeurs - destructeur
    ComposedPath ( const ComposedPath & other );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    ComposedPath ( unsigned int cardMax = CARD_MAX );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ComposedPath ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
     virtual std::ostream& print(std::ostream& os) const;
     virtual bool equals(const Path& other) const;
     friend void swap(ComposedPath& first, ComposedPath& second);
//----------------------------------------------------- Attributs protégés
     PathArray elements;
private:
    
};

//-------------------------------- Autres définitions dépendantes de <ComposedPath>

#endif // COMPOSEDPATH_H

