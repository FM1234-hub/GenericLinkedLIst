#ifndef __Persona_H__
#define __Persona_H__
#include <iostream>
class Persona
{
private:
    std::string name;
    int age;

public:
    Persona(std::string name, int age);
    //Persona(const Persona &o);
    ~Persona();
    std::string getName();
    void setName(std::string name);
    friend std::ostream &operator<<(std::ostream &os, const Persona &pe);
};
Persona::Persona(std::string name, int age)
{
    this->name = name;
    this->age = age;
}
Persona::Persona(const Persona &o)
{
    this->name = o.name;
    this->age = o.age;
}
Persona::~Persona()
{
}
std::ostream &operator<<(std::ostream &os, const Persona &pe)
{
    os << pe.name << " ";
    os << pe.age << " ";
    return os;
}
void Persona::setName(std::string name)
{
    this->name = name;
}
std::string Persona::getName()
{
    return this->name;
}
#endif