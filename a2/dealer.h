#include "hand.h"

using namespace std;

class dealer
{
private:
	hand *de_hand;
	int card_total;

public:
	dealer();

	~dealer();

	void set_card_total(int);

	hand *get_de_hand();

	int get_card_total();
};