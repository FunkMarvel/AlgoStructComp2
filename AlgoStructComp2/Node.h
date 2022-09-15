#pragma once

namespace Node
{
    /**
    * \brief Enum representing possible sides of node.
    */
    enum Direction
    {
        NaL,
        Link1,
        Link2,
        Link3,
        Link4
    };


    template <typename T>
    class Node {
        Node* NaP{nullptr};
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
            default:
                return NaP;
            }
        }

        Direction GetDirection(Node<T>* SomeNode)
        {
            if (SomeNode == Pointer1) return Link1;
            if (SomeNode == Pointer2) return Link2;
            if (SomeNode == Pointer3) return Link3;
            if (SomeNode == Pointer4) return Link4;
            return NaL;
        }

        Node<T>*& GetLink(Node<T>* SomeNode)
        {
            return GetLink(GetDirection(SomeNode));
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