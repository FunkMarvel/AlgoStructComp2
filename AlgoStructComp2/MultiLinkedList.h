#pragma once
#include "Node.h"
#include <cmath>
#include <initializer_list>


template<typename T>
class MultiLinkedList
{
public:
MultiLinkedList();
    MultiLinkedList(std::initializer_list<T> ArgList);

    ~MultiLinkedList();

    T& operator[](int Index);

    void Append(T NewElement);
    void Insert(int Index,T NewElement);
    void Remove();
    void Remove(int Index);

    
private:


protected:
Node<T>* Head_{nullptr};
    Node<T>* Tail_{nullptr};
    Node<T>* Child_[nullptr];

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
        Head_ = Tail_ = new Node<T>(NewElement);
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
    size_++;
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
    if (Index == size_ || Index == -Size_) Index = 0;
    {
        
    }
}


