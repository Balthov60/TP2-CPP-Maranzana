/*************************************************************************
                           Path  -  description
                             -------------------
    début                : 27/09/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Path> (fichier Path.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Path.h"

using namespace std;
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Path::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
//TODO: opérateur =

//-------------------------------------------- Constructeurs - destructeur
Path::Path ( const Path & unPath )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Path>" << endl;
#endif
} //----- Fin de Path (constructeur de copie)


Path::Path ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Path>" << endl;
#endif
} //----- Fin de Path


Path::~Path ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Path>" << endl;
#endif
} //----- Fin de ~Path


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

