#include <iostream>
#include <cstring>
using namespace std;

enum musicGenres { NONE, RAP, HIPHOP, ROCK, INDIE, CLASSICAL, ALTERNATIVE };

void getFavMusic(musicGenres &);
void showFavMusic(musicGenres);

int main() {

	musicGenres currFav = NONE;
	char cont;

	do {
		getFavMusic(currFav);  //Ask Matt for his favorite music genre today and store it as a musicGenres (enum) type
		showFavMusic(currFav); //Output Matt's favorite music genre today by converting the musicGenres enum type to a cstring

		cout << "Enter another genre? (y or n): ";
		cin >> cont;
		cont = tolower(cont);
	} while (cont == 'y');

	return 0;
}

void getFavMusic(musicGenres &currFav) {
	
	char fav[20]; //Where input is stored

	cout << "Hey Matt! What's your favorite music today?\n";
	if(currFav != NONE)
		cin.ignore(1000, '\n'); //This works but I have to enter the first genre twice
	cin.getline(fav, 20); //Keeps skipping here after first entry
	

	for (int i = 0; i < strlen(fav); i++) { //Makes input all lowercase to simplify cstring checking in switch statement
		fav[i] = tolower(fav[i]);
	}

	if (!strcmp(fav,"hiphop") || !strcmp(fav,"hip hop")) // Compare cstring 'fav' with lowercase music genre names and assign musicGenres type values to currFav
		currFav = HIPHOP;
	else if (!strcmp(fav,"rap"))
		currFav = RAP;
	else if (!strcmp(fav,"rock"))
		currFav = ROCK;
	else if (!strcmp(fav, "indie"))
		currFav = INDIE;
	else if (!strcmp(fav, "classical"))
		currFav = CLASSICAL;
	else if (!strcmp(fav, "alternative"))
		currFav = ALTERNATIVE;
}

void showFavMusic(musicGenres currFav) {
	char fav[20];
	switch (currFav)
	{
	case HIPHOP:
		strcpy(fav, "Hip Hop");
		break;
	case RAP:
		strcpy(fav, "Rap");
		break;
	case ROCK:
		strcpy(fav, "Rock");
		break;
	case INDIE:
		strcpy(fav, "Indie");
		break;
	case CLASSICAL:
		strcpy(fav, "Classical");
		break;
	case ALTERNATIVE:
		strcpy(fav, "Alternative");
	}

	cout << "Matt's favorite music genre today is " << fav << '!' << endl;
}

