#ifndef __NODE_H__
#define __NODE_H__
#include <iostream>
template <typename T>
class Node;
template <typename T>
std::ostream &operator<<(std::ostream &out, const Node<T> &node);
template <typename T>
class Node
{
private:
    T value;
    Node<T> *next;

public:
    Node() : next(nullptr) {}
    Node(T data, Node<T> *ptr = nullptr) : value(data), next(ptr) {}
    void setValue(T value);
    T getValue();
    void setNext(Node<T> *next);
    Node<T> *getNext();
    friend std::ostream &operator<<<>(std::ostream &out, const Node &node);
};
template <typename T>
std::ostream &operator<<(std::ostream &out, const Node<T> &node)
{
    out << node.value;
    return out;
}
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
#endif