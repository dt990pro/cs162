#pragma once
#include "event.h"
#include <iostream>

using namespace std;

class wumpus : public event
{
public:
	wumpus();
	~wumpus();
	void set_name();
	void percepts();
	void display_percepts();

private:
	int dead;
};