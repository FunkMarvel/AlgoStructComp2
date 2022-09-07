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
    
    Node<T>* GetHead();
    Node<T>* GetUp(Node<T> Current);
    
    Node<T>* TraverseList();
};

/**
 * \brief Construct empty list.
 */
template <typename T>
QuadLinkedList<T>::QuadLinkedList()
{
}

/**
 * \brief Construct list with single node.
 * \param NewValue Data to store in initial node.
 */
template <typename T>
QuadLinkedList<T>::QuadLinkedList(T NewValue)
{
    Head = Tail = CurrentNode = new Node<T>(NewValue);
    Size_++;
}

/**
 * \brief Delete all nodes and free data.
 */
template <typename T>
QuadLinkedList<T>::~QuadLinkedList()
{
}

template <typename T>

Node<T>* QuadLinkedList<T>::GetHead()
{
    return Head;
}

template <typename T>
Node<T>* QuadLinkedList<T>::GetUp(Node<T> Current)
{
    return CurrentNode.UpNode;
}

template <typename T>
Node<T>* QuadLinkedList<T>::TraverseList()
{
    for (int i = 0; i < Size_; ++i)
    {
        for (int i = 0; i < Size_; ++i)
        {
        CurrentNode = Head;
        CurrentNode.RightNode = Head->RightNode;
        }
    }
}
