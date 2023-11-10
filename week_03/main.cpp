#include <iostream>

void print (int x) { 
     for (size_t i = 0; i < x; i++) {
        for (size_t j = 0; j < x; j++)
        {
            if (j < i || i == 0 || j == x - 1) {
                std::cout << "* ";
            } else {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }
}
int main() {
    int x = 6;
    print(x);
}