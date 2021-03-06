/*************************************************************************
                     ComposedPath  -  trajet composé
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

const char * ComposedPath::GetStartCity() const
{
    return elements->Get(0)->GetStartCity();
} //----- Fin de StartFrom

const char * ComposedPath::GetEndCity() const
{
    return elements->Get(elements->GetSize() - 1)->GetEndCity();
} //----- Fin de StopAt

ComposedPath* ComposedPath::Clone() const
{
    return new ComposedPath(*this);
} //----- Fin de Clone

string ComposedPath::Serialize() const
{
    string serialized = "";
    serializationIndentationQty++;

    for (unsigned int i = 0; i < elements->GetSize(); i++)
    {
        if (i != 0)
        {
            for (int j = 0; j < serializationIndentationQty; j++)
                serialized += "\t";
        }

        serialized += elements->Get(i)->Serialize();

        if (i == 0)
            serialized.append(":").append(GetEndCity());

        if (i != elements->GetSize() - 1)
            serialized += "\r\n";
    }

    if (serializationIndentationQty > 0)
        serializationIndentationQty--;

    return serialized;
}

//------------------------------------------------- Surcharge d'opérateurs
ComposedPath& ComposedPath::operator=(ComposedPath other) 
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
    elements = new PathArray;
    *elements = *other.elements;
} //----- Fin de ComposedPath (constructeur de copie)


ComposedPath::ComposedPath ( unsigned int maxSize)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ComposedPath>" << endl;
#endif
    elements = new PathArray(maxSize);
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

int ComposedPath::serializationIndentationQty = 0;

//----------------------------------------------------- Méthodes protégées
bool ComposedPath::equals(const Path& other) const
{
    const ComposedPath& other_derived = dynamic_cast<const ComposedPath&>(other);
    return elements->Equals(*other_derived.elements);
} //----- Fin de equals

std::ostream& ComposedPath::print(std::ostream& os) const
{
    os << "Trajet Composé :" << endl;

	return elements->Print(os, false, true);
} //----- Fin de print

void swap(ComposedPath& first, ComposedPath& second)
{
	PathArray tmp = *(first.elements);
	*(first.elements) = *(second.elements);
	*(second.elements) = tmp;
} //----- Fin de swap
