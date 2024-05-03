#pragma once
#include <iostream>
using namespace std;
#include "balls.h"
#include "game.h"

class GameMachine
{
	const int serial_number;
	static const int max_games = 3;
	int no_of_games;
	Game** games;
public:
	GameMachine(int _serial_number);
	GameMachine(const GameMachine&) = delete;
	GameMachine& operator=(const GameMachine&) = delete;
	~GameMachine();
	friend ostream& operator<<(ostream &, const GameMachine&);
	
	void add_game(string game_name, int no_of_balls, int no_to_draw);
	void run();

};
