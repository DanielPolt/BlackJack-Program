#include "Card.h"
#include <string>

using namespace std;


//public functions
Card::Card(string p_rank, string p_suit, int p_value) {
	set_rank(p_rank);
	set_suit(p_suit);
	set_value(p_value);
}

/*
set_rank
precondition: Card object exists
postcondition: sets the rank value of the Card object to the input's value and also sets the ace boolean value of the Card object accordingly
*/
void Card::set_rank(string rank_param) {
	rank = rank_param;
	if (rank_param == "Ace")
		ace = true;
	else
		ace = false;
}

/*
set_suit
precondition: Card object exists
postcondition: sets the suit value of the Card object to the input's value
*/
void Card::set_suit(string suit_param) {
	suit = suit_param;
}




/*
set_value
precondition: Card object exists
postcondition: sets the value of the Card object to the input's value
*/
void Card::set_value(int value_param) {
	value = value_param;
}
/*
get_value
precondition: Card object exists and has a defined value
postcondition: returns the value of the card
*/
int Card::get_value() {
	return value;
}
/*
get_ace
precondition: Card object exists and has a defined ace value
postcondition: returns the ace value of the card
*/
bool Card::get_ace() {
	return ace;
}



/*
operator<<
precondition:  Card object with defined rank and suit values exist
postcondition: prints the representation of the Card object to the console
*/
ostream& operator<< (ostream& out, const Card& card_param)
{
	out << card_param.rank + " of " + card_param.suit << endl;
	return out;
}

/*
get_rep
precondition: Card object exists and has defined rank and suit values
postcondition: returns a represenation of the card
*/
string Card::get_rep() {
	return (rank + " of " + suit);
}