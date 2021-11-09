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
    return status;
  }

  int fastFind(double toFind) {
    int status; 
    for(int i = 0; i < elements; i++)
      if(toFind == array[i]) {
        status = 1;
        cout << "Elemento: " << toFind << " encontrado no índice " << i << endl;
        return status;
      }
    return status = 0;
  }

  int binarySearch(double toFind) {
    sort();
    int begin = 0;
    int end = elements;
    
    while(begin <= end) {
      int i = (begin + end) / (float)2;
      if(array[i] == toFind) {
        cout << "Elemento: " << toFind << " encontrado no índice " << i << endl;
        return 1;
      }
      if (array[i] < toFind) 
        begin = i++;
      else 
        end = i;
    }

    return 0;
  }

  int findLargestSmallest() {
    sort();

    cout << "O menor número do Array é: " << array[0] << " e o maior é: " << array[elements-1] << endl;
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
    return 1;
  }
};

int main() {
  Array array;

  array.fill();
  array.sort();
  array.find(5);
  array.fastFind(5);
  array.binarySearch(4);
  array.findLargestSmallest();
  array.modeArray();
  
  return 0;
}