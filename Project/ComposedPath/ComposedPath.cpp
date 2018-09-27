/*************************************************************************
                           ComposedPath  -  description
                             -------------------
    début                : 27/09/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <ComposedPath> (fichier ComposedPath.cpp) ------------

//---------------------------------------------------------------- INCLUDE
#define MAP 1

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "ComposedPath.h"

using namespace std;
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type ComposedPath::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
//TODO: opérateur =

//-------------------------------------------- Constructeurs - destructeur
ComposedPath::ComposedPath ( const ComposedPath & unComposedPath )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ComposedPath>" << endl;
#endif
} //----- Fin de ComposedPath (constructeur de copie)


ComposedPath::ComposedPath ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ComposedPath>" << endl;
#endif
} //----- Fin de ComposedPath


ComposedPath::~ComposedPath ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ComposedPath>" << endl;
#endif
} //----- Fin de ~ComposedPath


//------------------------------------------------------------------ PRIVE
bool ComposedPath::equals(const Path& other) const
{
        const ComposedPath& other_derived = dynamic_cast<const ComposedPath&>(other);
        // TODO Now compare *this to other_derived
        return false;
}
//----------------------------------------------------- Méthodes protégées

