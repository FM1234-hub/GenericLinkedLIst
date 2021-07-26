#include "LinkedList.h"

//Copy, move constructor
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
}