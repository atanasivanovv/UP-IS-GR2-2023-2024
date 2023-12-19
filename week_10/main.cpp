#include <iostream>

int main() {
    int* ptr = new int(5);

    std::cout << ptr << std::endl;
    std::cout << *ptr << std::endl;

    // This leads to memory leak of the first heap memory alocation!!!
    ptr = new int(10);

    delete ptr;
}