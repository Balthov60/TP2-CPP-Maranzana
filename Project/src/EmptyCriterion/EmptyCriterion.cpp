/*************************************************************************
                           EmptyCriterion  -  description
                             -------------------
    début                : 28/11/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <EmptyCriterion> (fichier EmptyCriterion.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "EmptyCriterion.h"
using namespace std;
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type EmptyCriterion::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


/*
//------------------------------------------------- Surcharge d'opérateurs
EmptyCriterion & EmptyCriterion::operator = ( const EmptyCriterion & unEmptyCriterion )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
EmptyCriterion::EmptyCriterion ( const EmptyCriterion & unEmptyCriterion )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <EmptyCriterion>" << endl;
#endif
} //----- Fin de EmptyCriterion (constructeur de copie)
*/ //TODO: Implement


EmptyCriterion::EmptyCriterion ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <EmptyCriterion>" << endl;
#endif
} //----- Fin de EmptyCriterion


EmptyCriterion::~EmptyCriterion ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <EmptyCriterion>" << endl;
#endif
} //----- Fin de ~EmptyCriterion


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

