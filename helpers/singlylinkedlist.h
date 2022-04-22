#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>

template <typename T>
class Node
{
private:
    T value;

protected:
    Node *next;

public:
    Node()
    {
        next = nullptr;
    }

    Node(T val)
    {
        value = val;
        next = nullptr;
    }

    T get_value() const { return value; }
    void set_value(T new_val) { value = new_val; }

    Node<T> *get_next() const { return next; }
    void set_next(Node<T> *new_val) { next = new_val; }

    Node<T> *append(T val)
    {
        Node *new_node = new Node(val);
        Node *free_spot = this;
        while (free_spot->next != nullptr)
        {
            free_spot = free_spot->next;
        }

        free_spot->next = new_node;

        return new_node;
    }

    void print() const
    {
        const Node *current = this;
        while (current != nullptr)
        {
            if (current == this)
            {
                std::cout << current->value;
            }
            else
            {
                std::cout << " -> " << current->value;
            }
            current = current->next;
        }
        std::cout << std::endl;
    }

    size_t n_next() const
    {
        // CPU: O(n)
        // Space: O(1)
        const Node *current = this;
        size_t size = 0;
        while (current)
        {
            ++size;
            current = current->next;
        }
        return size;
    }

    T back(size_t index_from_back) const
    {
        return back_node()->value;
    }

    Node *back_node(size_t index_from_back)
    {
        // CPU: O(n)
        // Space: O(1)
        size_t size = n_next();
        Node *current = this;
        for (size_t i = 0; i < size - 1 - index_from_back; ++i)
            current = current->next;

        return current;
    }

    void pop_middle()
    {
        // CPU: O(n)
        // Space: O(1)
        size_t size = n_next();
        Node *current = this;
        size_t idx_to_pop = (size - 1) / 2;
        for (size_t i = 0; i < idx_to_pop - 1; ++i)
            current = current->next;

        current->next = current->next->next;
        delete current->next;
    }

    Node reverse()
    {
        Node *current = this;
        Node *root = new Node(this->get_value());

        while (current->get_next())
        {
            Node *n = new Node(current->get_next()->get_value());
            n->set_next(root);

            current = current->get_next();
            root = n;
        }
        return *root;
    }

    Node<T> *reverse_inplace()
    {
        // Initialize current, previous and
        // next pointers
        Node<T> *current = this;
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
        // at this point current and next are nullptr
        // and prev points to the last node
        return prev;
    }
};

#endif