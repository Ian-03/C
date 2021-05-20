#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define MAX 100

struct music{

    int id;
    char name_song[30];
    char author[30];
    char tone[4];
    char chords[20];

} songs[MAX];

void menu (); 

void notes ();  

void check_songs ();  //know how many songs are in the txt and put them in the struct 'music'

void create_base ();   //give you the chords that will sound good in the tone that you want

void affinity ();    //check if the chord that you want to use can be a good option or an alternative for them

void save_song ();   //save our ideas in the txt file
 
void modify_song ();    //change the data of the songs that we have in the struct 'music'

void rewrite_songs ();   //pass all the songs that are in the struct to the txt file

void upper (char []);   //convert all the strings in upper case strings to make the program easier

int repetition (int [], int); 
