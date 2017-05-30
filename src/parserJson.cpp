#include <parserJson.h>
#include <iostream>
#include <vector>
#include <jansson.h>
#include <time.h>
#include <fstream>
#include <cctype>
#include <string.h>

using namespace std;

/**
    @brief subsidiary function to read file
    @param filePath - path to file that will be read
    @return string that represented content of file
*/
string readFile(string filePath);

string parseServerInfo(void){
    json_t * json = json_object();
    json_object_set_new(json, "title", json_string("HTTP Server with my favorite actors"));
    json_object_set_new(json, "developer",json_string( "Paul Burchak"));
    time_t seconds = time(0);
    tm* timeinfo = localtime(&seconds);
    string t = string(asctime(timeinfo));
    const char * correct = t.erase(t.length() - 1, t.length()).c_str();
    json_object_set_new(json, "time", json_string(correct));
    char * str = json_dumps(json, JSON_INDENT(2) | JSON_PRESERVE_ORDER);
    string jsonString(str);
    free(str);
    json_decref(json);
    return jsonString;
}

string parseActors(vector<Actor*> Actors){
    json_t * json = json_array();
    for(Actor * Actor : Actors){
        json_t * pl = json_object();
        json_object_set_new(pl, "id", json_integer(Actor->id()));
        json_object_set_new(pl, "name", json_string(Actor->name().c_str()));
        json_object_set_new(pl, "age", json_integer(Actor->age()));
        json_object_set_new(pl, "nation", json_string(Actor->nation().c_str()));
        json_array_append(json, pl);
        json_decref(pl);
    }
    char * str = json_dumps(json, JSON_INDENT(2) | JSON_PRESERVE_ORDER);
    string jsonString(str);
    free(str);
    json_decref(json);
    return jsonString;
}

string parseActorsByKey(vector<Actor*> Actors, string key, string value){
    if(Actors[0]->valueByField(key) != "NOT FIELD"){
        json_t * json = json_array();
        bool isFound = false;
        for(Actor * Actor : Actors){
            if(Actor->valueByField(key) == value){
                isFound = true;
                json_t * pl = json_object();
                json_object_set_new(pl, "id", json_integer(Actor->id()));
                json_object_set_new(pl, "name", json_string(Actor->name().c_str()));
                json_object_set_new(pl, "age", json_integer(Actor->age()));
                json_object_set_new(pl, "nation", json_string(Actor->nation().c_str()));
                json_array_append(json, pl);
                json_decref(pl);
            } 
        }
        char * str = json_dumps(json, JSON_INDENT(2) | JSON_PRESERVE_ORDER);
        string jsonString(str);
        free(str);
        json_decref(json);
        if(!isFound) return "NOT FOUND";
        return jsonString;
    } else {
        return "NOT FOUND";
    }
    
}

string parseFileInfo(string filePath){
    string fileContent = readFile(filePath.c_str());
    if (fileContent == "NOT FOUND") {
        cerr << "Can't open file" << endl;
        return fileContent;
    }
    json_t * json = json_object();
    json_object_set_new(json, "filename", json_string( "data.txt"));
    json_object_set_new(json, "size(bytes)",json_integer(fileContent.size()));
    json_object_set_new(json, "content",  json_string(fileContent.c_str()));
    char * str = json_dumps(json, JSON_INDENT(2) | JSON_PRESERVE_ORDER);
    string jsonString(str);
    free(str);
    json_decref(json);
    return jsonString;
}
string parseFileContent(string filePath){
   vector<double> numbers;
    double num = 0.0;
    bool secondDot = false;
    bool exist = false; 
    int i = 0;

    string fileStr = readFile(filePath.c_str());
    if (fileStr == "NOT FOUND") {
        cerr << "Can't open file" << endl;
        return fileStr;
    }
    while(fileStr[i]){
        if(isdigit(fileStr[i])){
            exist = true;
        }
        i++;
    }

const char*charArray = fileStr.c_str(); // array of chars

    if(exist == true){
        i = 0;
        while(charArray[i] != '\0'){
            if(isdigit(charArray[i]) || (charArray[i] == '-' && isdigit(charArray[i + 1]))){
                num = atof(charArray + i);
                numbers.push_back(num); 
                while(isdigit(charArray[i + 1]) || (charArray[i + 1] == '.' && secondDot == false)){
                    i++;
                    if(charArray[i] == '.'){
                        secondDot = true;
                    }
                }
                i++;
                secondDot = false;
            }
            else i++;
        }
    }

    json_t * json = json_object();
    json_object_set_new(json, "filename", json_string( "data.txt"));
    json_object_set_new(json, "number of numbers",json_integer(numbers.size()));
    json_t* arr = json_array();
    for(unsigned int i = 0; i < numbers.size(); i++) {
        json_t * item = json_object();
        json_object_set_new(item, "number" , json_integer(numbers[i]));
        json_array_insert_new(arr,i,item);
    }
    json_object_set_new(json, "numbers", arr);
    char * str = json_dumps(json, JSON_INDENT(2) | JSON_PRESERVE_ORDER);
    string jsonString(str);
    free(str);
    json_decref(json);
    return jsonString;
}


string readFile(string filePath){
    string buf;
    string result = "";
    ifstream myfile (filePath);
    if (!myfile.is_open()){
        return "NOT FOUND";
    }
    while (!myfile.eof()){
        getline(myfile, buf);
        result += buf;
    }
    myfile.close();
    return result;
}