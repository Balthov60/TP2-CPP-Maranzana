/*************************************************************************
                           TSimplePath  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <TSimplePath> (fichier TSimplePath.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>

using std::cout;
//------------------------------------------------------ Include personnel
#include "TSimplePath.h"
#include "SimplePath.h"
///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
static void testDisplay()
{
	/*
		expected output :
		{ Lyon ; Paris ; 0 }
	*/
	SimplePath path1 = SimplePath("Lyon", "Paris", TRAIN);
	cout << path1;
}

static void testEqualOperator()
{
	/*
		expected output :
		0
		1
	*/
	SimplePath path1 = SimplePath("Lyon", "Paris", TRAIN);
	SimplePath path2 = SimplePath("Varsovie", "Londres", AVION);
	bool result = path1 == path2;
	cout << result << "\r\n";

	SimplePath path3 = SimplePath("Lyon", "Paris", TRAIN);
	result = path1 == path3;
	cout << result << "\r\n";
}

static void testAssignmentOperator()
{
	/*
		expected output :
		{ Lyon ; Paris ; 0 }
	*/
	SimplePath path1 = SimplePath("Lyon", "Paris", TRAIN);
	SimplePath path2 = SimplePath("Varsovie", "Londres", AVION);

	path2 = path1;
	cout << path2;
}

static void testCopyConstructor()
{
	/*
		expected output :
		{ Varsovie ; Londres ; 3 }
	*/
	SimplePath path1 = SimplePath("Varsovie", "Londres", AVION);
	SimplePath path2 = path1;
	cout << path2;
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

