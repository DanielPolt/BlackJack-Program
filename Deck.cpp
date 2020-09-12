#include <iostream>
#include <string>
#include <algorithm> 
#include <vector> 
#include <random> 
#include <chrono> 
#include "Deck.h"

using namespace std;

//public functions
Deck::Deck() {}

/*
set_v
precondition: Deck object exists
postcondition: sets the vector (v) value of the Deck object to the input's value
*/
void Deck::set_v(vector<Card> v_param) {
	v = v_param;
}

/*
shuffle
precondition: Deck object exists and has a defined Card vector
postcondition: shuffles the Card vector
*/
void Deck::shuffle() {
	srand(time(nullptr));

	for (int i = 0; i < v.size(); i++) {
		int rand_i = rand() % v.size();

		Card card = v[i];
		Card rand_card = v[rand_i];

		v[i] = rand_card;
		v[rand_i] = card;
	}
}

/*
count
precondition: Deck object exists and has a defined Card vector
postcondition: returns the number of Cards in the deck
*/
int Deck::count() {
	return v.size();
}

/*
deal
precondition: Deck object exists and has a defined Card vector
postcondition: returns a vector composed of the user-specified number of Cards
*/
vector<Card> Deck::deal(int count) {
	vector<Card> vector;
	for (int i = 0; i < count; i++)
	{
		vector.push_back(v.back());
		v.pop_back();
	}
	return vector;
}