#pragma once

template <typename T>
struct Node {
private:
    Node* RightNode{nullptr};
    Node* LeftNode{nullptr};
    Node* UpNode{nullptr};
    Node* DownNode{nullptr};
    T Value{};

public:
    Node* GetRight() {return RightNode;}
    Node* GetLeft() {return LeftNode;}
    Node* GetUp() {return UpNode;}
    Node* GetDown() {return DownNode;}

    T& operator*(Node<T>* SomeNode) {return SomeNode.Value;}
    
    Node();
    explicit Node(T NewValue);
};

template <typename T>
Node<T>::Node() {
    Value = T();
}

template <typename T>
Node<T>::Node(T NewValue) {
    Value = NewValue;
}