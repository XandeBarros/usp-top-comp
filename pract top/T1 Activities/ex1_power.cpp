#include <iostream>
using namespace std;

int main() {
  int numberBase, numberExponent, result = 1;
  
  cout << "Digite o número da base: " << endl;
  cin >> numberBase;
  cout << "Digite o número do expoente: " << endl;
  cin >> numberExponent;

  if(numberExponent < 0) return 0;

  for(int i = 0; i < numberExponent; i++) {
    result *= numberBase;
  }

  cout << "O resultado de " << numberBase << " elevado a " << numberExponent << " é: " << result << endl;
}