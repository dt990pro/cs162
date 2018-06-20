#include<iostream>
#include<string>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include "card.h"

class deck
{
private:
	card cards[52];
	int given_cards_num;

public:
	deck();

	void set_deck();

	void set_given_cards_num(int);

	int &get_given_cards_num();

	card *get_cards();

	~deck();

	void display();

	void shuffle();

	void renew();
};