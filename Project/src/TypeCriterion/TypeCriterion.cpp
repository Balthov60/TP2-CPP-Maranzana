/*************************************************************************
                           TypeCriterion  -  description
                             -------------------
    début                : 28/11/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TypeCriterion> (fichier TypeCriterion.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TypeCriterion.h"
#include "../SimplePath/SimplePath.h"
#include "../ComposedPath/ComposedPath.h"
using namespace std;
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
const bool TypeCriterion::CheckMetadata(const char * line) const
{
    char * buffer = new char[strlen(line) + 1];
    strcpy(buffer, line);
    char * pch = strtok (buffer,";");
    if (composed) {
        pch = strtok (NULL, ";");
    }
    
    bool result =  (strcmp(pch, "0") != 0);
    delete[] buffer;

    return result;
} //----- Fin de CheckMetadata

const bool TypeCriterion::CheckLine(const char * path) const
{
	return composed ? (strstr(path, ":") != nullptr) : (strstr(path, ":") == nullptr);
} //----- Fin de CheckLine

const bool TypeCriterion::CheckPath(const Path * path) const
{
	return (typeid(*path) == (composed ? typeid(ComposedPath) : typeid(SimplePath)));
} //----- Fin de CheckPath


//------------------------------------------------- Surcharge d'opérateurs
TypeCriterion & TypeCriterion::operator = ( const TypeCriterion & other )
// Algorithme :
//
{
	composed = other.composed;
	return *this;
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
TypeCriterion::TypeCriterion ( const TypeCriterion & other ) : composed(other.composed)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TypeCriterion>" << endl;
#endif

} //----- Fin de TypeCriterion (constructeur de copie)

TypeCriterion::TypeCriterion ( bool selecComposed ) : composed(selecComposed)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TypeCriterion>" << endl;
#endif
} //----- Fin de TypeCriterion


TypeCriterion::~TypeCriterion ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TypeCriterion>" << endl;
#endif
} //----- Fin de ~TypeCriterion


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

