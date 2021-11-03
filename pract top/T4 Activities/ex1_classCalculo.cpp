#include <iostream>
using namespace std;

class Calculo {
public:
  float integral(int parts) {
    int init = 0, end = 1;

    float diffH = (end - init) / (float)parts;
    float sum = 0, sumParts = 0, initX = init, endX;

    while (endX < end) {
      endX = initX + diffH;
      sumParts = ((1/(1+(initX * initX))) + (1/(1 + (endX * endX))))/2;
      sum += sumParts * diffH;
      initX = endX;
    }

    float pi = 4 * sum;

    return pi;
  }
  float raiz(float answer, float number) {
    float res = 0;

    while(answer * answer != number) {
      res = ((answer * answer) + (number)) / (float)(2 * answer);
      if ((answer - res) < 0.00001) break;
      answer = res;
    }

    return answer;
  }
};

int main() {
  Calculo calc;
  int parts;
  float number, answer;

  cout << "Digite a quantidade de partes para calcular PI: (inteiro)" << endl;
  cin >> parts;

  cout << "O valor de PI é: " << calc.integral(parts) << endl;

  cout << "Digite o número para se extrair a Raiz Quadrada: " << endl;
  cin >> number;

  answer = number / (float)2;
  answer = calc.raiz(answer, number);

  cout << "A raiz quadrada de: " << number << " é: " << answer << endl;

  system("PAUSE");
  return 0;
}