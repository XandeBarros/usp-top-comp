#include <iostream>
using namespace std;

void preencherArrays(float arrayX[], float arrayY[], int terms) {
  for(int i = 0; i < terms; i++) {
    cout << "Digite o " << i + 1 << "° par ordenado (x, y): " << endl;
    cin >> arrayX[i];
    cin >> arrayY[i];
  }
}

float sumArray(float array[], int terms) {
  float sum = 0;

  for(int i = 0; i < terms; i++) {
    sum += array[i];
  }

  return sum;
}

float multArray(float arrayX[], float arrayY[], int terms) {
  float sum = 0;

  for(int i = 0; i < terms; i++) {
    sum += arrayX[i]*arrayY[i];
  }

  return sum;
}


int main() {
  int terms;

  cout << "Digite a quantidade de pares ordenados (x, y): " << endl;
  cin >> terms;

  float arrayX[terms], arrayY[terms];
  preencherArrays(arrayX, arrayY, terms);


  float sumX = sumArray(arrayX, terms), 
    sumY = sumArray(arrayY, terms), 
    multXY = multArray(arrayX, arrayY, terms), 
    squareX = multArray(arrayX, arrayX, terms);

  float slopeA = ((terms * multXY) - (sumX * sumY))/(float)((terms * squareX) - (sumX * sumX));
  float linearB = ((sumY * squareX) - (sumX * multXY))/(float)((terms * squareX) - (sumX * sumX));

  cout << "Coeficiente Angular: " << slopeA << endl; 
  cout << "Coeficiente Linear: " << linearB << endl;

  system("PAUSE");
  return 0;
}
