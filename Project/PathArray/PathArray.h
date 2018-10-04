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
const int CARD_MAX = 10;
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
    
    void Display(void) const;
    // Mode d'emploi :
    //      Affiche le contenu de la collection sur la sortie standard
    // Contrat :
    //
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
    unsigned int GetCurrentCard(void) const;
    // Mode d'emploi :
    //      Retourne la cardinalité courante de la collection
    // Contrat :
    //
    unsigned int GetMaxCard(void) const;
    // Mode d'emploi :
    //      Retourne la cardinalité maximale actuelle de la collection
    // Contrat :
    //
    Path* Get(int index) const;
    // Mode d'emploi :
    //      Retourne un élément de la collection
    //      > index : indice de l'élément à retourner
    // Contrat :
    //      0 <= index < currentCard
    std::ostream& Print(std::ostream& os) const;
    // Mode d'emploi :
    //      Ecrit une représentation en chaîne de caractères de la collection
    // sur un flux standard.
    //      > os : flux standard sur lequel écrire
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    PathArray& operator=(PathArray& other);


//-------------------------------------------- Constructeurs - destructeur
    PathArray ( const PathArray & otherPathArray );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    PathArray (const unsigned int cardMax = CARD_MAX);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~PathArray ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
Path ** elements;
unsigned int maxCard;
unsigned int currentCard;
};

//-------------------------------- Autres définitions dépendantes de <PathArray>

#endif // PATHARRAY_H

