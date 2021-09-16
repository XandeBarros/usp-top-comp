// C++ program to convert a decimal
// number to binary number

#include <iostream>
using namespace std;

int main()
{
	int numberDecimal, handleNumber;

  cout << "Digite um número decimal: " << endl;
  cin >> numberDecimal;

  handleNumber = numberDecimal;
 
  int numberBinary[32];

	int i = 0;
	while (numberDecimal > 0) {
		numberBinary[i] = numberDecimal % 2;
		numberDecimal = numberDecimal / 2;
		i++;
	}

  cout << "O número " << handleNumber << " na base binária vale: " << endl;

	for (int j = i - 1; j >= 0; j--) {
		cout << numberBinary[j];
	}

  cout << endl;

	return 0;
}
