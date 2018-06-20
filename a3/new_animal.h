#include "animal.h"

class new_animal :public animal
{
public:
	new_animal();
	~new_animal();
	void set_age(int);
	int get_age();
	void set_cost(int);
	int get_cost();

private:
	int age;
};