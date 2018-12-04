/*************************************************************************
            Catalog  -  Affichage & Manipulation des Trajets
                             -------------------
    début                : 27/09/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Catalog> (fichier Catalog.h) ----------------
#if ! defined ( CATALOG_H )
#define CATALOG_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <string>

#include "../PathArray/PathArray.h"
#include "../SearchEngine/SearchEngine.h"
#include "../FileSerializer/FileSerializer.h"
#include "../AbstractCriterion/AbstractCriterion.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalog>
//
// La classe Catalog permet d'ajouter, d'afficher et de chercher des trajets
// via la console.
//
//------------------------------------------------------------------------
class Catalog
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void Run();
    // Mode d'emploi :
    // Affiche des différentes commandes disponible, attend les entrées utilisateurs et appelle les fonctions associées.
    //
    // Contrat :
    //

//--------------------------------------------- Constructeur & Destructeur

    Catalog();
    // Mode d'emploi :
    // Simple constructeur qui alloue une pathArray & un searchEngine
    //
    // Contrat :
    //

    virtual ~Catalog ( );
    // Mode d'emploi :
    // Simple destructeur qui désalloue pathArray & searchEngine
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées

    void save() const;
    // Mode d'emploi :
    // Demande un chemin et utilise FileSerializer pour sauvegarder les données.
    //
    // Si le fichier existe déjà, demande une confirmation.
    // Si le chemin n'est pas valide, affiche un message d'erreur.
    //
    // Contrat :
    //
    void load() const;
    // Mode d'emploi :
    // Demande un chemin et utilise FileSerializer pour charger les données.
    //
    // Si le chemin n'est pas valide, affiche un message d'erreur.
    //
    // Contrat :
    //

    void addSimplePath() const;
    // Mode d'emploi :
    // Demande des informations et ajoute un SimplePath à la collection
    //
    // Contrat :
    //
    void addComposedPath() const;
    // Mode d'emploi :
    // Demande des informations et ajoute un ComposedPath à la collection
    //
    // Contrat :
    //
    void addPathAndNotifyUser(Path * path) const;
    // Mode d'emploi :
    // Essaie d'ajouter un Path à la collection et informe l'utilisateur
    // Soit le Path est ajouté soit il existe déjà.
    //
    // Contrat :
    //

    void searchForPath(const bool advanced = false) const;
    // Mode d'emploi :
    // Demande la ville de départ et d'arrivée et lance une recherche de trajet
    //
    //      > advanced : true pour effectuer une recherche avancée, false pour
    // une recherche simple
    //
    // Contrat :
    //

    void askForStartingCity(string & startingCity) const;
    // Mode d'emploi :
    // Demande une chaine de caractères à l'utilisateur pour le champ startCity
    //
    // Contrat :
    //
    void askForEndingCity(string & endingCity) const;
    // Mode d'emploi :
    // Demande une chaine de caractères à l'utilisateur pour le champ endCity
    //
    // Contrat :
    //
    unsigned int askForStageQty() const;
    // Mode d'emploi :
    // Demande un entier positif pour créer un trajet composé de n trajets simples.
    //
    // Contrat :
    //
    
    AbstractCriterion * askForCriterion() const;
    // Mode d'emploi :
    // Demande selon quel critère sauvegarder/charger et demande les paramètres
    // nécessaires correspondants 
    //
    // Contrat :
    //

    MeansOfTransport displayAndAskForMeansOfTransport() const;
    // Mode d'emploi :
    // Affiche les differents moyens de transport et attend que l'utilisateur en selectionne un.
    //
    // Contrat :
    //

    bool getStringInput(string & input) const;
    // Mode d'emploi :
    // Récupère une entrée chaîne de caractère sur le flux standard jusqu'à rencontrer un retour à la ligne
    //
    // Contrat :

    
    bool getNumberInput(int & input) const; 
    // Mode d'emploi :
    // Récupère une entrée nombre sur le flux standard
    //
    // Contrat :

    void cleanInputStream() const;
    // Mode d'emploi :
    // Efface les données actuelles de l'entrée standard
    //
    // Contrat :
    //
    void capitalizeFirstWordsLetter(string & input) const;
    // Mode d'emploi :
    // Met en majuscule toutes les premières lettres de mots
    //
    // Contrat :
    //

    void displayMainMenu() const;
    // Mode d'emploi :
    // Affiche le menu principal.
    //
    // Contrat :
    //
    void display() const;
    // Mode d'emploi :
    // Affiche le catalogue.
    //
    // Contrat :
    //
    void displayMeansOfTransport() const;
    // Mode d'emploi :
    // Affiche les différents moyens de transport.
    //
    // Contrat :
    //

    bool askForFileOverride() const;
    // Mode d'emploi :
    // Return true si l'utilisateur répond [y/Y/yes/Yes] et false si il répond [n/N/no/No]
    //
    // Contrat :
    //

//----------------------------------------------------- Attributs protégés

    PathArray * pathArray;
    SearchEngine * searchEngine;

};

//-------------------------------- Autres définitions dépendantes de <Catalog>

#endif // CATALOG_H