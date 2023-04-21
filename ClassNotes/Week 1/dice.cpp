#include <cstdlib>
#include <iostream>

class Dice {

    int sides;

    public:
        Dice() {
            sides = 6;
        }

        Dice(int s) {
            sides = s;
        }

        ~Dice(){} // removes from computer data

        int roll(){
            return (std::rand() % sides)+1;
        }
};

int main() {
    Dice die(20);
    int result = die.roll();
    std::cout << result << std::endl; 
}