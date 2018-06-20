#include "animal.h"

class polar_bear :public animal
{
public:
	polar_bear();
	~polar_bear();
	void set_age(int);
	int get_age();

private:
	int age, cost;
};