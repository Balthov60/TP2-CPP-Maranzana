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

using std::cout;
using std::endl;
//------------------------------------------------------ Include personnel
#include "Path.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs


Path& Path::operator=(Path& other) 
{
    return *this;
} //----- Fin de =

bool operator ==(const Path& first, const Path& second)
{
    // RTTI check
    if (typeid(first) != typeid(second))
        return false;
    // Invoke is_equal on derived types
    return first.equals(second);
} //----- Fin de ==

std::ostream& operator<<(std::ostream& os, const Path& path)
{
	return path.print(os);
} //----- Fin de <<

//-------------------------------------------- Constructeurs - destructeur
Path::Path ( const Path & otherPath )
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

