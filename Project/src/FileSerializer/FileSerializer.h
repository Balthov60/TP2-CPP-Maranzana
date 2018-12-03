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
// La classe FileSerializer permet de sauvegarder et de charger des catalogues
// dans des fichiers.
//
// La classe met aussi à disposition des méthodes de gestion de fichiers.
//
//------------------------------------------------------------------------

class FileSerializer
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    static FileSerializer * getInstance();
    // Mode d'emploi :
    // Retourne l'instance singleton de la classe FileSerializer.
    //
    // Contrat
    //

    void Save(PathArray * pathArray, const char * path, AbstractCriterion & criterion);
    // Mode d'emploi :
    // Sauvegarde une sélection de trajets de la collection dans un fichier
    //       pathArray : collection de trajets à sauvegarder
    //       path : chemin du fichier de sauvegarde
    //       criterion : critère de sélection des trajets
    //
    // Contrat :
    // path valide (testé dans Catalog)

    bool Load(PathArray * pathArray, const char * path, AbstractCriterion & criterion);
    // Mode d'emploi :
    // Charge les données du fichier pointé par "path" dans la collection "pathArray" selon les critères "criterion"
    //
    // En cas de problème dans le formattage du fichier renvoi false sinon true.
    //
    // Contrat :
    // path valide (testé dans Catalog)

    bool FileExist(const char * path);
    // Mode d'emploi :
    // Renvoi true si le fichier existe false sinon.
    //
    // Contrat :
    //

    bool FileCanBeCreated(const char path[]);
    // Mode d'emploi ;
    // Renvoi true si le fichier peut être créer donc si le dossier parent existe.
    //
    // Contrat :
    //

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
    // Mode d'emploi :
    // Traite une ligne du fichier représentant un SimplePath ou ComposedPath.
    //
    // Contrat :
    //

    Path * deserialize(string object);
    // Mode d'emploi :
    // Transforme un objet string en objet de type SimplePath ou ComposedPath
    //
    // Contrat :
    // Avoir un objet string représentant un Path
    //

    string removeIndentationAndMetadata(string object);
    // Mode d'emploi :
    // Supprime les tabulations en début de string et toutes les données situé après ":"
    //
    // Contrat :
    //


//----------------------------------------------------- Attributs protégés

private:
//----------------------------------------------------- Méthodes privées

//----------------------------------------------------- Attributs privés
    static FileSerializer * instance;

};

//-------------------------------- Autres définitions dépendantes de <FileSerializer>

#endif // FileSerializer_H

