//
//

#include <iostream>
#include "Playlist.h"
using namespace std;

PlaylistNode::PlaylistNode() {
	unigueID = "none";
	songName = "none";
	artistName = "none";
	songLength = 0;
}

PlaylistNode::PlaylistNode(string ID, string song, string artist, int lenght) {
	unigueID = ID;
	songName = song;
	artistName = artist;
	songLength = lenght;
}

void PlaylistNode::SetNext(PlaylistNode* next) {
	nextNodePtr = next;
}

void PlaylistNode::InsertAfter(PlaylistNode* node) {
	PlaylistNode* tempNext = nullptr;

	tempNext = nextNodePtr;
	nextNodePtr = node;
	node->SetNext(tempNext);
}

void PlaylistNode::PrintPlaylistNode() {
	cout << "Unique ID: " << unigueID
		<< "\nSong Name: " << songName
		<< "\nArtist Name: " << artistName
		<< "\nSong Length (in seconds): " << songLength;
}