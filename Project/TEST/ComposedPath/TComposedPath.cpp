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
#include "../../ComposedPath/ComposedPath.h"
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
	ComposedPath path;
	char varsovie[] = "Varsovie";
	char londres[] = "Londres";

	SimplePath spath = SimplePath((char*)varsovie, (char*)londres, AVION);
	path.GetElements()->Add(&spath);
	cout << path << "\r\n";
}

static void testEqualOperator()
{
	/*
		expected output :
		1
		0
	*/
	cout << "testEqualOperator" << "\r\n";
	ComposedPath path1;
	ComposedPath path2;

	bool result = (path1 == path2);
	cout << result << "\r\n";

	char varsovie[] = "Varsovie";
	char londres[] = "Londres";

	SimplePath spath = SimplePath((char*)varsovie, (char*)londres, AVION);
	path1.GetElements()->Add(&spath);
	result = (path1 == path2);
	cout << result << "\r\n";
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
	ComposedPath path1;
	ComposedPath path2(50);

	path1 = path2;
	path1.GetElements()->Display();
}

static void testCopyConstructor()
{
	/*
		expected output :
		{ de Varsovie à Londres en MT3 }
	*/
	cout << "testCopyConstructor" << "\r\n";
	ComposedPath path;
	char varsovie[] = "Varsovie";
	char londres[] = "Londres";

	SimplePath spath = SimplePath((char*)varsovie, (char*)londres, AVION);
	path.GetElements()->Add(&spath);
	ComposedPath path2 = path;
	cout << path2 << "\r\n";
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

