#include <iostream>
using namespace std;

int main() {
  int numberTerm, numerator = 1, denominator;
  float sum = 0;

  cout << "Digite a quantidade de termos: " << endl;
  cin >> numberTerm;

  denominator = numberTerm;

  for(int i = 0; i < numberTerm; i++) {
    sum += numerator / (float)denominator;
    numerator++;
    denominator--;
  }

  cout << "O resultado da soma dos " << numberTerm << " termos é: " << sum << endl;

  return 0;
}