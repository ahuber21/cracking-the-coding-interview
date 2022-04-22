#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>

template <typename T>
class Node
{
private:
    T value;

protected:
    Node *prev;
    Node *next;

public:
    Node(T val)
    {
        value = val;
        prev = nullptr;
        next = nullptr;
    }

    void append(T val)
    {
        Node *new_node = new Node(val);
        Node *free_spot = this;
        while (free_spot->next != nullptr)
        {
            free_spot = free_spot->next;
        }

        free_spot->next = new_node;
        new_node->prev = free_spot;
    }

    void remove_duplicates()
    {
        Node *base = this;
        while (base)
        {
            // search for duplicate values starting at next
            Node *other = base;
            while ((other = other->next) != nullptr)
            {
                if (base->value == other->value)
                {
                    std::cout << "Found a duplicate value: " << base->value << std::endl;
                    if (other->prev != nullptr)
                        other->prev->next = other->next;
                    if (other->next != nullptr)
                        other->next->prev = other->prev;
                    delete other;
                }
            }

            // move on one list element
            base = base->next;
        }
    }

    void print()
    {
        Node *current = this;
        Node *last;
        std::cout << "  forward:  ";
        while (current != nullptr)
        {
            if (current == this)
            {
                std::cout << current->value;
            }
            else
            {
                std::cout << " -> " << current->value;
                last = current;
            }
            current = current->next;
        }
        std::cout << std::endl;

        current = last;
        std::cout << "  backward: ";
        while (current != nullptr)
        {
            if (current == last)
                std::cout << current->value;
            else
            {
                std::cout << " -> " << current->value;
            }
            current = current->prev;
        }
        std::cout << std::endl;
    }
};

#endif