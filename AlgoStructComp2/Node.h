#pragma once

template <typename T>
struct Node {
    Node* RightNode{nullptr};
    Node* LeftNode{nullptr};
    Node* UpNode{nullptr};
    Node* DownNode{nullptr};
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