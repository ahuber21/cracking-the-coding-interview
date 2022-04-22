#include "../../helpers/singlylinkedlist.h"
#include <iostream>

template <typename T>
bool palindrome(Node<T> *head)
{
    Node reversed = head->reverse();
    printf("reversed: ");
    reversed.print();

    Node<T> *p1 = head;
    Node<T> *p2 = &reversed;

    while (p1 != nullptr && p2 != nullptr)
    {
        if (p1->get_value() != p2->get_value())
            return false;

        p1 = p1->get_next();
        p2 = p2->get_next();
    }

    return true;
}

template <typename T>
void wrapper(Node<T> *head)
{
    printf("The list ");
    head->print();
    printf("%s a palindrome\n", palindrome(head) ? "is" : "is not");
}

int main()
{
    Node head(0);
    head.append(1);
    head.append(2);
    head.append(3);
    head.append(3);
    head.append(2);
    head.append(1);
    head.append(0);

    wrapper(&head);
}
