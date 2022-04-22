#include "../../helpers/singlylinkedlist.h"

int main()
{
    Node root = Node(0);
    root.append(1);
    root.append(2);
    auto node = root.append(3);
    root.append(4);
    root.append(5);
    root.append(6);

    root.print();

    auto node_next = node->get_next();
    node->set_value(node_next->get_value());
    node->set_next(node_next->get_next());

    delete node_next;
    root.print();

    return 0;
}