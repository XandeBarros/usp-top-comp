#include <iostream>
using namespace std;

int main() {
  int init = 0, end = 1;
  int parts;

  cout << "Digite a quantidade de partes da função: (inteiro)" << endl;
  cin >> parts;

  float diffH = (end - init) / (float)parts;
  float sum = 0, sumParts = 0, initX = init, endX;

  while (endX < end) {
    endX = initX + diffH;
    sumParts = ((1/(1+(initX * initX))) + (1/(1 + (endX * endX))))/2;
    sum += sumParts * diffH;
    initX = endX;
  }

  float pi = 4 * sum;

  cout << "O valor de PI é: " << pi << endl;

  system("PAUSE");
  return 0;
}
