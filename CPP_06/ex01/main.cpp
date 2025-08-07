#include "Serializer.hpp"

int main()
{
    // Create a Data object
    Data original;
    original.input = 1337;

    // Get pointer to the object
    Data *ptr = &original;

    // Serialize the pointer
    uintptr_t raw = Serializer::serialize(ptr);

    // Deserialize it back to a pointer
    Data *restored = Serializer::deserialize(raw);

    // Output
    std::cout << "Original address:   " << ptr << std::endl;
    std::cout << "Restored address:   " << restored << std::endl;
    std::cout << "Original value:     " << ptr->input << std::endl;
    std::cout << "Restored value:     " << restored->input << std::endl;

    // Check if they match
    if (restored == ptr)
        std::cout << "Success: pointers match!" << std::endl;
    else
        std::cout << "Failure: pointers do not match!" << std::endl;

    return 0;
}
