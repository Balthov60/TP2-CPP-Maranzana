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

char * SimplePath::GetStartingCity() const
{
    return startCity;
} //----- Fin de StartFrom

char * SimplePath::GetEndingCity() const
{
    return endCity;
} //----- Fin de StopAt

SimplePath* SimplePath::Clone() const
{
    return new SimplePath(*this);
} //----- Fin de Clone

//------------------------------------------------- Surcharge d'opérateurs
SimplePath& SimplePath::operator=(SimplePath& other) 
{
    swap(*this, other); 

    return *this;
} //----- Fin de =
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

//----------------------------------------------------- Méthodes protégées
bool SimplePath::equals(const Path& other) const
{
    const SimplePath& other_derived = dynamic_cast<const SimplePath&>(other);
    return (strcmp(startCity, other_derived.GetStartingCity()) == 0)
        && (strcmp(endCity, other_derived.GetEndingCity()) == 0)
        && meanOfTransport == other_derived.meanOfTransport;
} //----- Fin de equals

std::ostream& SimplePath::print(std::ostream& os) const
{
	os 	<< "Trajet Simple :"													<< endl
		<< "\tDépart    : " << startCity									<< endl
		<< "\tArrivée   : " << endCity 										<< endl
		<< "\tTransport : " << MEAN_OF_TRANSPORT_STRINGS[meanOfTransport] 	<< endl;

	return os;
} //----- Fin de print

void swap(SimplePath& first, SimplePath& second)
{
    char * tmp = new char[strlen(first.GetStartingCity()) + 1];
    strcpy(tmp, first.GetStartingCity());

    delete [] first.GetStartingCity();
    first.startCity = new char[strlen(second.GetStartingCity()) + 1];
    strcpy(first.startCity, second.GetStartingCity());

    delete [] second.GetStartingCity();
    second.startCity = tmp;

    char * tmpE = new char[strlen(first.GetEndingCity()) + 1];
    strcpy(tmpE, first.GetEndingCity());

    delete [] first.GetEndingCity();
    first.endCity = new char[strlen(second.GetEndingCity()) + 1];
    strcpy(first.endCity, second.GetEndingCity());

    delete [] second.GetEndingCity();
    second.endCity = tmpE;


	MeansOfTransport tmpMot = second.meanOfTransport;
	second.meanOfTransport = first.meanOfTransport;
	first.meanOfTransport = tmpMot;
} //----- Fin de swap