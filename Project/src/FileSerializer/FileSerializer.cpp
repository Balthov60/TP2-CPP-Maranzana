/*************************************************************************
                           FileSerializer  -  description
                             -------------------
    début                : 28/11/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <FileSerializer> (fichier FileSerializer.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "FileSerializer.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type FileSerializer::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

FileSerializer * FileSerializer::getInstance()
{
    if (!instance)
        instance = new FileSerializer;

    return instance;
}

bool FileSerializer::save(PathArray * pathArray, const char * path/*, AbstractCriterion criterion*/)
{
    ofstream file;
    file.open(path);

    string data = string();
    int composedPathQty = 0;
    int simplePathQty = 0;

    for (int i = 0; i < pathArray->GetSize(); i++) {
        const Path *path = pathArray->Get(i);

        if (true /*criterion.CheckPath(path)*/) {


            cout << "OR" << endl;
            data.append(path->Serialize()).append("\r\n");

            cout << "HERE" << endl;

            (typeid(path) == typeid(SimplePath)) ? simplePathQty++ : composedPathQty++;
        }
    }

    file << simplePathQty << ";" << composedPathQty << std::endl;
    file << data;

    file.close();
    return true;
}

//------------------------------------------------- Surcharge d'opérateurs
/*
FileSerializer & FileSerializer::operator = ( const FileSerializer & unFileSerializer )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
FileSerializer::FileSerializer ( const FileSerializer & unFileSerializer )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <FileSerializer>" << endl;
#endif
} //----- Fin de FileSerializer (constructeur de copie)
*/ //TODO: Implement

FileSerializer::FileSerializer ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <FileSerializer>" << endl;
#endif
} //----- Fin de FileSerializer


FileSerializer::~FileSerializer ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <FileSerializer>" << endl;
#endif
} //----- Fin de ~FileSerializer


//------------------------------------------------------------------ PRIVE

FileSerializer * FileSerializer::instance = nullptr;

//----------------------------------------------------- Méthodes protégées

