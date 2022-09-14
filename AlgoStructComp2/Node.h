#pragma once

template <typename T>
class Node {

    Node* RightNode{nullptr};
    Node* LeftNode{nullptr};
    Node* UpNode{nullptr};
    Node* DownNode{nullptr};
    T Value{};

public:
    T& operator*(Node<T>* SomeNode) {return SomeNode.Value;}
    
    Node();
    explicit Node(T NewValue);
    ~Node();  
};

template <typename T>
Node<T>::Node() {
    Value = T();
}

template <typename T>
Node<T>::Node(T NewValue) {
    Value = NewValue;
}

template <typename T>
Node<T>::~Node()
{
    delete RightNode;
    delete LeftNode;
    delete UpNode;
    delete DownNode;
}

enum Direction
{
    Left,
    Right,
    Up,
    Down
};
