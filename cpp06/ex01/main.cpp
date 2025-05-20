#include "Serializer.hpp"

int main()
{
    Data d;
    d.id = 42;
    d.name = "Jacob";

    uintptr_t raw = Serializer::serialize(&d);
    Data* restored = Serializer::deserialize(raw);

    std::cout << "Original address: " << &d << std::endl;
    std::cout << "Restored address: " << restored << std::endl;

    if (restored == &d)
        std::cout << "Pointer restored successfully!" << std::endl;
    else
        std::cout << "Failed to restore pointer." << std::endl;

    std::cout << "Restored Data: id = " << restored->id << ", name = " << restored->name << std::endl;
}
