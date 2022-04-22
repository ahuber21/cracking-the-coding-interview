#include "../../helpers/stack.h"
#include <iostream>
#include <string>

template <class T>
class SpecialStack
{
public:
    SpecialStack() {}

    void push(T item)
    {
        s.push(item);

        if (m.isEmpty() || item < m.peek())
            m.push(item);
    }

    T pop()
    {
        T val = s.pop();
        if (val == m.peek())
            m.pop();

        return val;
    }

    T peek()
    {
        return s.peek();
    }

    bool isEmpty()
    {
        return s.isEmpty();
    }

    T min()
    {
        return m.peek();
    }

    void print()
    {
        printf("Stack:\n");
        s.print();
        printf("Minima:\n");
        m.print();
    }

private:
    Stack<T> s;
    Stack<T> m;
};

int main()
{
    SpecialStack<int> s;
    s.push(5);
    s.push(2);
    s.push(4);
    s.print();
    std::cout << "min: " << s.min() << std::endl;

    s.pop();
    s.pop();
    s.print();
    std::cout << "min: " << s.min() << std::endl;

    return 0;
}