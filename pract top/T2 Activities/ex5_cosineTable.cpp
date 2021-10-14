#include <iostream>
#include <iomanip>

using namespace std;

float myPow(float number, int exp) {
  float result = 1;

  for(int i = 0; i < exp; i++) {
    result *= number;
  }

  return result;
}

int myFactorial(int number) {
  int result = 1;

  for(int i = number; i > 0; i--) {
    result *= i;
  }

  return result;
}

float sine(float angle) {
  float sin = angle;
  int exponent = 3;
  int signal = -1;
  float numerator = 0, denominator = 0, nthTerm;

  for(int i = 0; i < 3; i++) {
    numerator = myPow(angle, exponent);
    denominator = myFactorial(exponent);
    nthTerm = (numerator * signal) / (float)denominator;
    sin += nthTerm;
    signal *= -1;
    exponent += 2;
  }

  return sin;
}

float cosine(float angle) {
  float cos = 1;
  int exponent = 2;
  int signal = -1;
  float numerator = 0, denominator = 0, nthTerm;

  for(int i = 0; i < 3; i++) {
    numerator = myPow(angle, exponent);
    denominator = myFactorial(exponent);
    nthTerm = (numerator * signal) / (float)denominator;
    cos += nthTerm;
    signal *= -1;
    exponent += 2;
  }

  return cos;
}

int main() {
  int rowNumber;
  cout << "Digite a quantidade de senos a serem escritos: " << endl;
  cin >> rowNumber;

  float sines[rowNumber], cosines[rowNumber], angles[rowNumber];

  for(int i = 0; i < rowNumber; i++) {
    cout << "Digite o " << i + 1 << "° ângulo (em radianos): " << endl;
    cin >> angles[i];

    sines[i] = sine(angles[i]);
    cosines[i] = cosine(angles[i]);
  }
  
  cout << endl;
  cout << "Ângulo" << setw(8) << " | " << "Seno" << setw(8) << " | " << "Cosseno" << setw(8) << endl;

  for(int i = 0; i < rowNumber; i++) {
    cout << angles[i] << setw(6) << " | " << sines[i] << setw(4) << " | " << cosines[i] << setw(8) << endl;
  }

  system("PAUSE");
  return 0;
}
