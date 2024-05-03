#include <iostream>
using namespace std;
#include "game.h"
#include "balls.h"

Game::Game(string _name, int _n_of_balls, int _no_to_draw) : 
	name(_name), no_to_draw(_no_to_draw), drawing_balls(_n_of_balls, nullptr) {};

ostream& operator<<(ostream& out, const Game& g)
{
	out << "Game: " << g.name << ", balls in game: " << endl << g.drawing_balls;
	return out;
}

Balls Game::draw()
{
	int res = 0;
	Balls result(0, nullptr);
	for (int i = 0; i < no_to_draw; i++)
	{
		int random_pos = rand() % drawing_balls.balls_no();
		if (!drawing_balls.draw(random_pos, res)) break;
		else result += res;
	}
	return result;
}
