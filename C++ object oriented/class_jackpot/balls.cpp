#pragma once
#include <iostream>
using namespace std;
#include "balls.h"

int Balls::id = 0;

Balls::Balls(int _no_of_balls, int* _balls) : set_id(++id), no_of_balls(_no_of_balls)
{
	if (no_of_balls <= 0)
	{
		this->no_of_balls = 0;
		balls = nullptr;
		return;
	}
	this->no_of_balls = _no_of_balls;
	if (_balls) {
		balls = new(nothrow) int[no_of_balls];
		if (!balls)
		{
			this->no_of_balls = 0;
			return;
		}
		for (int i = 0; i < no_of_balls; i++)
		{
			balls[i] = _balls[i];
		}
	}
	if (!_balls) {
		balls = new(nothrow) int[no_of_balls];
		if (!balls)
		{
			this->no_of_balls = 0;
			return;
		}
		for (int i = 0; i < no_of_balls; i++)
		{
			balls[i] = i+1;
		}
	}
}

void Balls::mix()
{
	for (int i = 0; i < no_of_balls; i++)
	{
		int idx = rand() % no_of_balls;
		swap(balls[i], balls[idx]);
	}
}

Balls::~Balls() { delete[] balls; }

ostream& operator<<(ostream& out, const Balls& b)
{
	out << "Set of balls no. " << b.set_id << " contains " << b.no_of_balls <<
		" balls with the numbers: ";
	for (int i = 0; i < b.no_of_balls; ++i)
	{
		out << b.balls[i] << ", ";
	}
	return out <<endl;
}


Balls::Balls(const Balls& b) : set_id(++id)
{
	if (b.no_of_balls <= 0)
	{
		this->no_of_balls = 0;
		balls = nullptr;
		return;
	}
	this->no_of_balls = b.no_of_balls;
	if (b.balls) {
		balls = new(nothrow) int[no_of_balls];
		if (!balls)
		{
			this->no_of_balls = 0;
			return;
		}
		for (int i = 0; i < no_of_balls; i++)
		{
			balls[i] = b.balls[i];
		}
	}
}

Balls& Balls::operator=(const Balls& b)
{
	if (no_of_balls != b.no_of_balls)
	{
		delete[] balls; 
		if (b.no_of_balls <= 0)
		{
			this->no_of_balls = 0;
			balls = nullptr;
			return *this;
		}
		this->no_of_balls = b.no_of_balls;
		if (b.balls) 
		{
			balls = new(nothrow) int[b.no_of_balls];
			if (!balls)
			{
				this->no_of_balls = 0;
				return *this;
			}
		}
	}
	for (int i = 0; i < no_of_balls; i++)
	{
		balls[i] = b.balls[i];
	}
	return *this;
}

bool Balls::draw(int pos, int& result)
{
	if (pos >= no_of_balls or pos<0) { return false; }
	result = balls[pos];
	this->no_of_balls = no_of_balls-1;
	int* a;
	a = new(nothrow) int[no_of_balls];

	for (int i = 0; i < no_of_balls; i++)
	{
		if (i < pos)
		{
			a[i] = balls[i];
		}
		if (i >= pos)
		{
			a[i] = balls[i + 1];
		}
	}
	delete[] balls;
	balls = new(nothrow) int[no_of_balls];
	balls = a;
	return true;
}

void Balls::operator+=(int ball_number)
{
	this->no_of_balls = no_of_balls + 1;
	int* a;
	a = new(nothrow) int[no_of_balls];
	for (int i = 0; i < no_of_balls-1; i++)
	{
		a[i] = balls[i];
	}
	balls = a;
	balls[no_of_balls-1] = ball_number;
}
