#include <iostream>
#include "vizinhos.hpp"
using namespace std;

int main() {
  Vizinhos vizinho;
  int matrizA[21][21];
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j <3; j++) {
      cout << "Digite o Elemento a[" << i+1 << "," << j+1 << "] da Matriz A: ";
      cin >> matrizA[i][j];
    }
  }

  vizinho.setMatrizA(matrizA);
  vizinho.getMatrizA();
  vizinho.setMatrizB();
  vizinho.getMatrizB();
  vizinho.desalocarMemoria();

  return 0;
}