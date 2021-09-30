#include <iostream>
using namespace std;

int main() {
  int initialMatrix[8][8], firstMatrix[4][4], secondMatrix[4][4], thirdMatrix[4][4], fourthMatrix[4][4];

  for(int row = 0; row < 8; row++) {
    for(int col = 0; col < 8; col++) {
      cout << "Digite o termo '" << row + 1 << " " << col + 1 <<"' da matriz: " << endl;
      cin >> initialMatrix[row][col];
    }
  }

  for(int row = 0; row < 4; row++) {
    for(int col = 0; col < 4; col++) {
      firstMatrix[row][col] = initialMatrix[row][col];
    }
  }

  for(int row = 0; row < 4; row++) {
    for(int col = 0; col < 4; col++) {
      secondMatrix[row][col] = initialMatrix[row][4 + col];
    }
  }

  for(int row = 0; row < 4; row++) {
    for(int col = 0; col < 4; col++) {
      thirdMatrix[row][col] = initialMatrix[4 + row][col];
    }
  }

  for(int row = 0; row < 4; row++) {
    for(int col = 0; col < 4; col++) {
      fourthMatrix[row][col] = initialMatrix[4 + row][4 + col];
    }
  }

  cout << "Primeira Matriz 4x4: " << endl;

  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      cout << firstMatrix[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl;
  cout << endl;

  cout << "Segunda Matriz 4x4: " << endl;

  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      cout << secondMatrix[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl;
  cout << endl;

  cout << "Terceira Matriz 4x4: " << endl;

  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      cout << thirdMatrix[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl;
  cout << endl;

  cout << "Quarta Matriz 4x4: " << endl;

  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      cout << fourthMatrix[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}