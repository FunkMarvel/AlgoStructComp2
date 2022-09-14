
#include <iostream>
#include "QuadLinkedList.h"


int main(int argc, char* argv[])
{
    QuadLinkedList<int> quadlist{1};
    std::cout << quadlist << std::endl;
    quadlist.AddNode(2, Left);
    std::cout << quadlist.MoveInDirection(Left);
    return 0;
}



























// int main(int argc, char* argv[])
// {
//
//     //Longer ut more clear method
//     MultiLinkedList<int> IntList{2,1};
//     // for (int I{}; I < IntList.GetSize(); ++I)
//     //     std::cout << IntList[I] << " ";
//     std::cout << IntList << std::endl;
//     std::cout << std::endl << "Size: " << IntList.GetSize() << std::endl;
//   
//
//     // IntList.InsertEnd(1);
//
//
//     IntList.Append(3);
//
//     for (int I{}; I < IntList.GetSize(); ++I)
//         std::cout << IntList[I] << " ";
//     std::cout << std::endl << "Size: " << IntList.GetSize() << std::endl;
//
//     IntList.Insert(-3, 0);
//
//     for (int I{}; I < IntList.GetSize(); ++I)
//         std::cout << IntList[I] << " ";
//     std::cout << std::endl << "Size: " << IntList.GetSize() << std::endl;
//
//     IntList.Remove();
//
//     for (int I{}; I < IntList.GetSize(); ++I)
//         std::cout << IntList[I] << " ";
//     std::cout << std::endl << "Size: " << IntList.GetSize() << std::endl;
//
//     IntList.Remove();
//
//     for (int I{}; I < IntList.GetSize(); ++I)
//         std::cout << IntList[I] << " ";
//     std::cout << std::endl << "Size: " << IntList.GetSize() << std::endl;
//
//     IntList.Remove();
//
//     for (int I{}; I < IntList.GetSize(); ++I)
//         std::cout << IntList[I] << " ";
//     std::cout << std::endl << "Size: " << IntList.GetSize() << std::endl;
//
//     IntList.Remove();
//
//     for (int I{}; I < IntList.GetSize(); ++I)
//         std::cout << IntList[I] << " ";
//     std::cout << std::endl << "Size: " << IntList.GetSize() << std::endl;
//
//     IntList.Insert(0, 11);
//
//     for (int I{}; I < IntList.GetSize(); ++I)
//         std::cout << IntList[I] << " ";
//     std::cout << std::endl << "Size: " << IntList.GetSize() << std::endl;
//
//     MultiLinkedList<int> PintList{1, 2, 3, 4, 5, 6, 7};
//     for (int I{-10}; I <= 10; ++I)
//         std::cout << PintList[I] << " ";
//     std::cout << std::endl << "Size: " << PintList.GetSize() << std::endl;
//     return 0;
// }
