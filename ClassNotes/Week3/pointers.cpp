#include <iostream>

int main() {
    double example = 4.1;
    std::cout << "Value: " << example << "\n";
    std::cout << "Address: " << &example << "\n";
    double value = example;
    double * address = &example;
    double addrvalue = *address;
    std::cout << "Value: " << value << "\n";
    std::cout << "Address: " << address << "\n";
    std::cout << "Value at address: " << addrvalue << "\n";
    std::cout << std::endl;

    int arr[5] = {2, 4, 5, 2, 0};
    std::cout << arr[0] << std::endl;
    int* start = &arr[0];
    std::cout << start << std::endl;
    std::cout << *start << std::endl;
    arr[0] = 8;
    std::cout << start << std::endl;
    std::cout << *start << std::endl;
}