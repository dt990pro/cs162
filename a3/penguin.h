#include "animal.h"

class penguin :public animal
{
public:
	penguin();
	~penguin();
	void set_age(int);
	int get_age();

private:
	int age, cost;
};