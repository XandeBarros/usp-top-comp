#include <iostream>
using namespace std;

int main()
{
  unsigned int fibonacci = 1, previous = 1, handleNumber;
  int userNumber;

  cout << "Digite o n-ésimo número que deseja: " << endl;
  cin >> userNumber;

  for (int i = 1; i < userNumber; i++)
  {
    handleNumber = fibonacci;
    fibonacci = fibonacci + previous;
    previous = handleNumber;
  }

  cout << "O " << userNumber << "° número da sequência de Fibonacci é: " << handleNumber << endl;

  return 0;
}
