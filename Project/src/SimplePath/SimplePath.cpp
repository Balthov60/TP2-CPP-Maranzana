/*************************************************************************
             SimplePath  -  Trajet Simple entre deux villes
                             -------------------
    début                : 27/09/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <SimplePath> (fichier SimplePath.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

//------------------------------------------------------ Include personnel
#include "SimplePath.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

char * SimplePath::GetStartCity() const
{
    return startCity;
} //----- Fin de StartFrom

char * SimplePath::GetEndCity() const
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
{
    startCity = new char[strlen(other.startCity)+1];
    strcpy(startCity, other.startCity);

    endCity = new char[strlen(other.endCity)+1];
    strcpy(endCity, other.endCity);

    meanOfTransport = other.meanOfTransport;

#ifdef MAP
    cout << "Appel au constructeur de copie de <SimplePath>" << endl;
#endif
} //----- Fin de SimplePath (constructeur de copie)


SimplePath::SimplePath(char * startingCity, char * endingCity, MeansOfTransport vehicle) : meanOfTransport(vehicle)
{
    startCity = new char[strlen(startingCity)+1];
    strcpy(startCity, startingCity);

    endCity = new char[strlen(endingCity)+1];
    strcpy(endCity, endingCity);

#ifdef MAP
    cout << "Appel au constructeur de <SimplePath>" << endl;
#endif
} //----- Fin de SimplePath


SimplePath::~SimplePath()
{
   	delete[] startCity;
   	delete[] endCity;

#ifdef MAP
    cout << "Appel au destructeur de <SimplePath>" << endl;
#endif
} //----- Fin de ~SimplePath

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

bool SimplePath::equals(const Path& other) const
{
    const SimplePath& other_derived = dynamic_cast<const SimplePath&>(other);

    return (strcmp(startCity, other_derived.GetStartCity()) == 0)
        && (strcmp(endCity, other_derived.GetEndCity()) == 0)
        && meanOfTransport == other_derived.meanOfTransport;
} //----- Fin de equals

std::ostream& SimplePath::print(std::ostream& os) const
{
	os 	<< "Trajet Simple :"												<< endl
		<< "\tDépart    : " << startCity									<< endl
		<< "\tArrivée   : " << endCity 										<< endl
		<< "\tTransport : " << MEAN_OF_TRANSPORT_STRINGS[meanOfTransport] 	<< endl;

	return os;
} //----- Fin de print

void swap(SimplePath& first, SimplePath& second)
{
    char * tmp = new char[strlen(first.GetStartCity()) + 1];
    strcpy(tmp, first.GetStartCity());

    delete [] first.GetStartCity();
    first.startCity = new char[strlen(second.GetStartCity()) + 1];
    strcpy(first.startCity, second.GetStartCity());

    delete [] second.GetStartCity();
    second.startCity = tmp;

    char * tmpE = new char[strlen(first.GetEndCity()) + 1];
    strcpy(tmpE, first.GetEndCity());

    delete [] first.GetEndCity();
    first.endCity = new char[strlen(second.GetEndCity()) + 1];
    strcpy(first.endCity, second.GetEndCity());

    delete [] second.GetEndCity();
    second.endCity = tmpE;

	MeansOfTransport tmpMot = second.meanOfTransport;
	second.meanOfTransport = first.meanOfTransport;
	first.meanOfTransport = tmpMot;
} //----- Fin de swap
