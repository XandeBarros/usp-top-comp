#include <iostream>
using namespace std;

float squareRoot(float answer, float number) {
  float res = 0;

  while(answer * answer != number) {
    res = ((answer * answer) + (number)) / (float)(2 * answer);
    if ((answer - res) < 0.00001) break;
    answer = res;
  }

  return answer;
}

int main() {
  float number, answer;
  
  cout << "Digite um número positivo: " << endl;
  cin >> number;
  if (number < 0) cout << "O número deve ser positivo!" << endl;

  answer = number / (float)2;
  
  answer = squareRoot(answer, number);

  cout << answer << endl;

  system("PAUSE");
  return 0;
}
