#include <iostream>
using namespace std;

int main() {
  int firstByte[8], secondByte[8], resultByte[8];

  for(int i = 0; i < 8; i++) {
    cout << "Digite o "<< i + 1 <<"° bit (0 ou 1) do primeiro Byte: " << endl;
    cin >> firstByte[i];
  }

  for(int i = 0; i < 8; i++) {
    cout << "Digite o "<< i + 1 <<"° bit (0 ou 1) do segundo Byte: " << endl;
    cin >> secondByte[i];
  }

  for(int i = 0; i < 8; i++) {
    resultByte[i] = firstByte[i] && secondByte[i];
  }

  cout << "O resultado do AND lógico entre os dois bytes é: " << endl;

  for(int i = 0; i < 8; i++) {
    cout << resultByte[i] << " ";
  }

  cout << endl;

  return 0;
}
