/*************************************************************************
                           FileSerializer  -  description
                             -------------------
    début                : 28/11/2018
    copyright            : (C) 2018 par Valentin Wallyn et Balthazar Frolin
    e-mail               : ...@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <FileSerializer> (fichier FileSerializer.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "FileSerializer.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

FileSerializer * FileSerializer::getInstance()
{
    if (!instance)
        instance = new FileSerializer;

    return instance;
}

void FileSerializer::save(PathArray * pathArray, const char * path/*, AbstractCriterion criterion*/)
{
    ofstream file;
    file.open(path);

    string data = string();
    int composedPathQty = 0;
    int simplePathQty = 0;

    for (int i = 0; i < pathArray->GetSize(); i++)
    {
        const Path *path = pathArray->Get(i);

        if (true /*criterion.CheckPath(path)*/)
        {
            data.append(path->Serialize()).append("\r\n");
            (typeid(path) == typeid(SimplePath)) ? simplePathQty++ : composedPathQty++;
        }
    }

    file << simplePathQty << ";" << composedPathQty << std::endl;
    file << data;
    file.close();
}

void FileSerializer::load(PathArray * pathArray, const char * path/*, AbstractCriterion criterion*/)
{
    ifstream file;
    file.open(path);

    char line[1024] = "";
    string object = string();

    // First Metadata Line
    file.getline(line, 1024);
    /*
    if (!criterion.CheckMetadata(line)
        return;
    */

    while(file.getline(line, 1024))
    {
        if (line[0] == '\t') // If you find \t that mean Composed Path must be Skipped
            continue;

        /*
        if (!criterion.checkLine(line))
            continue;
        */

        processLine(pathArray, &file, line);
    }

    file.close();
}

void FileSerializer::processLine(PathArray * pathArray, ifstream * file, char line[1024])
{
    if (strstr(line, ":") == NULL)
    {
       pathArray->Add(deserialize(line));
       return;
    }

    ComposedPath * composedPath = new ComposedPath();

    do {
        if (line[0] != '\t' && strstr(line, ":") == NULL)
        {
            pathArray->Add(composedPath);

            processLine(pathArray, file, line);
            return;
        }

        composedPath->AddStage(deserialize(line));
    }
    while (file->getline(line, 1024));
}

Path * FileSerializer::deserialize(string object)
{
    object = removeIndentationAndMetadata(object);

    char values[3][256];
    size_t lastPos = 0;

    for (int i = 0; i < 3; i++)
    {
        size_t pos = object.find(";", lastPos);
        strcpy(values[i], object.substr(lastPos, pos - lastPos).data());
        lastPos = pos + 1;
    }

    return new SimplePath(values[0], values[2], (MeansOfTransport) stoi(values[1]));
}
string FileSerializer::removeIndentationAndMetadata(string object)
{
    size_t first = object.find_last_of("\t");
    size_t last = object.find_last_of(":");

    if (first == string::npos)
        first = -1;

    if (last == string::npos)
        last = object.size();

    return object.substr(first + 1, last - first - 1);
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

FileSerializer::FileSerializer ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <FileSerializer>" << endl;
#endif
} //----- Fin de FileSerializer


FileSerializer::~FileSerializer ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <FileSerializer>" << endl;
#endif
} //----- Fin de ~FileSerializer


//------------------------------------------------------------------ PRIVE

FileSerializer * FileSerializer::instance = nullptr;

//----------------------------------------------------- Méthodes protégées

