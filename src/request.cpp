#include <request.h>
#include <iostream>
#include <cctype>

using namespace std;

Request::Request(){
    _method = "";
    _path = "";
}

Request::Request(string request){
    //find method
    size_t endMethod = request.find(" ");
    _method = string(request, 0, endMethod);
    //find path
    size_t endPath = request.find(" HTTP/1.");
    string path = string(request, endMethod + 1, endPath - endMethod - 1);
    _path = path;
    //parse path
    
    size_t quest = path.find("?");
    size_t equal = path.find("=");
    size_t _and = path.find("&");

    if(quest != string::npos && equal != string::npos){
        if (_and != string::npos) {
            while(_and != string::npos) {
                keyValue kv1 = {
                    ._key = string(path, quest + 1, equal - quest - 1),
                    ._value = string(path, equal + 1, _and - equal - 1)
                };
                _keyVal.push_back(kv1);
                                
                equal = path.find("=",equal+1);
                quest = path.find("&",_and+1);
                _and = path.find("&",_and+1);
            }
            size_t nextEqual = equal;
            _and = path.find("&"); 
                keyValue kv2 = {
                    ._key = string(path, _and + 1, nextEqual - _and - 1),
                    ._value = string(path, nextEqual + 1, path.length() - nextEqual)
                };
                _keyVal.push_back(kv2);
        }
        else {
            keyValue kv1 = {
                ._key = string(path, quest + 1, equal - quest - 1),
                ._value = string(path, equal + 1, path.length() - equal)
            };
            _keyVal.push_back(kv1);
        }
    } else {
        size_t slash = path.find("/", 1);
        keyValue kv = {
            ._key = "id",
            ._value = string(path, slash + 1, path.length() - slash)
        };
        _keyVal.push_back(kv);
    }
}

Request::~Request(){}

string Request::method() { return _method; }
string Request::path(){ return _path; }

vector <keyValue> Request::keyVal() {
    return _keyVal;
}