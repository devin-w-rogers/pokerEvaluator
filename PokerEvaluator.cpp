#include "PokerEvaluator.h"

using namespace std;

string PokerEvaluator::handType(vector <Card>& cards) {
	if (evalRoyalFlush(cards) == true) {
		return "Royal Flush";
	}
	else if (evalStraightFlush(cards) == true) {
		return "Straight Flush";
	}
	else if (evalFourKind(cards) == true) {
		return "Four Kind";
	}
	else if (evalFullHouse(cards) == true) {
		return "Full House";
	}
	else if (evalFlush(cards) == true) {
		return "Flush";
	}
	else if (evalStraight(cards) == true) {
		return "Straight";
	}
	else if (evalThreeKind(cards) == true) {
		return "Three Kind";
	}
	else if (evalTwoPair(cards) == true) {
		return "Two Pair";
	}
	else if (evalPair(cards) == true) {
		return "Pair";
	}
	else {
		return "High Card";
	}
}

bool PokerEvaluator::evalRoyalFlush(vector <Card>& cards)
{
	int heartsCounter = 0;
	int spadesCounter = 0;
	int diamondsCounter = 0;
	int clubsCounter = 0;
	string flushSuit = "";

	for (int i = 0; i < cards.size(); i++) {
		if (cards[i].suit == "Spades") {
			spadesCounter++;
		}
		if (cards[i].suit == "Hearts") {
			heartsCounter++;
		}
		if (cards[i].suit == "Diamonds") {
			diamondsCounter++;
		}
		if (cards[i].suit == "Clubs") {
			clubsCounter++;
		}
	}
	if (spadesCounter >= 5) {
		flushSuit = "Spades";
	}
	if (heartsCounter >= 5) {
		flushSuit = "Hearts";
	}
	if (diamondsCounter >= 5) {
		flushSuit = "Diamonds";
	}
	if (clubsCounter >= 5) {
		flushSuit = "Clubs";
	}

	vector <Card> flush;

	for (int i = 0; i < cards.size(); i++) {
		if (cards[i].suit == flushSuit) {
			flush.push_back(cards[i]);
		}
	}

	if (flush.size() == 0) {
		return false;
	}

	int counter = 0;
	if (flush[flush.size() - 1].getNumericValue() == 14) {
		for (int i = 0; i < flush.size() - 1; i++) {
			
			if (counter == 3 && flush[i].getNumericValue() == 13) {
				return true;
			}

			if (flush[i].getNumericValue() == flush[i + 1].getNumericValue() - 1) {
				counter++;
			}
		}
	}
	return false;
}

bool PokerEvaluator::evalStraightFlush(vector <Card>& cards)
{
	int heartsCounter = 0;
	int spadesCounter = 0;
	int diamondsCounter = 0;
	int clubsCounter = 0;
	string flushSuit = "";

	for (int i = 0; i < cards.size(); i++) {
		if (cards[i].suit == "Spades") {
			spadesCounter++;
		}
		if (cards[i].suit == "Hearts") {
			heartsCounter++;
		}
		if (cards[i].suit == "Diamonds") {
			diamondsCounter++;
		}
		if (cards[i].suit == "Clubs") {
			clubsCounter++;
		}
	}
	if (spadesCounter >= 5) {
		flushSuit = "Spades";
	}
	else if (heartsCounter >= 5) {
		flushSuit = "Hearts";
	}
	else if (diamondsCounter >= 5) {
		flushSuit = "Diamonds";
	}
	else if (clubsCounter >= 5) {
		flushSuit = "Clubs";
	}
	else {
		return false;
	}


	vector <Card> flush;
	int counter = 0;

	for (int i = 0; i < cards.size(); i++) {
		if (cards[i].suit == flushSuit) {
			flush.push_back(cards[i]);
		}
	}

	for (int i = 0; i < flush.size() - 1; i++) {
		if (flush[i + 1].getNumericValue() == (flush[i].getNumericValue()) + 1) {
			counter++;
		}
		else {
			counter = 0;
		}
	}
	if (counter == 4) {
		return true;
	}
	return false;
}

bool PokerEvaluator::evalFourKind(vector <Card>& cards)
{
	for (int i = 0; i < cards.size(); i++) {
		int counter = 1;
		for (int j = 0; j < cards.size(); j++) {
			if (j == i) {
				continue;
			}
			if (cards[i].getNumericValue() == cards[j].getNumericValue()) {
				counter++;
			}
		}
		if (counter == 4) {
			return true;
		}
	}
	return false;
}

bool PokerEvaluator::evalFullHouse(vector <Card>& cards)
{
	return evalThreeKind(cards) && evalPair(cards);
}

bool PokerEvaluator::evalFlush(vector <Card>& cards)
{
	int heartsCounter = 0;
	int spadesCounter = 0;
	int diamondsCounter = 0;
	int clubsCounter = 0;

	for (int i = 0; i < cards.size(); i++) {
		if (cards[i].suit == "Spades") {
			spadesCounter++;
		}
		if (cards[i].suit == "Hearts") {
			heartsCounter++;
		}
		if (cards[i].suit == "Diamonds") {
			diamondsCounter++;
		}
		if (cards[i].suit == "Clubs") {
			clubsCounter++;
		}
	}
	if (spadesCounter == 5 || heartsCounter == 5 || diamondsCounter == 5 || clubsCounter == 5) {
		return true;
	}
	return false;
}

bool PokerEvaluator::evalStraight(vector <Card>& cards)
{
	int counter = 0;
	for (int i = 0; i < cards.size() - 1; i++) {
		if (cards[i + 1].getNumericValue() == (cards[i].getNumericValue())+1) {
			counter++;
		}
		else {
			counter = 0;
		}
	}
	if (counter == 4) {
		return true;
	}
	return false;	
}

bool PokerEvaluator::evalThreeKind(vector <Card>& cards)
{
	for (int i = 0; i < cards.size(); i++) {
		int counter = 1;
		for (int j = 0; j < cards.size(); j++) {
			if (j == i) {
				continue;
			}
			if (cards[i].getNumericValue() == cards[j].getNumericValue()) {
				counter++;
			}
		}
		if (counter == 3) {
			return true;
		}
	}
	return false;
}

bool PokerEvaluator::evalTwoPair(vector <Card>& cards)
{
	vector <Card> temp;

	for (int i = 0; i < cards.size(); i++) {
		temp.push_back(cards[i]);
	}
	
	int counter = 0;
	for (int i = 0; i < temp.size(); i++) {
		
		for (int j = 0; j < temp.size(); j++) {
			if (j == i) {
				continue;
			}
			if (temp[i].getNumericValue() == temp[j].getNumericValue()) {
				temp.erase(temp.begin() + i);
				//temp.erase(temp.begin() + j);
				i = 0;
				counter++;
			}
		}
		
		if (counter == 2) {
			return true;
		}
	}
	return false;
}

bool PokerEvaluator::evalPair(vector <Card>& cards)
{
	for (int i = 0; i < cards.size(); i++) {
		int counter = 1;
		for (int j = 0; j < cards.size(); j++) {
			if (j == i) {
				continue;
			}
			if (cards[i].getNumericValue() == cards[j].getNumericValue()) {
				counter++;
			}
		}
		if (counter == 2) {
			return true;
		}
	}
	return false;
}