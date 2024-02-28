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



//Function for first case
int throwdice(){
  int roll1 = rolldie();
  int roll2 = rolldie();
  int sum = roll1 + roll2;

  cout << "Player rolled " << roll1 << " + " << roll2 << " = " << sum;

  if (sum == 7 || sum == 11){
    cout << " Player wins!" << endl;
    return 0;
  } 
  else if (sum == 2 || sum == 3 || sum == 12){
    cout << " House wins!" << endl;
    return -1;
  }
  else {
    cout << " setpoint is " << sum << "!" << endl;
    return sum;
  }
}

// Function for second case 
int throwdice2(int setpoint) {  
    while (true){
    int roll1 = rolldie();
    int roll2 = rolldie();
    int sum = roll1 + roll2;

    cout << "Player rolled " << roll1 << " + " << roll2 << " = " << sum;

      if (sum == setpoint){
        cout << " Player wins!" << endl;
        return 0;
      } 
      else if (sum == 7 || sum == 12){
        cout << " House wins!" << endl;
        return -1;
      }
      else {
        cout << " roll again" << endl;
      }
    }

}

int main() {
    int seed;
    cout << "Enter seed value: ";
    cin >> seed;
    srand(seed);
    bool play = true;

    while (play) {
        int result = throwdice();
        if (result != 0 && result != -1){
          throwdice2(result); 
        }
        cout << "Play again? ";
        char play2;
        cin >> play2;
        if (play2 != 'y'){
          play = false;
        }
    }

    return 0;
}
