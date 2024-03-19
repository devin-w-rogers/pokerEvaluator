#pragma once
#include "Card.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Deck
{
public:
    Deck();
    void shuffle();
    void printAllCards();
    bool getCards(int numRequestedCards, vector <Card>& cards); //this 'cards' vector is passed in by reference to be filled with cards from the deck 
    void addCardsBackToDeck(vector <Card>& cards);
private:
    vector <Card> allCards;
};
