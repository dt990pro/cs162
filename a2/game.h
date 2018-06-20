#include "deck.h"
#include "player.h"
#include "dealer.h"

using namespace std;

void int_check(string &);

class game
{
private:
	deck c;
	player *players;
	dealer game_dealer;
	int num_players;

public:
	game();

	void set_players();

	player *get_players();

	dealer get_dealer();

	int get_num_players();

	void set_cards();

	deck get_cards();

	~game();

	void set_play_total();

	void check_renew();

	void pass_de_rhand();

	void display_de_rhand();

	void pass_pl_rhand();

	void display_pl_rhand();

	void set_players_bet();

	void set_cards_total();

	void display_players_info();

	void check_bj(int);

	void hit();

	void dealer_turn();

	void display_dealer_info();

	int all_die();

	void compare();

	void clean_hand_card();
};
