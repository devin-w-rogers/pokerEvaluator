#include "Card.h"
#include "Deck.h"
#include "PokerEvaluator.h"
#include <cmath>

using namespace std;

int main()
{
	srand(time(0));
    vector <Card> cards;

    Deck d;

    PokerEvaluator evaluator;

	double royalCounter = 0, straightFlushCounter = 0, fourKindCounter = 0, houseCounter = 0, flushCounter = 0, straightCounter = 0, threeKindCounter = 0, twoPairCounter = 0, pairCounter = 0, highCardCounter = 0;
	double numOfHands = 500000;       //HARD CODED VALUE for number of hands played

    for (int i = 0; i < numOfHands; i++) {
        d.shuffle();
        d.getCards(5, cards);         //HARD CODED VALUE for number of cards in hand (5, 7, etc.)
        evaluator.handType(cards);

		if (evaluator.handType(cards) == "Royal Flush") {
			royalCounter++;
		}
		else if (evaluator.handType(cards) == "Straight Flush") {
			straightFlushCounter++;
		}
		else if (evaluator.handType(cards) == "Four Kind") {
			fourKindCounter++;
		}
		else if (evaluator.handType(cards) == "Full House") {
			houseCounter++;
		}
		else if (evaluator.handType(cards) == "Flush") {
			flushCounter++;
		}
		else if (evaluator.handType(cards) == "Straight") {
			straightCounter++;
		}
		else if (evaluator.handType(cards) == "Three Kind") {
			threeKindCounter++;
		}
		else if (evaluator.handType(cards) == "Two Pair") {
			twoPairCounter++;
		}
		else if (evaluator.handType(cards) == "Pair") {
			pairCounter++;
		}
		else {
			highCardCounter++;
		}
		d.addCardsBackToDeck(cards);
    }
	cout << "Poker Hand Statistics: " << endl;
	cout << "Royal Flush: " << (royalCounter / numOfHands) * 100 << "%" << endl;
	cout << "Straight Flush: " << (straightFlushCounter / numOfHands) * 100 << "%" << endl;
	cout << "Four of a Kind: " << (fourKindCounter / numOfHands) * 100 << "%" << endl;
	cout << "Full House: " << (houseCounter / numOfHands) * 100 << "%" << endl;
	cout << "Flush: " << (flushCounter / numOfHands) * 100 << "%" << endl;
	cout << "Straight: " << (straightCounter / numOfHands) * 100 << "%" << endl;
	cout << "Three of a Kind: " << (threeKindCounter / numOfHands) * 100 << "%" << endl;
	cout << "Two Pair: " << (twoPairCounter / numOfHands) * 100 << "%" << endl;
	cout << "Pair: " << (pairCounter / numOfHands) * 100 << "%" << endl;
	cout << "High Card: " << (highCardCounter / numOfHands) * 100 << "%" << endl;
}