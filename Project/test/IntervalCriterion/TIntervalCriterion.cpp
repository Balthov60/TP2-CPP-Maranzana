/*************************************************************************
                           TIntervalCriterion  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <TIntervalCriterion> (fichier TIntervalCriterion.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <cassert>

using std::cout;
//------------------------------------------------------ Include personnel
#include "TIntervalCriterion.h"
#include "../../src/SimplePath/SimplePath.h"
#include "../../src/ComposedPath/ComposedPath.h"
#include "../../src/IntervalCriterion/IntervalCriterion.h"
///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
static void testCheckMetadata()
{
	cout << "testCheckMetadata..." << "\r\n";

	char* line = "2|3|Lyon;XXXX;|XXXX;Bordeaux;";

	IntervalCriterion criterion(1, 1);
	bool result = criterion.CheckMetadata(line);
	assert(result == true);

	IntervalCriterion criterion2(0, 0);
	result = criterion2.CheckMetadata(line);
	assert(result == true);

	IntervalCriterion criterion3(1, 2);
	result = criterion3.CheckMetadata(line);
	assert(result == true);

	IntervalCriterion criterion4(2, 2);
	result = criterion4.CheckMetadata(line);
	assert(result == true);

	IntervalCriterion criterion5(7, 7);
	result = criterion5.CheckMetadata(line);
	assert(result == false);

	IntervalCriterion criterion6(3, 7);
	result = criterion6.CheckMetadata(line);
	assert(result == true);

	IntervalCriterion criterion7(1);
	result = criterion7.CheckMetadata(line);
	assert(result == true);

	IntervalCriterion criterion8(-5, 2);
	result = criterion8.CheckMetadata(line);
	assert(result == true);

	cout << "ok" << "\r\n";
}

static void testCheckLine()
{
	cout << "testCheckLine..." << "\r\n";

	char* line = "Lyon;1;Bordeaux:Paris";

	IntervalCriterion criterion(1, 1);
	bool result = criterion.CheckLine(line);
	assert(result == true);

	IntervalCriterion criterion2(0, 0);
	result = criterion2.CheckLine(line);
	assert(result == true);

	IntervalCriterion criterion3(1, 2);
	result = criterion3.CheckLine(line);
	assert(result == true);

	IntervalCriterion criterion4(2, 2);
	result = criterion4.CheckLine(line);
	assert(result == false);

	result = criterion4.CheckLine(line);
	assert(result == true);

	//should never be called
	IntervalCriterion criterion5(4, 4);
	result = criterion5.CheckLine(line);
	assert(result == false);

	IntervalCriterion criterion6(-5, 4);
	result = criterion6.CheckLine(line);
	assert(result == true);

	result = criterion6.CheckLine(line);
	assert(result == true);

	IntervalCriterion criterion7(1);
	result = criterion7.CheckLine(line);
	assert(result == true);

	result = criterion7.CheckLine(line);
	assert(result == true);

	result = criterion7.CheckLine(line);
	assert(result == true);

	cout << "ok" << "\r\n";
}

static void testCheckPath()
{
	cout << "testCheckPath..." << "\r\n";

	SimplePath* path = new SimplePath("Varsovie", "Londres", AVION);

	IntervalCriterion criterion(1, 1);
	bool result = criterion.CheckPath(path);
	assert(result == true);

	IntervalCriterion criterion2(0, 0);
	result = criterion2.CheckPath(path);
	assert(result == true);

	IntervalCriterion criterion3(1, 2);
	result = criterion3.CheckPath(path);
	assert(result == true);

	IntervalCriterion criterion4(2, 2);
	result = criterion4.CheckPath(path);
	assert(result == false);

	result = criterion4.CheckPath(path);
	assert(result == true);

	//should never be called
	IntervalCriterion criterion5(4, 4);
	result = criterion5.CheckPath(path);
	assert(result == false);

	IntervalCriterion criterion6(-5, 4);
	result = criterion6.CheckPath(path);
	assert(result == true);

	result = criterion6.CheckPath(path);
	assert(result == true);

	IntervalCriterion criterion7(1);
	result = criterion7.CheckPath(path);
	assert(result == true);

	result = criterion7.CheckPath(path);
	assert(result == true);

	result = criterion7.CheckPath(path);
	assert(result == true);

	delete path;
	cout << "ok" << "\r\n";
}

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
int main()
// Algorithme :
//
{
	testCheckPath();
	testCheckLine();
	testCheckMetadata();
} //----- fin de main

