#include <iostream>
using namespace std;

float myPow(float number, int exp) {
  float result = 1;

  for(int i = 0; i < exp; i++) {
    result *= number;
  }

  return result;
}

int main() {
  float quaterPi = 0, radius, volume;
  int i = 0;

  cout << "Digite o do Raio da esfera: " << endl;
  cin >> radius;
  
  do {
    int numerator = myPow(-1, i);
    int denominator = 2*i + 1;

    if((1/(float)denominator) < 0.0001) break;

    quaterPi += numerator/(float)denominator;
    i++;
  } while (true);

  float pi = 4 * quaterPi;

  volume = (4 * pi * myPow(radius, 3))/(float)3;

  cout << "O Volume da esfera de raio " << radius << " u.c. é: " << volume << " u.v." << endl;

  system("PAUSE");
  return 0;
}
