#include <iostream>

int main() {
    int a = 2;
    int b = 5;
    int * pa = &a;
    int * pb = &b;
    auto finalval = ++*pa++;
    std::cout << a << " is a, " << b << " is b" << std::endl;
    std::cout << finalval << " is finalval" << std::endl;
}