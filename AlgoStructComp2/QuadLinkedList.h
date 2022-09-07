#pragma once
#include "Node.h"

/**
 * \brief Quadruple linked list
 * \tparam T Data type of elements
 */
template <typename T>
class QuadLinkedList
{
private:
    Node<T>* Head{nullptr}, Tail{nullptr}, CurrentNode{nullptr};
    size_t Size_{};
    
public:
    QuadLinkedList();
    explicit QuadLinkedList(T NewValue);
    ~QuadLinkedList();
};

template <typename T>
QuadLinkedList<T>::QuadLinkedList()
{
}

template <typename T>
QuadLinkedList<T>::QuadLinkedList(T NewValue)
{
    Head = Tail = CurrentNode = new Node<T>(NewValue);
    
    Size_++;
}

template <typename T>
QuadLinkedList<T>::~QuadLinkedList()
{
}
