#include "pbear.h"
#include "penguin.h"
#include "tiger.h"
#include "new_animal.h"
#include<iostream>
#include<ctime>
#include<fstream>
#include<cstring>
#include<cstdlib>

using namespace std;

void int_check(string &);

class zoo
{
public:
	zoo();
	~zoo();
	void set_name_species(string);
	string get_name_species();
	double get_total();
	void display_info(int);
	void add_new_animal();
	tiger buy_tiger(int);
	penguin buy_penguin(int);
	polar_bear buy_pb(int);
	new_animal buy_new_species(int);
	int balance_check(const string);
	void buy_animal(int);
	int choose_feed_type();
	void stats();
	int time_goes_by();
	void born(const string, const int);
	void boom();
	void dead();
	void events();
	void payoff();

private:
	polar_bear *pb;
	penguin *penguins;
	tiger *tigers;
	new_animal *new_animals;
	string name_species;
	int cost_new_species, feed_cost_times;
	int num_pb, num_penquins, num_tigers, num_new_animals, day;

	double total;
	int avg_food_cost, feed_type;
};