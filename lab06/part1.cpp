/*Author: MIDN Ronny Saini
 *Filename: part1.cpp
 *Lets Roll
 */

#include <cstdlib>
#include <iostream>
using namespace std;


// Function to simulate a single roll of a single 6-sided die
int rolldie() {
    int roll;
    bool notValidRoll = true;
    while (notValidRoll) {
        roll = rand() % 8; // Generate a random number between 0 and 7
        if (roll >= 1 && roll <= 6) // Check if the roll is legitimate
            notValidRoll = false;
    }
    return roll;
}

int main() {
    // Seed the random number generator
    srand(time(0));

    // Simulate 5 rounds of rolling two dice
    for (int i = 0; i < 5; ++i) {
        int roll1 = rolldie();
        int roll2 = rolldie();
        cout << "Player rolled " << roll1 << " + " << roll2 << " = " << (roll1 + roll2) << endl;
    }

    return 0;
}
