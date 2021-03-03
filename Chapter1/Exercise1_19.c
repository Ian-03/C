#include<stdio.h>
#define MAX 1000

int getline(char[], int);

void reverse(char[]);

int counter=0;

int main(){

    char line[MAX];

        while(getline(line,MAX)>0){
            reverse(line);
            printf("\n");
        }

    return 0;
}

int getline(char line[], int max ){

    int i,c;

    for(i=0; i<max-1 && (c=getchar())!=EOF && c!='\n'; i++){
        line[i]=c;
        counter++;
    }

    return i;
}

void reverse(char line[]){

    int i;

    for(i=counter-1; i>=0; i--){
        printf("%c",line[i]);
    }
    counter=0;
}