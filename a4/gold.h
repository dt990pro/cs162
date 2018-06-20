#include "event.h"
#include <iostream>

using namespace std;

class gold : public event
{
public:
	gold();
	~gold();
	void set_name();
	void percepts();
	void display_percepts();

private:

};