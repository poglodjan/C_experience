#include <iostream>
#include <algorithm>
#include "playlist.h"
using namespace std;

//**********************STAGE 1**********************

Playlist::Playlist(string name) : name(name) {}

ostream& operator<<(ostream& os, const Playlist& playlist) {
    os << "Playlist: " << playlist.name << endl;

    if (playlist.songs.empty()) {
        os << "No songs in this playlist." << endl << endl;
    }
    else {
        for (auto it = playlist.songs.begin(); it != playlist.songs.end(); it++)
            os << *it;
    }
    return os;
}

void Playlist::add_song(Song song) {
    if (find(songs.begin(), songs.end(), song) == songs.end()) {
        songs.push_back(song);
    }
}

void Playlist::add_songs(list<Song>& song_list) {
    songs.splice(songs.end(), song_list);
}

void Playlist::add_songs(Playlist& otherplaylist) {
    songs.splice(songs.end(), otherplaylist.songs);
}

void Playlist::insert_song_by_genre(list<Song> song_list)
{
    if (song_list.empty()) return;

    Song song_to_insert = song_list.front();
    song_list.pop_front();

    auto it = find_if(songs.begin(), songs.end(), [&song_to_insert](const Song& s) 
        {
        return s.get_genre() == song_to_insert.get_genre();
        });

    if (it != songs.end()) {
        songs.insert(it, song_to_insert);
    }
    else {
        songs.push_back(song_to_insert);
    }
}

//**********************STAGE 2**********************

//**********************STAGE 3**********************

