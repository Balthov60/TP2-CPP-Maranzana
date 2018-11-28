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
#include "../ComposedPath/ComposedPath.h"
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

    static FileSerializer * getInstance();
    // Mode d'emploi :
    //
    // Contrat
    //

    void save(PathArray * pathArray, const char * path/*, AbstractCriterion criterion*/);
    // Mode d'emploi :
    // Sauvegarde la collection "pathArray" dans le fichier pointé par "path" selon les critères "criterion"
    //
    // Contrat :
    // path valide (testé dans Catalog)

    void load(PathArray * pathArray, const char * path/*, AbstractCriterion criterion*/);
    // Mode d'emploi :
    // Charge les données du fichier pointé par "path" dans la collection "pathArray" selon les critères "criterion"
    //
    // Contrat :
    // path valide (testé dans Catalog)

private:
    FileSerializer ( );
    // Mode d'emploi :
    // Constructeur par défaut (privé car Singleton)
    //
    // Contrat :
    //

public:
    virtual ~FileSerializer ( );
    // Mode d'emploi :
    // Destructeur par défaut
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

void processLine(PathArray * pathArray, ifstream * file, char * line);
Path * deserialize(string object);
string removeIndentationAndMetadata(string object);


//----------------------------------------------------- Attributs protégés

private:
//----------------------------------------------------- Méthodes privées

//----------------------------------------------------- Attributs privés
    static FileSerializer * instance;

};

//-------------------------------- Autres définitions dépendantes de <FileSerializer>

#endif // FileSerializer_H

