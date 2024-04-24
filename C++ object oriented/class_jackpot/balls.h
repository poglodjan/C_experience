#pragma once
#include <iostream>
using namespace std;

class Balls
{
public:
	enum class format {
		only_numbers, full
	};
private:
	static int id;
	const int set_id;
	int no_of_balls;
	int* balls;
	format printing_format = format::full;
public:
	// Part 1
	Balls(int _no_of_balls = 0, int* _balls = nullptr);
	~Balls();
	format& set_format() { return printing_format; }
	friend ostream& operator<<(ostream&, const Balls&);

	// Part 2
	Balls(const Balls&);
	Balls& operator=(const Balls&);
	
	// Part 3
	bool draw(int pos, int& result);
	void operator+=(int ball_number);

	// already implemented
	static int no_of_sets() { return id; }
	int balls_no() const { return no_of_balls; }
	void mix();

};
