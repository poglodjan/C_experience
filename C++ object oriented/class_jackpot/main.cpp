#include <iostream>
#include <ctime>
using namespace std;
#include "balls.h"
#include "game.h"
#include "machine.h"

int main()
{
	srand(1);
	// ==================   PART 1 (1 pkt) ===========================

	cout << endl << "-------------  PART 1 (1 pkt) --------------" << endl;
	int balls_numbers[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	Balls bs0;
	Balls bs1(6);
	Balls bs2(9, balls_numbers);
	Balls bs3(49);
	cout << bs0 << bs1 << bs2 << endl;

	bs3.set_format() = Balls::format::only_numbers;
	cout << bs3 << endl;

	// ==================   PART 2 (1,5 pkt) ===========================

	cout << endl << "-------------  PART 2 (1,5 pkt) --------------" << endl;
	Balls bs4(bs3);
	Balls bs5;
	bs5 = bs2;
	bs4.mix();
	bs5.mix();
	cout << "Currently we have " << Balls::no_of_sets() << " sets of balls" << endl;
	cout << bs4 << bs5 << endl;

	//// ==================   PART 3 (1,5 pkt) ===========================

	cout << endl << "-------------  PART 3 (1,5 pkt) --------------" << endl;
	int res = 0;
	if (bs3.draw(-1, res))
		cout << "Wrong position!" << endl;
	if (bs3.draw(50, res))
		cout << "Wrong position!" << endl;
	if (bs3.draw(1, res))
		bs0 += res;
	if (bs3.draw(3, res))
		bs0 += res;
	if (bs3.draw(5, res))
		bs0 += res;
	bs3.set_format() = Balls::format::full;
	cout << bs0 << bs3 << endl;

	//// ==================   PART 4 (0.5 pkt) ===========================

	cout << endl << "__part 4__" << endl;
	Game g1("Lotto", 49, 6);
	cout << g1 << endl;

	//// ==================   PART 5 (1 pkt) ===========================

	cout << endl << "-------------  PART 5 (1 pkt) --------------" << endl;
	Balls game_results;
	game_results.set_format() = Balls::format::only_numbers;
	game_results = g1.draw();
	cout << g1 << endl;
	cout << "Results: " << game_results << endl;

	//// ==================   PART 6 (1 pkt) ===========================

	cout << endl << "-------------  PART 6 (1 pkt) --------------" << endl;
	GameMachine gm1(1234);
	cout << gm1 << endl;

	//// ==================   PART 7 (1,5 pkt) ===========================

	cout << endl << "-------------  PART 7 (1,5 pkt) --------------" << endl;
	gm1.add_game("Lotto", 49, 6);
	gm1.add_game("Mini Lotto", 42, 5);
	gm1.add_game("Multi Multi", 80, 20);
	gm1.add_game("Euro Lotto", 50, 7);

	cout << gm1 << endl;

	gm1.run();

	cout << gm1 << endl;

}

