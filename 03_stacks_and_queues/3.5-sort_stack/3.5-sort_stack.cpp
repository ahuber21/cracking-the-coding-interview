#include "../../helpers/stack.h"
#include <iostream>
#include <string>

template <typename T>
void sorted_pop(Stack<T> &s1, Stack<T> &s2)
{
    // pop from s1 and put it to the right place into s2
    int n_moved = 0;
    int val = s1.pop();

    while (!s2.isEmpty() && val > s2.peek())
    {
        s1.push(s2.pop());
        n_moved++;
    }
    s2.push(val);
    for (int i = 0; i < n_moved; ++i)
    {
        s2.push(s1.pop());
    }
}

int main()
{
    // sort such that the smallest item goes to the top
    Stack<int> stack, sorted;

    stack.push(7);
    stack.push(12);
    stack.push(2);
    stack.push(24);
    stack.push(100);
    stack.push(1);

    printf("Unsorted\n");
    stack.print();

    while (!stack.isEmpty())
    {
        sorted_pop(stack, sorted);
    }

    printf("Sorted\n");
    sorted.print();

    return 0;
}