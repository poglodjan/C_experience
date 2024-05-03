#pragma once
#include <iostream>
using namespace std;
#include "machine.h"

GameMachine::GameMachine(int _serial_number) :
	serial_number(_serial_number), no_of_games(0), games(new Game* [max_games]) {};

void GameMachine::add_game(string game_name, int no_of_balls, int no_to_draw)
{
	if (no_of_games < max_games) {
		games[no_of_games++] = new Game(game_name, no_of_balls, no_to_draw);
	}
}

GameMachine::~GameMachine()
{
	for (int i = 0; i < no_of_games; i++)
	{
		delete games[i];
	}
	delete games;
}


ostream& operator<<(ostream& out, const GameMachine& gm)
{
	if (gm.no_of_games == 3) out << "Machine is full!!!" << endl;
	out << "Game machine S/N: " << gm.serial_number << endl;
	if (gm.no_of_games == 0) out << "Machine is empty" << endl;
	else {
		out << "Games available: " << endl;
		for (int i = 0; i < gm.no_of_games; i++) out << " " << *gm.games[i];
		out << endl << endl;
	}
	return out;
}


void GameMachine::run()
{
	cout << "Drawing"<<endl;
	for (int i = 0; i < no_of_games; i++)
	{
		Balls result(0, nullptr);
		result = games[i]->draw();
		cout << result;
		delete games[i];
	}
	no_of_games = 0;
}
