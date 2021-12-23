#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

typedef struct Node *Music;

//the music player only contains one library.

//doubly linked list:
struct Node
{
    Music Next; //ptr to next song.
    Music Prev; //ptr to previous song.

    int index;             //index of song in the library
    int song_length;       //length of the song in seconds
    bool play_or_pause;    //true for play, false for pause
    double playback_speed; //speed = 1 as default.
    char song_name[30];    //name of song
    char singer[30];       //name of singer
};

//Note that we pass the header node to the library as "Music Song", so that we can access the songs in our function.

int Play(Music Song, int index); /*we pass the header and the index of the song we want to play. once we reach the end of the song, 
                                    it returns the index(+1) to the next song and that next song automatically starts playing.*/
void Pause(Music Song);

void Next_Song(Music Song, int index); // we pass the index to the current song that is playing, pause it, shift to the next song (Music->Next),and start playing it.
void Prev_Song(Music Song);

Music Empty_Lib(); //header node to our music library.
Music Init_Song(); //allocating memory for addition of a new song

void New_Song(Music Song, char song[30], char singer[30]); /*we pass the name of the song, name of the singer, and insert at rear/front of the library.
                                                        Then we update the indices of all the songs*/

void Change_Location(Music Song, int index_curr, int index_new); //we pass the current index of the song and the new index, then update its location.
void Rename_Song(Music Song, char song[30], int index);          //we pass the index of the song that has to be renamed.

int Find_Song(Music Song, char song[30]); //user enters the name of the song to be found, and we return the index of that song.

void Loop_Song(Music Song, int index);             //index of the current song playing. we do Music->Next = Music and Music->Prev = Music; so that the current song starts playing in a loop.
void Change_Playback_speed(Music Song, int index); //we pass the index to the currently playing song and update its playback speed.

void Delete_song(Music Song, int index); //we pass the index the song that has to be deleted.
void Delete_Lib(Music Song);             //we pass the header, and clear the whole library apart from the header.
void Delete_Head(Music Song);            //if we want to remove the existence of the player.

void Print_Songs(Music Song); //displaying all the songs in the main library.

#endif