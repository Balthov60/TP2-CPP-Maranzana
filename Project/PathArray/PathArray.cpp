/*************************************************************************
                           PathArray  -  description
                             -------------------
    début                : 27/09/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <PathArray> (fichier PathArray.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "PathArray.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type PathArray::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
PathArray & PathArray::operator = ( const PathArray & unPathArray )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
PathArray::PathArray ( const PathArray & unPathArray )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <PathArray>" << endl;
#endif
} //----- Fin de PathArray (constructeur de copie)


PathArray::PathArray ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <PathArray>" << endl;
#endif
} //----- Fin de PathArray


PathArray::~PathArray ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <PathArray>" << endl;
#endif
} //----- Fin de ~PathArray


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

