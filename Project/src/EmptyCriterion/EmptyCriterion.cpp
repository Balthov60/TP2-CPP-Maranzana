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
const bool EmptyCriterion::CheckMetadata(const char * line) const
{
	return true;
} //----- Fin de CheckMetadata

const bool EmptyCriterion::CheckLine(const char * line) const
{
	return true;
} //----- Fin de CheckLine

const bool EmptyCriterion::CheckPath(const Path * path) const
{
	return true;
} //----- Fin de CheckPath


//------------------------------------------------- Surcharge d'opérateurs
EmptyCriterion & EmptyCriterion::operator = ( const EmptyCriterion & other )
// Algorithme :
//
{
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
EmptyCriterion::EmptyCriterion ( const EmptyCriterion & other )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <EmptyCriterion>" << endl;
#endif
} //----- Fin de EmptyCriterion (constructeur de copie)


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

