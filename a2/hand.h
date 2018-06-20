#pragma once
#include<iostream>
#include<cstring>
#include "card.h"

using namespace std;

class hand
{
private:
	card *hand_card;
	int cards_num;

public:
	hand();

	void pass(card *, int &);

	void hit(card *, int &);

	card *get_hand_card();

	int get_cards_num();

	~hand();
};
