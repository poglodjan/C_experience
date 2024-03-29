#pragma once
using namespace std;

class Bird
{
protected:
	bool isFlying;
public:
	Bird(bool);
	~Bird();
	void Fly();
	void Fly(bool);
	bool getFlyingInfo() const { return isFlying; }
};

class Parrot : public Bird
{
	string name;
public:
	Parrot(bool,string);
	~Parrot();
	void Fly();
};

class Kiwi : public Bird
{
	string name;
public:
	Kiwi(bool,string);
	~Kiwi();
	void Fly();
};
