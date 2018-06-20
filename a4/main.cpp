/******************************************************
** Program:	Wumpus Hunter
** Author:	Jiawei Mo
** Date:	05/21/2016
** Description:	the game to hunt wumpus
** Input:	the side length of the square map
** Output:	win, play again
******************************************************/
#include "wumpus.h"
#include "bat.h"
#include "pit.h"
#include "gold.h"
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

/******************************************************************************************************************************************
** Function:	comd
** Description:	to check if the command line is valid
** Parameters:	none
** Pre-Conditions:	command line info
** Post-Conditions:	may ask user to input again
******************************************************************************************************************************************/
int comd(int argc, char *argv[])
{
	if (argc != 3) return 0;
	if (!(argv[1][0] == '-' && argv[1][1] == 's' && argv[1][2] == '\0')) return 0;
	
	for (int i = 0; i < strlen(argv[2]); i++)
	{
		if (argv[2][i] < 48 || argv[2][i] > 57)
		{
			cout << "need int." << endl;
			return 0;
		}
	}

	if (atoi(argv[2]) < 4 || atoi(argv[2]) > 9)
	{
		cout << "need int.(>3 U <10)" << endl;
		return 0;
	}

	return atoi(argv[2]);
}

/******************************************************************************************************************************************
** Function:	display_map
** Description:	to display the map
** Parameters:	none
** Pre-Conditions:	array of map and num of side
** Post-Conditions:	map displayed
******************************************************************************************************************************************/
void display_map(char **map, int comd_num)
{
	for (int i = 0; i < comd_num + 1; i++)
	{
		for (int j = 0; j < comd_num + 1; j++)
			cout << map[i][j] << " ";
		cout << endl;
	}
}

/******************************************************************************************************************************************
** Function:	buildmap
** Description:	to set up info on the map
** Parameters:	none
** Pre-Conditions:	events, map, lenth of side
** Post-Conditions:	map displayed
******************************************************************************************************************************************/
void buildmap(room **rooms, char **map, int comd_num)
{
	for (int i = 0; i < comd_num + 1; i++)
	{
		map[i] = new char[comd_num + 1];
	}
	
	//set r
	for (int i = 0; i < comd_num + 1; i++)
		map[i][0] = char(48 + i);
	//set c
	for (int i = 0; i < comd_num + 1; i++)
	{
		if (i == 0)
		{
			for (int j = 1; j < comd_num + 1; j++)
				map[i][j] = char( 48 + j);
		}
		else
		{
			for (int j = 1; j < comd_num + 1; j++)
				map[i][j] = '*';
		}
	}
	
	//set events
	int px = 0, py = 0, overlay = 0;
	for (int i = 0; i < 6; i++)
		rooms[i]->set_p(py, px);
	
	for (int i = 0; i < 6; i++)
	{
		py = rand() % comd_num + 1;
		px = rand() % comd_num + 1;
		while (1)
		{
			overlay = 0;
			for (int j = 0; j < 6; j++)
			{
				if (rooms[j]->check_position(py, px) == 1)
				{
					overlay = 1;
					break;
				}
			}

			if (overlay == 0) break;
			if (overlay == 1)
			{
				py = rand() % comd_num + 1;
				px = rand() % comd_num + 1;
			}
		}
		rooms[i]->set_p(py, px);
		//map[py][px] = rooms[i]->get_name();
	}
}

/******************************************************************************************************************************************
** Function:	show_percepts
** Description:	display the percepts
** Parameters:	none
** Pre-Conditions:	events, coordinate
** Post-Conditions:	percepts displayed
******************************************************************************************************************************************/
void show_percepts(int y, int x, room **rooms)
{
	for (int i = 0; i < 6; i++)
	{
		if (rooms[i]->check_position(y - 1, x) == 1) rooms[i]->display_percepts();
		if (rooms[i]->check_position(y + 1, x) == 1) rooms[i]->display_percepts();
		if (rooms[i]->check_position(y, x - 1) == 1) rooms[i]->display_percepts();
		if (rooms[i]->check_position(y, x + 1) == 1) rooms[i]->display_percepts();
	}
}

void room_check(int &, int &, int, int &, int &, char **, room **);

/******************************************************************************************************************************************
** Function:	move_randomly
** Description:	move adv randomly
** Parameters:	none
** Pre-Conditions:	coordinate, side num, the map
** Post-Conditions:	coordinate changed
******************************************************************************************************************************************/
void move_randomly(int &y, int &x, int comd_num, char **map)
{
	y = rand() % comd_num + 1;
	x = rand() % comd_num + 1;
}

/******************************************************************************************************************************************
** Function:	room_check
** Description:	check which room adv is in
** Parameters:	none
** Pre-Conditions:	coordinate, side num, gold num, dead num, the map, events of rooms
** Post-Conditions:	info prompted
******************************************************************************************************************************************/
void room_check(int &y, int &x, int comd_num, int &gold_num, int &dead, char **map, room **rooms)
{
	map[y][x] = 'C';
	if (rooms[0]->check_position(y, x) == 1)
	{
		dead = 1;
		display_map(map, comd_num);
		cout << "wumpus! ahhh." << endl;
	}
	else if (rooms[1]->check_position(y, x) == 1)
	{
		map[y][x] = '*';
		cout << "bat!!!" << endl;
		move_randomly(y, x, comd_num, map);
		room_check(y, x, comd_num, gold_num, dead, map, rooms);
		display_map(map, comd_num);
		show_percepts(y, x, rooms);
	}
	else if (rooms[2]->check_position(y, x) == 1)
	{
		map[y][x] = '*';
		cout << "bat!!!" << endl;
		move_randomly(y, x, comd_num, map);
		room_check(y, x, comd_num, gold_num, dead, map, rooms);
		display_map(map, comd_num);
		show_percepts(y, x, rooms);
	}
	else if (rooms[3]->check_position(y, x) == 1)
	{
		dead = 1;
		display_map(map, comd_num);
		cout << "free fall." << endl;
	}
	else if (rooms[4]->check_position(y, x) == 1)
	{
		dead = 1;
		display_map(map, comd_num);
		cout << "free fall." << endl;
	}
	else if (rooms[5]->check_position(y, x) == 1)
	{
		gold_num = 1;
		cout << "find gold." << endl;
		rooms[5]->set_p(0, 0);
	}
}

/******************************************************************************************************************************************
** Function:	check_win
** Description:	check if adv wins
** Parameters:	none
** Pre-Conditions:	gold num, killed num
** Post-Conditions:	return -1 win, -0 not win
******************************************************************************************************************************************/
int check_win(int gold_num, int killed)
{
	if (gold_num == 1 && killed == 1) return 1;
	else return 0;
}

void act_move(int &, int &, int, char **);

/******************************************************************************************************************************************
** Function:	act_move
** Description:	adv moves
** Parameters:	direction
** Pre-Conditions:	coordinate, side num, the map
** Post-Conditions:	adv moved
******************************************************************************************************************************************/
void act_move(int &y, int &x, int comd_num, char **map)
{
	string dir;
	map[y][x] = '*';
	cout << "up, down, left, right: ";
	cin >> dir;
	while (!(dir == "up" || dir == "down" || dir == "left" || dir == "right"))
	{
		cout << "wrong input, again: ";
		cin >> dir;
	}

	if (dir == "up")
	{
		if (y == 1)
		{
			cout << "can not move." << endl;
			act_move(y, x, comd_num, map);
		}
		else
		{
			y -= 1;
			map[y][x] = 'C';
		}
	}

	if (dir == "down")
	{
		if (y == comd_num)
		{
			cout << "can not move." << endl;
			act_move(y, x, comd_num, map);
		}
		else
		{
			y += 1;
			map[y][x] = 'C';
		}
	}

	if (dir == "left")
	{
		if (x == 1)
		{
			cout << "can not move." << endl;
			act_move(y, x, comd_num, map);
		}
		else
		{
			x -= 1;
			map[y][x] = 'C';
		}
	}

	if (dir == "right")
	{
		if (x == comd_num)
		{
			cout << "can not move." << endl;
			act_move(y, x, comd_num, map);
		}
		else
		{
			x += 1;
			map[y][x] = 'C';
		}
	}
}

/******************************************************************************************************************************************
** Function:	fire_arrow
** Description:	fire an arrow
** Parameters:	direction
** Pre-Conditions:	coordinate, side num, killed num, the map, events of rooms
** Post-Conditions:	arrow fired
******************************************************************************************************************************************/
void fire_arrow(int y, int x, int comd_num, int &killed, char **map, room **rooms)
{
	string dir;
	cout << "up, down, left, right: ";
	cin >> dir;
	while (!(dir == "up" || dir == "down" || dir == "left" || dir == "right"))
	{
		cout << "wrong input, again: ";
		cin >> dir;
	}

	if (dir == "up")
	{
		for (int i = 0; i < 3; i++)
		{
			if (y == 1) break;
			y -= 1;
			if (rooms[0]->check_position(y, x) == 1)
			{
				rooms[0]->set_p(0, 0);
				cout << "on target." << endl;
				killed = 1;
				break;
			}
			else cout << "off target." << endl;
		}
	}

	if (dir == "down")
	{
		for (int i = 0; i < 3; i++)
		{
			if (y == comd_num) break;
			y += 1;
			if (rooms[0]->check_position(y, x) == 1)
			{
				rooms[0]->set_p(0, 0);
				cout << "on target." << endl;
				killed = 1;
				break;
			}
			else cout << "off target." << endl;
		}
	}

	if (dir == "left")
	{
		for (int i = 0; i < 3; i++)
		{
			if (x == 1) break;
			x -= 1;
			if (rooms[0]->check_position(y, x) == 1)
			{
				rooms[0]->set_p(0, 0);
				cout << "on target." << endl;
				killed = 1;
				break;
			}
			else cout << "off target." << endl;
		}
	}

	if (dir == "right")
	{
		for (int i = 0; i < 3; i++)
		{
			if (x == comd_num) break;
			x += 1;
			if (rooms[0]->check_position(y, x) == 1)
			{
				rooms[0]->set_p(0, 0);
				cout << "on target." << endl;
				killed = 1;
				break;
			}
			else cout << "off target." << endl;
		}
	}
}

/******************************************************************************************************************************************
** Function:	wumpus_move
** Description:	wumpus moves
** Parameters:	instant position
** Pre-Conditions:	side num, events of rooms
** Post-Conditions:	wumpus moved
******************************************************************************************************************************************/
void wumpus_move(int comd_num, room **rooms)
{
	int overlay = 0, py, px, perc;
	perc = rand() % 99 + 1;
	if (perc < 26) return;

	py = rand() % comd_num + 1;
	px = rand() % comd_num + 1;

	while (1)
	{
		overlay = 0;
		for (int i = 1; i < 6; i++)
		{
			if (rooms[i]->check_position(py, px) == 1) overlay = 1;
		}

		if (overlay == 0) break;
		if (overlay == 1)
		{
			py = rand() % comd_num + 1;
			px = rand() % comd_num + 1;
		}
	}

	rooms[0]->set_p(py, px);
	cout << "wumpus moved." << endl;
}

int main(int argc, char *argv[])
{
	int comd_num, x, y, sy, sx, gold_num, dead, killed, arrow, overlay;
	char p = 'C';
	string action, fm;

	cout << "Hunt the Wumpus" << endl;
	srand(time(NULL));
	comd_num = comd(argc, argv);
	if (comd_num == 0)
	{
		cout << "command error, cannot access." << endl;
		return 0;
	}
	
	//generate event
	room *rooms[6] =
	{
		new wumpus(),
		new bat(),
		new bat(),
		new pit(),
		new pit(),
		new gold()
	};
	
	//initia map
	char **map = NULL;

	while (1)
	{
		//generate map
		map = new char*[comd_num + 1];
		buildmap(rooms, map, comd_num);

		//start position
		y = rand() % comd_num + 1;
		x = rand() % comd_num + 1;
		while (1)
		{
			overlay = 0;
			for (int i = 0; i < 6; i++)
				if (rooms[i]->check_position(y, x) == 1) overlay = 1;

			if (overlay == 0) break;
			if (overlay == 1)
			{
				y = rand() % comd_num + 1;
				x = rand() % comd_num + 1;
			}
		}
		map[y][x] = p;
		sy = y;
		sx = x;

		//no gold, alive, haven't killed wumpus right now
		gold_num = 0;
		dead = 0;
		killed = 0;
		arrow = 3;

		display_map(map, comd_num);
		//game
		while (1)
		{
			//percepts
			show_percepts(y, x, rooms);

			//action
			cout << "move or fire an arrow? -move, -fire: ";
			cin >> action;
			while (1)
			{
				if (action == "move" || action == "fire") break;
				cout << "wrong input, again: ";
				cin >> action;
			}

			//move
			if (action == "move")
			{
				act_move(y, x, comd_num, map);
				display_map(map, comd_num);
				show_percepts(y, x, rooms);

				//check ? win
				if (check_win(gold_num, killed) == 1 && sy == y && sx == x)
				{
					cout << "you win!!!" << endl;
					break;
				}

				//check in which room
				room_check(y, x, comd_num, gold_num, dead, map, rooms);
				if (dead == 1)
				{
					cout << "you die." << endl;
					break;
				}

				//? fire
				cout << "want to fire an arrow? -Y or any other keyboards: ";
				cin >> fm;
				if (fm == "Y" || fm == "y")
				{
					fire_arrow(y, x, comd_num, killed, map, rooms);
					arrow -= 1;
				}
				if (arrow < 1 && killed == 0)
				{
					cout << "no arrows but wumpus alive. over." << endl;
					break;
				}
				if (killed == 0 && (fm == "Y" || fm == "y"))
				{
					//wumpus moved
					wumpus_move(comd_num, rooms);
					if (rooms[0]->check_position(y, x) == 1)
					{
						cout << "wumpus coming!" << endl;
						break;
					}
				}
			}

			if (action == "fire")
			{
				fire_arrow(y, x, comd_num, killed, map, rooms);
				arrow -= 1;
				if (arrow < 1 && killed == 0)
				{
					cout << "no arrows but wumpus alive. over." << endl;
					break;
				}
				if (killed == 0 && (fm == "Y" || fm == "y"))
				{
					//wumpus moved
					wumpus_move(comd_num, rooms);
					if (rooms[0]->check_position(y, x) == 1)
					{
						cout << "wumpus coming!" << endl;
						break;
					}
				}

				//? move
				cout << "want to move? -Y or any other keyboards: ";
				cin >> fm;
				if (fm == "Y" || fm == "y")
				{
					act_move(y, x, comd_num, map);
					display_map(map, comd_num);

					//check ? win
					if (check_win(gold_num, killed) == 1 && sy == y && sx == x)
					{
						cout << "you win!!!" << endl;
						break;
					}

					//check in which room
					room_check(y, x, comd_num, gold_num, dead, map, rooms);
					if (dead == 1)
					{
						cout << "you die." << endl;
						break;
					}
				}
			}
		}

		for (int i = 0; i < comd_num + 1; i++)
			delete[] map[i];
		delete[] map;

		cout << "play again? -Y or any other keyboards: ";
		cin >> action;
		if (!(action == "y" || action == "y")) break;
	}
	
	for (int i = 0; i < 6; i++)
		delete rooms[i];

	cout << "thanks." << endl;

	return 0;
}