#include "../../helpers/stack.h"
#include <iostream>
#include <string>

template <typename T>
class MyQueue
{
public:
    MyQueue() : removing(false), push(), pop() {}

    void add(T item)
    {
        if (removing)
            move_to_push();

        push.push(item);
    }

    T remove()
    {
        if (!removing)
            move_to_pop();

        return pop.pop();
    }

    bool isEmpty()
    {
        if (removing)
            return pop.isEmpty();
        else
            return push.isEmpty();
    }

    T peek()
    {
        if (removing)
            move_to_push();

        return push.peek();
    }

protected:
    // move everything to the push stack so that new elements can be added
    void move_to_push()
    {
        if (!removing)
            return;

        while (!pop.isEmpty())
            push.push(pop.pop());

        removing = false;
    }

    // move everything to the pop stack to start removing elements
    void move_to_pop()
    {
        if (removing)
            return;

        while (!push.isEmpty())
            pop.push(push.pop());

        removing = true;
    }

private:
    bool removing;
    Stack<T> push, pop;
};

int main()
{
    MyQueue<int> q;

    for (int i = 0; i < 25; ++i)
        q.add(i);

    printf("Added items\n");

    for (int i = 0; i < 20; ++i)
        std::cout << q.remove() << '\n';
    std::cout << std::flush;

    for (int i = 0; i < 25; ++i)
        q.add(i);

    printf("Added some more items\n");

    for (int i = 0; i < 20; ++i)
        std::cout << q.remove() << '\n';
    std::cout << std::flush;

    return 0;
}