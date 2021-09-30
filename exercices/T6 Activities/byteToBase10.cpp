#include <iostream>
using namespace std;

int myPow(int number, int exp) {
  int result = 1;

  for(int i = 0; i < exp; i++) {
    result *= number;
  }

  return result;
}

int main() {
  int oneByte[8], numberDecimal = 0;

  for(int i = 0; i < 8; i++) {
    cout << "Digite o "<< i + 1 <<"° bit (0 ou 1): " << endl;
    cin >> oneByte[i];
  }

  for(int i = 0; i < 8; i++) {
    int exp = 8 - (i + 1);
    numberDecimal += oneByte[i] * myPow(2, exp);
  }

  cout << "O byte inserido em Decimal é: " << numberDecimal << endl;
  
  return 0;
}
