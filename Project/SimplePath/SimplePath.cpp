/*************************************************************************
                           SimplePath  -  description
                             -------------------
    début                : 27/09/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <SimplePath> (fichier SimplePath.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;
//------------------------------------------------------ Include personnel
#include "SimplePath.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs
SimplePath& SimplePath::operator=(SimplePath& other) 
{
    swap(*this, other); 

    return *this;
}
//-------------------------------------------- Constructeurs - destructeur
SimplePath::SimplePath ( const SimplePath & other )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <SimplePath>" << endl;
#endif
    startCity = new char[strlen(other.startCity)+1];
    strcpy(startCity, other.startCity);
    endCity = new char[strlen(other.endCity)+1];
    strcpy(endCity, other.endCity);
    meanOfTransport = other.meanOfTransport;
} //----- Fin de SimplePath (constructeur de copie)


SimplePath::SimplePath ( char * startingCity, char * endingCity, 
						MeansOfTransport vehicle) : meanOfTransport(vehicle)
// Algorithme :
//
{

#ifdef MAP
    cout << "Appel au constructeur de <SimplePath>" << endl;
#endif
    startCity = new char[strlen(startingCity)+1];
    strcpy(startCity, startingCity);
    endCity = new char[strlen(endingCity)+1];
    strcpy(endCity, endingCity);
} //----- Fin de SimplePath


SimplePath::~SimplePath ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <SimplePath>" << endl;
#endif
   	delete [] startCity;
   	delete [] endCity;

} //----- Fin de ~SimplePath


//------------------------------------------------------------------ PRIVE
bool SimplePath::equals(const Path& other) const
{
    const SimplePath& other_derived = dynamic_cast<const SimplePath&>(other);
    return (strcmp(this->startCity, other_derived.startCity) == 0)
        && (strcmp(this->endCity, other_derived.endCity) == 0)
        && this->meanOfTransport == other_derived.meanOfTransport;
}
//----------------------------------------------------- Méthodes protégées
std::ostream& SimplePath::print(std::ostream& os) const
{	
	//TODO convert meanOfTransport value to meaningful string representation
	return os << " { " << startCity << " ; " << endCity << " ; "
			  << meanOfTransport << " } \r\n";
}

void swap(SimplePath& first, SimplePath& second)
{
	//TODO ask if we could use std::swap maybe ?
	char * tmp = first.startCity;
	first.startCity = second.startCity;
	second.startCity = tmp;

	tmp = first.endCity;
	first.endCity = second.endCity;
	second.endCity = tmp;

	MeansOfTransport tmpMot = second.meanOfTransport;
	second.meanOfTransport = first.meanOfTransport;
	first.meanOfTransport = tmpMot;
}
