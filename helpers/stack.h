#ifndef STACK_H
#define STACK_H

#include <iostream>

class EmptyStackException : public std::runtime_error
{
public:
    EmptyStackException(std::string const &msg = "Empty stack") : std::runtime_error(msg) {}
};

class NoMinStackException : public std::runtime_error
{
public:
    NoMinStackException(std::string const &msg = "Empty stack") : std::runtime_error(msg) {}
};

template <typename T>
struct StackNode
{
    T data;
    StackNode<T> *next;

    StackNode() : data(), next(nullptr) {}
    StackNode(T data) : data(data), next(nullptr) {}
};

template <class T>
class Stack
{
public:
    Stack() : top(nullptr) {}

    T pop()
    {
        if (top == nullptr)
            throw EmptyStackException();

        T item = top->data;
        top = top->next;
        return item;
    }

    T peek()
    {
        if (top == nullptr)
            throw EmptyStackException();
        return top->data;
    }

    void push(T item)
    {
        StackNode<T> *t = new StackNode<T>(item);
        t->next = top;
        top = t;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void print()
    {
        if (top == nullptr)
            throw EmptyStackException();

        StackNode<T> *current = top;
        while (current)
        {
            std::cout << current->data << std::endl;
            current = current->next;
        }
    }

private:
    StackNode<T> *top;
};

#endif