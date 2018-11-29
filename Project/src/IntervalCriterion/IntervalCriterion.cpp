/*************************************************************************
                           IntervalCriterion  -  description
                             -------------------
    début                : 28/11/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <IntervalCriterion> (fichier IntervalCriterion.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
#include <cstdlib>
//------------------------------------------------------ Include personnel
#include "IntervalCriterion.h"
using namespace std;
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
const bool IntervalCriterion::CheckMetadata(const char * line)
{
	char * buffer = new char[strlen(line) + 1];
    strcpy(buffer, line);

    int nb_simple;
    int nb_comp;

    char * pch = strtok (buffer, METADATA_DELIMITER);
    nb_simple = atoi(pch);
    pch = strtok (NULL, METADATA_DELIMITER);
    nb_comp = atoi(pch);

    int nb_path = nb_simple + nb_comp;
    if (endIndex > nb_path)
    {
    	endIndex = -1;
    }
    if (startIndex <= 0)
    {
    	startIndex = 1;
    }

    bool result = (startIndex <= nb_path) && (endIndex <= nb_path);

    delete[] buffer;
	return result;
} //----- Fin de CheckMetadata

const bool IntervalCriterion::CheckLine(const char * line)
{
	bool result = (startIndex <= lineCount) && (endIndex == -1 || endIndex >= lineCount);
	lineCount++;
	return result;
} //----- Fin de CheckLine

const bool IntervalCriterion::CheckPath(const Path * path)
{
	bool result = (startIndex <= pathCount) && (endIndex == -1 || endIndex >= pathCount);
	pathCount++;
	return result;
} //----- Fin de CheckPath


//------------------------------------------------- Surcharge d'opérateurs
IntervalCriterion & IntervalCriterion::operator = ( IntervalCriterion other )
// Algorithme :
//
{
	startIndex = other.startIndex;
	endIndex = other.endIndex;
	pathCount = other.pathCount;
	lineCount = other.lineCount;
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
IntervalCriterion::IntervalCriterion ( const IntervalCriterion & other )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <IntervalCriterion>" << endl;
#endif
    startIndex = other.startIndex;
	endIndex = other.endIndex;
	pathCount = other.pathCount;
	lineCount = other.lineCount;
} //----- Fin de IntervalCriterion (constructeur de copie)


IntervalCriterion::IntervalCriterion ( int m, int n) : startIndex(m), endIndex(n), pathCount(1), lineCount(1)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <IntervalCriterion>" << endl;
#endif
    if (startIndex == 0)
    {
    	startIndex = 1;
    }
    if (endIndex == 0)
    {
    	endIndex = 1;
    }
} //----- Fin de IntervalCriterion


IntervalCriterion::~IntervalCriterion ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <IntervalCriterion>" << endl;
#endif
} //----- Fin de ~IntervalCriterion


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

