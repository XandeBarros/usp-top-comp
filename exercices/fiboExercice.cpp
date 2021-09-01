#include <iostream>
using namespace std;

int main()
{
  unsigned int fibonacci = 1, previous = 1, handleNumber;
  int userNumber;

  cout << "Quantos números? " << endl;
  cin >> userNumber;

  cout << "Fibo " << 1 << ":" << previous << endl;

  for (int i = 1; i < userNumber; i++)
  {
    cout << "Fibo " << i + 1 << ":" << fibonacci << endl;
    handleNumber = fibonacci;
    fibonacci = fibonacci + previous;
    previous = handleNumber;
  }

  return 0;
}
