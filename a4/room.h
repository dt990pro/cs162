#pragma once

class room
{
public:
	room();
	~room();
	virtual void set_name() = 0;
	void set_p(int, int);
	virtual int check_position(int, int);
	virtual char get_name();
	virtual void display_percepts();

protected:
	char name;
	int px;
	int py;
};