#pragma once
#include "room.h"

class event : public room
{
public:
	event();
	~event();
	virtual void percepts() = 0;

private:

};