#include <iostream>
#include <iomanip>

using namespace std;

class TrigonometricFunction {
  private:
    float cos;
    float sin;
    float tan;
  
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

    void setTangent() {
      tan = sin / (float)cos;
    }

  public:
    void setSine(float angle, int terms) {
      sin = angle;
      int exponent = 3;
      int signal = -1;
      float numerator = 0, denominator = 0, nthTerm;
      for(int i = 0; i < terms; i++) {
        numerator = myPow(angle, exponent);
        denominator = myFactorial(exponent);
        nthTerm = (numerator * signal) / (float)denominator;
        sin += nthTerm;
        signal *= -1;
        exponent += 2;
      }
    }

    void setCosine(float angle, int terms) {
      cos = 1;
      int exponent = 2;
      int signal = -1;
      float numerator = 0, denominator = 0, nthTerm;
      for(int i = 0; i < terms; i++) {
        numerator = myPow(angle, exponent);
        denominator = myFactorial(exponent);
        nthTerm = (numerator * signal) / (float)denominator;
        cos += nthTerm;
        signal *= -1;
        exponent += 2;
      }
    }

    float getSine() {
      return sin;
    }

    float getCosine() {
      return cos;
    }

    float getTangent() {
      setTangent();
      return tan;
    }
};

int main() {
  TrigonometricFunction trigFuntions;
  int terms = 0;
  float angle = 0;

  cout << "Digite o ângulo desejado em radianos: " << endl;
  cin >> angle;
  cout << "Digite a quantidade de termos da sequência: " << endl;
  cin >> terms;

  trigFuntions.setCosine(angle, terms);
  trigFuntions.setSine(angle, terms);
  cout << "SENO: " << setw(12) << trigFuntions.getSine() << endl;
  cout << "COSSENO: " << setw(9) << trigFuntions.getCosine() << endl;
  cout << "TANGENTE: " << setw(6) << trigFuntions.getTangent() << endl;

  return 0;
}