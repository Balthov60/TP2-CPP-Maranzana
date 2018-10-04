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
#include "../SimplePath/SimplePath.h"
#include "SearchEngine.h"
///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
static void testAdd()
{
	/*
		expected output :
		{ de Lyon à Paris en MT0 }
	*/
	cout << "testAdd" << "\r\n";
	SearchEngine* se = new SearchEngine();

	/*char lyon[] = "Lyon";
	char paris[] = "Paris";
	SimplePath* path1 = new SimplePath(lyon, paris, TRAIN);*/
	
	//char londres[] = "Londres";
	//char budapest[] = "Budapest";
	//SimplePath* path2 = new SimplePath(londres, paris, TRAIN);

	//se->AddPath(path1);
	//se->AddPath(path2);

	//se->DisplayMatrix();


	//delete path1;
	//delete path2;

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
	//char barcelone[] = "barcelone";
	//char moscou[] = "moscou";
	//SimplePath* path3 = new SimplePath(barcelone, paris, TRAIN);
}

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
int main()
// Algorithme :
//
{
	testAdd();
} //----- fin de main

