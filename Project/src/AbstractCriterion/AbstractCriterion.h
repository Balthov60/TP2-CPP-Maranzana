/*************************************************************************
                           AbstractCriterion  -  description
                             -------------------
    début                : 28/11/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <AbstractCriterion> (fichier AbstractCriterion.h) ----------------
#if ! defined ( AbstractCriterion_H )
#define AbstractCriterion_H

//--------------------------------------------------- Interfaces utilisées
#include "../Path/Path.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <AbstractCriterion>
// Critère de sélection pour la sauvegarde et le chargement de trajets
//------------------------------------------------------------------------

class AbstractCriterion
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual const bool CheckMetadata(const char * line) = 0;
    // Mode d'emploi :
    // Vérifie que les métadonnées du fichier vérifient le critère
    // Retourne :
    //      - true si le critère est vérifié
    //      - false sinon

    virtual const bool CheckLine(const char * line) = 0;
    // Mode d'emploi :
    // Vérifie si la chaîne de caractères représentant un trajet vérifie 
    // ce critère ou pas, ie. si elle est sélectionnée pour le parsing ou pas
    // Retourne :
    //      - true si le critère est vérifié
    //      - false sinon

    virtual const bool CheckPath(const Path * path) = 0;
    // Mode d'emploi :
    // Vérifie si le trajet vérifie ce critère ou pas, ie. si il 
    // est sélectionné pour la sauvegarde ou non
    // Retourne :
    //      - true si le critère est vérifié
    //      - false sinon


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
protected:
    AbstractCriterion ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    AbstractCriterion ( const AbstractCriterion & other );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

public:
    virtual ~AbstractCriterion ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
static const char * METADATA_DELIMITER;
static const char * COMPOSED_PATH_FLAG;
static const char * PATH_DELIMITER;
};

//-------------------------------- Autres définitions dépendantes de <AbstractCriterion>

#endif // AbstractCriterion_H

