#pragma once
#include <ostream>

#include "Node.h"

/**
 * \brief Quadruple linked list
 * \tparam T Data type of elements
 */
template <typename T>
class QuadLinkedList
{

    Node<T>* Head{nullptr};
    Node<T>* Tail{nullptr};
    Node<T>* CurrentNode{nullptr};
    size_t Size_{};
    
public:
    QuadLinkedList();
    explicit QuadLinkedList(T NewValue);
    ~QuadLinkedList();
    
    T& GetHead() {return Head->Value;}
    T& GetCurrent() {return CurrentNode->Value;}
    friend std::ostream& operator<<(std::ostream& os, QuadLinkedList& SomeList)
    {
        os << SomeList.GetCurrent();
        return os;
    } 

    // Add Nodes:
    void AddNode(T ValueToAdd, Direction SideToAddAt);
    T& MoveToHead();
    T& MoveInDirection(Direction DirectionToMoveIn);
    T& MoveInDirection(Direction DirectionToMoveIn, size_t NumberOfSteps);
    
    // Node<T>* TraverseList();
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
void QuadLinkedList<T>::AddNode(T ValueToAdd, Direction SideToAddAt)
{
    if (Size_ <= 0) {Head = Tail = CurrentNode = new Node<T>(ValueToAdd); Size_++;}
    
    Node<T>* NewNode{nullptr};
    switch (SideToAddAt)
    {
    case Left:
        if (CurrentNode->LeftNode) return;
        NewNode = CurrentNode->LeftNode = new Node<T>(ValueToAdd);
        NewNode->RightNode = CurrentNode;
        break;
    case Right:
        if (CurrentNode->RightNode) return;
        NewNode = CurrentNode->RightNode = new Node<T>(ValueToAdd);
        NewNode->LeftNode = CurrentNode;
        break;
    case Up:
        if (CurrentNode->UpNode) return;
        NewNode = CurrentNode->UpNode = new Node<T>(ValueToAdd);
        NewNode->DownNode = CurrentNode;
        break;
    case Down:
        if (CurrentNode->DownNode) return;
        NewNode = CurrentNode->DownNode = new Node<T>(ValueToAdd);
        NewNode->UpNode = CurrentNode;
        break;
    }
    Size_++;
}

template <typename T>
T& QuadLinkedList<T>::MoveToHead()
{
    CurrentNode = Head;
    return CurrentNode->Value;
}

template <typename T>
T& QuadLinkedList<T>::MoveInDirection(Direction DirectionToMoveIn)
{
    Node<T>* NewNode{nullptr};
    switch (DirectionToMoveIn)
    {
    case Left:
        NewNode = CurrentNode->LeftNode;
        break;
    case Right:
        NewNode = CurrentNode->RightNode;
        break;
    case Up:
        NewNode = CurrentNode->UpNode;
        break;
    case Down:
        NewNode = CurrentNode->DownNode;
        break;
    }
    if(NewNode) CurrentNode = NewNode;
    return CurrentNode->Value;
}

template <typename T>
T& QuadLinkedList<T>::MoveInDirection(Direction DirectionToMoveIn, size_t NumberOfSteps)
{
    Node<T> PrevNode{nullptr};
    for (int i = 0; i < NumberOfSteps; ++i)
    {
        PrevNode = CurrentNode;
        MoveInDirection(DirectionToMoveIn);
        if (PrevNode == CurrentNode) break;
    }
    return CurrentNode->Value;
}

// template <typename T>
// Node<T>* QuadLinkedList<T>::TraverseList()
// {
//     for (int i = 0; i < Size_; ++i)
//     {
//         for (int i = 0; i < Size_; ++i)
//         {
//         CurrentNode = Head;
//         CurrentNode->RightNode = Head->RightNode;
//         }
//     }
// }
