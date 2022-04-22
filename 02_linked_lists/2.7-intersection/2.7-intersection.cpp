#include "../../helpers/singlylinkedlist.h"
#include <iostream>

template <typename T>
void intersect(Node<T> &l1, Node<T> &l2)
{
    // O(1) in space
    // O(A*B) in CPU, A length l1, B length l2
    Node<T> *c1 = &l1;
    Node<T> *c2 = &l2;

    while (c1 != nullptr)
    {
        while (c2 != nullptr)
        {
            if (c1 == c2)
            {
                std::cout << "Found intersecting node with value "
                          << c1->get_value() << " at " << c1 << std::endl;
                return;
            }
            c2 = c2->get_next();
        }
        c2 = &l2;
        c1 = c1->get_next();
    }
}

template <typename T>
void intersect_based_on_last_node(Node<T> &l1, Node<T> &l2)
{
    Node<T> *r1 = l1.reverse_inplace();
    r1->print();
    Node<T> *r2 = l2.reverse_inplace();
    r2->print();

    if (r1 != r2)
    {
        std::cout << "No intersection" << std::endl;
        return;
    }

    std::cout << "Could intersect" << std::endl;

    T final_val;
    while (r1 == r2)
    {
        final_val = r1->get_value();
        r1 = r1->get_next();
        r2 = r2->get_next();
    }
    std::cout << "Found intersecting value = " << final_val << std::endl;
}

/* Function to reverse the linked list */
template <typename T>
Node<T> *reverse(Node<T> *head)
{
    // Initialize current, previous and
    // next pointers
    Node<T> *current = head;
    Node<T> *prev = nullptr, *next = nullptr;

    while (current != nullptr)
    {
        // Store next
        next = current->get_next();

        // Reverse current node's pointer
        current->set_next(prev);

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    return prev;
}

int main()
{
    Node l1(0);
    l1.append(1);
    l1.append(2);
    Node<int> *appended = l1.append(3);
    l1.append(4);
    l1.append(5);

    Node l2(9);
    l2.append(8);
    l2.append(8);
    Node<int> *tmp = l2.append(1);
    tmp->set_next(appended);

    l1.print();
    l2.print();

    intersect_based_on_last_node(l1, l2);
    // Node<int> *flipped = reverse(&l1);
    // std::cout << "Flipped root: " << flipped->get_value() << std::endl;
    // flipped->print();

    return 0;
}