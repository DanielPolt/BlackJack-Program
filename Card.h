#ifndef POLT_CARD_H
#define POLT_CARD_H

#include <string>

using namespace std;

class Card {
private:
	string rank;
	string suit;
	int value;
	char ace;
public:
	Card(string p_rank = "", string p_suit = "", int p_value = 0);
	void set_rank(string);
	void set_suit(string);

	void set_value(int);
	int get_value();
	bool get_ace();

	friend ostream& operator<< (ostream&, const Card&);
	string get_rep();
};

#endif // POLT_CARD_H