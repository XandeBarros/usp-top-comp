#include <iostream>
using namespace std;

int main()
{
	int numberBinary;

  cout << "Digite um número binário: " << endl;
  cin >> numberBinary;

	int numberDecimal = 0;

	int base = 1;

	int temp = numberBinary;
	while (temp) {
		int lastDigit = temp % 10;
		temp = temp / 10;

		numberDecimal += lastDigit * base;

		base = base * 2;
	}

	cout << "O numéro binário " << numberBinary << " vale " << numberDecimal << " na base decimal" << endl;
  return 0;
}
