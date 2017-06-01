/**
    @file
    @brief Module to parse data to Json string
*/
#ifndef PARSERJSON_H
#define PARSERJSON_H

#include <iostream>
#include <vector>
#include <actor.h>
#include <request.h>

using namespace std;

/**
    @brief get server information
    @return string in Json format that contain information about server
*/
string parseServerInfo(void);

/**
    @brief get all Actors in Json fromat
    @param Actors - vector of Actors to parse in Json
    @return string in Json format that contain information about all Actors
*/
string parseActors(vector<Actor*> Actors);

/**
    @brief get Actors that specified filed equals specified value
    @param Actors - vector of Actors to filter and parse in Json 
    @param keyValue - field on which to filter Actors
    @param value - content of field to filter Actors
    @return string in Json format that contain information about server
*/
string parseActorsByKey(vector<Actor*> Actors, vector<keyValue> KeyVal);

/**
    @brief get information about file
    @param filePath - path to file
    @return string in Json format that contain information about file
*/
string parseFileInfo(string filePath);

/**
    @brief get information about file content
    @param filePath - path to file
    @return string in Json format that contain information about file content
*/
string parseFileContent(string filePath);

#endif //PARSERJSON_H