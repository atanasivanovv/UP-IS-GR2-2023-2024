#include <iostream>

void printClientIds(int** hotel, const size_t size) {
    for (size_t i = 0; i < size; i++) {
        if (hotel[i] != nullptr) {
            std::cout << *hotel[i] << " ";
        }
    }
    std::cout << std::endl;
}

void putClientIdInIndex(int** hotel, const size_t index, const int clientId) {
    if (hotel[index] == nullptr) {
        hotel[index] = new int(clientId);
    }
}

void clearClientIdInIndex(int** hotel, const size_t index, const int clientId) {
    if (hotel[index] != nullptr) {
        delete hotel[index];
        hotel[index] = nullptr;
    }
}

int main() {
    size_t size = 10;
    int** hotel = new int*[size]();
    int clientId = 5;
    hotel[0] = nullptr;
    hotel[0] = new int(clientId);
    hotel[1] = new int(clientId);

    printClientIds(hotel, size);

    hotel[0] = nullptr;

    printClientIds(hotel, size);

    for (size_t i = 0; i < size; i++) {
        if (hotel[i] != nullptr) {
            delete hotel[i]; 
        }
    }
    delete [] hotel;

    std::cout << "END";
}