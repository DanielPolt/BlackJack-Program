/*
 Solution to blackjack project
 Solution written by Daniel Polt.
*/
//This program uses object-oriented programming for a simple game of blackjack between the user and the computer

#include <iostream>
#include <string>
#include <algorithm> 
#include <vector> 
#include <random> 
#include <chrono> 
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Card.cpp"
#include "Deck.cpp"

using namespace std;

int main()
{
	//variables, structures, and Card object
	vector<Card> v;
	vector<string> ranks{ "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };
	vector<int> values{ 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 1 };
	vector<string> suits{ "Clubs", "Diamonds", "Hearts", "Spades" };
	vector<Card> dealt;
	Card c;
	char chr = 'n';
	char h_s = 's';
	
	cout << "Blackjack" << endl << endl;

	//create vector of cards
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			c.set_rank(ranks[j]);
			c.set_value(values[j]);
			c.set_suit(suits[i]);
			v.push_back(c);
		}
	}
	
	
	do
	{
		//create Deck object, give it the card vector, and shuffle the vector
		Deck d;
		d.set_v(v);
		d.shuffle();

		Hand player(d.deal(2));
		Hand dealer(d.deal(2));

		while (dealer.get_value() < 17)
		{
			dealer += (d.deal(1))[0];
		}

		cout << "DEALER'S SHOW CARD:" << endl;
		dealer.display_show();
		
		cout << endl << "YOUR CARDS:" << endl;
		player.display();
		cout << endl << "Hit or stand? (h/s): ";
		cin >> h_s;

		while (player.get_value() < 21 && h_s != 's' && h_s != 'S' && !player.get_blackjack())
		{	
			player += (d.deal(1))[0];
			cout << endl << "YOUR CARDS:" << endl;
			player.display();
			if (player.get_value() < 21 && player.get_aces() == 0)
			{
				cout << endl << "Hit or stand? (h/s): ";
				cin >> h_s;
			}
		} 

		cout << endl << "DEALER'S CARDS:" << endl;
		dealer.display();

		cout << endl << "YOUR POINTS:     " << player.get_value() << endl;
		cout << "DEALER'S POINTS: " << dealer.get_value() << endl << endl;

		if (dealer.get_blackjack())
		{
			cout << "The dealer got blackjack. You lose!" << endl;
		}
		else if (player.get_blackjack())
		{
			cout << "You got blackjack. You win!" << endl;
		}
		else if (dealer.get_value() > 21)
		{
			cout << "Yay! The dealer busted. You win!" << endl;
		}
		else if (player.get_value() > 21)
		{
			cout << "You busted. You lose!" << endl;
		}
		else if (dealer.get_value() < player.get_value())
		{
			cout << "You have more points than the dealer. You win!" << endl;
		}
		else if (dealer.get_value() == player.get_value())
		{
			cout << "You have the same number of points as the dealer. Tie!" << endl;
		}
		else
			cout << "You have fewer points than the dealer. You loose!" << endl;

		cout << endl << "Play again? (y/n): ";
		cin >> chr;
		cout << endl << "Come back soon!" << endl;

	} while (chr != 'n' && chr != 'N');
	
	return 0;
}