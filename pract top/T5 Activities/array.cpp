#include<iostream>
using namespace std;

class Array {
private: 
  double* array;
  int elements;
public:
  int fill() {
    cout << "Digite a quantidade de Elementos no array: " << endl;
    cin >> elements;

    array = new double[elements];

    cout << "Preencha o Array: " << endl;
    for(int i = 0; i < elements; i++)
      cin >> array[i];
    return 1;
  }

  void printArray() {
    for(int i = 0; i < elements; i++)
      cout << array[i] << " | ";
    cout << endl;
  }

  int sort() {
    double auxiliarSuffle;
    for(int i = 0; i < elements; i++)
      for(int j = 0; j < elements - 1; j++) {
        if(array[j] > array[j+1]) {
          auxiliarSuffle = array[j];
          array[j] = array[j+1];
          array[j+1] = auxiliarSuffle;
        }
      }
    return 1;
  }

  int find(double toFind) {
    int status = 0; 
    for(int i = 0; i < elements; i++)
      if(toFind == array[i]) {
        status = 1;
        cout << "Elemento: " << toFind << " encontrado no índice " << i << endl;
      }
    if (status == 0) cout << "Elemento: " << toFind << " não encontrado " << endl;
    cout << endl;
    return status;
  }

  int fastFind(double toFind) {
    int status = 0; 
    for(int i = 0; i < elements; i++)
      if(toFind == array[i]) {
        status = 1;
        cout << "Elemento: " << toFind << " encontrado no índice " << i << endl;
        cout << endl;
        return status;
      }
    if (status == 0) cout << "Elemento: " << toFind << " não encontrado " << endl;
    cout << endl;
    return status;
  }

  int binarySearch(double toFind) {
    sort();
    int begin = 0;
    int end = elements - 1;
    
    while(begin <= end) {
      int i = begin + (end - begin) / 2;
      if(array[i] == toFind) {
        cout << "Elemento: " << toFind << " encontrado no índice " << i << endl;
        cout << endl;
        return 1;
      }
      if (array[i] < toFind) {
        begin = i+1;
      } else {
        end = i-1;
      }
    }

    cout << "Elemento: " << toFind << " não encontrado " << endl;
    cout << endl;
    return 0;
  }

  int findLargestSmallest() {
    sort();

    cout << "O menor número do Array é: " << array[0] << " e o maior é: " << array[elements-1] << endl;
    cout << endl;
    return 1;
  }

  int modeArray() {
    int mode = array[0], count = 0, countMode = 1;

    for (int i = 0; i < elements; ++i) {
      if (array[i] == mode) ++countMode;
      else ++count;
      if (count > countMode)
      {
        mode = array[i];
        countMode = count;
        count = 0;
      }
    }

    cout << "A moda é: " << mode << endl;
    cout << endl;
    return 1;
  }
};

int main() {
  Array array;

  array.fill();

  cout << "Array/Tabela antes da Ordenação: " << endl;
  array.printArray();
  cout << endl;
  
  array.sort();
  cout << "Array/Tabela depois da Ordenação: " << endl;
  array.printArray();
  cout << endl;

  double procuradoUm;
  cout << "Digite o primeiro número procurado (Busca sem parada): " << endl;
  cin >> procuradoUm;
  array.find(procuradoUm);

  double procuradoDois;
  cout << "Digite o segundo número procurado (Busca com parada): " << endl;
  cin >> procuradoDois;
  array.fastFind(procuradoDois);
  
  double procuradoTres;
  cout << "Digite o terceiro número procurado (Busca binária): " << endl;
  cin >> procuradoTres;
  array.binarySearch(procuradoTres);

  array.findLargestSmallest();

  array.modeArray();
  
  system("PAUSE");
  return 0;
}