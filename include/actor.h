/**
    @file
    @brief Data about favorite Actor
*/
#ifndef Actor_H
#define Actor_H

#include <iostream>

using namespace std;

/**
    @class Actor
    @brief defines a favorite Actor
*/
class Actor{
    int _id;
    string _name;
    string _nation;
    int _age;
public:
    /**
        @brief default public constructor for Actor
    */
    Actor();

    /**
        @brief default public destructor for Actor
    */
    ~Actor();

    /**
        @brief public constructor for Actor that fill all fields in Actor
        @param id - unique number of Actor
        @param name - name of Actor
        @param nation - nationality of Actor
        @param age - Actor's age
    */
    Actor(int id, string name, string nation, int age);

    /**
        @brief get id of Actor
        @return string that represents unique number of Actor
    */
    int id();

    /**
        @brief get name of Actor
        @return string that represents name of Actor
    */
    string name();

    /**
        @brief get nation of Actor
        @return string that represents nationality of Actor
    */
    string nation();

    /**
        @brief get age of Actor
        @return string that represents age of Actor
    */
    int age();

    /**
        @brief get value that contain specified filed of Actor
        @param field - string that defines field which value returns
        @return string that represents value at specified field
    */
    string valueByField(string field);
};

#endif