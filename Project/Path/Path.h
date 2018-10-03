/*************************************************************************
                           Path  -  description
                             -------------------
    début                : 27/09/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Path> (fichier Path.h) ----------------
#if ! defined ( PATH_H )
#define PATH_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
enum MeansOfTransport { TRAIN, AUTO, BATEAU, AVION, END_DELIMITER };

const int MEAN_OF_TRANSPORT_QTY = END_DELIMITER;
const int MEAN_OF_TRANSPORT_STRING_MAX_SIZE = 15;

const char MEAN_OF_TRANSPORT_STRINGS[MEAN_OF_TRANSPORT_QTY][MEAN_OF_TRANSPORT_STRING_MAX_SIZE]
            { "Train", "Auto", "Bateau", "Avion"};
//------------------------------------------------------------------------
// Rôle de la classe <Path>
//
// Classe abstraite représentant un trajet entre 2 villes par un certain 
// moyen de transport. Permet de manipuler les trajets sans distinction de 
// types
//------------------------------------------------------------------------

class Path
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    virtual bool StartFrom(char city[]) const = 0;

    virtual bool StopAt(char city[]) const = 0;

//------------------------------------------------- Surcharge d'opérateurs
    Path& operator=(Path& other);

    // implémentation tirée de : 
    // https://stackoverflow.com/questions/1691007/whats-the-right-way-to-overload-operator-for-a-class-hierarchy
    // https://stackoverflow.com/questions/9287704/is-there-an-idiomatic-approach-in-c-for-comparing-polymorphic-types-for-object?noredirect=1&lq=1
    friend bool operator ==(const Path& first, const Path& second);

    friend std::ostream& operator<<(std::ostream& os, const Path& path);

//-------------------------------------------- Constructeurs - destructeur
    Path ( const Path & otherPath );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //  otherPath est un Path en état stable

    Path ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Path ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
virtual std::ostream& print(std::ostream& os) const = 0;
    // Mode d'emploi :
    // Méthode permettant l'affichage de la classe Path sur un flux (os). 
    // Voir les classes dérivées pour la réalisation concrète
    // Contrat :
    //
//----------------------------------------------------- Attributs protégés

private:
    virtual bool equals(const Path& other) const = 0;


};

//-------------------------------- Autres définitions dépendantes de <Path>


#endif // PATH_H

