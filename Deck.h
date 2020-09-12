#ifndef POLT_DECK_H
#define POLT_DECK_H

#include <iostream>
#include <string>
#include <algorithm> 
#include <vector> 
#include <random> 
#include <chrono> 
#include "Card.h"

using namespace std;

class Deck {
private:
	vector<Card> v;
public:
	Deck();
	void set_v(vector<Card>);
	void shuffle();
	int count();
	vector<Card> deal(int);
};

#endif // POLT_DECK_H