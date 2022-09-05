
#include "Node.h"

#include "iostream"
#include "MultiLinkedList.h"



int main(int argc, char* argv[])
{
    //Longer ut more clear method
    MultiLinkedList<int> IntList{2,1};
    // for (int I{}; I < IntList.GetSize(); ++I)
    //     std::cout << IntList[I] << " ";
    std::cout << IntList << std::endl;
    std::cout << std::endl << "Size: " << IntList.GetSize() << std::endl;
  

    // IntList.InsertEnd(1);


    for (int I{}; I < IntList.GetSize(); ++I)
        std::cout << IntList[I] << " ";
    std::cout << std::endl << "Size: " << IntList.GetSize() << std::endl;
    return 0;
}
