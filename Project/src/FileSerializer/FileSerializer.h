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

    FileSerializer ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~FileSerializer ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <FileSerializer>

#endif // FileSerializer_H

