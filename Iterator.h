#ifndef __ITERATOR_H__
#define __ITERATOR_H__
#include "LinkedList.h"

template <typename T>
class Iterator
{
private:
    Node<T> *Position;

public:
    Iterator(Node<T> *ptr) : Position(ptr) {}
    Iterator() : Position(nullptr) {}
    Iterator operator+(const Iterator &b);
    bool operator==(const Iterator &i);
    bool operator!=(const Iterator &i);
    T operator*();
    Iterator &operator++();
    Iterator operator++(int);
};
template <typename T>
Iterator<T> Iterator<T>::operator+(const Iterator &b)
{
    while (this->Position != b.Position)
    {
        this->Position = Position->getNext();
    }
    return *this;
}
template <typename T>
bool Iterator<T>::operator==(const Iterator &i)
{
    return Position == i.Position;
}
template <typename T>
bool Iterator<T>::operator!=(const Iterator &i)
{
    return Position != i.Position;
}
template <typename T>
T Iterator<T>::operator*()
{
    return Position->getValue();
}
template <typename T>
Iterator<T> &Iterator<T>::operator++()
{
    Position = Position->getNext();
    return *this;
}
template <typename T>
Iterator<T> Iterator<T>::operator++(int)
{
    Iterator temp = *this;
    Position = Position->getNext();
    return temp;
}
#endif