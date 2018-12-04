/*************************************************************************
                           TCityCriterion  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <TCityCriterion> (fichier TCityCriterion.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <cassert>

using std::cout;
//------------------------------------------------------ Include personnel
#include "TCityCriterion.h"
#include "../../src/SimplePath/SimplePath.h"
#include "../../src/ComposedPath/ComposedPath.h"
#include "../../src/CityCriterion/CityCriterion.h"
///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
static void testCheckMetadata()
{
	cout << "testCheckMetadata..." << "\r\n";

	CityCriterion criterion("Lyon", "Bordeaux");
	bool result = criterion.CheckMetadata("15|5|Lyon;XXXX;|XXXX;Bordeaux;");
	assert(result == true);

	result = criterion.CheckMetadata("15|5|XXXX;YYYY;|XXXX;Bordeaux;");
	assert(result == false);

	result = criterion.CheckMetadata("15|5|Lyon;YYYY;|XXXX;YYYY;");
	assert(result == false);

	result = criterion.CheckMetadata("15|5|ZZZZ;YYYY;A;B   ; C;Lyon;|A;B   ; C;XXXX;Bordeaux;YYYY;");
	assert(result == true);

	CityCriterion criterion2("Lyon");
	result = criterion2.CheckMetadata("15|5|Lyon;XXXX;|XXXX;Bordeaux;");
	assert(result == true);

	result = criterion2.CheckMetadata("15|5|XXXX;YYYY;|XXXX;Bordeaux;");
	assert(result == false);

	result = criterion2.CheckMetadata("15|5|XXXX;YYYY;|Lyon;Bordeaux;");
	assert(result == false);

	CityCriterion criterion3(nullptr, "Bordeaux");
	result = criterion3.CheckMetadata("15|5|Lyon;XXXX;|XXXX;Bordeaux;");
	assert(result == true);

	result = criterion3.CheckMetadata("15|5|Bordeaux;YYYY;|XXXX;YYYY;");
	assert(result == false);

	result = criterion3.CheckMetadata("15|5|XXXX;YYYY;|Lyon;ZZZZ;");
	assert(result == false);

	CityCriterion criterion4;
	result = criterion4.CheckMetadata("15|5|Lyon;XXXX;|XXXX;Bordeaux;");
	assert(result == false);

	CityCriterion criterion5("a", nullptr);
	result = criterion5.CheckMetadata("0|0||");
	assert(result == false);

	cout << "ok" << "\r\n";
}

static void testCheckLine()
{
	cout << "testCheckLine..." << "\r\n";
	CityCriterion criterion("Lyon", "Bordeaux");

	bool result = criterion.CheckLine("Lyon;1;Bordeaux");
	assert(result == true);

	CityCriterion criterion2("Lyon");
	result = criterion2.CheckLine("Lyon;1;Bordeaux");
	assert(result == true);

	CityCriterion criterion3(nullptr, "Bordeaux");
	result = criterion3.CheckLine("Lyon;1;Bordeaux");
	assert(result == true);

	CityCriterion criterion4;
	result = criterion4.CheckLine("Lyon;1;Bordeaux");
	assert(result == false);

	CityCriterion criterion5("XXXX");
	result = criterion5.CheckLine("Lyon;1;Bordeaux");
	assert(result == false);

	CityCriterion criterion6(nullptr, "XXXX");
	result = criterion6.CheckLine("Lyon;1;Bordeaux");
	assert(result == false);

	CityCriterion criterion7("XXXX", "XXXX");
	result = criterion7.CheckLine("Lyon;1;Bordeaux");
	assert(result == false);

	CityCriterion criterion8("XXXX", "XXXX");
	result = criterion8.CheckLine("Lyon;1;Bordeaux:Paris");
	assert(result == false);

	CityCriterion criterion9("Lyon", "XXXX");
	result = criterion9.CheckLine("Lyon;1;Bordeaux:Paris");
	assert(result == false);

	CityCriterion criterion10("XXXX", "Bordeaux");
	result = criterion10.CheckLine("Lyon;1;Bordeaux:Paris");
	assert(result == false);

	CityCriterion criterion11("XXXX", "Paris");
	result = criterion11.CheckLine("Lyon;1;Bordeaux:Paris");
	assert(result == false);

	CityCriterion criterion12(nullptr, "Paris");
	result = criterion12.CheckLine("Lyon;1;Bordeaux:Paris");
	assert(result == true);

	CityCriterion criterion13("Lyon");
	result = criterion13.CheckLine("Lyon;1;Bordeaux:Paris");
	assert(result == true);

	CityCriterion criterion14;
	result = criterion14.CheckLine("Lyon;1;Bordeaux:Paris");
	assert(result == false);

	cout << "ok" << "\r\n";
}

static void testCheckPath()
{
	cout << "testCheckPath..." << "\r\n";
	char varsovie[] = "Varsovie";
	char londres[] = "Londres";

	SimplePath* path = new SimplePath(varsovie, londres, AVION);

	CityCriterion criterion("Varsovie");
	bool result = criterion.CheckPath(path);
	assert(result == true);

	CityCriterion criterion2(nullptr, "Londres");
	result = criterion2.CheckPath(path);
	assert(result == true);

	CityCriterion criterion3("Varsovie", "Londres");
	result = criterion3.CheckPath(path);
	assert(result == true);

	CityCriterion criterion4("XXXX", "Londres");
	result = criterion4.CheckPath(path);
	assert(result == false);

	CityCriterion criterion5("Varsovie", "XXXX");
	result = criterion5.CheckPath(path);
	assert(result == false);

	CityCriterion criterion6("", "");
	result = criterion6.CheckPath(path);
	assert(result == false);

	CityCriterion criterion7;
	result = criterion7.CheckPath(path);
	assert(result == false);

	CityCriterion criterion8("Londres");
	result = criterion8.CheckPath(path);
	assert(result == false);

	CityCriterion criterion9("XXXX", "XXXX");
	result = criterion9.CheckPath(path);
	assert(result == false);

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

