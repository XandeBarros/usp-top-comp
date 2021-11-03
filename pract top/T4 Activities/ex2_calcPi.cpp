#include <iostream>
#include <cmath>
using namespace std;

float myPow(float number, int exp) {
  float result = 1;

  for(int i = 0; i < exp; i++) {
    result *= number;
  }

  return result;
}

float pi() {
  float sum = 0, part, denominator, sign = 1;
  int i = 1;

  do {
    denominator = 2*i - 1;
    part = 1 / (float)(denominator * denominator * denominator);
    sum += sign * part;
    sign *= -1;
    i++;
  } while (part >= 0.0001);

  float pi = cbrt(sum * 32);

  return pi;
}

int main() {
  float radius, volume;

  cout << "O valor de PI é: " << endl;
  cout << pi() << endl;

  cout << "Digite o do Raio da esfera: " << endl;
  cin >> radius;

  volume = (4 * pi() * myPow(radius, 3))/(float)3;

  cout << "O Volume da esfera de raio " << radius << " u.c. é: " << volume << " u.v." << endl;

  system("PAUSE");

  return 0;
}