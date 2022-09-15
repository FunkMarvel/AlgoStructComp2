#pragma once
#include <list>
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

    Node<T>* Head_{nullptr};
    // Node<T>* Tail{nullptr};
    Node<T>* CurrentNode_{nullptr};
    
    size_t Size_{};

    int Index;
    std::vector<std::list<T>> AdjList; // P-Array containing adjacency lists
    


public:
    QuadLinkedList();
    explicit QuadLinkedList(T NewValue);
    ~QuadLinkedList();

  
    void SizeForArray(int Index);
    void AddEdge(int v,int w);
    void BreathFirstSearch(int s);
    
    
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

template <typename T>
void QuadLinkedList<T>::SizeForArray(int Index)
{
    this->Index = Index;
    AdjList.resize(Index);
}


template <typename T>
void QuadLinkedList<T>::BreathFirstSearch(int s)
{
    
   std::vector<bool> VisitedNodes;
    VisitedNodes.resize(Index,false);

    std::list<T> queue;

    VisitedNodes[s] = true;
    queue.push_back(s);
    
    while (!queue.empty())
    {
       s = queue.front();
        std::cout << s << " ";
        queue.pop_front();
        for (auto adjecent: AdjList[s])
        {
            if (!VisitedNodes[adjecent])
            {
                VisitedNodes[adjecent] = true;
                queue.push_back(adjecent);
            }
        }
    }
}

template <typename T>
void QuadLinkedList<T>::AddNode(T ValueToAdd, Direction SideToAddAt)
{
    if (Size_ <= 0) {Head_ = CurrentNode_ = new Node<T>(ValueToAdd); Size_++;}
    
    Node<T>* NewNode{nullptr};
    switch (SideToAddAt)
    {
    case Left:
        if (CurrentNode_->LeftNode) return;
        NewNode = CurrentNode_->LeftNode = new Node<T>(ValueToAdd);
        NewNode->RightNode = CurrentNode_;
        break;
    case Right:
        if (CurrentNode_->RightNode) return;
        NewNode = CurrentNode_->RightNode = new Node<T>(ValueToAdd);
        NewNode->LeftNode = CurrentNode_;
        break;
    case Up:
        if (CurrentNode_->UpNode) return;
        NewNode = CurrentNode_->UpNode = new Node<T>(ValueToAdd);
        NewNode->DownNode = CurrentNode_;
        break;
    case Down:
        if (CurrentNode_->DownNode) return;
        NewNode = CurrentNode_->DownNode = new Node<T>(ValueToAdd);
        NewNode->UpNode = CurrentNode_;
        break;
    }
    Size_++;
}

template <typename T>
T QuadLinkedList<T>::RemoveCurrentNode()
{
    if (Size_ <= 0) throw std::runtime_error("Cannot remove from empty list.");
    // if (Size_ <= 1)
    // {
    //     auto ReturnValue = Head_->Value;
    //     delete Head_;
    //     Size_--;
    //     return ReturnValue;
    // }
    
    auto NodeToRemove = CurrentNode_;

    CurrentNode_ = nullptr;
    
    if (NodeToRemove->LeftNode && NodeToRemove->RightNode)
    {
        NodeToRemove->LeftNode->RightNode = NodeToRemove->RightNode;
        NodeToRemove->RightNode->LeftNode = NodeToRemove->LeftNode;
        CurrentNode_ = NodeToRemove->LeftNode;
    }
    else if (NodeToRemove->LeftNode)
    {
        NodeToRemove->LeftNode->RightNode = nullptr;
        if(!CurrentNode_) CurrentNode_ = NodeToRemove->LeftNode;
    }
    else if (NodeToRemove->RightNode)
    {
        NodeToRemove->RightNode->LeftNode = nullptr;
        if(!CurrentNode_) CurrentNode_ = NodeToRemove->RightNode;
    }

    if (NodeToRemove->UpNode && NodeToRemove->DownNode)
    {
        NodeToRemove->UpNode->DownNode = NodeToRemove->DownNode;
        NodeToRemove->DownNode->UpNode = NodeToRemove->UpNode;
        if(!CurrentNode_) CurrentNode_ = NodeToRemove->UpNode;
    }
    else if (NodeToRemove->UpNode)
    {
        NodeToRemove->UpNode->DownNode = nullptr;
        if(!CurrentNode_) CurrentNode_ = NodeToRemove->UpNode;
    }
    else if (NodeToRemove->DownNode)
    {
        NodeToRemove->DownNode->UpNode = nullptr;
        if(!CurrentNode_) CurrentNode_ = NodeToRemove->DownNode;
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
    case Left:
        NewNode = CurrentNode_->LeftNode;
        break;
    case Right:
        NewNode = CurrentNode_->RightNode;
        break;
    case Up:
        NewNode = CurrentNode_->UpNode;
        break;
    case Down:
        NewNode = CurrentNode_->DownNode;
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
