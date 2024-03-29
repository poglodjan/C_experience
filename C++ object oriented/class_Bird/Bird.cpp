#include <iostream>
#include "Bird.h"

Bird::Bird(bool _isFlying) : isFlying(_isFlying)
{
	cout << "Bird is created" << endl;
}

Bird::~Bird()
{
	cout << "Bird dies" << endl;
}

void Bird::Fly()
{
	if (isFlying)
		cout << "Fly, fly, fly" << endl;
	else
		cout << "I cant fly" << endl;
}

void Bird::Fly(bool isFlyingInfo) 
{
	if (isFlyingInfo)
		cout << "Fly, fly, fly" << endl;
	else
		cout << "I cant fly" << endl;
}

Parrot::Parrot(bool _isFlying, string _name) : Bird(_isFlying), name(_name)
{
	isFlying = true;
	cout << "Parrot is created" << endl;
}
Parrot::~Parrot()
{
	cout << "Parrot dies" << endl;
}

Kiwi::Kiwi(bool _isFlying, string _name) : Bird(_isFlying), name(_name)
{
	isFlying = false;
	cout << "Kiwi is created" << endl;
}
Kiwi::~Kiwi()
{
	cout << "Kiwi dies" << endl;
}

void Parrot::Fly()
{
	if (isFlying)
		cout << "Fly, fly, fly" << endl;
	else
		cout << "I cant fly" << endl;
}

void Kiwi::Fly()
{
	Bird::Fly();
}
