#include "player.h"

player::player()
{
	pl_hand = new hand[1];
}

hand *player::get_pl_hand()
{
	return pl_hand;
}

void player::set_playing_total(int n)
{
	playing_total = n;
}

int player::get_playing_total()
{
	return playing_total;
}
	
void player::set_bet(int n)
{
	bet = n;
}

int player::get_bet()
{
	return bet;
}
	
void player::set_card_total(int n)
{
	card_total = n;
}

int player::get_card_total()
{
	return card_total;
}

player::~player()
{
	delete[] pl_hand;
}