#include <iostream>
#include "song.h"
using namespace std;

ostream& operator<<(ostream& out, const Song& s)
{
	int minutes = s.length / 60;
	int seconds = s.length - minutes * 60;
	string genreStr;

	switch (s.genre)
	{
	case Genre::Pop:
		genreStr = "[Pop]";
		break;
	case Genre::Rock:
		genreStr = "[Rock]";
		break;
	case Genre::Electronic:
		genreStr = "[Electronic]";
		break;
	case Genre::Blues:
		genreStr = "[Blues]";
		break;
	case Genre::Country:
		genreStr = "[Country]";
		break;
	}

	out << s.title << " - " << s.author << " (" << minutes <<
		(seconds < 10 ? ":0" : ":") << seconds << ") " << genreStr << endl;
	return out;
}

//**********************STAGE 1**********************

// construct
Song::Song(string title, string author, Genre g, int length)
	: title(title), author(author), genre(g), length(length) {}

// operator==
bool operator==(const Song& first, const Song& other) {
	return first.title == other.title && first.author == other.author;
}