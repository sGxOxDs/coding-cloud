#include "DeckCard.h"
#include <iostream>
#include <string>
#include <random>
#include <time.h>
//DeckCard的函式

const string Card::suits[4] = { " 紅心 ", " 方塊 ", " 黑桃 ", " 梅花 " };
const string Card::faces[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10","J", "Q", "K" };

string Card::toString()
{
	return suits[suit] + " " + faces[face];
}


DeckOfCards::DeckOfCards()
{
	currentCard = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 13; j++)
		{
			Card tempCard(j, i);
			deck.push_back(tempCard);
		}
}

void DeckOfCards::shuffle()
{
	srand(time(NULL));
	/*for (; currentCard < 52; currentCard++)
	{
		int r = rand() % 52;
		Card tempCard = deck[currentCard];
		deck[currentCard] = deck[r];
		deck[r] = tempCard;
	}*/
	bool ready[52];
	for (int i = 0; i < 52; i++)
		ready[i] = false;
	int flag = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 13; j++)
		{
			Card tempCard(j, i);
			if (tempCard.toString() == deck[currentCard].toString());
			{
				int r;
				do {
					r = rand() % 52;
				} while (ready[r]&&flag<26);
				tempCard = deck[currentCard];
				deck[currentCard] = deck[r];
				deck[r] = tempCard;
				ready[r] = true;
				ready[currentCard] = true;
				flag++;
			}
			currentCard++;
		}
}

Card& DeckOfCards::dealCard()
{
	currentCard--;
	return deck[currentCard];
}

bool DeckOfCards::moreCards()
{
	if (currentCard != 0)
		return true;
	return false;
}
