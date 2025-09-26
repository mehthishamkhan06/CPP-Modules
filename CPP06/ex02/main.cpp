#include "Base.hpp"
#include "Identify.hpp"


int main() {
    Base* obj = generate();

    std::cout << "Identify from pointer: ";
    identify(obj);

    std::cout << "Identify from reference: ";
    identify(*obj);

    delete obj;
}
