#pragma once
#include <ostream>
#include <vector>

#include "Node.h"

/**
 * \brief Quadruple linked list
 * \tparam T Data type of elements
 */
template <typename T>
class QuadLinkedList
{
    Node::Node<T>* Head_{nullptr};
    // Node::Node<T>* Tail{nullptr};
    Node::Node<T>* CurrentNode_{nullptr};
    size_t Size_{};

public:
    QuadLinkedList();
    explicit QuadLinkedList(T NewValue);
    ~QuadLinkedList();

    T& GetHead() { return Head_->Value; }
    T& GetCurrent() { return CurrentNode_->Value; }

    static Node::Direction GetOpposingDirection(Node::Direction Side)
    {
        switch (Side)
        {
        case Node::Link1:
            return Node::Link3;
        case Node::Link2:
            return Node::Link4;
        case Node::Link3:
            return Node::Link1;
        case Node::Link4:
            return Node::Link2;
        case Node::NaL:
            return Node::NaL;
        }
        return Node::NaL;
    }

    friend std::ostream& operator<<(std::ostream& os, QuadLinkedList& SomeList)
    {
        os << SomeList.GetCurrent();
        return os;
    }

    // Add and remove Nodes:
    void AddNode(T ValueToAdd, Node::Direction SideToAddAt);
    T RemoveCurrentNode();

    // traverse list:
    T& MoveToHead();
    T& MoveInDirection(Node::Direction DirectionToMoveIn);
    T& MoveInDirection(Node::Direction DirectionToMoveIn, size_t NumberOfSteps);

    // Node::Node<T>* TraverseList();
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
    Head_ = CurrentNode_ = new Node::Node<T>(NewValue);
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
void QuadLinkedList<T>::AddNode(T ValueToAdd, Node::Direction SideToAddAt)
{
    if (Size_ <= 0)
    {
        Head_ = CurrentNode_ = new Node::Node<T>(ValueToAdd);
        Size_++;
    }

    Node::Node<T>* NewNode{nullptr};
    NewNode = CurrentNode_->GetLink(SideToAddAt);
    if (NewNode) return;

    NewNode = new Node::Node<T>(ValueToAdd);
    CurrentNode_->GetLink(SideToAddAt) = NewNode;
    NewNode->GetLink(GetOpposingDirection(SideToAddAt)) = CurrentNode_;
    
    ++CurrentNode_->NumberOfLinks;
    ++NewNode->NumberOfLinks;

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
    if (NodeToRemove->NumberOfLinks > 2) throw std::runtime_error("Removing node may cause memory leak.");

    if (NodeToRemove->NumberOfLinks < 2)
    {
        for (int i = Node::Link1; i <= Node::Link4; ++i)
        {
            auto currentLink = static_cast<Node::Direction>(i);
            if(!NodeToRemove->GetLink(currentLink)) continue;
            CurrentNode_ = NodeToRemove->GetLink(currentLink);
            CurrentNode_->GetLink(NodeToRemove) = nullptr;
            --CurrentNode_->NumberOfLinks;
        }
    }
    else
    {
        std::vector<Node::Node<T>*> NodesToLink{};
        NodesToLink.reserve(2);
        for (int i = Node::Link1; i <= Node::Link4; ++i)
        {
            auto currentLink = static_cast<Node::Direction>(i);
            if (!NodeToRemove->GetLink(currentLink)) continue;
            NodesToLink.push_back(NodeToRemove->GetLink(currentLink));
        }

        NodesToLink[0]->GetLink(NodeToRemove) = NodesToLink[1];
        NodesToLink[1]->GetLink(NodeToRemove) = NodesToLink[0];
        CurrentNode_ = NodesToLink[0];
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
T& QuadLinkedList<T>::MoveInDirection(Node::Direction DirectionToMoveIn)
{
    Node::Node<T>* NewNode{nullptr};
    NewNode = CurrentNode_->GetLink(DirectionToMoveIn);
    if (NewNode) CurrentNode_ = NewNode;
    return CurrentNode_->Value;
}

template <typename T>
T& QuadLinkedList<T>::MoveInDirection(Node::Direction DirectionToMoveIn, size_t NumberOfSteps)
{
    Node::Node<T> PrevNode{nullptr};
    for (int i = 0; i < NumberOfSteps; ++i)
    {
        PrevNode = CurrentNode_;
        MoveInDirection(DirectionToMoveIn);
        if (PrevNode == CurrentNode_) break;
    }
    return CurrentNode_->Value;
}

// template <typename T>
// Node::Node<T>* QuadLinkedList<T>::TraverseList()
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