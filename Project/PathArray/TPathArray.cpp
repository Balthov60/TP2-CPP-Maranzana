/*************************************************************************
                           TPathArray  -  description
                             -------------------
    début                : 25/09/2018
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <TPathArray> (fichier TPathArray.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
//------------------------------------------------------ Include personnel
#include "TPathArray.h"



///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
//static type nom ( liste de paramètres )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
//{
//} //----- fin de nom

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
static void testConstructeurDefaut2()
{
	/*
		expected output :
		0
		15
		{}
	*/
	PathArray ensemble(15);
	ensemble.Display();
}

static void testConstructeurDefaut1()
{
	/*
		expected output :
		0
		10
		{}
	*/
	PathArray ensemble;
	ensemble.Display();
}

static void testConstructeurDefaut()
{
	cout << "Test constructeur defaut" << endl; 
	testConstructeurDefaut1();
	testConstructeurDefaut2();
	cout << "Fin Test constructeur defaut" << endl; 
}

static void testEstEgal2()
{
	/*
		expected output:
		1
	*/
	
	PathArray firstE;
	PathArray secondE;

	char varsovie[] = "Varsovie";
	char londres[] = "Londres";

	SimplePath path1 = SimplePath((char*)varsovie, (char*)londres, AVION);
	firstE.Add(&path1);
	secondE.Add(&path1);
	cout << firstE.Equals(firstE) << endl;
}

static void testEstEgal1()
{
	/*
		expected output:
		0
	*/
	PathArray firstE;
	PathArray secondE;

	char varsovie[] = "Varsovie";
	char londres[] = "Londres";

	SimplePath path1 = SimplePath((char*)varsovie, (char*)londres, AVION);
	SimplePath path2 = SimplePath((char*)londres, (char*)varsovie, AVION);
	firstE.Add(&path1);
	secondE.Add(&path2);
	cout << firstE.Equals(secondE) << endl;
}

static void testEstEgal()
{
	cout << "Test EstEgal" << endl; 
	testEstEgal1();
	testEstEgal2();
	cout << "Fin Test EstEgal" << endl; 
}

static void testAdd()
{
	cout << "Test Add" << endl; 
	PathArray firstE;

	char varsovie[] = "Varsovie";
	char londres[] = "Londres";

	SimplePath path1 = SimplePath((char*)varsovie, (char*)londres, AVION);
	SimplePath path2 = SimplePath((char*)londres, (char*)varsovie, AVION);
	firstE.Add(&path1);
	firstE.Add(&path2);

	firstE.Display();
	cout << "Fin Test Add" << endl; 
}

static void testAdjust3()
{
	/*
		expected output:
		4 as maxCard
	*/
	PathArray e1(5);
	e1.Adjust(-1);
	e1.Display();
}

static void testAdjust2()
{
	/*
		expected output:
		1 as maxCard
	*/
	PathArray e1(5);
	char varsovie[] = "Varsovie";
	char londres[] = "Londres";

	SimplePath path1 = SimplePath((char*)varsovie, (char*)londres, AVION);
	e1.Add(&path1);
	e1.Adjust(-5);
	e1.Display();
}

static void testAdjust1()
{
	/*
		expected output:
		10 as maxCard
	*/
	PathArray e1(5);
	e1.Adjust(5);
	e1.Display();
}

static void testAdjust()
{
	cout << "Test Adjust" << endl; 
	testAdjust1();
	testAdjust2();
	testAdjust3();
	cout << "Fin Test Adjust" << endl; 
}


int main ()
// Algorithme :
//
{
	testConstructeurDefaut();
	testEstEgal();
	testAdd();
	testAdjust();
} //----- fin de Nom

