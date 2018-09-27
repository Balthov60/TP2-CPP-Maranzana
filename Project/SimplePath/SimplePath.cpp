/*************************************************************************
                           SimplePath  -  description
                             -------------------
    début                : 27/09/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <SimplePath> (fichier SimplePath.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "SimplePath.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type SimplePath::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
SimplePath & SimplePath::operator = ( const SimplePath & unSimplePath )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
SimplePath::SimplePath ( const SimplePath & unSimplePath )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <SimplePath>" << endl;
#endif
} //----- Fin de SimplePath (constructeur de copie)


SimplePath::SimplePath ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <SimplePath>" << endl;
#endif
} //----- Fin de SimplePath


SimplePath::~SimplePath ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <SimplePath>" << endl;
#endif
} //----- Fin de ~SimplePath


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
