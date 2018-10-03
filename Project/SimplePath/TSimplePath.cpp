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
		{ de Lyon à Paris en MT0 }
	*/
	cout << "testDisplay" << "\r\n";
	char lyon[] = "Lyon";
	char * plyon = lyon;

	char paris[] = "Paris";
	char * pparis = paris;
	SimplePath path1 = SimplePath(plyon, pparis, TRAIN);
	cout << path1;
}

static void testEqualOperator()
{
	/*
		expected output :
		0
		1
	*/
	cout << "testEqualOperator" << "\r\n";
	char lyon[] = "Lyon";
	char * plyon = lyon;

	char paris[] = "Paris";
	char * pparis = paris;

	char varsovie[] = "Varsovie";
	char * pvarsovie = varsovie;

	char londres[] = "Londres";
	char * plondres = londres; 

	SimplePath path1 = SimplePath(plyon, pparis, TRAIN);
	SimplePath path2 = SimplePath(pvarsovie, plondres, AVION);
	bool result = path1 == path2;
	cout << result << "\r\n";

	char lyon2[] = "Lyon";
	char * plyon2 = lyon2;

	char paris2[] = "Paris";
	char * pparis2 = paris2;

	SimplePath path3 = SimplePath(plyon2, pparis2, TRAIN);
	result = path1 == path3;
	cout << result << "\r\n";
}

static void testAssignmentOperator()
{
	/*
		expected output :
		{ de Lyon à Paris en MT0 }
	*/
	cout << "testAssignmentOperator" << "\r\n";
	char lyon[] = "Lyon";
	char * plyon = lyon;

	char paris[] = "Paris";
	char * pparis = paris;

	char varsovie[] = "Varsovie";
	char * pvarsovie = varsovie;

	char londres[] = "Londres";
	char * plondres = londres; 

	SimplePath path1 = SimplePath(plyon, pparis, TRAIN);
	SimplePath path2 = SimplePath(pvarsovie, plondres, AVION);

	path2 = path1;
	cout << path2;
}

static void testCopyConstructor()
{
	/*
		expected output :
		{ de Varsovie à Londres en MT3 }
	*/
	cout << "testCopyConstructor" << "\r\n";
	char varsovie[] = "Varsovie";
	char * pvarsovie = varsovie;

	char londres[] = "Londres";
	char * plondres = londres; 

	SimplePath path1 = SimplePath(pvarsovie, plondres, AVION);
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

