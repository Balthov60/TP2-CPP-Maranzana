/*************************************************************************
                           TSearchEngine  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <TSearchEngine> (fichier TSearchEngine.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>

using std::cout;
//------------------------------------------------------ Include personnel
#include "TSearchEngine.h"
#include "../../src/SimplePath/SimplePath.h"
#include "../../src/SearchEngine/SearchEngine.h"
///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
static void testAdvancedSearch3()
{
	cout << "DEBUT testAdvancedSearch3" << "\r\n";
	/*
		expected output :
		=================================================
		Trajet Simple :
		Départ    : A
		Arrivée   : B
		Transport : Avion
		puis
		Trajet Simple :
		Départ    : B
		Arrivée   : A
		Transport : Avion
		Fin trajet

		Début trajet :
		Trajet Simple :
		Départ    : A
		Arrivée   : B
		Transport : Avion
		puis
		Trajet Simple :
		Départ    : B
		Arrivée   : C
		Transport : Train
		puis
		Trajet Simple :
		Départ    : C
		Arrivée   : A
		Transport : Train
		Fin trajet

		Début trajet :
		Trajet Simple :
		Départ    : A
		Arrivée   : A
		Transport : Train
		Fin trajet
		=================================================
	*/
	SearchEngine* se = new SearchEngine();
	char a[] = "A";
	char b[] = "B";
	char c[] = "C";

	SimplePath* ts1 = new SimplePath(a, b, AVION);
	SimplePath* tc1 = new SimplePath(a, a, TRAIN);
	SimplePath* ts2 = new SimplePath(b, a, AVION);
	SimplePath* tc2 = new SimplePath(b, c, TRAIN);
	SimplePath* ts3 = new SimplePath(c, a, TRAIN);

	se->AddPath(ts1);
	se->AddPath(tc1);
	se->AddPath(ts2);
	se->AddPath(tc2);
	se->AddPath(ts3);

	se->AdvancedSearch(a, a);
	delete se;

	delete ts1;
	delete tc1;
	delete ts2;
	delete tc2;
	delete ts3;
	cout << "FIN testAdvancedSearch3" << "\r\n";
}

static void testAdvancedSearch2()
{
	cout << "DEBUT testAdvancedSearch2" << "\r\n";
	/*
		expected output :
		=================================================
		Début trajet :
		Trajet Simple :
			Départ    : A
			Arrivée   : A
			Transport : Avion
		puis
		Trajet Simple :
			Départ    : A
			Arrivée   : B
			Transport : Auto
		puis
		Trajet Simple :
			Départ    : B
			Arrivée   : D
			Transport : Train
		Fin trajet
		=================================================
		=================================================
		Début trajet :
		Trajet Simple :
			Départ    : A
			Arrivée   : B
			Transport : Auto
		puis
		Trajet Simple :
			Départ    : B
			Arrivée   : D
			Transport : Train
		Fin trajet
		=================================================
	*/

	SearchEngine* se = new SearchEngine();
	char a[] = "A";
	char b[] = "B";
	char d[] = "D";
	SimplePath* ts1 = new SimplePath(a, a, AVION);
	SimplePath* tc1 = new SimplePath(b, d, TRAIN);
	SimplePath* ts2 = new SimplePath(a, b, AUTO);

	se->AddPath(ts1);
	se->AddPath(tc1);
	se->AddPath(ts2);

	se->AdvancedSearch(a, d);

	delete se;

	delete ts1;
	delete tc1;
	delete ts2;

	cout << "FIN testAdvancedSearch2" << "\r\n";
}




static void testAdvancedSearch1()
{
	cout << "DEBUT testAdvancedSearch1" << "\r\n";
	/*
		expected output :
		=================================================
		Début trajet :
		Trajet Simple :
			Départ    : A
			Arrivée   : B
			Transport : Avion
		puis
		Trajet Simple :
			Départ    : B
			Arrivée   : C
			Transport : Train
		ou
		Trajet Simple :
			Départ    : B
			Arrivée   : C
			Transport : Avion
		Fin trajet
		=================================================
		=================================================
		Début trajet :
		Trajet Simple :
			Départ    : A
			Arrivée   : C
			Transport : Train
		Fin trajet
		=================================================
	*/
	SearchEngine* se = new SearchEngine();
	char a[] = "A";
	char b[] = "B";
	char c[] = "C";

	SimplePath* ts1 = new SimplePath(a, b, AVION);
	SimplePath* tc1 = new SimplePath(b, c, TRAIN);
	SimplePath* ts2 = new SimplePath(b, c, AVION);
	SimplePath* tc2 = new SimplePath(a, c, TRAIN);

	se->AddPath(ts1);
	se->AddPath(tc1);
	se->AddPath(ts2);
	se->AddPath(tc2);

	se->AdvancedSearch(a, c);
	delete se;

	delete ts1;
	delete tc1;
	delete ts2;
	delete tc2;
	cout << "FIN testAdvancedSearch1" << "\r\n";
}

static void testAdvancedSearch()
{
	
	cout << "DEBUT testAdvancedSearch" << "\r\n";
	testAdvancedSearch1();
	testAdvancedSearch2();
	testAdvancedSearch3();
	cout << "FIN testAdvancedSearch" << "\r\n";
}

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
int main()
// Algorithme :
//
{
	testAdvancedSearch();
} //----- fin de main

