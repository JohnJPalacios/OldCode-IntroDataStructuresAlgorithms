//
// Author: John Palacios with help from: Manveer Sani and Professor LePendu. References: Starting out with C++ 7th ed by Tony Gadis and CPlusplus.com

#include<iostream>
#include<iomanip>
#include "Playlist.h"
using namespace std;

void PrintMenu(string);
// displays a set of options for interacting with the playlist

void FullListOut(string, PlaylistNode*);
// implementation of the "Output Full List" menue option
// Prints song information of each PlaylistNode in playlist.

void AddSong(PlaylistNode**, PlaylistNode**);
// implementation of the "Add song" menu item.
// Adds a song to the end of the play list.

void RemoveSong(PlaylistNode**);
// implementation of the "Remove song" function.
// prompts user for unique song ID, displays song removed message,
// then removes song from list

void ChangePosition(PlaylistNode**, PlaylistNode**);
// implementation of the "Change position of song" menu option.
// prompt user for current song position, then new song position, then
// displays song title and moved to new position message.
// position < 1; new position = 1, position > n; positon = n, else 
// song moved to position position.

void OutputArtist(PlaylistNode*);
// implementation of the "Output songs by specific artist" menu option.
// Prompts user for artists name, displays song information for songs
// by selected artist in the playlist.

void PutputTotalTime(PlaylistNode*);
// this function simply reads out the total length of time playlist will
// play in seconds.

void CleanUp(PlaylistNode*);
//Deletes all dynamically allocated memory in the linked list before exit.

int main() {
	string title;

	cout << "Enter playlist's title:" << endl;
	getline(cin, title);
	cout << endl;

	PrintMenu(title);
	return 0;
}

void PrintMenu(string title) {
	char choice = 'a';
	PlaylistNode* head = nullptr;
	PlaylistNode* tail = nullptr;

	//Test Data
	PlaylistNode* temp = nullptr;
	head = new PlaylistNode("SD123", "Peg", "Steely Dan", 237);
	temp = new PlaylistNode("JJ234", "All For You", "Janet Jackson", 391);
	head->SetNext(temp);
	tail = temp;
	temp = nullptr;
	temp = new PlaylistNode("J345", "Canned Heat", "Jamiroquai", 330);
	tail->SetNext(temp);
	tail = temp;
	temp = nullptr;
	temp = new PlaylistNode("JJ456", "Black Eagle", "Janet Jackson", 197);
	tail->SetNext(temp);
	tail = temp;
	temp = nullptr;
	temp = new PlaylistNode("SD567", "I Got The News", "Steely Dan", 306);
	tail->SetNext(temp);
	tail = temp;
	temp = nullptr;

	while (choice != 'q') {
		bool valid = false;
		cout << title << " PLAYLIST MENU\n"
			<< "a - Add song\n"
			<< "d - Remove song\n"
			<< "c - Change position of song\n"
			<< "s - Output songs by specific artist\n"
			<< "t - Output total time of playlist (in seconds)\n"
			<< "o - Output full playlist\n"
			<< "q - Quit\n" << endl;

		while (valid == false) {
			cout << "Choose an option:" << endl;
			cin >> choice;

			choice = tolower(choice);

			switch (choice)
			{
			case 'a':
				valid = true;
				AddSong(&head, &tail);
				cout << endl;
				break;
			case 'd':
				valid = true;
				RemoveSong(&head);
				cout << endl;
				break;
			case 'c':
				valid = true;
				ChangePosition(&head, &tail);
				cout << endl;
				break;
			case 's':
				valid = true;
				OutputArtist(head);
				cout << endl;
				break;
			case 't':
				valid = true;
				PutputTotalTime(head);
				cout << endl;
				break;
			case 'o':
				valid = true;
				FullListOut(title, head);
				cout << endl;
				break;
			case 'q':
				valid = true;
				CleanUp(head);
				break;

			default:
				cout << choice << " is not an option, try again" << endl;
				break;
			}
		}
	}
	
}

void FullListOut(string title, PlaylistNode* head) {
	int count = 1;
	PlaylistNode* temp = head;

	cout << title << " - OUTPUT FULL PLAYLIST" << endl;
	
	while (temp != nullptr) {
		cout << count << "." << endl;
		temp->PrintPlaylistNode();
		if (temp->GetNext() != nullptr) { cout << endl << endl; }
		temp = temp->GetNext();
		count++;
	}

	if (head == nullptr) { cout << "Playlist is empty"; }
	cout << endl;
}

void AddSong(PlaylistNode** head, PlaylistNode** tail) {
	string ID;
	string song;
	string artist;
	int length;
	PlaylistNode* temp = nullptr;

	cout << "ADD SONG\nEnter song's unique ID:" << endl;
	cin >> ID;
	cin.get();

	cout << "Enter song's name:" << endl;
	getline(cin, song);

	cout << "Enter artist's name:" << endl;
	getline(cin, artist);

	cout << "Enter song's length (in seconds):" << endl;
	cin >> length;

	temp = new PlaylistNode(ID, song, artist, length);

	if (*tail == nullptr) {
		*head = temp;
		*tail = temp;
	}
	else {
		(*tail)->InsertAfter(temp);
		*tail = temp;
	}
}

void RemoveSong(PlaylistNode** head) {
	bool found = false;
	string id;
	PlaylistNode* temp = nullptr;
	PlaylistNode* trail = nullptr;

	cout << "REMOVE SONG\nEnter song's unique ID:" << endl;
	cin >> id;

	//Find Node
	if ((*head)->GetID() == id) {
		temp = *head;
		*head = (*head)->GetNext();
		delete temp;
		temp = nullptr;
	}
	else {
		temp = (*head)->GetNext();
		trail = *head;
		while (temp != nullptr && found != true) {
			if (temp->GetID() == id) {
				cout << "\"" << temp->GetSongName() << "\" removed." << endl;
				trail->SetNext(temp->GetNext());
				delete temp;
				temp = trail->GetNext();
				found = true;
			}
			if (temp != nullptr) {
				temp = temp->GetNext();
				trail = trail->GetNext();
			}
			
		}
		if (!found) { cout << "ID NOT FOUND\n"; }
	}

}

void ChangePosition(PlaylistNode** head, PlaylistNode** tail) {
	int pos = 0;
	int des = 0;
	int count = 1;
	int NumberSongs = 0;
	PlaylistNode* temp = nullptr;
	PlaylistNode* trail = nullptr;
	PlaylistNode* current = nullptr;
	PlaylistNode* destination = nullptr;

	/*cout << "CHANGE POSITION OF SONG\nEnterSong's current position:" << endl;
	cin >> pos;
	cout << "Enter new position for song:" << endl;
	cin >> des;*/
	pos = 1;
	des = 3;

	//Determine number of elements in list
	current = *head;
	while (current != nullptr) {
		current = current->GetNext();
		NumberSongs++;
	}

	//Find song initial position
	current = *head;
	while (current != nullptr && count < pos) {
		trail = current;
		current = current->GetNext();
		count++;
	}

	//Copy Current Song details
	temp = new PlaylistNode(current->GetID(), current->GetSongName(), current->GetArtistName(), current->GetSongLength());

	//Find node before destination
	count = 1;
	destination = *head;
	while (destination != nullptr && count < des - 1) {
		destination = destination->GetNext();
		count++;
	}

	//Handle destination being <= 1
	if (des <= 1) { 
		temp->SetNext(*head);
		*head = temp;
	}
	//Handle destination >= numberSongs
	else if (des >= NumberSongs) {
		(*tail)->SetNext(temp);
		*tail = temp;
	}
	else {
		//Insert after destination - 1
		destination->InsertAfter(temp);
		/*if (destination == *tail) { *tail = temp; }*/
	}

	//Remove and delete current node from list
	if (trail != nullptr) {
		trail->SetNext(current->GetNext());
		delete current;
		current = nullptr;
	}
	

	//User message
	cout << "\"" << temp->GetSongName() << "\" moved to position " << des << endl;
}

void OutputArtist(PlaylistNode* head) {
	int count = 0;
	string name;
	PlaylistNode* temp = nullptr;
	
	cin.ignore();
	cout << "OUTPUT SONGS BY SPECIFIC ARTIST\nEnter artist's name:" << endl;
	getline(cin, name);
	cout << endl;

	temp = head;
	count++;
	while (temp != nullptr) {
		if (temp->GetArtistName() == name) {
			cout << count << "." << endl;
			temp->PrintPlaylistNode();
			if (temp->GetNext() != nullptr) { cout << endl << endl; }
		}
		temp = temp->GetNext();
		count++;
	}
}

void PutputTotalTime(PlaylistNode* head) {
	int sum = 0;
	PlaylistNode* temp = nullptr;

	//Accomplish task
	temp = head;
	while (temp != nullptr) {
		sum += temp->GetSongLength();
		temp = temp->GetNext();
	}

	//Print user message
	cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)\nTotal time: " << sum
		<< " seconds" << endl;
}

void CleanUp(PlaylistNode* head) {
	PlaylistNode* temp = nullptr;
	while (head != nullptr) {
		temp = head;
		head = head->GetNext();
		delete temp;
	}
}