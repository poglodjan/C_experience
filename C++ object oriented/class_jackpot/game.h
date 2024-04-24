#pragma once
#include <iostream>
using namespace std;
#include "balls.h"

class Game
{
	string name;
	int no_to_draw;
	Balls drawing_balls;
public:
	// Part 4
	Game(string _name, int _no_of_balls, int _no_to_draw);
	friend ostream& operator<<(ostream&, const Game&);
	// Part 5
	Balls draw();

	string get_name() const { return name; }
};
