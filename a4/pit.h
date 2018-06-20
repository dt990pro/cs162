#pragma once
#include "event.h"
#include <iostream>

using namespace std;

class pit : public event
{
public:
	pit();
	~pit();
	void set_name();
	void percepts();
	void display_percepts();

private:

};