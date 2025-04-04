#include <iostream>
#include <fstream>
using namespace std;


int main(){

  string file;
  int x, count1 = 0, count2 = 0, count3 = 0, count4 = 0;

  cout << "Enter a filename: ";
  cin >> file;
  ifstream fin(file);

  if (!fin){
    cout << "Error: Input file not found";
    return 1;
  }

  fin >> x;
  while (fin){
    if (10 <= x && x <= 19)
      count1++;
    else if (20 <= x && x <= 29)
      count2++;
    else if (30 <= x && x <= 39)
      count3++;
    else if (40 <= x && x <= 49)
      count4++;
    fin >> x;
  }

  cout << "[10,19]: ";
  while (count1 > 0){
    cout << "*";
    count1--;
  }
  cout << endl;
  cout << "[20,29]: ";
  while (count2 > 0){
    cout << "*";
    count2--;
  }
  cout << endl;
  cout << "[30,39]: ";
  while (count3 > 0){
    cout << "*";
    count3--;
  }
  cout << endl;
  cout << "[40,49]: ";
  while (count4 > 0){
    cout << "*";
    count4--;
  }
  cout << endl;

  return 0;
}
