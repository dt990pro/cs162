#include "hand.h"

hand::hand(){}
/******************************************************************************************************************************************
** Function:	pass
** Description:	to pass two cards
** Parameters:	int-num of cards
** Pre-Conditions:	none
** Post-Conditions:	give two cards
******************************************************************************************************************************************/
void hand::pass(card cards[], int &located)
{
	cards_num = 2;
	hand_card = new card[cards_num];
	
	for (int i = 0; i < cards_num; i++)
	{
		hand_card[i] = cards[located];
		located += 1;
	}
}
/******************************************************************************************************************************************
** Function:	hit
** Description:	to pass a card if someone hits
** Parameters:	int-num of cards
** Pre-Conditions:	none
** Post-Conditions:	give a card
******************************************************************************************************************************************/
void hand::hit(card cards[], int &located)
{
	cards_num += 1;

	card *temp;
	temp = hand_card;
	hand_card = new card[cards_num];

	for (int i = 0; i < cards_num - 1; i++)
	{
		hand_card[i] = temp[i];
	}

	hand_card[cards_num - 1] = cards[located];
	located += 1;
	//delete 
	delete[] temp;
}

card *hand::get_hand_card()
{
	return hand_card;
}

int hand::get_cards_num()
{
	return cards_num;
}

hand::~hand(){}
