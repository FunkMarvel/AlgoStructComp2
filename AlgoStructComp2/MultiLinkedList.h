#pragma once

#include <cmath>
#include <initializer_list>


template<typename T>
class MultiLinkedList
{
public:
    MultiLinkedList();
    //list of elements of type const T.
    MultiLinkedList(std::initializer_list<T> ArgList);
    //MultiLinkedList foo {10,20};  // calls initializer_list ctor
    //MultiLinkedList bar (10,20);  // calls first constructor 
    ~MultiLinkedList();

    T& operator[](int Index);

    void Append(T NewElement);
    void Insert(int Index,T NewElement);
    void Remove();
    void Remove(int Index);

    void InsertEnd(T NewElement);
    
    int GetSize() const;
    
private:


protected:
    Node<T>* Head_{nullptr};
    Node<T>* Tail_{nullptr};
   // Node<T>* Child_[nullptr];
    Node<T>* CurrentNode_{nullptr};
    int Size_{};
    
    int RolloverIndex (int Index) const;
};

template <typename T>
MultiLinkedList<T>::MultiLinkedList()
{
   Head_ = Tail_ = CurrentNode_ = new Node<T>();
    Size_ = 1 ;
     
}

template <typename T>
void MultiLinkedList<T>::Append(T NewElement)
{
    if (Size_ < 1)
    {
        //Head and tail is both the head and tail since there is only 1 element inn the current linkedlist.
        Head_ = Tail_ = new Node<T>(NewElement);
        //it's Pointing on itself
        Head_->NextNode = Head_->PrevNode = Tail_;
        Tail_->NextNode = Head_->PrevNode = Head_;
        Size_++;
        return;
    }
    //Telling the new node to point to the current tail.
    Tail_->NextNode = new Node<T>(NewElement);
    Tail_->NextNode->PrevNode = Tail_;
    //Tail is now on the new Node created above.
    Tail_ = Tail_->NextNode;
    //new tail is poiting to head
    Tail_->NextNode = Head_;
    //Head got a new tail node to point to
    Head_->PrevNode = Tail_;
    Size_++;
}

template <typename T>
void MultiLinkedList<T>::Insert(int Index, T NewElement)
{
    if (Size_ < 1)
    {
        Append(NewElement);
        return;
    }
    //to check positive and negative index(if -1 then = 0)
    if (Index == Size_ || Index == -Size_) Index = 0;
    {
        CurrentNode_ = Head_;
        Index = RolloverIndex(Index);
        for (int i{}; i < Index; i++)
        {
            CurrentNode_ = CurrentNode_->NextNode;
        }

        auto TempNode = CurrentNode_;
        CurrentNode_ = new Node<T>(NewElement);
        CurrentNode_ = CurrentNode_->NextNode = TempNode;
        CurrentNode_->PrevNode = TempNode->PrevNode;
        CurrentNode_->PrevNode->NextNode = CurrentNode_;
        TempNode->PrevNode = CurrentNode_;
        
    } 
}

template <typename T>
int MultiLinkedList<T>::GetSize() const { return Size_; }

template <typename T>
int MultiLinkedList<T>::RolloverIndex(int Index) const
{
        if (Index == 0) return 0;
    //Index gets the reminder of size
        if (Index > 0) return (Index % Size_);
    //Returning the value of the absolute value of remainder of size (15/2 = 1)
        return Size_ - (std::abs(Index) % Size_);
}

template <typename T>
MultiLinkedList<T>::MultiLinkedList(std::initializer_list<T> ArgList)
{
    //receives a argument that is used as size.
    Size_ = static_cast<int>(ArgList.size());
    //All three is now New node with the the same pointer to the beginning of the argument that got sent.
    Head_ = Tail_ = CurrentNode_ = new Node<T>(*(ArgList.begin()));
    //This for loop connects all the elements
    for (int I{}; I < Size_; ++I) {
        //Changes the current next node into the new node that got created. Which is the one further back.
        CurrentNode_->NextNode = new Node<T>(*(ArgList.begin() + I));
        //tell the node infront that the new node is the new prev node.
        CurrentNode_->NextNode->PrevNode = CurrentNode_;
        
        CurrentNode_ = CurrentNode_->NextNode;
    }
    //CurrentNode is now the lat element and therefor the tail.
    Tail_ = CurrentNode_;
    //Since its a circular Dual linked list the tails next element would be the head
    Tail_->NextNode = Head_;
    //and vise versa.
    Head_->PrevNode = Tail_;
}

template <typename T>
MultiLinkedList<T>::~MultiLinkedList()
{
    CurrentNode_ = Head_;
    for (int I{}; I < Size_; ++I)
    {
        auto TempNode = CurrentNode_->NextNode;
        delete CurrentNode_;
        CurrentNode_ = TempNode;
    }
}

template <typename T>
T& MultiLinkedList<T>::operator[](int Index)
{
    if (Index == 0) return Head_->Value;
    Index = RolloverIndex(Index);
    CurrentNode_ = Head_;
    for (int I{}; I < Index; ++I)
        CurrentNode_ = CurrentNode_->NextNode;
    return CurrentNode_->Value;
}



