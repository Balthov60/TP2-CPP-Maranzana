/*************************************************************************
                           ComposedPath  -  description
                             -------------------
    début                : 27/09/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <ComposedPath> (fichier ComposedPath.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using std::cout;
using std::endl;
//------------------------------------------------------ Include personnel
#include "ComposedPath.h"
//------------------------------------------------------------- Constantes
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
PathArray* ComposedPath::GetElements ( ) const
// Algorithme :
{
    return elements;
} //----- Fin de GetElements

void ComposedPath::AddStage(Path *path) const
// Algorithme :
{
    elements->Add(path);
} //----- Fin de AddStage

char * ComposedPath::GetStartingCity() const
{
    return elements->Get(0)->GetStartingCity();
} //----- Fin de StartFrom

char * ComposedPath::GetEndingCity() const
{
    return elements->Get(elements->GetCurrentCard() - 1)->GetEndingCity();
} //----- Fin de StopAt

ComposedPath* ComposedPath::Clone() const
{
    return new ComposedPath(*this);
} //----- Fin de Clone

//------------------------------------------------- Surcharge d'opérateurs
ComposedPath& ComposedPath::operator=(ComposedPath& other) 
{
    swap(*this, other); 

    return *this;
} //----- Fin de =

//-------------------------------------------- Constructeurs - destructeur
ComposedPath::ComposedPath ( const ComposedPath & other )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ComposedPath>" << endl;
#endif
    elements = new PathArray();
    *elements = *other.elements;
} //----- Fin de ComposedPath (constructeur de copie)


ComposedPath::ComposedPath ( unsigned int cardMax)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ComposedPath>" << endl;
#endif
    elements = new PathArray(cardMax);
} //----- Fin de ComposedPath


ComposedPath::~ComposedPath ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ComposedPath>" << endl;
#endif
    delete elements;
} //----- Fin de ~ComposedPath


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
bool ComposedPath::equals(const Path& other) const
{
    const ComposedPath& other_derived = dynamic_cast<const ComposedPath&>(other);
    return elements->Equals(*other_derived.elements);
} //----- Fin de equals

std::ostream& ComposedPath::print(std::ostream& os) const
{
    os << "Trajet Composé :" << endl;

	return elements->Print(os);
} //----- Fin de print

void swap(ComposedPath& first, ComposedPath& second)
{
	PathArray tmp = *(first.elements);
	*(first.elements) = *(second.elements);
	*(second.elements) = tmp;
} //----- Fin de swap