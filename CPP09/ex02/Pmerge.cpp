#include "Pmerge.hpp"

Pmerge::Pmerge(){

}

Pmerge::Pmerge(std::string input){
    this->init_sorting();
}

Pmerge::Pmerge(const Pmerge &copy){
    *this = copy;
}


Pmerge &Pmerge::operator=(const Pmerge &copy){
    (void)copy;
    return (*this);
}

void makepair(int a, int b){
    if (a < b)
        _push_back(a);
    else
        push_back();

}

void Pmerge::init_sorting(){
    std::cout << "Initializing sorting..." << std::endl;
    for (size_t i = 0; i < _vector.size(); i+=2){
        makepair(_vector[i], _vector[i + 1]);
    }
}

void Pmerge::sort(){
    std::cout << "Sorting..." << std::endl;

}