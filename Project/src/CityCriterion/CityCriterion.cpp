/*************************************************************************
                           CityCriterion  -  description
                             -------------------
    début                : 28/11/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <CityCriterion> (fichier CityCriterion.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CityCriterion.h"
using namespace std;
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CityCriterion::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


/*
//------------------------------------------------- Surcharge d'opérateurs
CityCriterion & CityCriterion::operator = ( const CityCriterion & unCityCriterion )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
CityCriterion::CityCriterion ( const CityCriterion & unCityCriterion )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CityCriterion>" << endl;
#endif
} //----- Fin de CityCriterion (constructeur de copie)
*/ //TODO: Implement

CityCriterion::CityCriterion ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CityCriterion>" << endl;
#endif
} //----- Fin de CityCriterion


CityCriterion::~CityCriterion ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CityCriterion>" << endl;
#endif
} //----- Fin de ~CityCriterion


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

