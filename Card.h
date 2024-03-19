#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Card
{
public:
	string CardSuit[4] = { "Hearts", "Spades", "Diamonds", "Clubs" };
	Card(int nv, string S);
	const int getNumericValue();
	void setNumericValue(int nv);
	void print();
	string suit;

private:
	int numericValue; //2-14
	
};

