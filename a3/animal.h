#pragma once
#include<string>

using namespace std;

class animal
{
public:
	animal();
	animal(string);
	~animal();
	void set_name(string);
	string get_name();

protected:
	string name;
};