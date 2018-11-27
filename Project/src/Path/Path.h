/*************************************************************************
                           Path  -  Trajet (abstrait)
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

//------------------------------------------------------------------ Types
// Note : Nous avons inversé les catégories types et constantes pour pouvoir faire les déclarations

enum MeansOfTransport { TRAIN, AUTO, BATEAU, AVION, END_DELIMITER };

//------------------------------------------------------------- Constantes

const int MEAN_OF_TRANSPORT_STRING_MAX_SIZE = 15;
const int MEAN_OF_TRANSPORT_QTY = END_DELIMITER;

const char MEAN_OF_TRANSPORT_STRINGS[MEAN_OF_TRANSPORT_QTY][MEAN_OF_TRANSPORT_STRING_MAX_SIZE] = { "Train", "Auto", "Bateau", "Avion"};

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

    virtual const char * GetStartCity() const = 0;
    // Mode d'emploi :
    // Récupère le nom de la ville de départ
    // Voir les classes dérivées pour la réalisation concrète

    virtual const char * GetEndCity() const = 0;
    // Mode d'emploi :
    // Récupère le nom de la ville d'arrivée
    // Voir les classes dérivées pour la réalisation concrète

    virtual Path * Clone() const = 0;
    // Mode d'emploi :
    // Dublique le trajet
    // Voir les classes dérivées pour la réalisation concrète

//------------------------------------------------- Surcharge d'opérateurs

    friend bool operator ==(const Path& first, const Path& second);
    // implémentation tirée de :
    // https://stackoverflow.com/questions/1691007/whats-the-right-way-to-overload-operator-for-a-class-hierarchy
    // https://stackoverflow.com/questions/9287704/is-there-an-idiomatic-approach-in-c-for-comparing-polymorphic-types-for-object?noredirect=1&lq=1

    friend std::ostream& operator<<(std::ostream& os, const Path& path);
    // Mode d'emploi :
    // Affiche les données formatées en utilisant la fonction print

//-------------------------------------------- Constructeurs - destructeur

protected:
    Path();
    // Mode d'emploi :
    // Constructeur par défaut (vide)

public:
    virtual ~Path();
    // Mode d'emploi :
    // Destructeur par défaut (vide)

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

    virtual std::ostream& print(std::ostream& os) const = 0;
    // Mode d'emploi :
    // Méthode permettant l'affichage de la classe Path sur un flux (os).
    // Voir les classes dérivées pour la réalisation concrète

//----------------------------------------------------- Attributs protégés

private:
//----------------------------------------------------- Méthodes privées
    virtual bool equals(const Path& other) const = 0;

};

//-------------------------------- Autres définitions dépendantes de <Path>


#endif // PATH_H

