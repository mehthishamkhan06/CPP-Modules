#include <iostream>
#include "Serializer.hpp"

int main() {
    Data data;
    data.id = 42;
    data.name = "Hello Serialization";

    std::cout << "Original Data address: " << &data << "\n";

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized value (uintptr_t): " << raw << "\n";

    Data* restored = Serializer::deserialize(raw);
    std::cout << "Restored Data address: " << restored << "\n";

    if (restored == &data)
        std::cout << "Success: restored pointer matches original!\n";

    std::cout << "Restored Data content -> id: " 
              << restored->id << ", name: " << restored->name << "\n";

    return 0;
}
