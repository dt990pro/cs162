#include<iostream>
#include<cstring>
#include "hand.h"

using namespace std;

class player
{
private:
	hand *pl_hand;
	int playing_total;
	int card_total;
	int bet;

public:
	player();

	hand *get_pl_hand();

	void set_playing_total(int);

	int get_playing_total();
	
	void set_bet(int);

	int get_bet();
	
	void set_card_total(int);

	int get_card_total();

	~player();
};
