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
// Représente un trajet simple entre une ville de départ et une ville
// d'arrivée par un unique moyen de transport.
//------------------------------------------------------------------------

class SimplePath : public Path
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    virtual char * GetStartingCity() const;

   virtual char * GetEndingCity() const;

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
    // Mode d'emploi :
    //      Ecrit une représentation de l'objet en chaîne de caractères sur un
    // flux standard
    //      > os : flux standard sur lequel on écrit
    // Contrat :
    //
    virtual bool equals(const Path& other) const;
    // Mode d'emploi :
    //      Compare si le ComposedPath est égal à un autre trajet.
    // Renvoie true si les trajets sont égaux, faux sinon.
    // Contrat :
    //
    friend void swap(SimplePath& first, SimplePath& second);
    // Mode d'emploi :
    //      Echange les valeurs des attributs entre 2 objets SimplePath
    //      > first : Premier objet de l'échange
    //      > second : Second objet de l'échange
    // Contrat :
    //

//----------------------------------------------------- Attributs protégés
    char * startCity;
    char * endCity;
    MeansOfTransport meanOfTransport;
    
};

//-------------------------------- Autres définitions dépendantes de <SimplePath>

#endif // SIMPLEPATH_H

