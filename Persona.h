#ifndef __Persona_H__
#define __Persona_H__
#include <iostream>
using namespace std;
class Persona
{
private:
    string name;
    int age;

public:
    Persona(string name, int age);
    ~Persona();
    string getName();
    void setName(std::string name);
    friend ostream &operator<<(ostream &os, const Persona &pe);
};
Persona::Persona(string name, int age)
{
    this->name = name;
    this->age = age;
}
Persona::~Persona()
{
}
ostream &operator<<(ostream &os, const Persona &pe)
{
    os << pe.name << " ";
    os << pe.age << " ";
    return os;
}
void Persona::setName(string name)
{
    this->name = name;
}
string Persona::getName()
{
    return this->name;
}
#endif