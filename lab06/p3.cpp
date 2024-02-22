/*Author: MIDN Ronny Saini
 *filename: p3.cpp
 *Craps improved
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
int throwdice(int& setpoint) {
    int roll1 = rolldie();
    int roll2 = rolldie();
    int sum = roll1 + roll2;

    cout << "Player rolled " << roll1 << " + " << roll2 << " = " << sum;

    if (setpoint == 0) { // First roll
        if (sum == 7 || sum == 11){
            cout << " Player wins!" << endl;
            return 0;
        }
        else if (sum == 2 || sum == 3 || sum == 12) {
            cout << " House wins!" << endl;
            return -1;
        }
        else {
            setpoint = sum;
            cout << " setpoint is " << setpoint << "!" << endl;
        }
    } else { // After first rolls
        if (sum == setpoint) {
            cout << " Player wins!" << endl;
            return 0;
        } else if (sum == 7 || sum == 12) {
            cout << " House wins!" << endl;
            return -1;
        } else {
            cout << " roll again" << endl;
        }
    }

    return sum;
}

int main() {
    int seed;
    cout << "Enter seed value: ";
    cin >> seed;
    srand(seed);
    int setpoint = 0; 
    char playAgain;
    while (true) {
        int result;
        while (true) {
            result = throwdice(setpoint);
            if (result == 0 || result == -1)
                break;
        }

        cout << "Play again? (y/n): ";
        cin >> playAgain;
        if (playAgain != 'y'){
            break;
        }
    }

    return 0;
}
