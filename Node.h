#ifndef NODE_H
#define NODE_H

#include <iostream>
template <typename T>
class Node
{
private:
    T value;
    Node<T> *next;
    template <typename U>
    friend class List;

public:
    Node() : next(nullptr) {}
    Node(T data, Node<T> *ptr = nullptr) : value(data), next(ptr) {}
    void setValue(T value);
    T getValue();
    void setNext(Node<T> *next);
    Node<T> *getNext();
};
template <typename T>
void Node<T>::setValue(T value)
{
    this->value = value;
}
template <typename T>
T Node<T>::getValue()
{
    return value;
}
template <typename T>
void Node<T>::setNext(Node<T> *next)
{
    this->next = next;
}
template <typename T>
Node<T> *Node<T>::getNext()
{
    return next;
}

#endif // NODE_H
