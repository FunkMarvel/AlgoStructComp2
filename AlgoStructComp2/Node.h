#pragma once

template <typename T>
struct Node {

    Node* Link1{nullptr};
    Node* Link2{nullptr};
    Node* Link3{nullptr};
    Node* Link4{nullptr};
    T Value{};
    
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

/**
 * \brief Enum representing possible sides of node.
 */
enum Direction
{
    Link1,
    Link2,
    Link3,
    Link4
};