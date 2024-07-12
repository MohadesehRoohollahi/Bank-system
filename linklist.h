#ifndef LINKLIST_H
#define LINKLIST_H

#include <string>
#include "account.h"

template<typename T>
class Node{
private:
    T data;
    Node<T> * next;
    Node<T> * previous;
public:
    Node();
    Node(const T & data);
    void setData(T data);
    void setNext(Node<T> * next);
    void setPrevious(Node<T> * previous);
    T & getData();
    Node<T>* getNext();
    Node<T>* getPrevious();
};

//-----------------------------------------------------

template<typename T>
class LinkList
{
private:
    Node<T> * head;
    Node<T> * tail;
    int size;
public:
    LinkList();
    LinkList(const LinkList<T> & that);
    void pushBack(T data);
    int getSize();
    void clear();
    Node<T>* getHead();
    ~LinkList();
};

//-----------------------------------------------------

template<typename T>
Node<T>::Node() {
    next = nullptr;
    previous = nullptr;
}

template<typename T>
Node<T>::Node(const T& data){
    this->data = data;
    this->next = nullptr;
    this->previous = nullptr;
}

template<typename T>
void Node<T>::setData(T data) {
    this->data = data;
}

template<typename T>
void Node<T>::setNext(Node<T> * next) {
    this->next = next;
}

template<typename T>
void Node<T>::setPrevious(Node<T> * previous) {
    this->previous = previous;
}

template<typename T>
T& Node<T>::getData() {
    return this->data;
}

template<typename T>
Node<T> * Node<T>::getNext() {
    return this->next;
}

template<typename T>
Node<T> * Node<T>::getPrevious() {
    return this->previous;
}


//--------------------------------------------------------------------------------


template<typename T>
LinkList<T>::LinkList() {
    size = 0;
    head = nullptr;
    tail= nullptr;
}

template<typename T>
LinkList<T>::LinkList(const LinkList<T>& that){
    head = nullptr;
    tail = nullptr;
    size = 0;
    Node<T>* current = that.head;
    while (current != nullptr) {
        pushBack(current->getData());
        current = current->getNext();
    }
}

template<typename T>
Node<T>* LinkList<T>::getHead() {
    return head;
}

template<typename T>
int LinkList<T>::getSize() {
    return size;
}

template<typename T>
void LinkList<T>::pushBack(T data) {
    Node<T> * tmp = new Node<T>;
    tmp->setData(data);
    if(head == nullptr){
        head = tail = tmp;
    }
    else{
        tmp->setPrevious(tail);
        tail->setNext(tmp);
        tail = tmp;
    }
    size++;
}

template<typename T>
void LinkList<T>::clear() {
    Node<T> *tmp = head;

    while (tmp != nullptr) {
        Node<T> * tmp2 = tmp;
        tmp = tmp->getNext();
        delete tmp2;
    }

    size = 0;
    head = nullptr;
    tail = nullptr;
}

template<typename T>
LinkList<T>::~LinkList() {
    clear();
}

#endif // LINKLIST_H
