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

    Node<T>* Head_{nullptr};
    // Node<T>* Tail{nullptr};
    Node<T>* CurrentNode_{nullptr};
    size_t Size_{};
    
public:
    QuadLinkedList();
    explicit QuadLinkedList(T NewValue);
    ~QuadLinkedList();
    
    T& GetHead() {return Head_->Value;}
    T& GetCurrent() {return CurrentNode_->Value;}
    friend std::ostream& operator<<(std::ostream& os, QuadLinkedList& SomeList)
    {
        os << SomeList.GetCurrent();
        return os;
    } 

    // Add and remove Nodes:
    void AddNode(T ValueToAdd, Direction SideToAddAt);
    T RemoveCurrentNode();

    // traverse list:
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
    Head_ = CurrentNode_ = new Node<T>(NewValue);
    Size_++;
}

/**
 * \brief Delete all nodes and free data.
 */
template <typename T>
QuadLinkedList<T>::~QuadLinkedList()
{
    while (Size_ > 0)
        RemoveCurrentNode();
}

/**
 * \brief Add node to given side of current node, if side is free.
 * \param ValueToAdd Value to store in node.
 * \param SideToAddAt Enum representing side to add at.
 */
template <typename T>
void QuadLinkedList<T>::AddNode(T ValueToAdd, Direction SideToAddAt)
{
    if (Size_ <= 0) {Head_ = CurrentNode_ = new Node<T>(ValueToAdd); Size_++;}
    
    Node<T>* NewNode{nullptr};
    switch (SideToAddAt)
    {
    case Link1:
        if (CurrentNode_->Link2) return;
        NewNode = CurrentNode_->Link2 = new Node<T>(ValueToAdd);
        NewNode->Link1 = CurrentNode_;
        break;
    case Link2:
        if (CurrentNode_->Link1) return;
        NewNode = CurrentNode_->Link1 = new Node<T>(ValueToAdd);
        NewNode->Link2 = CurrentNode_;
        break;
    case Link3:
        if (CurrentNode_->Link3) return;
        NewNode = CurrentNode_->Link3 = new Node<T>(ValueToAdd);
        NewNode->Link4 = CurrentNode_;
        break;
    case Link4:
        if (CurrentNode_->Link4) return;
        NewNode = CurrentNode_->Link4 = new Node<T>(ValueToAdd);
        NewNode->Link3 = CurrentNode_;
        break;
    }
    Size_++;
}

/**
 * \brief Function for removing the current node. Can currently cause memory leaks.
 * \return Value of removed node.
 */
template <typename T>
T QuadLinkedList<T>::RemoveCurrentNode()
{
    if (Size_ <= 0) throw std::runtime_error("Cannot remove from empty list.");
    
    auto NodeToRemove = CurrentNode_;

    CurrentNode_ = nullptr;
    
    if (NodeToRemove->Link2 && NodeToRemove->Link1)
    {
        NodeToRemove->Link2->Link1 = NodeToRemove->Link1;
        NodeToRemove->Link1->Link2 = NodeToRemove->Link2;
        CurrentNode_ = NodeToRemove->Link2;
    }
    else if (NodeToRemove->Link2)
    {
        NodeToRemove->Link2->Link1 = nullptr;
        if(!CurrentNode_) CurrentNode_ = NodeToRemove->Link2;
    }
    else if (NodeToRemove->Link1)
    {
        NodeToRemove->Link1->Link2 = nullptr;
        if(!CurrentNode_) CurrentNode_ = NodeToRemove->Link1;
    }

    if (NodeToRemove->Link3 && NodeToRemove->Link4)
    {
        NodeToRemove->Link3->Link4 = NodeToRemove->Link4;
        NodeToRemove->Link4->Link3 = NodeToRemove->Link3;
        if(!CurrentNode_) CurrentNode_ = NodeToRemove->Link3;
    }
    else if (NodeToRemove->Link3)
    {
        NodeToRemove->Link3->Link4 = nullptr;
        if(!CurrentNode_) CurrentNode_ = NodeToRemove->Link3;
    }
    else if (NodeToRemove->Link4)
    {
        NodeToRemove->Link4->Link3 = nullptr;
        if(!CurrentNode_) CurrentNode_ = NodeToRemove->Link4;
    }
    
    if (Head_ == NodeToRemove) Head_ = CurrentNode_;

    auto ReturnValue = NodeToRemove->Value;
    delete NodeToRemove;
    Size_--;
    
    return ReturnValue;
}

template <typename T>
T& QuadLinkedList<T>::MoveToHead()
{
    CurrentNode_ = Head_;
    return CurrentNode_->Value;
}

template <typename T>
T& QuadLinkedList<T>::MoveInDirection(Direction DirectionToMoveIn)
{
    Node<T>* NewNode{nullptr};
    switch (DirectionToMoveIn)
    {
    case Link1:
        NewNode = CurrentNode_->Link2;
        break;
    case Link2:
        NewNode = CurrentNode_->Link1;
        break;
    case Link3:
        NewNode = CurrentNode_->Link3;
        break;
    case Link4:
        NewNode = CurrentNode_->Link4;
        break;
    }
    if(NewNode) CurrentNode_ = NewNode;
    return CurrentNode_->Value;
}

template <typename T>
T& QuadLinkedList<T>::MoveInDirection(Direction DirectionToMoveIn, size_t NumberOfSteps)
{
    Node<T> PrevNode{nullptr};
    for (int i = 0; i < NumberOfSteps; ++i)
    {
        PrevNode = CurrentNode_;
        MoveInDirection(DirectionToMoveIn);
        if (PrevNode == CurrentNode_) break;
    }
    return CurrentNode_->Value;
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
