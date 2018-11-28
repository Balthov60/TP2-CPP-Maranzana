/*************************************************************************
                           TTypeCriterion  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <TTypeCriterion> (fichier TTypeCriterion.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <cassert>

using std::cout;
//------------------------------------------------------ Include personnel
#include "TTypeCriterion.h"
#include "../../src/SimplePath/SimplePath.h"
#include "../../src/ComposedPath/ComposedPath.h"
#include "../../src/TypeCriterion/TypeCriterion.h"
///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
static void testCheckMetadata()
{
	cout << "testCheckMetadata..." << "\r\n";
	TypeCriterion criterion(false);
	bool result = criterion.CheckMetadata("0|0");
	assert(result == false);
	
	result = criterion.CheckMetadata("0|12");
	assert(result == false);

	result = criterion.CheckMetadata("12|0");
	assert(result == true);

	TypeCriterion criterionComp(true);
	result = criterionComp.CheckMetadata("1|0");
	assert(result == false);
	
	result = criterionComp.CheckMetadata("12|12");
	assert(result == true);

	result = criterionComp.CheckMetadata("0|12");
	assert(result == true);

	cout << "ok" << "\r\n";
}

static void testCheckLine()
{
	cout << "testCheckLine..." << "\r\n";
	TypeCriterion criterion(false);

	bool result = criterion.CheckLine("Paris;1;Varsovie");
	assert(result == true);

	result = criterion.CheckLine("Paris;1;Varsovie: \
			Varsovie;2;Marseilles");
	assert(result == false);

	TypeCriterion criterionComp(true);

	result = criterionComp.CheckLine("Paris;1;Varsovie");
	assert(result == false);

	result = criterionComp.CheckLine("Paris;1;Varsovie: \
			Varsovie;2;Marseilles");
	assert(result == true);
	cout << "ok" << "\r\n";
}

static void testCheckPath()
{
	cout << "testCheckPath..." << "\r\n";
	char varsovie[] = "Varsovie";
	char londres[] = "Londres";

	SimplePath* path = new SimplePath(varsovie, londres, AVION);

	TypeCriterion criterion(false);
	bool result = criterion.CheckPath(path);
	assert(result == true);

	ComposedPath* cpath = new ComposedPath;
	cpath->GetElements()->Add(path);

	result = criterion.CheckPath(cpath);
	assert(result == false);

	TypeCriterion criterionComp(true);

	result = criterionComp.CheckPath(cpath);
	assert(result == true);

	delete cpath;
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

