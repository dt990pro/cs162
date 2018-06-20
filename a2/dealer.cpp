#include "dealer.h"

dealer::dealer()
{
	de_hand = new hand[1];
	card_total = 0;
}

dealer::~dealer()
{
	delete[] de_hand;
}

void dealer::set_card_total(int n)
{
	card_total = n;
}

hand *dealer::get_de_hand()
{
	return de_hand;
}

int dealer::get_card_total()
{
	return card_total;
}