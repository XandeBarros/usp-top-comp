#include <iostream>
using namespace std;

float series() {
  int numerator = 1, denominator = 1;
  float sum = 0;

  for(int i = 1; i <= 50; i++) {
    numerator = 2*i - 1;
    denominator = i;

    sum += numerator/(float)denominator;
  }

  return sum;
}

int main() {
  cout << "O valor da soma é: " << series() << endl;
  
  system("PAUSE");
  return 0;
}
