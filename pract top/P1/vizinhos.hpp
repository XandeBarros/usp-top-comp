#include <iostream>
#include <iomanip>
using namespace std;

class Vizinhos {
private:
  int linhas;
  int colunas;
  int** matrizA;
  float** matrizB;
public:
  Vizinhos();
  int setMatrizA(int matriz[21][21]);
  int getMatrizA();
  int setMatrizB();
  int getMatrizB();
  int desalocarMemoria();
};
