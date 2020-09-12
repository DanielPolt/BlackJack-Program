#ifndef POLT_HAND_H
#define POLT_HAND_H

#include <iostream>
#include <string>
#include <algorithm> 
#include <vector> 
#include <random> 
#include <chrono> 
#include "Card.h"

using namespace std;

class Hand {
private:
	vector<Card> v;
	int value;
	int aces;
	int tens;
	char blackjack;
public:
	Hand(vector<Card> v_param)
	{
		v = v_param;
		value = 0;
		aces = 0;
		tens = 0;
		for (int i = 0; i < v.size(); i++)
		{
			value += v[i].get_value();
			if (v[i].get_ace())
			{
				aces++;
			}
			if (v[i].get_value() == 10)
			{
				tens++;
			}
			blackjack = (tens > 0) && (aces > 0);
		}
	}
	
	/*
	display
	precondition: Hand object exists and has a defined Card vector
	postcondition: displays representations of the Cards in the vector
	*/
	void display() {
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i];
		}
	}

	/*
	display
	precondition: Hand object exists and has a defined Card vector
	postcondition: displays first Card in the vector
	*/
	void display_show() {
		cout << v[0];
	}


	/*
	get_count
	precondition: Hand object exists and has a defined Card vector
	postcondition: returns the number of Cards in the deck
	*/
	int get_count() {
		return v.size();
	}
	/*
	get_aces
	precondition: Hand object exists and has a defined aces value
	postcondition: returns the Hand's aces value, the number of aces counting for 1 points
	*/
	int get_aces() {
		return aces;
	}
	/*
	get_blackjack
	precondition: Hand object exists and has a defined blackjack value
	postcondition: returns the  blackjack value of the Hand
	*/
	bool get_blackjack() {
		return blackjack;
	}
	/*
	get_value
	precondition: Hand object exists and has a defined point value
	postcondition: returns the a value of the hand, optimizing it if there are aces in hand
	*/
	int get_value() {
		if (aces > 0)
		{
			while (aces > 0 && (value + 10) < 22)
			{
				value += 10;
				aces--;
			}
		}
		return value;
	}


	/*
	operator+=
	precondition:  Hand object and a Card object operand exist
	postcondition: adds the Card object to the Hand's vector and returns the vector
	*/
	Hand& operator+= (const Card& card_param)
	{
		v.insert(v.begin() + v.size(), card_param);
		value += v[v.size() - 1].get_value();
		if (v[v.size() - 1].get_ace())
			aces++;
		return *this;
	}

};
#endif // POLT_HAND_H