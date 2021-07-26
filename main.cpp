#include "LinkedList.h"
#include "Persona.h"
int main()
{
    List<int> l1;
    l1.push_front(3);
    l1.push_back(5);
    l1.push_front(8);
    l1.push_back(10);
    l1.insert(2, 4);
    l1.push_back(9);

    for (Iterator<int> iterator = l1.begin(); iterator != l1.end(); ++iterator)
    {
        std::cout << *iterator << "-->";
    }
    std::cout << std::endl;
    l1.pop_front();
    l1.pop_back();
    List<int> l2 = l1;
    l2.push_back(15);
    for (Iterator<int> i = l2.begin(); i != l2.end(); i++)
    {
        std::cout << *i << "-->";
    }
    std::cout << std::endl;
    l2.remove(3);
    for (Iterator<int> i = l2.begin(); i != l2.end(); i++)
    {
        std::cout << *i << "-->";
    }
    std::cout << std::endl;
    Persona p1("Fabrizio", 22);
    Persona p2("Juan", 18);
    Persona p3("Leonardo", 20);
    Persona p4("Maria", 15);
    Persona p5("Melissa", 23);
    Persona p6("Carlos", 30);
    List<Persona> p;
    p.push_front(p3);
    p.push_back(p2);
    p.push_back(p1);
    p.push_back(p4);
    p.insert(2, p5);
    p.push_back(p6);
    for (Iterator<Persona> i = p.begin(); i != p.end(); i++)
    {
        std::cout << *i << "-->";
    }
    p.remove(3);
    std::cout << std::endl;
    for (Iterator<Persona> i = p.begin(); i != p.end(); i++)
    {
        std::cout << *i << "-->";
    }
}
