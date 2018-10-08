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
	for (j = 0; j < size; j++)
	{
		if (*elements[j] == *path)
		{
			return true;
		}
	}
	return false;
} //----- fin de Contains

unsigned int PathArray::GetSize(void) const
// Algorithme :
//
{
	return size;
} //----- fin de GetSize

unsigned int PathArray::GetMaxSize(void) const
// Algorithme :
//
{
	return maxSize;
} //----- fin de GetMaxSize

Path* PathArray::Get(int index) const
// Algorithme :
//
{
	return elements[index];
} //----- fin de GetMaxSize

std::ostream& PathArray::Print(std::ostream& os, bool advanced) const
// Algorithme :
//
{
	unsigned int j;
	if (advanced)
	{
		if (size > 0)
		{
			for (j = 0; j < size - 1; j++)
			{
				os << *elements[j];
				os << "ou" << std::endl;
			}
			os << *elements[size-1];
		}
	}
	else
	{
		for (j = 0; j < size; j++)
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
	if (anotherPathArray.GetSize() != size)
	{
		return false;
	}
	else
	{
		unsigned int j;
		for (j = 0; j < size; j++)
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
	for (j = 0; j < size; j++)
	{
	    
		if (*elements[j] == *pathToAdd)
		{
			return false;
		}
	}
	if (size == maxSize)
	{
	    Adjust(size);
	}
	elements[size] = pathToAdd;
	size++;

	return true;
} //----- fin de Add

unsigned int PathArray::Adjust(int delta)
// Algorithme :
//
{
	int temp = maxSize - size;
	if (delta >= 0 || -delta <= temp)
	{
		maxSize += delta;
	}	
	else 
	{
		maxSize = size;
	}

	Path** newElements = new Path*[maxSize];
	unsigned int j;
	for (j = 0; j < size; j++)
	{
	 	newElements[j] = elements[j];
	}
	delete [] elements;
	elements = newElements;
	return maxSize;
} //----- fin de Adjust

bool PathArray::Remove(Path* element)
// Algorithme :
//
{
	if (Contains(element))
	{
		Path** newElements = new Path*[size-1];
		unsigned int j;
		unsigned int i = 0;
		for (j = 0; j < size; j++)
		{
		    
			if (!(*elements[j] == *element)) //TODO we could define != operator 
			{
				newElements[i] = elements[j];
				i++;
			}
		}
		delete [] elements;
		elements = newElements;
		size--;
		maxSize = size;
		return true;
	}
	maxSize = size;
	return false;
} //----- fin de Remove

unsigned int PathArray::Remove(const PathArray & anotherPathArray)
{
	unsigned int oldmaxSize = maxSize;
	unsigned int j;
	int count = 0;
	if (Equals(anotherPathArray))
	{
		count = size;
		size = 0;
	}
	else 
	{
		for (j = 0; j < anotherPathArray.GetSize(); j++)
		{
			if (Remove(anotherPathArray.Get(j)))
			{
				count++;
			}
		}
		maxSize = oldmaxSize;
	}
	
	return count;
} //----- fin de Remove

//------------------------------------------------- Surcharge d'opérateurs
PathArray& PathArray::operator=(const PathArray& other) 
{
	if (this != &other)
	{
		for (unsigned int j = 0; j < size; j++)
	    {
	    	delete elements[j];
	    }
		delete [] elements;

		size = other.GetSize();
		maxSize = other.GetMaxSize();

		elements = new Path*[maxSize];
		for (unsigned int j = 0; j < size; j++)
		{
			elements[j] = other.Get(j)->Clone();
		}
	}
    return *this;
}
#ifdef MAP
cout << "Appel à la surcharge du = de <PathArray>" << endl;
#endif

//-------------------------------------------- Constructeurs - destructeur
PathArray::PathArray(const PathArray & anotherPathArray)
{
    maxSize = anotherPathArray.maxSize;
    size = anotherPathArray.size;

    elements = new Path*[maxSize];

    for (unsigned int j = 0; j < size; j++)
    {
    	elements[j] = anotherPathArray.elements[j]->Clone();
    }

#ifdef MAP
	cout << "Appel au constructeur de copie de <PathArray>" << endl;
#endif
} //----- Fin de PathArray (constructeur de copie)

PathArray::PathArray(const unsigned int maxSize)
{
	elements = new Path*[maxSize];
	this->maxSize = maxSize;

	size = 0;

#ifdef MAP
	cout << "Appel au constructeur de <PathArray>" << endl;
#endif
} //----- Fin de PathArray

PathArray::~PathArray()
{
    for (unsigned int j = 0; j < size; j++)
    {
    	delete elements[j];
    }
    delete [] elements;

#ifdef MAP
	cout << "Appel au destructeur de <PathArray>" << endl;
#endif
} //----- Fin de ~PathArray

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
