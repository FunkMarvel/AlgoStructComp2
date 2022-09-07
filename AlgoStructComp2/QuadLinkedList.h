#pragma once
#include "Node.h"

template <typename T>
class QuadLinkedList
{
private:
    Node<T> Head{nullptr}, Tail{nullptr}, CurrentNode{nullptr};
    size_t Size_{};
    
public:
    QuadLinkedList();
    ~QuadLinkedList();
};

template <typename T>
QuadLinkedList<T>::QuadLinkedList()
{
}

template <typename T>
QuadLinkedList<T>::~QuadLinkedList()
{
}
