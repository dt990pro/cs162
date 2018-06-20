#include "new_animal.h"

new_animal::new_animal() :animal(){}

new_animal::~new_animal(){}

void new_animal::set_age(int n)
{
	age = n;
}

int new_animal::get_age()
{
	return age;
}