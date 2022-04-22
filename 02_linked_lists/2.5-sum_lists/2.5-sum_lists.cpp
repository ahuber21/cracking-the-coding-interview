#include "../../helpers/singlylinkedlist.h"

template <typename T>
Node<T> add(Node<T> l1, Node<T> l2)
{
    // O(N) in space and CPU where N is the length of the longer list

    bool carry = false;
    Node result = Node(-1);

    Node<T> *c1 = &l1;
    Node<T> *c2 = &l2;
    Node<T> *cr = &result;

    while ((c1 != nullptr) || (c2 != nullptr))
    {
        int val = carry ? 1 : 0;
        if (c1)
        {
            val += c1->get_value();
            c1 = c1->get_next();
        }
        if (c2)
        {
            val += c2->get_value();
            c2 = c2->get_next();
        }

        carry = (val > 9);
        val %= 10;

        if (cr->get_value() == -1)
        {
            // first iteration
            cr->set_value(val);
        }
        else
        {
            cr->append(val);
            cr = cr->get_next();
        }
    }

    if (carry)
        cr->append(1);

    return result;
}

int main()
{
    Node l1 = Node(7);
    l1.append(1);
    l1.append(6);

    Node l2 = Node(5);
    l2.append(9);
    l2.append(2);

    Node l3 = add(l1, l2);

    l3.print();

    return 0;
}