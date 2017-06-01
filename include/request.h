/**
    @file
    @brief Wrapper for client request
*/
#ifndef REQUEST_H
#define REQUEST_H

#include <iostream>
#include <vector>
using namespace std;

/**
    @struct keyValue
    @brief defines key and value for request to server
*/

struct keyValue {
    string _key;
    string _value;
};
/**
    @class Request
    @brief defines a client request
*/
class Request{
    string _method;
    string _path;
    string _key;
    vector <keyValue> _keyVal;
public:
    /**
        @brief default public constructor for Request
    */
    Request();

    /**
        @brief public constructor for Request that process string as request
        @param request - string for processing request
    */
    Request(string request);

    /**
        @brief default public destructor for Request
    */
    ~Request();

    /**
        @brief get method from client Request
        @return string that defines method of Request
    */
    string method();

    /**
        @brief get path from client Request
        @return string that defines path of Request
    */
    string path();
    
    /**
        @brief get specified key and value in path from client Request
        @return vector of structs KeyValue that defines specified key and values in path of Request
    */
    vector <keyValue> keyVal();
};

#endif //REQUEST_H