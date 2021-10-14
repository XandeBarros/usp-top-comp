#include <iostream>
using namespace std;

long long int myPow(int number, int exp) {
  long long int result = 1;

  for(int i = 0; i < exp; i++) {
    result *= number;
  }

  return result;
}

long double series() {
  long long int numerator;
  long double sum = 0;

  for(int i = 1; i <= 50; i++) {
    int denominator = 51;
    numerator = myPow(2, i);
    denominator -= i;

    sum += numerator/(long double)denominator;
  }

  return sum;
}

int main() {
  cout << "O valor da soma é: " << series() << endl;

  system("PAUSE");
  return 0;
}
