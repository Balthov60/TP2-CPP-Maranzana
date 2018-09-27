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


Path& Path::operator=(Path& other) 
{
    //TODO: opérateur = 
    //swap(*this, other); 

    return *this;
}


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
bool operator ==(const Path& first, const Path& second)
{
    // RTTI check
    if (typeid(first) != typeid(second))
        return false;
    // Invoke is_equal on derived types
    return first.equals(second);
}
//----------------------------------------------------- Méthodes protégées

