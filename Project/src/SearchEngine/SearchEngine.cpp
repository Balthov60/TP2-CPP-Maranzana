/*************************************************************************
                           SearchEngine  -  description
                             -------------------
    début                : 04/10/2018
    copyright            : (C) 2018 par WALLYN Valentin - FROLIN Balthazar
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <SearchEngine> (fichier SearchEngine.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>

using namespace std;

//------------------------------------------------------ Include personnel
#include "SearchEngine.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void SearchEngine::SimpleSearch(const char * startingCity, const char * endingCity) const
// Algorithme :
//		Recherche dans la matrice de proximité si un trajet direct existe entre startingCity
// et endingCity. Si oui, affiche le trajet, sinon affiche qu'aucun trajet n'a été trouvé.
{
    unsigned int startIndex = getStartCityIndex(startingCity);
    unsigned int endIndex = getEndCityIndex(endingCity);

    if (startIndex != startCurrentSize && endIndex != endCurrentSize && adjacencyMatrix[startIndex][endIndex]->GetSize() > 0)
    {
    	adjacencyMatrix[startIndex][endIndex]->Print(cout);
    }
    else
    {
    	cout << "\tAucun trajet correspondant n'a été trouvé." << endl;
    }

} //----- Fin de simpleSearch


void SearchEngine::AdvancedSearch(const char * startingCity, const char * endingCity) const
// Algorithme :
//		Instancie le noeud initial de la recherche récursive puis apelle la fonction de recherche
// récursive. Voir la fonction "recursiveSearch" pour l'algorithme de recherche.
{
	unsigned int startIndex = getStartCityIndex(startingCity);
    unsigned int endIndex = getEndCityIndex(endingCity);

    if (startIndex != startCurrentSize && endIndex != endCurrentSize)
    {
	    SearchEngine::node node;
	    node.startIndex = startIndex;
	    node.previous = NULL;

	    bool* doneIndex = new bool[startCurrentSize];
	    for (unsigned int j = 0; j < startCurrentSize; j++)
	    {
	    	doneIndex[j] = false;
	    }
    	recursiveSearch(&node, endIndex, doneIndex);
	    delete [] doneIndex;
    }
    else
    {
    	cout << "\tAucun trajet correspondant n'a été trouvé." << endl;
    }
} //----- Fin de advancedSearch


void SearchEngine::AddPath(Path* path)
// Algorithme :
//		Ajoute un trajet à la matrice de proximité en effectuant les réallocations
// de mémoire nécessaires lorsque les tableaux sont pleins. Stocke les villes de départ
// et d'arrivée de manière unique
{
	unsigned int startCityIndex = getStartCityIndex(path->GetStartCity());
	unsigned int endCityIndex = getEndCityIndex(path->GetEndCity());

	if (startCityIndex == startCurrentSize)
	{	

		startCities[startCityIndex] = new char[strlen(path->GetStartCity()) + 1];
		strcpy(startCities[startCityIndex], path->GetStartCity());
		startCurrentSize++;
		if (startCurrentSize == startMaxSize)
		{
			char ** tmpCities = new char*[startMaxSize * 2];
			for (unsigned int j = 0; j < startCurrentSize; j++)
			{
				tmpCities[j] = new char[strlen(startCities[j]) + 1];
				strcpy(tmpCities[j], startCities[j]);
			}
			for (unsigned int j = 0; j < startCurrentSize; j++)
		    {
		    	delete [] startCities[j];
		    }
		    
			delete [] startCities;
			startCities = tmpCities;
			


			PathArray*** tmp = new PathArray**[startMaxSize * 2];
			for (unsigned int j = 0; j < startMaxSize * 2; j++)
		    {
		    	tmp[j] = new PathArray*[endMaxSize];
		    	for (unsigned int i = 0; i < endMaxSize; i++)
		    	{
		    		tmp[j][i] = new PathArray();
		    		if (i < endCurrentSize && j < startCurrentSize - 1)
		    		{
			    		*tmp[j][i] = *adjacencyMatrix[j][i];
			    	}
		    	}
		    }
			for (unsigned int j = 0; j < startMaxSize; j++)
		    {
		    	for (unsigned int i = 0; i < endMaxSize; i++)
		    	{
		    		delete adjacencyMatrix[j][i];
		    	}
		    	delete [] adjacencyMatrix[j];
		    }
		    startMaxSize = startMaxSize * 2;
		    delete [] adjacencyMatrix;
			adjacencyMatrix = tmp;
		}
	}

	if (endCityIndex == endCurrentSize)
	{
		endCities[endCityIndex] = new char[strlen(path->GetEndCity()) + 1];
		strcpy(endCities[endCityIndex], path->GetEndCity());
		endCurrentSize++;
		if (endCurrentSize == endMaxSize)
		{
			char ** tmpCities = new char*[endMaxSize * 2];
			for (unsigned int j = 0; j < endCurrentSize; j++)
			{
				tmpCities[j] = new char[strlen(endCities[j]) + 1];
				strcpy(tmpCities[j], endCities[j]);
			}
			for (unsigned int j = 0; j < endCurrentSize; j++)
		    {
		    	delete [] endCities[j];
		    }
		    
			delete [] endCities;
			endCities = tmpCities;
			

			
			PathArray*** tmp = new PathArray**[startMaxSize];
			for (unsigned int j = 0; j < startMaxSize; j++)
		    {
		    	tmp[j] = new PathArray*[endMaxSize * 2];
		    	for (unsigned int i = 0; i < endMaxSize * 2; i++)
		    	{
		    		tmp[j][i] = new PathArray();
		    		if (i < endCurrentSize - 1 && j < startCurrentSize)
		    		{
			    		*tmp[j][i] = *adjacencyMatrix[j][i];
			    	}
		    	}
		    }
			for (unsigned int j = 0; j < startMaxSize; j++)
		    {
		    	for (unsigned int i = 0; i < endMaxSize; i++)
		    	{
		    		delete adjacencyMatrix[j][i];
		    	}
		    	delete [] adjacencyMatrix[j];
		    }
		    endMaxSize = endMaxSize * 2;
		    delete [] adjacencyMatrix;
			adjacencyMatrix = tmp;
		}
		
	}

	adjacencyMatrix[startCityIndex][endCityIndex]->Add(path->Clone());

} //----- Fin de addPath

//------------------------------------------------- Surcharge d'opérateurs
SearchEngine & SearchEngine::operator = ( const SearchEngine & other )
// Algorithme :
//
{
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
SearchEngine::SearchEngine ( const SearchEngine & other )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <SearchEngine>" << endl;
#endif
} //----- Fin de SearchEngine (constructeur de copie)


SearchEngine::SearchEngine( const unsigned int size )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <SearchEngine>" << endl;
#endif
    adjacencyMatrix = new PathArray**[size];
    for (unsigned int j = 0; j < size; j++)
    {
    	adjacencyMatrix[j] = new PathArray*[size];
    	for (unsigned int i = 0; i < size; i++)
    	{
    		adjacencyMatrix[j][i] = new PathArray();
    	}
    }
    startCities = new char*[size];
    endCities = new char*[size];
    startCurrentSize = 0;
    startMaxSize = size;
    endCurrentSize = 0;
    endMaxSize = size;

} //----- Fin de SearchEngine


SearchEngine::~SearchEngine ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <SearchEngine>" << endl;
#endif
    for (unsigned int j = 0; j < startMaxSize; j++)
    {
    	for (unsigned int i = 0; i < endMaxSize; i++)
    	{
    		delete adjacencyMatrix[j][i];
    	}
    	delete [] adjacencyMatrix[j];
    }
    delete [] adjacencyMatrix;

    for (unsigned int j = 0; j < startCurrentSize; j++)
    {
    	delete [] startCities[j];
    }

    for (unsigned int j = 0; j < endCurrentSize; j++)
    {
    	delete [] endCities[j];
    }
    delete [] startCities;
    delete [] endCities;
} //----- Fin de ~SearchEngine


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
unsigned int SearchEngine::getStartCityIndex(const char * city) const
// Algorithme :
//		Parcoure la liste des villes de départ enregistrées et récupère l'index
// de la ville "city"
{
	for (unsigned int  j = 0; j < startCurrentSize; j++)
	{
		if (strcmp(startCities[j], city) == 0)
		{
			return j;
		}
	}
	return startCurrentSize;
} //----- Fin de getStartCityIndex

unsigned int SearchEngine::getEndCityIndex(const char * city) const
// Algorithme :
//		Parcoure la liste des villes d'arrivée enregistrées et récupère l'index
// de la ville "city"
{
	for (unsigned int j = 0; j < endCurrentSize; j++)
	{
		if (strcmp(endCities[j], city) == 0)
		{
			return j;
		}
	}
	return endCurrentSize;
} //----- Fin de getEndCityIndex

bool SearchEngine::recursiveSearch(node* node, unsigned int endIndex, bool * doneIndex) const
// Algorithme :
//		Explore les noeuds reliés au noeud initial "node" dans la matrice de proximité récursivement
// jusqu'à l'arrivée sur un noeud possèdant comme ville d'arrivée la destination objectif (endIndex)
// ou que tous les noeuds de départs aient été explorés (stockés dans doneIndex)
// Si un trajet a été trouvé, affiche la composition de celui-ci en parcourant les noeuds solution
{
	for (unsigned int j = 0; j < endCurrentSize; j++)
	{
		node->endIndex = j;
		
		if (adjacencyMatrix[node->startIndex][j]->GetSize() > 0)
		{
			if (j == endIndex)
			{
				node->next = NULL;
				while (node->previous != NULL)
				{
					node = node->previous;
				}
				cout << "Début trajet :" << endl;
				while (node->next != NULL)
				{
					adjacencyMatrix[node->startIndex][node->endIndex]->Print(cout, true);
					cout << "puis" << endl;
					node = node->next;
				}
				adjacencyMatrix[node->startIndex][node->endIndex]->Print(cout, true);
				cout << "Fin trajet" << endl << endl;
				return true;
			}
			unsigned int startIndex = getStartCityIndex(endCities[j]);
			if (startIndex != startCurrentSize)
			{			
				if (!doneIndex[startIndex])
				{
					doneIndex[node->startIndex] = true;
					SearchEngine::node next;
					next.previous = node;
					next.startIndex = startIndex;

					node->next = &next;
					recursiveSearch(&next, endIndex, doneIndex);
				}
			}
			
		}
	}
	return false;
} //----- Fin de recursiveSearch
