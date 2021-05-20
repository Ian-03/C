#include"header.h"

//----------------------------------------------------------------------

int main(){

    srand (time (0));

    check_songs (); 

    do{
        menu();

        switch (option){

            case 1: create_base (); break;
            case 2: affinity (); break;
            case 3: save_song (); break;
            case 4: modify_song (); break;
            case 5: rewrite_songs (); return 0;
                    
        }
        
    }while (1);
}

//----------------------------------------------------------------------
                                                              
void menu (){

    system ("cls");
    
    printf(".:PIANO MUSIC COMPOSER:.\n");
    
    printf("\n  1.Create the base for a new song\n");
    printf("\n  2.Check chords affinity\n");
    printf("\n  3.Save your song idea\n");
    printf("\n  4.Modify your ideas\n");
    printf("\n  5.Close the program\n");

    do{
        printf("\nSelect the option that you want to use: ");
        fflush (stdin);
        scanf("%d", &option);

    }while (option < 1 || option > 6);

    system ("cls");

    return;
    
}

//----------------------------------------------------------------------

void notes (){

    printf("\nNotes (english-spanish)\n");

    printf("\n1.C-Do");
    printf("\n3.D-Re");
    printf("\n5.E-Mi");
    printf("\n6.F-Fa");
    printf("\n8.G-Sol");
    printf("\n10.A-La");
    printf("\n12-Si");
    printf("\n*You can add a '#' to the finel of the note to use a sharp note*\n");
    printf("\n*The number that are not in the list are the # notes*\n");
}

//----------------------------------------------------------------------

void check_songs (){          //see how many songs are already in the txt file

    int i, c;

    FILE* songs_log = fopen ("register.txt", "r");

    while ((c = fgetc (songs_log)) != EOF){   //get the number of songs

        if (c == '\n'){

            k++;
        }
    }

    rewind (songs_log);

    for (i = 0;  i < k; i++){     //put all the songs of the txt file in the struct

        fscanf(songs_log, "%d", &songs[i].id); 

        fscanf(songs_log, "%s", songs[i].name_song);

        fscanf(songs_log, "%s", songs[i].author);

        fscanf(songs_log, "%s", songs[i].tone);

        fscanf(songs_log, "%s", songs[i].chords);
    }
}

//----------------------------------------------------------------------

void create_base (){

    int i, j, num, amount_chords, final_chords[15], scales[8], x, size;
    
    char t[4];

    printf("Basic Info:\n");

    notes();

    while (1){

        printf("\n -Type the tone of the song (Ex. 'C', 'f#', 'LAb', 'do', 'B'): ");    //check what tone will be the song 
        fflush (stdin);
        scanf("%s", t);
        upper (t);
        
        if (strcmp (t, "DO") == 0 || strcmp (t, "C") == 0){
            num = 1;
            break;
        }else if (strcmp (t, "DO#") == 0 || strcmp (t, "C#") == 0){
            num = 2;
            break;
        }else if (strcmp (t, "RE") == 0 || strcmp (t, "D") == 0){
            num = 3;
            break;
        }else if (strcmp (t, "RE#") == 0 || strcmp (t, "D#") == 0){
            num = 4;
            break;
        }else if (strcmp (t, "MI") == 0 || strcmp (t, "E") == 0){
            num = 5;
            break;
        }else if (strcmp (t, "FA") == 0 || strcmp (t, "F") == 0){
            num = 6;
            break;
        }else if (strcmp (t, "FA#") == 0 || strcmp (t, "F#") == 0){
            num = 7;
            break;
        }else if (strcmp (t, "SOL") == 0 || strcmp (t, "G") == 0){
            num = 8;
            break;
        }else if (strcmp (t, "SOL#") == 0 || strcmp (t, "G#") == 0){
            num = 9;
            break;
        }else if (strcmp (t, "LA") == 0 || strcmp (t, "A") == 0){
            num = 10;
            break;
        }else if (strcmp (t, "LA#") == 0 || strcmp (t, "A#") == 0){
            num = 11;
            break;
        }else if (strcmp (t, "SI") == 0 || strcmp (t, "B") == 0){
            num = 12;
            break;
        }else printf("\nYou didn't type a correct tone. Try again.\n");
    
    }

    printf("\nHow many chords do you want? (Recommended 4): ");
    scanf("%d", &amount_chords);

    //1 3 5 6 8 10 12

    scales[0] = num;

    for (i = 1; i < 7; i++){          //with this you get the scale of the tone

        if (i != 3){
            scales[i] = scales[i - 1] + 2;
        }else scales[i] = scales[i - 1] + 1;
    }

    scales[i] = '\0';

    size = 0; 

    for (i = 0; i < amount_chords; i++){   //get the chords
        
        size++;

        x = (rand () % 7);

        final_chords[i] = scales[x];
        
    }

    printf("\nThe chords will be:\n");

    for (i = 0; i < amount_chords; i++){

        printf("\n");

        switch(final_chords[i]){
            case 1: printf("DO-C"); break;
            case 2: printf("DO#-C#"); break;
            case 3: printf("RE-D"); break;
            case 4: printf("RE#-D#"); break;
            case 5: printf("MI-E"); break;
            case 6: printf("FA-F"); break;
            case 7: printf("FA#-F#"); break;
            case 8: printf("SOL-G"); break;
            case 9: printf("SOL#-G#"); break;
            case 10: printf("LA-A"); break;
            case 11: printf("LA#-A#"); break;
            case 12: printf("SI-B"); break;
            case 13: printf("DO-C"); break;
            case 14: printf("DO#-C#"); break;
            case 15: printf("RE-D"); break;
            case 16: printf("RE#-D#"); break;
            case 17: printf("MI-E"); break;
            case 18: printf("FA-F"); break;
            case 19: printf("FA#-F#"); break;
            case 20: printf("SOL-G"); break;
            case 21: printf("SOL#-G#"); break;
            case 22: printf("LA-A"); break;
            case 23: printf("LA#-A#"); break;
            case 24: printf("SI-B"); break;
            
        }
    }

    printf("\n\n");

    system("pause");

}

void affinity (){

    int num, i, j, nchords, numchords[20], flag;

    //basic scales
    
    int c[] = {1,3,5,6,8,10,12};
    int d[] = {2,3,5,7,8,10,12};
    int e[] = {2,4,5,7,9,10,12};
    int f[] = {1,3,5,6,8,10,11};
    int g[] = {1,3,5,7,8,10,12};
    int a[] = {2,3,5,7,9,10,12};
    int b[] = {2,4,5,7,9,11,12};

    char t[4];

    printf("Basic Info:\n");

    notes();

    while (1){

        printf("\n -Type the tone of the song (Ex. 'C', 'f#', 'LAb', 'do', 'B'): ");
        fflush (stdin);
        scanf("%s", t);
        upper (t);
        
        if (strcmp (t, "DO") == 0 || strcmp (t, "C") == 0){
            num = 1;
            break;
        }else if (strcmp (t, "DO#") == 0 || strcmp (t, "C#") == 0){
            num = 2;
            break;
        }else if (strcmp (t, "RE") == 0 || strcmp (t, "D") == 0){
            num = 3;
            break;
        }else if (strcmp (t, "RE#") == 0 || strcmp (t, "D#") == 0){
            num = 4;
            break;
        }else if (strcmp (t, "MI") == 0 || strcmp (t, "E") == 0){
            num = 5;
            break;
        }else if (strcmp (t, "FA") == 0 || strcmp (t, "F") == 0){
            num = 6;
            break;
        }else if (strcmp (t, "FA#") == 0 || strcmp (t, "F#") == 0){
            num = 7;
            break;
        }else if (strcmp (t, "SOL") == 0 || strcmp (t, "G") == 0){
            num = 8;
            break;
        }else if (strcmp (t, "SOL#") == 0 || strcmp (t, "G#") == 0){
            num = 9;
            break;
        }else if (strcmp (t, "LA") == 0 || strcmp (t, "A") == 0){
            num = 10;
            break;
        }else if (strcmp (t, "LA#") == 0 || strcmp (t, "A#") == 0){
            num = 11;
            break;
        }else if (strcmp (t, "SI") == 0 || strcmp (t, "B") == 0){
            num = 12;
            break;
        }else printf("\nYou didn't type a correct tone. Try again.\n");
    
    }

    printf("\nHow many chords do you want to check? ");
    scanf("%d", &nchords);

    printf("\n-You are going to type the tone basing on the above list (Ex. '1' '5' '11' etc)\n");  

    for (i = 0; i < nchords; i++){

        printf("\nChord %d: ", i + 1);
        scanf("%d", &numchords[i]);
    }

    printf("\nResults:\n");    //print if there's any problems with the chords

    for (i = 0; i < nchords; i++){
        
        flag = 0;

        for (j = 0; j < nchords; j++){

            if (num == 1){

                if (c[j] == numchords[i]){
                    flag = 1;
                }
                

            }else if (num == 3){

                if (d[j] == numchords[i]){
                    flag = 1;
                }

            }else if (num == 5){

                if (e[j] == numchords[i]){
                    flag = 1;
                }
                
            }else if (num == 6){

                if (f[j] == numchords[i]){
                    flag = 1;
                }

            }else if (num == 8){

                if (g[j] == numchords[i]){
                    flag = 1;
                }

            }else if (num == 10){

                if (a[j] == numchords[i]){
                    flag = 1;
                }

            }else{
                if (b[j] == numchords[i]){
                    flag = 1;
                }
                
            }
        }
        if (flag == 1){
            printf("\nThe chord %d has great affinity\n", i + 1);
        }else printf("\nThe chord %d might cause some problems with the song. You can try with the Tone %d\n\n", i + 1, numchords[i] + 1);
    }

    system("pause");

}


//-----------------------------------------------------------------------------------------------------

void save_song (){    //

    printf("Data of the song:\n");

    printf("\n*Important: If you need to put a space, use the character '_' instead of the space*\n");

    printf("\n -Id for the song (with this id you can modify the song later Ex '1564', '87') -> ");
    fflush (stdin);
    scanf("%d", &songs[k].id);

    printf("\n -Name of the song (Ex. 'The_code_melody') -> ");
    fflush (stdin);
    scanf("%s", songs[k].name_song);

    printf("\n -Author (Ex. 'Freddie_Mercury') -> ");
    fflush (stdin);
    scanf("%s", songs[k].author);

    printf("\n -Tone of the song (Ex. 'do', 'E', 'Fa', 'B') -> ");
    fflush (stdin);
    scanf("%s", songs[k].tone);
    upper (songs[k].tone);

    printf("\n -Chords of the song (Ex. 'do-mi-fa-sol', 'E-F#-G#-A-B') -> ");
    fflush (stdin);
    scanf("%s", songs[k].chords);
    upper (songs[k].chords);

    k++;
}

//----------------------------------------------------------------------

void modify_song (){

    int id, i, x, op, flag = 0;

    while (flag == 0){

        printf("Type the ID of the song that you want to change: ");
        fflush (stdin);
        scanf("%d", &id);

        for (i = 0; i < k; i++){

            if (id == songs[i].id){  

                flag = 1;
                break;
            }
        }
        printf(flag == 0 ? "ERROR. That ID doesn't exit, try again\n" : "");
    }

    do{

    printf("\nData of that ID:\n");

    printf("\n-Name of the song: %s\n", songs[i].name_song);
    printf("\n-Author: %s\n", songs[i].author);
    printf("\n-Tone: %s\n", songs[i].tone);
    printf("\n-Chords: %s\n", songs[i].chords);

    printf("\nSelect the option that you want to change:\n");

    printf("\n1.ID");
    printf("\n2.Name of the song");
    printf("\n3.Author");
    printf("\n4.Tone");
    printf("\n5.Chords\n");


    do{

        printf("\n-> ");
        fflush(stdin);
        scanf("%d", &x);

    } while (x > 5 || x < 1);  //avoid mistakes

    system("cls");

    switch (x){

        case 1: printf("Type the new id: ");
                scanf("%d", &songs[i].id);

                break;
        
        case 2: printf("Type the new songs name: ");
                fflush (stdin);
                scanf("%s", songs[i].name_song);

                break;
        
        case 3: printf("Type the author: ");
                fflush (stdin);
                scanf("%s", songs[i].author);

                break;
        
        case 4: printf("Type the new tone: ");
                scanf("%s", songs[i].tone);
                fflush (stdin);
                upper (songs[i].tone);

                break;

        case 5: printf("Type the new chords: ");
                fflush (stdin);
                scanf("%s", songs[i].chords);
                upper (songs[i].chords);

                break; 
    }

    printf("\nThe info was update successfully");

    do{
        printf("\n\nDo you want to do another change? Press '1' to do a new change or '2' to return to the menu...");
        scanf("%d", &op);

    }while (op < 1 || op > 2);

    if (op == 2){
        break;
    }
    
    }while (1);
}

//----------------------------------------------------------------------

void rewrite_songs (){     //if we modify something of a song then this funcions is going to update the txt file

    FILE* songs_register = fopen ("register.txt", "w");

    FILE* list_songs = fopen ("songs.txt", "w");
    
    int i;

    for (i = 0; i < k; i++){

        //save songs in the register file 

        fprintf(songs_register, "%d ", songs[i].id);

        fprintf(songs_register, "%s ", songs[i].name_song);

        fprintf(songs_register, "%s ", songs[i].author);
        
        fprintf(songs_register, "%s ", songs[i].tone);
        
        fprintf(songs_register, "%s\n", songs[i].chords);

        //save songs in the songs file 

        fprintf(list_songs, "ID: %d\t", songs[i].id);

        fprintf(list_songs, "Name of the song: %s\t", songs[i].name_song);

        fprintf(list_songs, "Author: %s\t", songs[i].author);
        
        fprintf(list_songs, "Tone: %s\t", songs[i].tone);
        
        fprintf(list_songs, "Chords: %s\n", songs[i].chords);

    }
}

void upper (char s[]){  //pass all strings to upper case

    int i;

    for (i = 0; i < strlen(s); i++){

        if (isalpha (s[i])){
            s[i] = toupper (s[i]);
        }
    }
}

int repetition (int acordes[], int size){

    int i, j, aux;

    for (i = 0; i < size; i++){
        for (j = 0; j < size - 1; j++){

            if (acordes[j] > acordes[j + 1]){
                aux = acordes[j];
                acordes[j] = acordes[j + 1];
                acordes[j + 1] = aux;
            }
        }
    }

    for (i = 0; i < size - 1; i++){
        
        if (acordes[i] == acordes[i + 1]){
            return 1;
        }
    }

    return 0; 
} 
