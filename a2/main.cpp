/*********************************************************************
** Program Filename:	blackjack
** Author:	Jiawei Mo
** Date:	4/24/2016
** Description:	black jack game
** Input:	player num, player bet, player total
** Output:	player info and dealer info
*********************************************************************/
#include "game.h"

/******************************************************************************************************************************************
** Function:	int_check
** Description:	to check if the input is int
** Parameters:	none
** Pre-Conditions:	the input is string 
** Post-Conditions:	may ask user to input again
******************************************************************************************************************************************/
void int_check(string &str)
{
	for (int i = 0; i < strlen(str.c_str()); i++)
	{
		if (str.at(i) < 48 || str.at(i) > 57)
		{
			cout << "need int." << endl << "input: ";
			cin >> str;
			i = -1;
		}
	}
}

int main()
{
	game bj;
	string quit;

	bj.set_cards();
	//bj.get_cards().display();

	bj.set_players();
	bj.set_play_total();

	while (1)
	{
		//dealer gets two cards
		bj.pass_de_rhand();
		bj.display_de_rhand();

		//players gets two cards
		bj.pass_pl_rhand();
		
		//players bet
		bj.set_players_bet();

		//comput cards total
		bj.set_cards_total();

		//display_players_info
		bj.display_players_info();

		//hit or not
		bj.hit();
		for (int i = 0; i < bj.get_num_players(); i++)
		{
			if (bj.get_players()[i].get_card_total() > 21)
			{
				bj.get_players()[i].set_playing_total(bj.get_players()[i].get_playing_total() - bj.get_players()[i].get_bet());
				bj.get_players()[i].set_bet(0);
			}
		}

		//players info agian
		bj.display_players_info();

		//check if all die
		if (bj.all_die() == 1) bj.display_dealer_info();

		if (bj.all_die() == 0)
		{
			//dealer turn
			bj.dealer_turn();

			//dealer info
			bj.display_dealer_info();

			//compare
			bj.compare();
		}

		cout << endl << "each player's amount: " << endl;
		for (int i = 0; i < bj.get_num_players(); i++)
		{
			cout << "player #" << i + 1 << " : " << bj.get_players()[i].get_playing_total() << endl;
			if (bj.get_players()[i].get_playing_total() == 0)
			{
				cout << "amount hits 0, GAME OVER." << endl;
				bj.clean_hand_card();
				return 0;
			}
		}

		while (1)
		{
			cout << endl << "Q for QUIT, N for NEXT TURN: ";
			cin >> quit;

			if (quit == "Q" || quit == "q")
			{
				cout << "Bye." << endl;
				bj.clean_hand_card();
				return 0;
			}

			else if (quit == "N" || quit == "n")
			{
				cout << "--------------------------------------------------" << endl << "next turn." << endl;
				bj.clean_hand_card();
				break;
			}

			else
			{
				cout << "input error!!!";
			}
		}
	}

	return 0;
}
