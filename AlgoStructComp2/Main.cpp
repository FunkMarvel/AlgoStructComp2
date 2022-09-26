
#include <iostream>
#include <exception>
#include "QuadLinkedList.h"



int main(int argc, char* argv[])
{
    
    QuadLinkedList<int> quadlist{1};
    std::cout << quadlist << std::endl;
    quadlist.AddNode(2, Task1::Link1);
    std::cout << quadlist.MoveInDirection(Task1::Link1) << std::endl;
    quadlist.AddNode(3, Task1::Link4);
    std::cout << quadlist.MoveInDirection(Task1::Link4) << std::endl;
    std::cout << quadlist.MoveInDirection(Task1::Link2)<< std::endl;
    try
    {
        quadlist.AddNode(11, Task1::Link4);
    }
    catch (const std::runtime_error& error)
    {
        std::cout << error.what();
    }

    return 0;
}
