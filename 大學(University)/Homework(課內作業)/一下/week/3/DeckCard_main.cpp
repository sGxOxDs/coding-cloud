// Demonstrate the copy constructor and assignment operator

#include <iostream>
#include "DeckCard.h"

int main(int argc, const char *argv[])
{
    DeckOfCards deck;
    deck.shuffle();
    while (deck.moreCards()) {
        Card& c = deck.dealCard();
        cout << c.toString() << endl;
    }
    return 0;
}
