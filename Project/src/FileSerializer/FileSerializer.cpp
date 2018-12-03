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
#include <cstring>
//------------------------------------------------------ Include personnel
#include "FileSerializer.h"

//------------------------------------------------------------- Constantes
const int MAX_LINE_SIZE = 1024;
const int MAX_FIELD_SIZE = 256;
const int FIELD_QTY = 3;
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

FileSerializer * FileSerializer::getInstance()
{
    if (!instance)
        instance = new FileSerializer;

    return instance;
}

void FileSerializer::Save(PathArray * pathArray, const char * path, AbstractCriterion & criterion)
{
    ofstream file;
    file.open(path);

    // Meta
    int composedPathQty = 0;
    int simplePathQty = 0;
    string startCityList("");
    string endCityList("");

    //Data
    string data("");

    for (unsigned int i = 0; i < pathArray->GetSize(); i++)
    {
        const Path *path = pathArray->Get(i);

        if (criterion.CheckPath(path))
        {
            data.append(path->Serialize());
            data.append("\r\n");

            (dynamic_cast<const ComposedPath *>(path) == nullptr) ? simplePathQty++ : composedPathQty++;

            if (startCityList.find(path->GetStartCity()) == string::npos)
            {
                startCityList.append(path->GetStartCity());
                startCityList.append(";");
            }

            if (endCityList.find(path->GetEndCity()) == string::npos)
            {
                endCityList.append(path->GetEndCity());
                endCityList.append(";");
            }
        }
    }

    file << simplePathQty << "|" << composedPathQty << "|" << startCityList << "|" << endCityList << std::endl;
    file << data;
    file.close();
}

bool FileSerializer::Load(PathArray * pathArray, const char * path, AbstractCriterion & criterion)
{
    ifstream file;
    file.open(path);

    char line[MAX_LINE_SIZE] = "";
    string object("");

    // First Metadata Line
    file.getline(line, MAX_LINE_SIZE);

    if (!criterion.CheckMetadata(line))
        return true;

    try
    {
        while(file.getline(line, MAX_LINE_SIZE))
        {
            if (line[0] == '\t') // If you find \t that means Composed Path must be Skipped
                continue;

            if (!criterion.CheckLine(line))
                    continue;

            processLine(pathArray, &file, line);
        }
    }
    catch (const std::invalid_argument & e)
    {
       file.close();
       cerr << e.what();

       return false;
    }

    file.close();
    return true;
}

bool FileSerializer::FileExist(const char path[])
{
    ifstream f(path);
    return f.good();
}

bool FileSerializer::FileCanBeCreated(const char path[])
{
    ofstream f(path);
    return f.is_open();
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

void FileSerializer::processLine(PathArray * pathArray, ifstream * file, char line[MAX_LINE_SIZE])
// Algorithme
// Prend une ligne du fichier
//      SI la ligne représente un trajet simple, envoi la ligne dans deserialize()
//      SI la ligne représente le début d'un trajet composé, récupère le reste des données et utilise deserialize
//
// Une fois l'objet deserializé, il est ajouté au catalogue (pathArray).
{
    if (strstr(line, ":") == nullptr)
    {
        pathArray->Add(deserialize(line));
        return;
    }

    ComposedPath * composedPath = new ComposedPath();
    composedPath->AddStage(deserialize(line));

    while (file->getline(line, MAX_LINE_SIZE))
    {
        if (line[0] != '\t')
        {
            pathArray->Add(composedPath);

            processLine(pathArray, file, line);
            return;
        }
        try
        {
            composedPath->AddStage(deserialize(line));
        }
        catch (const std::invalid_argument & e)
        {
            delete composedPath;
            throw e;
        }
    }
    pathArray->Add(composedPath); // In Case file end with a composed path.
}

Path * FileSerializer::deserialize(string object)
{
    object = removeIndentationAndMetadata(object);

    char values[FIELD_QTY][MAX_FIELD_SIZE];
    size_t lastPos = 0;

    for (int i = 0; i < 3; i++)
    {
        size_t pos = object.find(";", lastPos);

        if (pos == string::npos)
            throw std::invalid_argument("Le contenu du fichier n'est pas valide...");

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