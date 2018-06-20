#include "deck.h"

using namespace std;

deck::deck(){}
/******************************************************************************************************************************************
** Function:	set_deck
** Description:	to set up deck
** Parameters:	string of suits
** Pre-Conditions:	none
** Post-Conditions:	deck set up
******************************************************************************************************************************************/
void deck::set_deck()
{
	string c = "club", s = "spade", h = "heart", d = "diamond", str;
	int trace = 0;

	for (int i = 0; i < 4; i++)
	{
		switch (i)
	{
		case 0:
			str = c;
			break;
		case 1:
			str = s;
			break;
		case 2:
			str = h;
			break;
		case 3:
			str = d;
			break;
		}

		for (int j = 0; j < 13; j++)
		{
			cards[trace].set(str, j + 1);
			trace += 1;
		}
	}

	shuffle();
}

void deck::set_given_cards_num(int n)
{
	given_cards_num = n;
}

int &deck::get_given_cards_num()
{
	return given_cards_num;
}

card *deck::get_cards()
{
	return cards;
}

deck::~deck()
{
	//cout << "des in deck." << endl;
}

void deck::display()
{
	for (int i = 0; i < 52; i++)
	{
		cards[i].display();
	}
}
/******************************************************************************************************************************************
** Function:	shuffle
** Description:	to shuffle deck
** Parameters:	none
** Pre-Conditions:	none
** Post-Conditions:	deck shuffled
******************************************************************************************************************************************/
void deck::shuffle()
{
	given_cards_num = 0;

	if (given_cards_num == 0)
	{
		srand(time(NULL));
		card temp;
		temp.set("abc", 99);

		for (int i = 0; i < 999; i++)
		{
			int t = rand() % 52;
			temp = cards[0];
			cards[0] = cards[t];
			cards[t] = temp;
		}
	}
}

void deck::renew()
{
	set_deck();
	shuffle();
}
