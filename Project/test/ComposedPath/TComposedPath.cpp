/*************************************************************************
                           TComposedPath  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <TComposedPath> (fichier TComposedPath.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>

using std::cout;
//------------------------------------------------------ Include personnel
#include "TComposedPath.h"
#include "../../src/ComposedPath/ComposedPath.h"
///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
static void testDisplay()
{
	/*
		expected output :
	*/
	cout << "testDisplay" << "\r\n";
	ComposedPath* path = new ComposedPath;
	char varsovie[] = "Varsovie";
	char londres[] = "Londres";

	SimplePath* spath = new SimplePath((char*)varsovie, (char*)londres, AVION);
	path->GetElements()->Add(spath);
	cout << *path << "\r\n";

	delete path;
}

static void testEqualOperator()
{
	/*
		expected output :
		1
		0
	*/
	cout << "testEqualOperator" << "\r\n";
	ComposedPath* path1 = new ComposedPath;
	ComposedPath* path2 = new ComposedPath;

	bool result = (*path1 == *path2);
	cout << result << "\r\n";

	char varsovie[] = "Varsovie";
	char londres[] = "Londres";

	SimplePath* spath = new SimplePath((char*)varsovie, (char*)londres, AVION);
	path1->GetElements()->Add(spath);
	result = (*path1 == *path2);
	cout << result << "\r\n";

	
	delete path1;
	delete path2;
}

static void testAssignmentOperator()
{
	/*
		expected output :
		0
		50
		{}
	*/
	cout << "testAssignmentOperator" << "\r\n";
	ComposedPath* path1 = new ComposedPath;
	ComposedPath* path2 = new ComposedPath(50);

	*path1 = *path2;
	path1->GetElements()->Print(cout);

	delete path1;
	delete path2;
	
}

static void testCopyConstructor()
{
	/*
		expected output :
		{ de Varsovie à Londres en MT3 }
	*/
	cout << "testCopyConstructor" << "\r\n";
	ComposedPath* path = new ComposedPath;
	char varsovie[] = "Varsovie";
	char londres[] = "Londres";

	SimplePath* spath = new SimplePath((char*)varsovie, (char*)londres, AVION);
	path->GetElements()->Add(spath);
	ComposedPath* path2 = new ComposedPath(*path);
	cout << *path2 << "\r\n";

	delete path;
	delete path2;
}

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
int main()
// Algorithme :
//
{
	testDisplay();
	testEqualOperator();
	testAssignmentOperator();
	testCopyConstructor();
} //----- fin de main

