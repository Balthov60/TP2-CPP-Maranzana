/*************************************************************************
                           PathArray  -  description
                             -------------------
    début                : 27/09/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <PathArray> (fichier PathArray.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using std::cout;
using std::endl;
//------------------------------------------------------ Include personnel
#include "PathArray.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool PathArray::Contains(const Path* path) const
// Algorithme :
//
{
	unsigned int j;
	for (j = 0; j < currentCard; j++)
	{
		if (*elements[j] == *path)
		{
			return true;
		}
	}
	return false;
} //----- fin de Contains

unsigned int PathArray::GetCurrentCard(void) const
// Algorithme :
//
{
	return currentCard;
} //----- fin de GetCurrentCard

unsigned int PathArray::GetMaxCard(void) const
// Algorithme :
//
{
	return maxCard;
} //----- fin de GetMaxCard

Path* PathArray::Get(int index) const
// Algorithme :
//
{
	return elements[index];
} //----- fin de GetMaxCard


void PathArray::Display ( void ) const
// Algorithme :
//
{
	cout << currentCard << "\r\n";
	cout << maxCard << "\r\n";
	cout << "{";
	if (currentCard > 0)
	{
		unsigned int j;
		for (j = 0; j < currentCard - 1; j++)
		{
			cout << *elements[j]; 
			cout << ",";
		}

		cout << *elements[currentCard - 1];
	}
	cout << "}" << "\r\n";
	
} //----- fin de Display

std::ostream& PathArray::Print(std::ostream& os, bool advanced) const
// Algorithme :
//
{
	unsigned int j;
	if (advanced)
	{
		if (currentCard > 0)
		{
			for (j = 0; j < currentCard - 1; j++)
			{
				os << *elements[j];
				os << "ou" << std::endl;
			}
			os << *elements[currentCard-1];
		}
	}
	else
	{
		for (j = 0; j < currentCard; j++)
		{
			os << "Etape " << j + 1 << " - ";
			os << *elements[j];
		}
	}
	

	return os;
} //----- fin de Print

bool PathArray::Equals(const PathArray & anotherPathArray) const
// Algorithme :
//
{
	if (anotherPathArray.GetCurrentCard() != currentCard)
	{
		return false;
	}
	else
	{
		unsigned int j;
		for (j = 0; j < currentCard; j++)
		{
			if (!anotherPathArray.Contains(elements[j]))
				return false;
		}
	}
	return true;
} //----- fin de Equals

bool PathArray::Add(Path* pathToAdd)
// Algorithme :
//
{
	unsigned int j;
	for (j = 0; j < currentCard; j++)
	{
	    
		if (*elements[j] == *pathToAdd)
		{
			return false;
		}
	}
	if (currentCard == maxCard)
	{
	    Adjust(currentCard);
	}
	elements[currentCard] = pathToAdd;
	currentCard++;

	return true;
} //----- fin de Add

unsigned int PathArray::Adjust(int delta)
// Algorithme :
//
{
	int temp = maxCard - currentCard;
	if (delta >= 0 || -delta <= temp)
	{
		maxCard += delta;
	}	
	else 
	{
		maxCard = currentCard;
	}

	Path** newElements = new Path*[maxCard];
	unsigned int j;
	for (j = 0; j < currentCard; j++)
	{
	 	newElements[j] = elements[j];
	}
	delete [] elements;
	elements = newElements;
	return maxCard;
} //----- fin de Adjust

bool PathArray::Remove(Path* element)
// Algorithme :
//
{
	if (Contains(element))
	{
		Path** newElements = new Path*[currentCard-1];
		unsigned int j;
		unsigned int i = 0;
		for (j = 0; j < currentCard; j++)
		{
		    
			if (!(*elements[j] == *element)) //TODO we could define != operator 
			{
				newElements[i] = elements[j];
				i++;
			}
		}
		delete [] elements;
		elements = newElements;
		currentCard--;
		maxCard = currentCard;
		return true;
	}
	maxCard = currentCard;
	return false;
} //----- fin de Remove

unsigned int PathArray::Remove(const PathArray & anotherPathArray)
// Algorithme :
//
{
	unsigned int oldMaxCard = maxCard;
	unsigned int j;
	int count = 0;
	if (Equals(anotherPathArray))
	{
		count = currentCard;
		currentCard = 0;
	}
	else 
	{
		for (j = 0; j < anotherPathArray.GetCurrentCard(); j++)
		{
			if (Remove(anotherPathArray.Get(j)))
			{
				count++;
			}
		}
		maxCard = oldMaxCard;
	}
	
	return count;
} //----- fin de Remove




//------------------------------------------------- Surcharge d'opérateurs
PathArray& PathArray::operator=(const PathArray& other) 
{
#ifdef MAP
	cout << "Appel à la surcharge du = de <PathArray>" << endl;
#endif
	if (this != &other)
	{
		for (unsigned int j = 0; j < currentCard; j++)
	    {
	    	delete elements[j];
	    }
		delete [] elements;

		currentCard = other.GetCurrentCard();
		maxCard = other.GetMaxCard();

		elements = new Path*[maxCard];
		for (unsigned int j = 0; j < currentCard; j++)
		{
			elements[j] = other.Get(j)->Clone();
		}
	}
    return *this;
}

//-------------------------------------------- Constructeurs - destructeur
PathArray::PathArray ( const PathArray & anotherPathArray )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <PathArray>" << endl;
#endif
    maxCard = anotherPathArray.maxCard;
    currentCard = anotherPathArray.currentCard;
    elements = new Path*[maxCard];
    unsigned int j;
    for (j = 0; j < currentCard; j++)
    {
    	elements[j] = anotherPathArray.elements[j]->Clone();
    }
} //----- Fin de PathArray (constructeur de copie)


PathArray::PathArray(const unsigned int cardMax)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <PathArray>" << endl;
#endif
	elements = new Path*[cardMax];
	maxCard = cardMax;
	currentCard = 0;
} //----- Fin de PathArray

PathArray::~PathArray ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <PathArray>" << endl;
#endif
    for (unsigned int j = 0; j < currentCard; j++)
    {
    	delete elements[j];
    }
    delete [] elements;
} //----- Fin de ~PathArray


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées