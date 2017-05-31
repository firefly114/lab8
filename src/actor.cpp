#include <actor.h>

Actor::Actor() {
    _id = -1;
    _name = "";
    _nation = "";
    _age = -1;
}

Actor::~Actor() {}

Actor::Actor(int id, string name, string nation, int age) {
    _id = id;
    _name = name;
    _nation = nation;
    _age = age;
}


int Actor::id(){ return _id; }
string Actor::name(){ return _name; }
string Actor::nation(){ return _nation; }
int Actor::age(){ return _age; }
string Actor::valueByField(string field) {
    if(field == "id") return to_string(_id);
    if(field == "age") return to_string(_age);
    if(field == "name") return _name;
    if(field == "nation") return _nation;
    return "NOT FIELD";
}