#include <iostream>
using namespace std;

int main(){

  char letter, func, junk;
  int x;
  double y;

  cin >> letter >> junk >> x >> junk >> func >> y;

  if (letter == 'f'){
    
    if (func == '+')
      cout << x << " + " << y << " = " << x + y << endl;
    if (func == '-')
      cout << x << " - " << y << " = " << x - y << endl;

  } else if (letter == 'r'){
    
    double x2 = (x%10)*100;
    x = x/10;
    x2 = x2 + (x%10)*10;
    x = x/10;
    x2 = x2 + (x%10);
    if (func == '+')
      cout << x2 << " + " << y << " = " << x2 + y << endl;
    if (func == '-')
      cout << x2 << " - " << y << " = " << x2 - y << endl;
    
  }

  return 0;
}

