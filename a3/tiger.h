#include "animal.h"

class tiger :public animal
{
public:
	tiger();
	~tiger();
	void set_age(int);
	int get_age();
	void set_bonus(float);
	float get_bonus();

private:
	int age, cost;
	float bonus;
};