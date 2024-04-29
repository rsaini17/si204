#include <iostream>
#include <fstream>
using namespace std;

struct fruit {
  string name;
  double price;
};

int find(string name, fruit *F, int length);

int main()
{
  string fileName;
  cout << "Filename: ";
  cin >> fileName;

  if (fileName != "fruit1.txt" && fileName != "fruit2.txt"){
    cout << "File not found!" << endl;
    return -1;
  }

  ifstream fin(fileName);
  int length;
  string s;
  fin >> length >> s;

  fruit *F = new fruit[length];
  char c;
  for(int i = 0; i < length; i++)
    fin >> F[i].name >> c >> F[i].price;

  double total = 0;
  string command;

  while (true){
    cout << "command: ";
    cin >> command;
    if (command == "checkout"){
      cout << "total is $" << total << endl;
      delete [] F;
      return -1;
    }
    else if (command == "add"){
      double pounds;
      string junk, name;
      cin >> pounds >> junk >> name;
      int i = find(name,F,length);
      if (i == -2){
        cout << "Error! " << name << " not found!" << endl;
      } else {
      total += pounds*F[i].price;
      }
    }
    else if (command == "price"){
      string name;
      cin >> name;
      int i = find(name,F,length);
      if (i == -2){
        cout << "Error! " << name << " not found!" << endl;
      } else {
      cout << name << " are $" << F[i].price << " per pound" << endl;
      }
    }
  }
  
  delete [] F;
  return 0;
}

int find(string name, fruit *F, int length){
  for(int i=0; i < length; i++)
  {
    if(F[i].name == name)
      return i;
  }
  return -2;
}
