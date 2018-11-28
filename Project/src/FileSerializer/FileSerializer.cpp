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

//------------------------------------------------------ Include personnel
#include "FileSerializer.h"

using namespace std;
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type FileSerializer::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


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

//----------------------------------------------------- Méthodes protégées

