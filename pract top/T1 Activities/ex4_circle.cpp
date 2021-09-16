#include <iostream> 
using namespace std;

int main() {
  int numberCoord;
  float xCoord, yCoord;
  int included = 0, notIncluded = 0;

  cout << "Digite a quantidade de pares ordenados que irão ser verificados: " << endl;
  cin >> numberCoord;

  if(numberCoord < 0) {
    cout << "Digite um número maior que zero" << endl;
    return 0;
  }

  for (int i = 0; i < numberCoord; i++) {
    cout << "Digite a coordenada x do " << i + 1 << "° par ordenado" << endl;
    cin >> xCoord;
    cout << "Digite a coordenada y do " << i + 1 << "° par ordenado" << endl;
    cin >> yCoord;

    if (xCoord < 0 || yCoord < 0) {
      cout << "O ponto não pertence à região H" << endl;
    }

    bool verification = (xCoord * xCoord) + (yCoord * yCoord) <= 1;

    if (verification) {
      cout << "\n\n";
      cout << "O ponto (" << xCoord << ", " << yCoord <<") pertence à região H" << endl;
      cout << "\n\n";
      included++;
    } else {
      cout << "O ponto (" << xCoord << ", " << yCoord <<") não pertence à região H" << endl;
      notIncluded++;
    }
  }

  cout << included << " pontos pertenciam à H e " << notIncluded << " não pertenciam à H" << endl;

  return 0;
}