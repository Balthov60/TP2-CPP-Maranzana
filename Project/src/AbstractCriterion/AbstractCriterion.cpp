/*************************************************************************
                           AbstractCriterion  -  description
                             -------------------
    début                : 28/11/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <AbstractCriterion> (fichier AbstractCriterion.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "AbstractCriterion.h"
using namespace std;
//------------------------------------------------------------- Constantes
const char * AbstractCriterion::METADATA_DELIMITER = "|";
const char * AbstractCriterion::COMPOSED_PATH_FLAG = ":";
const char * AbstractCriterion::PATH_DELIMITER = ";";
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
AbstractCriterion::AbstractCriterion ( const AbstractCriterion & other )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <AbstractCriterion>" << endl;
#endif
} //----- Fin de AbstractCriterion (constructeur de copie)


AbstractCriterion::AbstractCriterion ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <AbstractCriterion>" << endl;
#endif
} //----- Fin de AbstractCriterion


AbstractCriterion::~AbstractCriterion ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <AbstractCriterion>" << endl;
#endif
} //----- Fin de ~AbstractCriterion


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

