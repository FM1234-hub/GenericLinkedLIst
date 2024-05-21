#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include "Iterator.h"
template <typename T>
class List;
template <typename T>
std::ostream &operator<<(std::ostream &os, const List<T> &o);
template <typename T>
class List
{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    List(); // default constructor
    List(const List<T> &o);
    List(List<T> &&o) : size{o.size}, head{o.head}, tail{o.tail}
    {
        o.size = 0;
        o.head = nullptr;
        o.tail = nullptr;
    }
    ~List(); // Destructor
    int getSize() const;
    void push_front(T value);
    void push_back(T append);
    void insert(int pos, T value);
    void pop_front();
    void pop_back();
    void remove(int pos);
    void eliminar(T value);
    bool find(T value);
    bool isempty();
    void printLots(List<T> P);
    List &operator=(const List<T> &o);
    Iterator<T> begin();
    Iterator<T> end();
    template <typename U>
    friend class Iterator;
    friend std::ostream &operator<< <>(std::ostream &os, const List &o);
};
// Cout overloading
template <typename T>
std::ostream &operator<<(std::ostream &os, const List<T> &o)
{
    Node<T> *currentNode = o.head;
    if (!currentNode)
    {
        os << "The list is empty"
           << "\n";
    }
    while (currentNode != nullptr)
    {
        if (currentNode->getNext() == nullptr)
        {
            os << currentNode->getValue();
            currentNode = currentNode->getNext();
        }
        else
        {
            os << currentNode->getValue() << "-->";
            currentNode = currentNode->getNext();
        }
    }
    return os;
}
// Iterators
template <typename T>
Iterator<T> List<T>::begin()
{
    return Iterator<T>(head);
}
template <typename T>
Iterator<T> List<T>::end()
{
    return Iterator<T>(tail);
}
// Constructors
template <typename T>
List<T>::List()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}
template <typename T>
List<T>::List(const List<T> &o)
{
    this->head = nullptr;
    this->tail = nullptr;
    this->size = o.size;
    for (Iterator<T> i = o.head; i != o.tail; i++)
    {
        this->push_back(*i);
    }
}
// Assignment operator
template <typename T>
List<T> &List<T>::operator=(const List<T> &o)
{
    List copy = o;
    std::swap(*this, copy);
    return *this;
}

// Destructor
template <typename T>
List<T>::~List()
{
    Node<T> *currentNode = head;
    while (currentNode != nullptr)
    {
        head = head->getNext();
        delete currentNode;
    }
}
// Removing
template <typename T>
void List<T>::pop_front()
{
    if (head)
    {
        Node<T> *temp = head;
        head = head->getNext();
        delete temp;
        size--;
    }
}
template <typename T>
void List<T>::remove(int pos)
{
    if (head)
    {
        Node<T> *currentNode = head;
        if (pos == 1)
        {
            head = head->getNext();
            delete currentNode;
        }
        else
        {
            Node<T> *previousNode = nullptr;
            while (pos != 1)
            {
                previousNode = currentNode;
                currentNode = currentNode->getNext();
                pos--;
            }
            previousNode->setNext(currentNode->getNext());
            delete currentNode;
        }
        size--;
    }
}
template <typename T>
bool List<T>::isempty()
{
    if (this->head == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <typename T>
void List<T>::eliminar(T value)
{
    if (this->head)
    {
        Node<T> *currentNode = this->head;
        if (this->head->value == value)
        {
            this->head = currentNode->getNext();
            delete currentNode;
        }
        Node<T> *previousNode = nullptr;
        while (currentNode->getNext())
        {
            previousNode = currentNode;
            if (currentNode->value == value)
            {
                previousNode->setNext(currentNode->getNext());
                delete currentNode;
                size--;
            }
            currentNode = previousNode->getNext();
        }
    }
}

template <typename T>
bool List<T>::find(T value)
{
    if (this->head->value == value)
    {
        return true;
    }
    Node<T> *currentNode = this->head;
    while (currentNode->getNext() != nullptr)
    {
        if (currentNode->value == value)
        {
            return true;
        }
        currentNode = currentNode->getNext();
    }
    return false;
}
template <typename T>
void List<T>::printLots(List<T> P)
{
    Node<T> *currentNode = this->head;
    Node<T> *currentNode2 = P.head;
    int i = 1;
    while (currentNode && currentNode2)
    {
        if (i = currentNode2->value)
        {
            std::cout << currentNode->value << std::endl;
            currentNode2 = currentNode2->getNext();
        }
        currentNode = currentNode->getNext();
        i++;
    }
}
template <typename T>
void List<T>::pop_back()
{
    if (head != nullptr)
    {
        Node<T> *currentNode = head;
        Node<T> *previousNode = nullptr;
        if (head->getNext() == nullptr)
        {
            delete head;
        }
        else
        {
            while (currentNode->getNext() != nullptr)
            {
                previousNode = currentNode;
                currentNode = currentNode->getNext();
            }
            previousNode->setNext(nullptr);
            delete currentNode;
        }
        size--;
    }
}
// Insertion
template <typename T>
void List<T>::push_front(T value)
{
    Node<T> *newNode = new Node<T>(value);
    if (!head)
    {
        head = newNode;
    }
    else
    {
        newNode->setNext(head);
        head = newNode;
    }
    size++;
}
template <typename T>
void List<T>::push_back(T value)
{
    Node<T> *newNode = new Node<T>(value);
    if (!head)
    {
        head = newNode;
    }
    else
    {
        Node<T> *currentNode = head;
        while (currentNode->getNext())
        {
            currentNode = currentNode->getNext();
        }
        currentNode->setNext(newNode);
    }
    size++;
}
template <typename T>
void List<T>::insert(int pos, T value)
{
    Node<T> *newNode = new Node<T>(value);
    if (!head && pos == 1)
    {
        head = newNode;
    }
    else if (head != nullptr && pos == 1)
    {
        this->push_front(value);
    }
    else if ((this->size + 1) == pos)
    {
        this->push_back(value);
    }
    else if (!head && pos != 1)
    {
        return;
    }
    else if (pos > this->size)
    {
        return;
    }
    else
    {
        Node<T> *currentNode = head;
        Node<T> *previousNode = nullptr;
        while (pos != 1)
        {
            previousNode = currentNode;
            currentNode = currentNode->getNext();
            pos--;
        }
        newNode->setNext(currentNode);
        previousNode->setNext(newNode);
    }
    size++;
}
// Accesors
template <typename T>
int List<T>::getSize() const
{
    return size;
}

#endif // LINKEDLIST_H
