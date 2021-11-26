#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int procurarMatrix(int **matrix, int length, int uLine, int uColumn, int palavra[]) {
  if ((uColumn + 1 == length) && (uLine + 1 == length)) return 1;
  if (matrix[uLine][uColumn] != palavra[0]) return 0;

  int linhaAux = uLine + 1;
  int colunaAux = length - uColumn;

  // int *matrixAuxiliar[linhaAux];

  // for(int i = 0; i < linhaAux; i++) {
  //   matrixAuxiliar[i] = new int[colunaAux]();
  // }

  // int auxL = 0;

  // for(int lin = 0; lin < linhaAux; lin++) {
  //   int auxC = uColumn;
  //   for(int col = 0; col < colunaAux; col++) {
  //     matrixAuxiliar[lin][col] = matrix[auxL][auxC];
  //     auxC++;
  //   }

  //   auxL++;
  // }

  int counter = 0;
  int init = 1;

  for(int lin = uLine; lin > 0; lin--) {
    for(int col = uColumn; col > 0; col--) {
      if (matrix[uLine - init][uColumn] == palavra[init]) counter++;
      if (matrix[uLine - init][uColumn + init] == palavra[init]) counter++;
      if (matrix[uLine][uColumn + init] == palavra[init]) counter++;
    }

    init++;
  }

  return counter;

  // for(int lin = 0; lin < linhaAux; lin++) {
  //   for(int col = 0; col < colunaAux; col++) {
  //     cout << matrixAuxiliar[lin][col] << " | ";
  //   }

  //   cout << endl;
  // }
  
  // return 1;
}

int main() {
  string palavra;
  cout << "Digite a palavra que você quer usar: " << endl;
  cin >> palavra;

  for_each(palavra.begin(), palavra.end(), [](char & c) {
    c = tolower(c);
  });

  int len = palavra.length();

  int palavraNum[len], *palavraMatrix[len];

  for(int i = 0; i < len; i++) {
    palavraMatrix[i] = new int[len];
  }

  // Transforma a palavra em número

  for(int i = 0; i < len; i++) {
    palavraNum[i] = int(palavra[i]) - 96;
  }

  // Coloca o Array na matriz

  for(int lin = 0; lin < len; lin++) {
    int aux = len - lin;
    for(int col = 0; col < len; col++) {
      if ((col - lin) < 0) {
        palavraMatrix[lin][col] = palavraNum[aux];
        aux++;
      } else {
        palavraMatrix[lin][col] = palavraNum[col - lin];
      }
    }
  }

  // Contar quantidade de palavras 

  int userLin, userCol;

  cout << "Digite a linha do primeiro elemento: de 1 a " << len << endl;
  cin >> userLin;
  userLin--;

  cout << "Digite a coluna do primeiro elemento: de 1 a " << len << endl;
  cin >> userCol;
  userCol--;

  cout << procurarMatrix(palavraMatrix, len, userLin, userCol, palavraNum) << endl;

  // Mostra a Matriz

  for(int lin = 0; lin < len; lin++) {
    for(int col = 0; col < len; col++) {
      cout << palavraMatrix[lin][col] << " | ";
    }
    cout << endl;
  }

  return 0;
}