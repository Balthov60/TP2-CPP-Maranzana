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
// Représente un trajet composé de plusieurs sous-trajets (simples ou eux-
// mêmes composés)
//------------------------------------------------------------------------

class ComposedPath : public Path
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    PathArray* GetElements ( ) const;
    // Mode d'emploi :
    //      Retourne la collection de Path composant le trajet
    // Contrat :
    //

    void AddStage(Path *path) const;
    // Mode d'emploi :
    //      Ajoute une étape (trajet) au trajet composé
    //      > path : pointeur sur le trajet à ajouter
    // Contrat :
    //      path est un pointeur sur trajet valide

    virtual char * GetStartCity() const;
    // Mode d'emploi :
    //      Getter de "startCity"
    // Contrat :
    //

    virtual char * GetEndCity() const;
    // Mode d'emploi :
    //      Getter de "endCity"
    // Contrat :
    //

    virtual ComposedPath* Clone() const;
    // Mode d'emploi :
    //      Duplique le trajet
    // Contrat :
    //
//------------------------------------------------- Surcharge d'opérateurs
    ComposedPath& operator=(ComposedPath other);


//-------------------------------------------- Constructeurs - destructeur
    ComposedPath ( const ComposedPath & other );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    ComposedPath ( unsigned int maxSize = MAX_SIZE );
    // Mode d'emploi :
    //      > maxSize : taille maximum initiale de la collection de trajets,
    // par defaut égale à MAX_SIZE
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
    friend void swap(ComposedPath& first, ComposedPath& second);
    // Mode d'emploi :
    //      Echange les valeurs des attributs entre 2 objets ComposedPath
    //      > first : Premier objet de l'échange
    //      > second : Second objet de l'échange
    // Contrat :
    //
//----------------------------------------------------- Attributs protégés
     PathArray* elements;
private:
    
};

//-------------------------------- Autres définitions dépendantes de <ComposedPath>

#endif // COMPOSEDPATH_H

