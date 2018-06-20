#include "zoo.h"

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
			cout << "need int.(>0) " << endl << "input: ";
			cin >> str;
			i = -1;
		}
	}

	while (atoi(str.c_str()) == 0)
	{
		cout << "need int.(>0) " << endl << "input: ";
		cin >> str;
		int_check(str);
	}
}

zoo::zoo()
{
	avg_food_cost = 10;
	total = 15000;
	day = 0;
	num_pb = 0;
	num_penquins = 0;
	num_tigers = 0;
	num_new_animals = 0;
	pb = new polar_bear[num_pb];
	penguins = new penguin[num_penquins];
	tigers = new tiger[num_tigers];
	new_animals = new new_animal[num_new_animals];
}

zoo::~zoo()
{
	delete[]tigers;
	delete[]pb;
	delete[]penguins;
	delete[]new_animals;
}

void zoo::set_name_species(string str)
{
	name_species = str;
}

string zoo::get_name_species()
{
	return name_species;
}

double zoo::get_total()
{
	return total;
}

/******************************************************************************************************************************************
** Function:	display_info
** Description:	to display the info of the day and teh total
** Parameters:	none
** Pre-Conditions:	the input is int
** Post-Conditions:	display day and total or balance.
******************************************************************************************************************************************/
void zoo::display_info(int n)
{
	if (n == 0) cout << "Day: " << day << endl << "Your total: $" << total << endl << endl;
	if (n == 1) cout << "Present balance: $" << total << endl;
}

/******************************************************************************************************************************************
** Function:	add_new_animal
** Description:	to ddd a new animal and set its info.
** Parameters:	name of the species, cost of the species, feed cost times of the species.
** Pre-Conditions:	none
** Post-Conditions:	set a new animal.
******************************************************************************************************************************************/
void zoo::add_new_animal()
{
	string add, cost, times;
	cout << "the name of the new species: ";
	cin >> add;
	set_name_species(add);

	cout << get_name_species() << " stored." << endl << "----------------------------------------------" << endl
		<< "set the cost of the new species: ";
	cin >> cost;
	int_check(cost);
	cost_new_species = atoi(cost.c_str());

	cout << cost_new_species << " stored." << endl << "----------------------------------------------" << endl
		<< "set the times of the avg_food_cost: ";
	cin >> times;
	int_check(times);
	feed_cost_times = atoi(times.c_str());

	cout << feed_cost_times << " stored." << endl << "----------------------------------------------" << endl;
}

/******************************************************************************************************************************************
** Function:	buy_tiger
** Description:	to buy a tiger.
** Parameters:	new tiger and its name.
** Pre-Conditions:	none
** Post-Conditions:	a new tiger bought.
******************************************************************************************************************************************/
tiger zoo::buy_tiger(int n)
{
	tiger new_tiger;
	string name;
	if (n != 0) total -= 10000;
	display_info(1);

	cout << "give name to the tiger: ";
	cin >> name;
	new_tiger.set_name(name);
	new_tiger.set_age(n);

	return new_tiger;
}

/******************************************************************************************************************************************
** Function:	buy_penguin
** Description:	to buy a penguin.
** Parameters:	new penguin and its name.
** Pre-Conditions:	none
** Post-Conditions:	a new penguin bought.
******************************************************************************************************************************************/
penguin zoo::buy_penguin(int n)
{
	penguin new_penguin;
	string name;
	if (n != 0) total -= 1000;
	display_info(1);

	cout << "give name to the penguin: ";
	cin >> name;
	new_penguin.set_name(name);
	new_penguin.set_age(n);

	return new_penguin;
}

/******************************************************************************************************************************************
** Function:	buy_pb
** Description:	to buy a polar_bear.
** Parameters:	new polar_bear and its name.
** Pre-Conditions:	none
** Post-Conditions:	a new polar_bear bought.
******************************************************************************************************************************************/
polar_bear zoo::buy_pb(int n)
{
	polar_bear new_pb;
	string name;
	if (n != 0) total -= 5000;
	display_info(1);

	cout << "give name to the polar bear: ";
	cin >> name;
	new_pb.set_name(name);
	new_pb.set_age(n);

	return new_pb;
}

/******************************************************************************************************************************************
** Function:	buy_new_species
** Description:	to buy a new_species.
** Parameters:	new new_species and its name.
** Pre-Conditions:	none
** Post-Conditions:	a new new_species bought.
******************************************************************************************************************************************/
new_animal zoo::buy_new_species(int n)
{
	new_animal new_species;
	string name;
	if (n != 0) total -= cost_new_species;
	display_info(1);

	cout << "give name to the " << name_species << ": ";
	cin >> name;
	new_species.set_name(name);
	new_species.set_age(n);

	return new_species;
}

/******************************************************************************************************************************************
** Function:	balance_check
** Description:	to check if the balance allows user to buy animals.
** Parameters:	none
** Pre-Conditions:	the name of the animal and it can not be changed.
** Post-Conditions:	may prompt no money to buy a specific animal-return 0. have money to buy-return 1. no money to buy any animal-return 2.
******************************************************************************************************************************************/
int zoo::balance_check(const string name)
{
	if (total < 1000)
	{
		cout << "budget is week. can not buy any animal." << endl;
		return 2;
	}

	if (name == "tiger")
	{
		if (total < 10000)
		{
			cout << "have no money to buy..." << endl;
			return 0;
		}
	}
	if (name == "polarbear")
	{
		if (total < 5000)
		{
			cout << "have no money to buy..." << endl;
			return 0;
		}
	}
	if (name == "penguin")
	{
		if (total < 1000)
		{
			cout << "have no money to buy..." << endl;
			return 0;
		}
	}
	if (name == name_species)
	{
		if (total < cost_new_species)
		{
			cout << "have no money to buy..." << endl;
			return 0;
		}
	}

	return 1;
}

/******************************************************************************************************************************************
** Function:	born
** Description:	a baby borned.
** Parameters:	none
** Pre-Conditions:	none
** Post-Conditions:	a baby will born.
******************************************************************************************************************************************/
void zoo::born(const string name, const int n)
{
	if (name == "tiger")
	{
		tiger *temp;
		num_tigers += 1;
		temp = tigers;
		tigers = new tiger[num_tigers];

		for (int i = 0; i < num_tigers - 1; i++) tigers[i] = temp[i];

		tigers[num_tigers - 1] = buy_tiger(n);
		delete[]temp;
	}

	else if (name == "polarbear")
	{
		polar_bear *temp;
		num_pb += 1;
		temp = pb;
		pb = new polar_bear[num_pb];

		for (int i = 0; i < num_pb - 1; i++) pb[i] = temp[i];

		pb[num_pb - 1] = buy_pb(n);
		delete[]temp;
	}

	else if (name == "penguin")
	{
		penguin *temp;
		num_penquins += 1;
		temp = penguins;
		penguins = new penguin[num_penquins];

		for (int i = 0; i < num_penquins - 1; i++) penguins[i] = temp[i];

		penguins[num_penquins - 1] = buy_penguin(n);
		delete[]temp;
	}

	else if (name == name_species)
	{
		new_animal *temp;
		num_new_animals += 1;
		temp = new_animals;
		new_animals = new new_animal[num_new_animals];

		for (int i = 0; i < num_new_animals - 1; i++) new_animals[i] = temp[i];

		new_animals[num_new_animals - 1] = buy_new_species(n);
		delete[]temp;
	}
}


/******************************************************************************************************************************************
** Function:	buy_animal
** Description:	to buy an animal.
** Parameters:	species's name.
** Pre-Conditions:	none
** Post-Conditions:	a new species bought.
******************************************************************************************************************************************/
void zoo::buy_animal(int n)
{
	string name;
	int balance, old = 0;

	cout << "the name:" << endl << "tiger" << endl << "polarbear" << endl << "penquin" << endl << name_species << endl << "which one: ";
	cin >> name;

	while (1)
	{
		if (n == 3)
		{
			balance = balance_check(name);
			if (balance == 0)
			{
				cout << "buy another one: ";
				cin >> name;
			}
			else if (balance == 1)
			{
				if (name == "tiger" || name == "polarbear" || name == "penguin" || name == name_species)
				{
					born(name, n);
					break;
				}
				else
				{
					cout << "no name fit." << endl << "input again: ";
					cin >> name;
				}
			}
		}
		if (n == 0)
		{
			if (name == "tiger")
			{
				for (int i = 0; i < num_tigers; i++)
				{
					if (tigers[i].get_age() > 3) old = 1;
				}
				if (old == 1)
				{
					born(name, n);
					break;
				}
				else
				{
					cout << "no tiger younger than 3." << endl << "input again: ";
					cin >> name;
				}
			}
			else if (name == "polarbear")
			{
				for (int i = 0; i < num_pb; i++)
				{
					if (pb[i].get_age() > 3) old = 1;
				}
				if (old == 1)
				{
					born(name, n);
					break;
				}
				else
				{
					cout << "no polar bear younger than 3." << endl << "input again: ";
					cin >> name;
				}
			}
			else if (name == "penguin")
			{
				for (int i = 0; i < num_penquins; i++)
				{
					if (penguins[i].get_age() > 3) old = 1;
				}
				if (old == 1)
				{
					born(name, n);
					break;
				}
				else
				{
					cout << "no penguin younger than 3." << endl << "input again: ";
					cin >> name;
				}
			}
			else if (name == name_species)
			{
				for (int i = 0; i < num_new_animals; i++)
				{
					if (new_animals[i].get_age() > 3) old = 1;
				}
				if (old == 1)
				{
					born(name, n);
					break;
				}
				else
				{
					cout << "no " << name_species << " younger than 3." << endl << "input again : ";
					cin >> name;
				}
			}
			else
			{
				cout << "no name fit." << endl << "input again: ";
				cin >> name;
			}
		}
	}
	cout << "Budget states: ";
	if (total < 5000) cout << "Low Balance!!!" << endl;
	if (total > 4999 && total < 10000) cout << "Healthy Budget..." << endl;
	if (total > 9999 && total < 50000) cout << "Wealthy!!!" << endl;
	if (total > 49999) cout << "A Mountain of Money!!!" << endl;
}

/******************************************************************************************************************************************
** Function:	choose_feed_type
** Description:	choose what to feed animals.
** Parameters:	species's name.
** Pre-Conditions:	none
** Post-Conditions:	a feed type chose.
******************************************************************************************************************************************/
int zoo::choose_feed_type()
{
	string str;
	cout << endl << "Three different types of feed:" << endl;
	cout << "Generic: Base case, behaves normally. -1" << endl;
	cout << "Premium: Twice as expensive for all animals, sickness becomes half as likely to occur. -2" << endl;
	cout << "Cheap: Half as expensive for all animals, sickness becomes twice as likely to occur. -3" << endl;
	cout << "your choice: ";
	cin >> str;
	int_check(str);
	feed_type = atoi(str.c_str());
	while (feed_type > 3)
	{
		cout << "no feed type fit." << endl << "input agian: ";
		cin >> str;
		int_check(str);
		feed_type = atoi(str.c_str());
	}

	return feed_type;
}

/******************************************************************************************************************************************
** Function:	stats
** Description:	display stats
** Parameters:	none
** Pre-Conditions:	none
** Post-Conditions:	stats printed.
******************************************************************************************************************************************/
void zoo::stats()
{
	cout << "Zoo Stats:" << endl;
	cout << "you have " << num_tigers << " tigers." << endl;
	for (int i = 0; i < num_tigers; i++)
	{
		cout << "name" << "\t\t" << "age" << endl;
		cout << tigers[i].get_name() << "\t\t" << tigers[i].get_age() << endl;
	}
	cout << "you have " << num_pb << " polar bears." << endl;
	for (int i = 0; i < num_pb; i++)
	{
		cout << "name" << "\t\t" << "age" << endl;
		cout << pb[i].get_name() << "\t\t" << pb[i].get_age() << endl;
	}
	cout << "you have " << num_penquins << " penguins." << endl;
	for (int i = 0; i < num_penquins; i++)
	{
		cout << "name" << "\t\t" << "age" << endl;
		cout << penguins[i].get_name() << "\t\t" << penguins[i].get_age() << endl;
	}
	cout << "you have " << num_new_animals << " " << name_species << endl;
	for (int i = 0; i < num_new_animals; i++)
	{
		cout << "name" << "\t\t" << "age" << endl;
		cout << new_animals[i].get_name() << "\t\t" << new_animals[i].get_age() << endl;
	}
	cout << endl;
}

/******************************************************************************************************************************************
** Function:	time_goes_by
** Description:	set stats when a new day comes.
** Parameters:	none
** Pre-Conditions:	none
** Post-Conditions:	stats set.
******************************************************************************************************************************************/
int zoo::time_goes_by()
{
	day += 1;
	display_info(0);
	//older
	for (int i = 0; i < num_tigers; i++) tigers[i].set_age(tigers[i].get_age() + 1);
	for (int i = 0; i < num_pb; i++) pb[i].set_age(pb[i].get_age() + 1);
	for (int i = 0; i < num_penquins; i++) penguins[i].set_age(penguins[i].get_age() + 1);
	for (int i = 0; i < num_new_animals; i++) new_animals[i].set_age(new_animals[i].get_age() + 1);
	//feed cost
	double times;
	cout << "now, feed them what?" << endl;
	choose_feed_type();
	if (feed_type == 1) times = 1;
	if (feed_type == 2) times = 2;
	if (feed_type == 3) times = 0.5;

	if (num_tigers > 0)
	{
		total -= 5 * avg_food_cost * times;
		display_info(1);
	}
	if (total < 1) return 1;
	if (num_pb > 0)
	{
		total -= 3 * avg_food_cost * times;
		display_info(1);
	}
	if (total < 1) return 1;
	if (num_penquins > 0)
	{
		total -= 1 * avg_food_cost * times;
		display_info(1);
	}
	if (total < 1) return 1;
	if (num_new_animals > 0)
	{
		total -= feed_cost_times * avg_food_cost * times;
		display_info(1);
	}
	if (total < 1) return 1;

	//stats
	stats();
	if (total > 0) return 0;
}

/******************************************************************************************************************************************
** Function:	boom
** Description:	a tiger day.
** Parameters:	the bonus-int
** Pre-Conditions:	none
** Post-Conditions:	get bonus, added to total.
******************************************************************************************************************************************/
void zoo::boom()
{
	int b;
	srand(time(NULL));
	b = rand() % 251 + 250;
	cout << "$" << b << endl;
	total += b;
	display_info(1);
}

/******************************************************************************************************************************************
** Function:	dead
** Description:	an animal will die.
** Parameters:	species name, the animal name
** Pre-Conditions:	none
** Post-Conditions:	an animal died.
******************************************************************************************************************************************/
void zoo::dead()
{
	string sname, name;
	int name_match = 0, dead_num;

	cout << "Devote which animal?" << endl << "tiger" << endl << "polarbear" << endl << "penquin" << endl << name_species << endl << "which one: ";
	while (1)
	{
		cin >> sname;
		if (sname == "tiger")
		{
			if (num_tigers == 0)
			{
				cout << "no tiger to sacrifice. find another one: ";
			}
			else
			{
				cout << "the name of the tiger: ";
				while (1)
				{
					cin >> name;
					for (int i = 0; i < num_tigers; i++)
					{
						if (name == tigers[i].get_name())
						{
							name_match = 1;
							dead_num = i;
							break;
						}
					}
					if (name_match == 0)
					{
						cout << "no name matched. again: ";
					}
					if (name_match == 1) break;
				}
				cout << tigers[dead_num].get_name() << " died." << endl;
				tiger *temp;
				num_tigers -= 1;
				temp = tigers;
				tigers = new tiger[num_tigers];

				for (int i = 0; i < dead_num; i++) tigers[i] = temp[i];
				for (int i = dead_num + 1; i < num_tigers + 1; i++) tigers[i - 1] = temp[i];

				delete[]temp;
				break;
			}
		}
		else if (sname == "polarbear")
		{
			if (num_pb == 0)
			{
				cout << "no polar bear to sacrifice. find another one: ";
			}
			else
			{
				cout << "the name of the polar bear: ";
				while (1)
				{
					cin >> name;
					for (int i = 0; i < num_pb; i++)
					{
						if (name == pb[i].get_name())
						{
							name_match = 1;
							dead_num = i;
							break;
						}
					}
					if (name_match == 0)
					{
						cout << "no name matched. again: ";
					}
					if (name_match == 1) break;
				}
				cout << pb[dead_num].get_name() << " died." << endl;
				polar_bear *temp;
				num_pb -= 1;
				temp = pb;
				pb = new polar_bear[num_pb];

				for (int i = 0; i < dead_num; i++) pb[i] = temp[i];
				for (int i = dead_num + 1; i < num_pb + 1; i++) pb[i - 1] = temp[i];

				delete[]temp;
				break;
			}
		}
		else if (sname == "penguin")
		{
			if (num_penquins == 0)
			{
				cout << "no penguin to sacrifice. find another one: ";
			}
			else
			{
				cout << "the name of the penguin: ";
				while (1)
				{
					cin >> name;
					for (int i = 0; i < num_penquins; i++)
					{
						if (name == penguins[i].get_name())
						{
							name_match = 1;
							dead_num = i;
							break;
						}
					}
					if (name_match == 0)
					{
						cout << "no name matched. again: ";
					}
					if (name_match == 1) break;
				}
				cout << penguins[dead_num].get_name() << " died." << endl;
				penguin *temp;
				num_penquins -= 1;
				temp = penguins;
				penguins = new penguin[num_penquins];

				for (int i = 0; i < dead_num; i++) penguins[i] = temp[i];
				for (int i = dead_num + 1; i < num_penquins + 1; i++) penguins[i - 1] = temp[i];

				delete[]temp;
				break;
			}
		}
		else if (sname == name_species)
		{
			if (num_new_animals == 0)
			{
				cout << "no " << name_species << " to sacrifice. find another one: ";
			}
			else
			{
				cout << "the name of the " << name_species << ": ";
				while (1)
				{
					cin >> name;
					for (int i = 0; i < num_new_animals; i++)
					{
						if (name == new_animals[i].get_name())
						{
							name_match = 1;
							dead_num = i;
							break;
						}
					}
					if (name_match == 0)
					{
						cout << "no name matched. again: ";
					}
					if (name_match == 1) break;
				}
				cout << new_animals[dead_num].get_name() << " died." << endl;
				new_animal *temp;
				num_new_animals -= 1;
				temp = new_animals;
				new_animals = new new_animal[num_new_animals];

				for (int i = 0; i < dead_num; i++) new_animals[i] = temp[i];
				for (int i = dead_num + 1; i < num_new_animals + 1; i++) new_animals[i - 1] = temp[i];

				delete[]temp;
				break;
			}
		}
		else
		{
			cout << "no name fit." << endl << "input again: ";
		}
	}
}

/******************************************************************************************************************************************
** Function:	events
** Description:	random events.
** Parameters:	num of events-int, input file.
** Pre-Conditions:	none
** Post-Conditions:	get into one event.
******************************************************************************************************************************************/
void zoo::events()
{
	int e, death_point;
	ifstream input;
	string s;
	input.open("event.txt");
	srand(time(NULL));
	e = rand() % 100;
	cin.ignore();
	cout << "Random Event." << endl;
	if (e > 59)
	{
		for (int i = 0; i < 1; i++)
			getline(input, s);
		cout << s << endl;
		return;
	}
	if (feed_type == 1) death_point = 10;
	if (feed_type == 2) death_point = 5;
	if (feed_type == 3) death_point = 20;
	if (e < death_point)
	{
		for (int i = 0; i < 3; i++)
			getline(input, s);
		cout << s << endl;
		cout << "death percentage: " << death_point << "%" << endl;
		dead();
		return;
	}
	if (e > 9 && e < 50)
	{
		for (int i = 0; i < 2; i++)
			getline(input, s);
		cout << s << endl;
		if (num_tigers == 0)
		{
			cout << "but no tiger in the zoo. no bonus." << endl;
			return;
		}
		boom();
		return;
	}
	if (e > 49 && e < 60)
	{
		for (int i = 0; i < 4; i++)
			getline(input, s);
		cout << s << endl;
		buy_animal(0);
		return;
	}
}

/******************************************************************************************************************************************
** Function:	payoff
** Description:	get payoff.
** Parameters:	get money-double
** Pre-Conditions:	none
** Post-Conditions:	payoff added to total.
******************************************************************************************************************************************/
void zoo::payoff()
{
	double money;
	cout << "Payoff:" << endl;
	cout << "tigers-" << endl;
	for (int i = 0; i < num_tigers; i++)
	{
		if (tigers[i].get_age() < 3)
		{
			money = 2 * 1000;
			cout << "+ " << money << endl;
			total += money;
		}
		else
		{
			money = 1000;
			cout << "+ " << money << endl;
			total += money;
		}
	}
	cout << "polar bears-" << endl;
	for (int i = 0; i < num_pb; i++)
	{
		if (pb[i].get_age() < 3)
		{
			money = 2 * 500;
			cout << "+ " << money << endl;
			total += money;
		}
		else
		{
			money = 500;
			cout << "+ " << money << endl;
			total += money;
		}
	}
	cout << "penguins-" << endl;
	for (int i = 0; i < num_penquins; i++)
	{
		if (penguins[i].get_age() < 3)
		{
			money = 2 * 100;
			cout << "+ " << money << endl;
			total += money;
		}
		else
		{
			money = 100;
			cout << "+ " << money << endl;
			total += money;
		}
	}
	cout << name_species << "-" << endl;
	for (int i = 0; i < num_new_animals; i++)
	{
		if (new_animals[i].get_age() < 3)
		{
			money = 2 * cost_new_species / 10;
			cout << "+ " << money << endl;
			total += money;
		}
		else
		{
			money = cost_new_species / 10;
			cout << "+ " << money << endl;
			total += money;
		}
	}
	display_info(1);
}