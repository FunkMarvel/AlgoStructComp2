#pragma once

#include <cmath>
#include <initializer_list>


template<typename T>
class MultiLinkedList
{

protected:
    Node<T>* Head_{nullptr};
    Node<T>* Tail_{nullptr};
    // Node<T>* Child_[nullptr];
    Node<T>* CurrentNode_{nullptr};
    int Size_{};
    
    int RolloverIndex (int Index) const;
    
public:
    MultiLinkedList();
    //list of elements of type const T.
    MultiLinkedList(std::initializer_list<T> ArgList);
    //MultiLinkedList foo {10,20};  // calls initializer_list ctor
    //MultiLinkedList bar (10,20);  // calls first constructor 
    ~MultiLinkedList();

    T& operator[](int Index);

    friend std::ostream& operator<<(std::ostream& os, MultiLinkedList& SomeList)
    {
        auto CurrentNode = SomeList.Head_;
        for (int i = 0; i < SomeList.Size_; ++i)
        {
            os << CurrentNode->Value;
            if (i != SomeList.Size_-1) os << " ";
            CurrentNode = CurrentNode->NextNode;
        }
        return os;
    }

    void Append(T NewElement);
    void Insert(int Index,T NewElement);
    void Remove();
    void Remove(int Index);

    void InsertEnd(T NewElement);
    
    int GetSize() const;
    
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
        //it's Pointing to itself
        Head_->NextNode = Head_->PrevNode = Tail_->NextNode = Tail_->PrevNode = Head_;
        Size_++;
        return;
    }
    //Telling the new node to point to the current tail.
    Tail_->NextNode = new Node<T>(NewElement);
    Tail_->NextNode->PrevNode = Tail_;
    //Tail is now on the new Node created above.Tail_ gets updated here.
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
        // calls append if list is empty to add first element:
        Append(NewElement);
        return;
    }
   
    if (Index == Size_ || Index == -Size_) Index = 0;

    // sets CurrentNode to head to start iterating
    CurrentNode_ = Head_;
    
    Index = RolloverIndex(Index);  // projects given Index into interval [0,Size_)
    for (int i{}; i < Index; i++)
    {
        // moves currentNode until it points at element to insert new element infront of
        CurrentNode_ = CurrentNode_->NextNode;
    }

    auto TempNode = CurrentNode_;  // creates temp refrence to CurrentNode.
    CurrentNode_ = new Node<T>(NewElement);  // sets currentNode to be new node.
    CurrentNode_ = CurrentNode_->NextNode = TempNode;  // links new node to tail-end of list
    CurrentNode_->PrevNode = TempNode->PrevNode;  // links new node to head-end of list.
    CurrentNode_->PrevNode->NextNode = CurrentNode_;  // links head-end of list to new node.
    TempNode->PrevNode = CurrentNode_;  // links tail-end of list to new node.
}

template <typename T>
int MultiLinkedList<T>::GetSize() const { return Size_; }

template <typename T>
int MultiLinkedList<T>::RolloverIndex(int Index) const
{
        if (Index == 0) return 0;
        if (Index < 0 && Index % Size_ == 0) return 0;
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
    //Makes Head_,Tail_ and currentNode_ point to the beginning of the list of inputs.
    Head_ = Tail_ = CurrentNode_ = new Node<T>(*(ArgList.begin()));
    //This for loop connects all the elements
    for (int I{1}; I < Size_; ++I) {
        //Adds next input to the list. The new node will be the currentNodes next node.
        CurrentNode_->NextNode = new Node<T>(*(ArgList.begin() + I));
        //Makes the new node point back to the current node. 
        CurrentNode_->NextNode->PrevNode = CurrentNode_;
        //Moving the current node one forward. to make it ready for the next node that will get created.
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



