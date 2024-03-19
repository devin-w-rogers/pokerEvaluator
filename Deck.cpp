#include "Deck.h"
#include "Card.h"

struct comparerator {
	inline bool operator() (Card& card1, Card& card2) {

		return (card1.getNumericValue() < card2.getNumericValue());
	}
};

Deck::Deck()
{
	for (int i = 2; i < 15; i++) {
		Card c(i, "Hearts");
		allCards.push_back(c);
	}
	for (int i = 2; i < 15; i++) {
		Card c(i, "Spades");
		allCards.push_back(c);
	}
	for (int i = 2; i < 15; i++) {
		Card c(i, "Diamonds");
		allCards.push_back(c);
	}
	for (int i = 2; i < 15; i++) {
		Card c(i, "Clubs");
		allCards.push_back(c);
	}
}

void Deck::shuffle()
{

	int randomNum;
	
	for (int i = 0; i < 52; i++)
	{
		randomNum = rand() % 52;
		Card temp = allCards[i];
		allCards[i] = allCards[randomNum];
		allCards[randomNum] = temp;
	}
}

void Deck::printAllCards()
{
	for (int i = 0; i < allCards.size(); i++) {
		allCards[i].print();
	}
}

bool Deck::getCards(int numRequestedCards, vector <Card>& cards)
{
	for (int i = 0; i < numRequestedCards; i++) {
		if (numRequestedCards > allCards.size()) {
			return false;
		}
		cards.push_back(allCards[i]);
	}
	sort(cards.begin(), cards.end(), comparerator());

	allCards.erase(allCards.begin(), allCards.begin()+numRequestedCards);
	return true;
}

void Deck::addCardsBackToDeck(vector <Card>& cards)
{

	for (int i = 0; i < cards.size(); i++) {
		allCards.push_back(cards[i]);
	}
	cards.clear();
}
