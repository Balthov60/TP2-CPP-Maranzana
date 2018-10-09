/*************************************************************************
                           PathArray  -  description
                             -------------------
    début                : 27/09/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <PathArray> (fichier PathArray.h) ----------------
#if ! defined ( PATHARRAY_H )
#define PATHARRAY_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include "../Path/Path.h"

//------------------------------------------------------------- Constantes
const int MAX_SIZE = 10;

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <PathArray>
// Collection permettant la gestion dynamique de trajets (Path)
//------------------------------------------------------------------------

class PathArray
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool Equals(const PathArray & otherPathArray) const;
    // Mode d'emploi :
    //      Compare le contenu de la collection avec une autre collection PathArray.
    // Renvoie true si les collections sont égales, false sinon.
    //      > otherPathArray : collection à comparer
    // Contrat :
    //
    bool Add(Path* pathToAdd);
    // Mode d'emploi :
    //      Ajoute un trajet à la collection
    // Renvoie false si un trajet similaire est déjà présent dans la collection,
    // true sinon.
    //      > pathToAdd : trajet à ajouter
    // Contrat :
    //      pathToAdd pointe vers un objet Path valide
    unsigned int Adjust(int delta);
    // Mode d'emploi :
    //      Ajuste la taille de la collection.
    //      > delta : offset de la taille de la collection. Si delta > 0, la taille de la
    // collection s'agrandit de delta. Sinon, la taille de la collection se réduit de la valeur
    // de delta, dans la limite du nombre d'éléments déjà présent.
    // Contrat :
    //
    bool Remove(Path* element);
    // Mode d'emploi :
    //      Retire un trajet de la collection
    // Renvoie true si l'objet a pu être supprimé, false sinon
    //      > element : trajet à supprimer
    // Contrat :
    //      element pointe vers un objet Path valide
    unsigned int Remove(const PathArray & otherPathArray);
    // Mode d'emploi :
    //      Retire un ensemble de trajets de la collection
    // Renvoie le nombre d'éléments effectivement supprimés.
    //      > otherPathArray : ensemble de trajets à supprimer
    // Contrat :
    //
    bool Contains(const Path* value) const;
    // Mode d'emploi :
    //      Teste si un trajet est présent dans la collection
    // Renvoie true si le trajet est présent dans la collection, false sinon
    //      > value : Trajet à tester
    // Contrat :
    //      value pointe vers un objet Path valide
    unsigned int GetSize(void) const;
    // Mode d'emploi :
    //      Retourne la taille courante de la collection
    // Contrat :
    //
    unsigned int GetMaxSize(void) const;
    // Mode d'emploi :
    //      Retourne la taille maximale actuelle de la collection
    // Contrat :
    //
    Path* Get(int index) const;
    // Mode d'emploi :
    //      Retourne un élément de la collection
    //      > index : indice de l'élément à retourner
    // Contrat :
    //      0 <= index < size

    std::ostream& Print(std::ostream& os, bool advanced = false, bool composed = false) const;
    // Mode d'emploi :
    //      Ecrit une représentation en chaîne de caractères de la collection
    // sur un flux standard.
    //      > os : flux standard sur lequel écrire
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    PathArray& operator=(const PathArray & other);


//-------------------------------------------- Constructeurs - destructeur
    PathArray(const PathArray & otherPathArray);
    // Mode d'emploi (constructeur de copie) :
    // Constructeur simple qui copie chaque attributs de "other" dans un nouveau objet
    //
    // Contrat :
    //

    PathArray(const unsigned int maxSize = MAX_SIZE);
    // Mode d'emploi :
    // Constructeur basique qui alloue un tableau de taille "cardMax"
    //
    // maxSize :
    // Taille maximal de la collection sans réallocation (par défaut : MAX_SIZE)
    //
    // Contrat :
    //

    virtual ~PathArray();
    // Mode d'emploi :
    // Destructeur basique qui désalloue le tableau elements
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

    Path ** elements;
    unsigned int maxSize;
    unsigned int size;
};

//-------------------------------- Autres définitions dépendantes de <PathArray>

#endif // PATHARRAY_H

