/*************************************************************************
                           FileSerializer  -  description
                             -------------------
    début                : 28/11/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <FileSerializer> (fichier FileSerializer.h) ----------------
#if ! defined ( FileSerializer_H )
#define FileSerializer_H

//--------------------------------------------------- Interfaces utilisées
#include <string>

#include "../Catalog/Catalog.h"
#include "../Path/Path.h"
#include "../SimplePath/SimplePath.h"
#include "../AbstractCriterion/AbstractCriterion.h"

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <FileSerializer>
//
//
//------------------------------------------------------------------------

class FileSerializer
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    static FileSerializer * getInstance();
    // Mode d'emploi :
    //
    // Contrat
    //

    bool save(PathArray * pathArray, const char * path/*, AbstractCriterion criterion*/);
    // Mode d'emploi :
    //
    // Contrat :
    // path valide (testé dans Catalog)


//------------------------------------------------- Surcharge d'opérateurs
    FileSerializer & operator = ( const FileSerializer & unFileSerializer );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    FileSerializer ( const FileSerializer & unFileSerializer );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

private:
    FileSerializer ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

public:
    virtual ~FileSerializer ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

private:
//----------------------------------------------------- Méthodes privées

//----------------------------------------------------- Attributs privés
    static FileSerializer * instance;

};

//-------------------------------- Autres définitions dépendantes de <FileSerializer>

#endif // FileSerializer_H

