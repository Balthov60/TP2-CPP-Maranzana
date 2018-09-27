/*************************************************************************
               Catalog  -  Affichage & Manipulation des Trajets
                             -------------------
    début                : 27/09/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Catalog> (fichier Catalog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Catalog.h"

using namespace std;
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Constructeurs - destructeur

Catalog::Catalog ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalog>" << endl;
#endif
} //----- Fin de Catalog


Catalog::~Catalog ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalog>" << endl;
#endif
} //----- Fin de ~Catalog

int main()
{
    cout << "Hello Word" << endl;
    return 0;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

