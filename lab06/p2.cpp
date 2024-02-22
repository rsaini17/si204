/*Author: MIDN Ronny Saini
 *Filename: p2.cpp
 *Craps
 */


#include <cstdlib>
#include <iostream>
using namespace std;

// Function to roll die
int rolldie() {
    int roll;
    bool notValid = true;
    while (notValid) {
        roll = rand() % 8;
        if (roll >= 1 && roll <= 6){
            notValid = false;
        }
    }
    return roll;
}

// Function to roll 2 die and check sum
int throwdice() {
    int roll1 = rolldie();
    int roll2 = rolldie();
    int sum = roll1 + roll2;

    cout << "Player rolled " << roll1 << " + " << roll2 << " = " << sum;
    
    if (sum == 7 || sum == 11){
        cout << " Player wins!" << endl;
        return 0;
    }
    else if (sum == 2 || sum == 3 || sum == 12) {
        cout << " House wins!" << endl;
        return -1;
    }
    else
        cout << " roll again" << endl;
    
    return sum;
}

int main() {
    // Seed
    int seed;
    cout << "Enter seed value: ";
    cin >> seed;
    srand(seed);
  
    // Play Craps
    int result;
    while (true) {
        result = throwdice();
        if (result == 0 || result == -1)
            break;
    }

    return 0;
}
