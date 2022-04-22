#include "../../helpers/singlylinkedlist.h"

int main()
{
    Node root = Node(0);
    root.append(1);
    root.append(2);
    root.append(3);
    root.append(4);
    root.append(5);
    root.append(6);
    root.append(7);

    root.print();

    std::cout << root.back(2) << std::endl;
    std::cout << root.back(7) << std::endl;

    return 0;
}