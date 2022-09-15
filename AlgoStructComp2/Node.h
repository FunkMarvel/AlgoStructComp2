#pragma once

namespace Node
{
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


    template <typename T>
    class Node {

        Node* Pointer1{nullptr};
        Node* Pointer2{nullptr};
        Node* Pointer3{nullptr};
        Node* Pointer4{nullptr};

    public:
        unsigned short NumberOfLinks{};
        T Value{};

        Node*& GetLink(Direction dir)
        {
            switch (dir)
            {
            case Link1:
                return Pointer1;
            case Link2:
                return Pointer2;
            case Link3:
                return Pointer3;
            case Link4:
                return Pointer4;
            }
            return nullptr;
        }
    
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
}