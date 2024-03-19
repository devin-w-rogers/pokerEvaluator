#include "Card.h"



Card::Card(int nv, string S)
{
	numericValue = nv;
	suit = S;
}

const int Card::getNumericValue() 
{
	return numericValue;
}

void Card::setNumericValue(int nv)
{
	numericValue = nv;
}

void Card::print()
{
	if (numericValue <= 10) {
		cout << numericValue << " of " << suit << endl;
	}
	else if (numericValue == 11) {
		cout << "J of " << suit << endl;
	}
	else if (numericValue == 12) {
		cout << "Q of " << suit << endl;
	}
	else if (numericValue == 13) {
		cout << "K of " << suit << endl;
	}
	else if (numericValue == 14) {
		cout << "A of " << suit << endl;
	}
}
