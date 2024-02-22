/*Author: MIDN Ronny Saini
 *Filename: p1.cpp
 *Lets Roll
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

int main() {
    //seed
    int seed;
    cout << "Enter seed value: ";
    cin >> seed;
    srand(seed);
  
    //5 rounds of rolling two dice
    for (int i = 1; i <= 5; i++) {
        int roll1 = rolldie();
        int roll2 = rolldie();
        cout << "Player rolled " << roll1 << " + " << roll2 << " = " << (roll1 + roll2) << endl;
    }

    return 0;
}
