/******************************************************
** Program:	Zoo Tycoon
** Author:	Jiawei Mo
** Date: 05/07/2016
** Description:	Zoo Tycoon game
** Input:	Maybe new animal. Animals' name. 
** Output:	game prompt.
******************************************************/
#include "zoo.h"
#include<iostream>

using namespace std;

int main()
{
	zoo z;
	string add_animal, str;

	cout << "Zoo Tycoon" << endl;
	z.display_info(0);

	cout << "Want a new animal? (Y, N): ";
	cin >> add_animal;
	while (1)
	{
		if (add_animal == "Y" || add_animal == "y")
		{
			z.add_new_animal();
			break;
		}
		else if (add_animal == "N" || add_animal == "n") break;
		else
		{
			cout << "error. (Y, N): ";
			cin >> add_animal;
		}
	}

	cout << "now, buy an animal to start." << endl;
	z.buy_animal(3);

	cout << "buy another one? Y to confirm: ";
	cin >> str;
	if (str == "Y" || str == "y") z.buy_animal(3);

	while (1)
	{
		if (z.time_goes_by() == 1)
		{
			cout << "insufficient funds!!!" << endl << "game over." << endl;
			break;
		}

		//random event
		z.events();
		//payoff
		z.payoff();

		if (z.get_total() < 1)
		{
			cout << "Game Over." << endl;
			break;
		}

		//buy
		cout << "buy an animal? Y-buy, Any other keyboard-continue: ";
		cin >> str;
		if (str == "Y" || str == "y") z.buy_animal(3);

		//quit
		cout << "Want to quit? Q-quit, Any other keyboard-continue: ";
		cin >> str;
		if (str == "Q" || str == "q") break;
	}
	cout << "Thanks" << endl;

	return 0;
}