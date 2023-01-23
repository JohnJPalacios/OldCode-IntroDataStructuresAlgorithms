//
//

#ifndef PLAYLIST_H
#define PLAYLIST_H
#include<string>
using namespace std;

class PlaylistNode
{
public:
	PlaylistNode();
	PlaylistNode(string ID, string song, string artist, int lenght);
	void InsertAfter(PlaylistNode* node);
	void SetNext(PlaylistNode* next);
	string GetID() { return unigueID; }
	string GetSongName() { return songName; }
	string GetArtistName() { return artistName; }
	int GetSongLength() { return songLength; }
	PlaylistNode* GetNext() { return nextNodePtr; }
	void PrintPlaylistNode();

private:
	string unigueID;
	string songName;
	string artistName;
	int songLength;
	PlaylistNode* nextNodePtr = nullptr;
};

#endif // !PLAYLIST_H