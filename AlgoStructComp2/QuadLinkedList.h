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

    // Add Nodes:
    void AddNode(Node<T>& Current, Direction SideToAddAt, T ValueToAdd);
    void MoveInDirection(Node<T> Current, Direction SideToMoveTo);
    
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
void QuadLinkedList<T>::AddNode(Node<T>& Current, Direction SideToAddAt, T ValueToAdd)
{
    Node<T>* NewNode{nullptr};
    switch (SideToAddAt)
    {
    case Left:
        NewNode = Current.GetLeft();
        if(NewNode) return;
        NewNode = new Node<T>(ValueToAdd);
        Current.LeftNode = NewNode;
        NewNode->RightNode = Current;
        break;
    case Right:
        NewNode = Current.GetRight();
        if(NewNode) return;
        NewNode = new Node<T>(ValueToAdd);
        Current.RightNode = NewNode;
        NewNode->LeftNode = Current;
        break;
    case Up:
        NewNode = Current.GetUp();
        if(NewNode) return;
        NewNode = new Node<T>(ValueToAdd);
        Current.UpNode = NewNode;
        NewNode->DownNode = Current;
        break;
    case Down:
        NewNode = Current.GetDown();
        if(NewNode) return;
        NewNode = new Node<T>(ValueToAdd);
        Current.DownNode = NewNode;
        NewNode->UpNode = Current;
        break;
    }
}

template <typename T>
void QuadLinkedList<T>::MoveInDirection(Node<T> Current, Direction SideToMoveTo)
{
    switch (SideToMoveTo)
    {
    case Left:
        Current = Current.GetLeft();
        break;
    case Right:
        Current = Current.GetRight();
        break;
    case Up:
        Current = Current.GetUp();
        break;
    case Down:
        Current = Current.GetDown();
        break;
    }
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
