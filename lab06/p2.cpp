#include <cstdlib>
#include <iostream>
using namespace std;

// Function to simulate a single roll of a single 6-sided die
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

// Function to simulate a single throw of two dice and process the role within the game
int throwdice() {
    int roll1 = rolldie();
    int roll2 = rolldie();
    int sum = roll1 + roll2;

    cout << "Player rolled " << roll1 << " + " << roll2 << " = " << sum;
    
    if (sum == 7 || sum == 11)
        cout << " Player wins!" << endl;
    else if (sum == 2 || sum == 3 || sum == 12)
        cout << " House wins!" << endl;
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
