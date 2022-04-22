#include "../../helpers/doublylinkedlist.h"
#include <string>

int main()
{
    Node root = Node(1);
    root.append(1);
    root.append(1);
    root.append(1);
    root.append(1);
    root.append(5);
    root.append(20);
    root.append(10);
    root.append(15);
    root.append(10);
    root.append(10);
    root.append(10);

    printf("Before:\n");
    root.print();

    root.remove_duplicates();

    printf("After:\n");
    root.print();

    return 0;
}