#include "event.h"
#include <iostream>

using namespace std;

class bat : public event
{
public:
	bat();
	~bat();
	void set_name();
	void percepts();
	void display_percepts();

private:

};