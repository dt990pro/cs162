#pragma once
#include<string>

using namespace std;

class card
{
private:
	string suit;
	int value;

public:
	card();

	void set(string, int);

	string get_suit();

	int get_value();

	~card();

	void display();
};
