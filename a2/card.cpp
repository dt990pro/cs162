#include<iostream>
#include<string>
#include "card.h"

using namespace std;


card::card(){}

void card::set(string str, int n)
{
	suit = str;
	value = n;
}

string card::get_suit()
{
	return suit;
}

int card::get_value()
{
	return value;
}

card::~card(){}
/******************************************************************************************************************************************
** Function:	display
** Description:	to display each card info
** Parameters:	none
** Pre-Conditions:	none
** Post-Conditions:	each card info displayed. 
******************************************************************************************************************************************/
void card::display()
{
	if (value == 1) cout << suit << "\t" << "A" << "\t";
	if (value == 11) cout << suit << "\t" << "J" << "\t";
	if (value == 12) cout << suit << "\t" << "Q" << "\t";
	if (value == 13) cout << suit << "\t" << "K" << "\t";
	if (!(value == 1 || value == 11 || value == 12 || value == 13)) cout << suit << "\t" << value << "\t";
}