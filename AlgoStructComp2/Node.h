template <typename T>
struct Node
{
    Node* NextNode{nullptr};
    Node* PrevNode{nullptr};
    T Value{};

    Node();
    explicit Node(T NewValue);
    
};

template <typename T>
Node<T>::Node()
{
    Value = T();
}

template <typename T>
Node<T>::Node(T NewValue)
{
    
}


