#pragma once
#include "Card.h"
#include "Deck.h"


class PokerEvaluator
{
public:

	string handType(vector <Card>& cards);
	bool evalRoyalFlush(vector <Card> &cards);
	bool evalStraightFlush(vector <Card>& cards);
	bool evalFourKind(vector <Card>& cards);
	bool evalFullHouse(vector <Card>& cards);
	bool evalFlush(vector <Card>& cards);
	bool evalStraight(vector <Card>& cards);
	bool evalThreeKind(vector <Card>& cards);
	bool evalTwoPair(vector <Card>& cards);
	bool evalPair(vector <Card>& cards);

private:



};

