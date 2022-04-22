#include "../../helpers/singlylinkedlist.h"
#include <iostream>
#include <string>
enum AnimalType
{
    DOG = 0,
    CAT,
    ANY
};

struct Animal
{
    AnimalType type;
    std::string name;
    int age;

    friend std::ostream &operator<<(std::ostream &os, const Animal &animal);
};
std::ostream &operator<<(std::ostream &os, const Animal &animal)
{
    os << animal.name << " age " << animal.age << std::endl;
    return os;
}

class Shelter
{
public:
    Shelter() : root(nullptr) {}

    void enqueue(Animal animal)
    {
        if (root == nullptr)
        {
            root = new Node<Animal>(animal);
            return;
        }

        Node<Animal> *current = root;
        while (current->get_next())
            current = current->get_next();
        current->append(animal);
    }

    Animal dequeue(AnimalType type)
    {
        Node<Animal> *current = root, *previous = nullptr;

        while ((type != AnimalType::ANY) && (current->get_value().type != type))
        {
            previous = current;
            current = current->get_next();
        }

        Animal animal = current->get_value();
        if (previous)
            previous->set_next(current->get_next());
        else
            root = current->get_next();

        return animal;
    }

    Animal dequeueAny()
    {
        return dequeue(AnimalType::ANY);
    }

    Animal dequeueCat()
    {
        return dequeue(AnimalType::CAT);
    }

    Animal dequeueDog()
    {
        return dequeue(AnimalType::DOG);
    }

    void print()
    {
        if (root)
            root->print();
    }

private:
    Node<Animal> *root;
};

int main()
{
    Shelter shelter;
    shelter.enqueue({AnimalType::DOG, "wuff", 1});
    shelter.enqueue({AnimalType::DOG, "bark", 3});
    shelter.enqueue({AnimalType::DOG, "grrr", 2});
    shelter.enqueue({AnimalType::DOG, "hump", 4});
    shelter.enqueue({AnimalType::CAT, "purr", 12});

    shelter.print();

    Animal a = shelter.dequeueAny();
    std::cout << "dequeued any: " << a.name << std::endl;

    a = shelter.dequeueDog();
    std::cout << "dequeued dog: " << a.name << std::endl;

    a = shelter.dequeueCat();
    std::cout << "dequeued cat: " << a.name << std::endl;

    return 0;
}