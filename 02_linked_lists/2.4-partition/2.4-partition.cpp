#include "../../helpers/singlylinkedlist.h"
#include <iostream>

template <typename T>
Node<T> partition(Node<T> *original, T part_value)
{
    // CPU: O(n), since we go through all elements
    // Space: O(n), since we make a copy of the list

    Node<T> new_root;
    bool init = true;

    Node<T> *current = original;
    Node<T> *partioned_current = nullptr;
    while (current)
    {
        if (current->get_value() < part_value)
        {
            if (init)
            {
                init = false;
                new_root.set_value(current->get_value());
                partioned_current = &new_root;
            }
            else
            {
                partioned_current->append(current->get_value());
                partioned_current = partioned_current->get_next();
            }
        }
        current = current->get_next();
    }

    current = original;
    while (current)
    {
        if (current->get_value() >= part_value)
        {
            partioned_current->append(current->get_value());
            partioned_current = partioned_current->get_next();
        }
        current = current->get_next();
    }

    return new_root;
}

template <typename T>
Node<T> *partition_with_pointers(Node<T> *original, T part_value)
{
    Node<T> *small_root = nullptr;
    Node<T> *big_root = nullptr;
    Node<T> *partioned_small = nullptr;
    Node<T> *partioned_big = nullptr;

    Node<T> *current = original;

    // Note: Since we are dealing with pointers this will have
    //       O(1) space complexity, but we have to be careful since
    //       we alter the original linked list
    while (current)
    {
        // first iteration: store everything that's smaller
        if (current->get_value() < part_value)
        {
            if (small_root == nullptr)
            {
                // start the new, partioned list with this element
                small_root = current;
                partioned_small = current;
            }
            else
            {
                // save the element to the partioned list
                // and advance the list
                partioned_small->set_next(current);
                partioned_small = partioned_small->get_next();
            }
        }
        else
        {
            if (partioned_big == nullptr)
            {
                big_root = current;
                partioned_big = current;
            }
            else
            {
                partioned_big->set_next(current);
                partioned_big = partioned_big->get_next();
            }
        }
        // advance the list by one
        current = current->get_next();
    }

    // chain the two lists together
    partioned_small->set_next(big_root);
    // make the list end after the last "big" element
    partioned_big->set_next(nullptr);

    return small_root;
}

int main()
{
    Node original = {0};
    original.append(3);
    original.append(5);
    original.append(8);
    original.append(5);
    original.append(10);
    original.append(2);
    original.append(1);

    original.print();

    Node<int> new_root = partition(&original, 5);
    new_root.print();

    Node<int> *p_new_root = partition_with_pointers(&original, 5);
    p_new_root->print();
}