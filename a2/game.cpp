#include "game.h"

game::game(){}
/******************************************************************************************************************************************
** Function:	set_players
** Description:	to set players
** Parameters:	string-play_num to hold players num
** Pre-Conditions:	none
** Post-Conditions:	players set up.
******************************************************************************************************************************************/
void game::set_players()
{
	string player_num;

	cout << "how many players: ";
	cin >> player_num;
	int_check(player_num);
	num_players = atoi(player_num.c_str());

	while (num_players < 1)
	{
		cout << "at least 1 player." << endl << "how many players: ";
		cin >> player_num;
		int_check(player_num);
		num_players = atoi(player_num.c_str());
	}

	players = new player[num_players];
}

player *game::get_players()
{
	return players;
}

dealer game::get_dealer()
{
	return game_dealer;
}

int game::get_num_players()
{
	return num_players;
}

void game::set_cards()
{
	c.set_deck();
}

deck game::get_cards()
{
	return c;
}

game::~game()
{
	delete[] players;
}
/******************************************************************************************************************************************
** Function:	set_play_total
** Description:	to set players playing total
** Parameters:	string-play_total to hold playing total
** Pre-Conditions:	none
** Post-Conditions:	playing total set up. 
******************************************************************************************************************************************/
void game::set_play_total()
{
	string play_total;

	for (int i = 0; i < num_players; i++)
	{
		cout << "player #" << i + 1 << " your total amount. (> 0): ";
		cin >> play_total;
		int_check(play_total);

		while (atoi(play_total.c_str()) < 1)
		{
			cout << "> 0: ";
			cin >> play_total;
			int_check(play_total);
		}

		players[i].set_playing_total(atoi(play_total.c_str()));
	}
}
/******************************************************************************************************************************************
** Function:	check_renew
** Description:	to check if cards used up
** Parameters:	none
** Pre-Conditions:	none
** Post-Conditions:	cards may be renewed. 
******************************************************************************************************************************************/
void game::check_renew()
{
	if (c.get_given_cards_num() == 52 || c.get_given_cards_num() == 51)
	{
		cout << "cards used up, renewed." << endl;
		c.renew();
	}
}
/******************************************************************************************************************************************
** Function:	pass_de_rhand
** Description:	to pass cards to dealer right hand
** Parameters:	none
** Pre-Conditions:	none
** Post-Conditions:	cards passed to dealer.
******************************************************************************************************************************************/
void game::pass_de_rhand()
{
	check_renew();
	game_dealer.get_de_hand()[0].pass(c.get_cards(), c.get_given_cards_num());
}
/******************************************************************************************************************************************
** Function:	display_de_rhand
** Description:	to display dealer right hand
** Parameters:	none
** Pre-Conditions:	none
** Post-Conditions:	dealer right hand displayed.
******************************************************************************************************************************************/
void game::display_de_rhand()
{
	cout << "dealer" << "\t\t\t";
	for (int i = 0; i < game_dealer.get_de_hand()[0].get_cards_num(); i++)
	{
		cout << "-----" << "\t";
		if (i == 0) cout << "?????" << "\t" << "?" << "\t";
		if (i != 0) game_dealer.get_de_hand()[0].get_hand_card()[i].display();
	}
	
	cout << endl;
}
/******************************************************************************************************************************************
** Function:	pass_pl_rhand
** Description:	to pass cards to players right hand
** Parameters:	none
** Pre-Conditions:	none
** Post-Conditions:	cards passed to players. 
******************************************************************************************************************************************/
void game::pass_pl_rhand()
{
	for (int i = 0; i < num_players; i++)
	{
		check_renew();
		players[i].get_pl_hand()[0].pass(c.get_cards(), c.get_given_cards_num());
	}
}
/******************************************************************************************************************************************
** Function:	display_pl_rhand
** Description:	to display players right hand
** Parameters:	none
** Pre-Conditions:	none
** Post-Conditions:	players right hand displayed. 
******************************************************************************************************************************************/
void game::display_pl_rhand()
{
	for (int i = 0; i < num_players; i++)
	{
		cout << "player #" << i + 1 << "\t\t";
		for (int j = 0; j < players[i].get_pl_hand()[0].get_cards_num(); j++)
		{
			cout << "-----" << "\t";
			players[i].get_pl_hand()[0].get_hand_card()[j].display();
		}
		cout << endl;
	}
}
/******************************************************************************************************************************************
** Function:	set_players_bet
** Description:	to set up bet for dealer and players
** Parameters:	string-bet_input to hold bet
** Pre-Conditions:	none
** Post-Conditions:	players and dealer bet set up.
******************************************************************************************************************************************/
void game::set_players_bet()
{
	string bet_input;

	for (int i = 0; i < num_players; i++)
	{
		cout << "player #" << i + 1 << " your bet: ";
		cin >> bet_input;
		int_check(bet_input);

		while (atoi(bet_input.c_str()) > players[i].get_playing_total() || atoi(bet_input.c_str()) < 1)
		{
			cout << "bet should be at least 1 and not over your playing total." << endl << "input again: ";
			cin >> bet_input;
			int_check(bet_input);
		}

		players[i].set_bet(atoi(bet_input.c_str()));
	}
}
/******************************************************************************************************************************************
** Function:	set_cards_total
** Description:	to set up cards total for dealer and players
** Parameters:	int-ct to hold cards total
** Pre-Conditions:	none
** Post-Conditions:	players and dealer cards total set up. 
******************************************************************************************************************************************/
void game::set_cards_total()
{
	int ct;
	//dealer
	ct = 0;
	for (int i = 0; i < game_dealer.get_de_hand()[0].get_cards_num(); i++)
	{
		if (game_dealer.get_de_hand()[0].get_hand_card()[i].get_value() == 1) ct += 11;

		else if (game_dealer.get_de_hand()[0].get_hand_card()[i].get_value() > 9) ct += 10;

		else ct += game_dealer.get_de_hand()[0].get_hand_card()[i].get_value();
	}

	if (ct > 21)
	{
		ct = 0;

		for (int i = 0; i < game_dealer.get_de_hand()[0].get_cards_num(); i++)
		{
			if (game_dealer.get_de_hand()[0].get_hand_card()[i].get_value() == 1) ct += 1;

			else if (game_dealer.get_de_hand()[0].get_hand_card()[i].get_value() > 9) ct += 10;

			else ct += game_dealer.get_de_hand()[0].get_hand_card()[i].get_value();
		}
	}
	game_dealer.set_card_total(ct);

	//players
	for (int i = 0; i < num_players; i++)
	{
		ct = 0;

		for (int j = 0; j < players[i].get_pl_hand()[0].get_cards_num(); j++)
		{
			if (players[i].get_pl_hand()[0].get_hand_card()[j].get_value() == 1) ct += 11;

			else if (players[i].get_pl_hand()[0].get_hand_card()[j].get_value() > 9) ct += 10;

			else ct += players[i].get_pl_hand()[0].get_hand_card()[j].get_value();
		}

		if (ct > 21)
		{
			ct = 0;

			for (int j = 0; j < players[i].get_pl_hand()[0].get_cards_num(); j++)
			{
				if (players[i].get_pl_hand()[0].get_hand_card()[j].get_value() == 1) ct += 1;

				else if (players[i].get_pl_hand()[0].get_hand_card()[j].get_value() > 9) ct += 10;

				else ct += players[i].get_pl_hand()[0].get_hand_card()[j].get_value();
			}
		}
		players[i].set_card_total(ct);
	}
}
/******************************************************************************************************************************************
** Function:	display_players_info
** Description:	to display players info
** Parameters:	none
** Pre-Conditions:	none
** Post-Conditions:	players info printed. 
******************************************************************************************************************************************/
void game::display_players_info()
{
	cout << "present players info:" << endl;
	for (int i = 0; i < num_players; i++)
	{
		cout << "player #" << i + 1 << "\t\t";
		cout << "-----" << "\t" << "total: " << "\t" << players[i].get_playing_total() << "\t" << "-----" << "\t" << "bet: " << "\t" << players[i].get_bet() << endl;
		cout << "\t\t\t";
		for (int j = 0; j < players[i].get_pl_hand()[0].get_cards_num(); j++)
		{
			cout << "-----" << "\t";
			players[i].get_pl_hand()[0].get_hand_card()[j].display();
		}
		cout << endl << "card total: " << players[i].get_card_total();
		cout << endl << endl;
	}
}
/******************************************************************************************************************************************
** Function:	check_bj
** Description:	to check if players get BJ
** Parameters:	none
** Pre-Conditions:	none
** Post-Conditions:	may print out BJ. 
******************************************************************************************************************************************/
void game::check_bj(int n)
{
	if (players[n].get_card_total() == 21) cout << "BLACK JACK!!! (but you still can hit if you want...)" << endl;
}
/******************************************************************************************************************************************
** Function:	hit
** Description:	to ask if players want card and give them cards
** Parameters:	string-whether check
** Pre-Conditions:	none
** Post-Conditions:	players may get new card. 
******************************************************************************************************************************************/
void game::hit()
{
	string hit_check;

	for (int i = 0; i < num_players; i++)
	{
		while (1)
		{
			check_renew();
			check_bj(i);
			cout << "player #" << i + 1 << " hit? (yes/no): ";
			cin >> hit_check;

			if (hit_check == "yes" || hit_check == "Yes" || hit_check == "YES")
			{
				players[i].get_pl_hand()[0].hit(c.get_cards(), c.get_given_cards_num());
				set_cards_total();
				cout << "your card: " << endl;

				for (int j = 0; j < players[i].get_pl_hand()[0].get_cards_num(); j++)
				{
					players[i].get_pl_hand()[0].get_hand_card()[j].display();
					cout << endl;
				}

				if (players[i].get_card_total() > 21)
				{
					cout << "BUST!!!" << endl;
					break;
				}
				cout << endl;
			}

			else if (hit_check == "no" || hit_check == "No" || hit_check == "NO")
			{
				break;
			}

			else cout << "input error." << endl;
		}
	}
}
/******************************************************************************************************************************************
** Function:	dealer_turn
** Description:	to determine whether dealer gets new card
** Parameters:	none
** Pre-Conditions:	none
** Post-Conditions:	dealer may gey new card.
******************************************************************************************************************************************/
void game::dealer_turn()
{
	cout << "dealer turn:" << endl;
	while (game_dealer.get_card_total() < 17)
	{
		game_dealer.get_de_hand()[0].hit(c.get_cards(), c.get_given_cards_num());
		set_cards_total();
	}

	if (game_dealer.get_card_total() > 21) cout << "dealer BUST!!! (^o^)" << endl;
}
/******************************************************************************************************************************************
** Function:	display_dealer_info
** Description:	to display dealer's info
** Parameters:	none
** Pre-Conditions:	none
** Post-Conditions:	dealer's info printed.
******************************************************************************************************************************************/
void game::display_dealer_info()
{
	cout << "dealer" << "\t\t\t";
	for (int i = 0; i < game_dealer.get_de_hand()[0].get_cards_num(); i++)
	{
		cout << "-----" << "\t";
		game_dealer.get_de_hand()[0].get_hand_card()[i].display();
	}

	cout << endl << "card total: " << game_dealer.get_card_total() << endl;
}
/******************************************************************************************************************************************
** Function:	all_die
** Description:	to check if all players bust when they hit
** Parameters:	int-number of busted players
** Pre-Conditions:	none
** Post-Conditions:	if all players bust then return 1 otherwise return 0.
******************************************************************************************************************************************/
int game::all_die()
{
	int dead = 0;

	for (int i = 0; i < num_players; i++)
	{
		if (players[i].get_bet() == 0) dead += 1;
	}

	if (dead == num_players) return 1;
	if (dead != num_players) return 0;
}
/******************************************************************************************************************************************
** Function:	compare
** Description:	to compare players total with dealer total
** Parameters:	none
** Pre-Conditions:	none
** Post-Conditions:	players may win or loose or remain their playing totals. 
******************************************************************************************************************************************/
void game::compare()
{
	if (game_dealer.get_card_total() > 21)
	{
		for (int i = 0; i < num_players; i++)
		{
			if (players[i].get_card_total() <= 21)
			{
				players[i].set_playing_total(players[i].get_playing_total() + players[i].get_bet());
				players[i].set_bet(0);
			}
		}
	}

	if (game_dealer.get_card_total() < 21)
	{
		for (int i = 0; i < num_players; i++)
		{
			if (players[i].get_card_total() < game_dealer.get_card_total())
			{
				players[i].set_playing_total(players[i].get_playing_total() - players[i].get_bet());
				players[i].set_bet(0);
			}

			if (players[i].get_card_total() == game_dealer.get_card_total()) players[i].set_bet(0);

			if (players[i].get_card_total() > game_dealer.get_card_total() && players[i].get_card_total() < 21)
			{
				players[i].set_playing_total(players[i].get_playing_total() + players[i].get_bet());
				players[i].set_bet(0);
			}

			if (players[i].get_card_total() == 21)
			{
				players[i].set_playing_total(players[i].get_playing_total() + players[i].get_bet() * 2);
				players[i].set_bet(0);
			}
		}
	}

	if (game_dealer.get_card_total() == 21)
	{
		for (int i = 0; i < num_players; i++)
		{
			if (players[i].get_card_total() == 21) players[i].set_bet(0);
			if (players[i].get_card_total() < 21)
			{
				players[i].set_playing_total(players[i].get_playing_total() - players[i].get_bet());
				players[i].set_bet(0);
			}
		}
	}
}
/******************************************************************************************************************************************
** Function:	clean_hand_card
** Description:	to delete cards in the hand
** Parameters:	none
** Pre-Conditions:	none
** Post-Conditions:	delete cards in the hand
******************************************************************************************************************************************/
void game::clean_hand_card()
{
	for (int i = 0; i < num_players; i++)
	{
		delete[] players[i].get_pl_hand()[0].get_hand_card();
	}

	delete[] game_dealer.get_de_hand()[0].get_hand_card();
}