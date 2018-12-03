/*************************************************************************
                           CityCriterion  -  description
                             -------------------
    début                : 28/11/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <CityCriterion> (fichier CityCriterion.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
#include <cctype>
//------------------------------------------------------ Include personnel
#include "CityCriterion.h"
using namespace std;
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
const bool CityCriterion::CheckMetadata(const char * line)
{
	if (startCity == nullptr && endCity == nullptr)
	{
		return false;
	}

	bool result = false;

	char * buffer = new char[strlen(line) + 1];
    strcpy(buffer, line);

    char *save_ptr1;
    char *save_ptr2;

    strtok_r(buffer, METADATA_DELIMITER, &save_ptr1); //number of simple path
    strtok_r(NULL, METADATA_DELIMITER, &save_ptr1); //number of composed path

    char * list_token = strtok_r(NULL, METADATA_DELIMITER, &save_ptr1); //list of starting cities

    if (list_token && startCity != nullptr)
    {
    	char * buffer2 = new char[strlen(list_token) + 1];
    	strcpy(buffer2, list_token);
    	char * city_token = strtok_r(buffer2, PATH_DELIMITER, &save_ptr2);
    	do
    	{
    		cityToLower(city_token);
    		result = (strcmp(city_token, startCity) == 0);
    		city_token = strtok_r(NULL, PATH_DELIMITER, &save_ptr2);
    	} while (city_token != nullptr && !result);
    	delete[] buffer2;
    }

    if (list_token && endCity != nullptr)
    {
    	bool endResult = false;
    	list_token = strtok_r(NULL, METADATA_DELIMITER, &save_ptr1); //list of ending cities
    	char * buffer2 = new char[strlen(list_token) + 1];
    	strcpy(buffer2, list_token);
    	char * city_token = strtok_r(buffer2, PATH_DELIMITER, &save_ptr2);
    	do 
    	{
    		cityToLower(city_token);
    		endResult = (strcmp(city_token, endCity) == 0);
    		city_token = strtok_r(NULL, PATH_DELIMITER, &save_ptr2);
    	} while (city_token != nullptr && !endResult);
    	// if we are in AND condition, combine with former result
    	result = (startCity != nullptr) ? (result && endResult) : endResult;
    	delete[] buffer2;
    }

    delete[] buffer;

	return result;
} //----- Fin de CheckMetadata

const bool CityCriterion::CheckLine(const char * line)
{
	if (startCity == nullptr && endCity == nullptr)
	{
		return false;
	}

	char * buffer = new char[strlen(line) + 1];
    strcpy(buffer, line);

    char * buffer2 = new char[strlen(line) + 1];
    strcpy(buffer2, line);

    char * save_ptr1;
    char * save_ptr2;

    char * simple_token = strtok_r(buffer, PATH_DELIMITER, &save_ptr1);

    bool result = false;
    if (startCity != nullptr)
    {    
    	cityToLower(simple_token);
	    result = (strcmp(simple_token, startCity) == 0);
    }

    if (endCity != nullptr)
    {
    	char * comp_token = strtok_r(buffer2, COMPOSED_PATH_FLAG, &save_ptr2);
    	comp_token = strtok_r(NULL, COMPOSED_PATH_FLAG, &save_ptr2);
    	if (comp_token == nullptr)
    	{
    		// simple path : getting word after second ;
    		strtok_r(NULL, PATH_DELIMITER, &save_ptr1);
    		simple_token = strtok_r(NULL, PATH_DELIMITER, &save_ptr1);
    		// if we are in AND condition, combine with former result
    		cityToLower(simple_token);
    		result = (startCity != nullptr) ? (result && strcmp(simple_token, endCity) == 0) : (strcmp(simple_token, endCity) == 0);
    	}
    	else
    	{
    		cityToLower(comp_token);
    		// if we are in AND condition, combine with former result
    		result = (startCity != nullptr) ? (result && strcmp(comp_token, endCity) == 0) : (strcmp(comp_token, endCity) == 0);
    	}
    }
    
    delete[] buffer; 
    delete[] buffer2;

    return result;
} //----- Fin de CheckLine

const bool CityCriterion::CheckPath(const Path * path)
{
	bool result = false;
	if (startCity != nullptr)
    {    
    	char * startCpy = new char[strlen(path->GetStartCity()) + 1];
    	strcpy(startCpy, path->GetStartCity());
    	cityToLower(startCpy);
	    result = (strcmp(startCpy, startCity) == 0);
	    delete [] startCpy;
    }
    if (endCity != nullptr)
    {
    	char * endCpy = new char[strlen(path->GetEndCity()) + 1];
    	strcpy(endCpy, path->GetEndCity());
    	cityToLower(endCpy);
    	// if we are in AND condition, combine with former result
    	result = (startCity != nullptr) ? (result && strcmp(endCpy, endCity) == 0) : (strcmp(endCpy, endCity) == 0);
    	delete[] endCpy;
    }
    return result;
} //----- Fin de CheckPath




//------------------------------------------------- Surcharge d'opérateurs
CityCriterion & CityCriterion::operator = ( CityCriterion other )
// Algorithme :
//
{
	dispose();
	create(other.startCity, other.endCity);
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
CityCriterion::CityCriterion ( const CityCriterion & other )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CityCriterion>" << endl;
#endif
    create(other.startCity, other.endCity);
} //----- Fin de CityCriterion (constructeur de copie)

CityCriterion::CityCriterion ( const char * startingCity, const char * endingCity ) 
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CityCriterion>" << endl;
#endif
    create(startingCity, endingCity);
} //----- Fin de CityCriterion


CityCriterion::~CityCriterion ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CityCriterion>" << endl;
#endif
    dispose();
} //----- Fin de ~CityCriterion


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void CityCriterion::create( const char * startingCity, const char * endingCity )
{
	if (startingCity != nullptr)
	{
		startCity = new char[strlen(startingCity) + 1];
		strcpy(startCity, startingCity);
		cityToLower(startCity);
	}
	else
	{
		startCity = nullptr;
	}
	if (endingCity != nullptr)
	{
		endCity = new char[strlen(endingCity) + 1];
		strcpy(endCity, endingCity);
		cityToLower(endCity);
	}
	else
	{
		endCity = nullptr;
	}
}

void CityCriterion::dispose()
{
	delete[] startCity;
	delete[] endCity;
}

void CityCriterion::cityToLower(char * city) const
{
	for (unsigned int i = 0; i < strlen(city); i++)
	{
		city[i] = tolower(city[i]);
	}
}