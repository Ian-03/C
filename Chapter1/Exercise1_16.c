#include<stdio.h>
#define max 1000

int lenght(char [], int);

void copy(char[], char[]);

int main(){

    int len,maximun=0;
    char line[max],longest[max];
    
    
    while((len=lenght(line,max))>0){
        if(len>maximun){
            maximun=len;
            copy(line,longest);
        }
        printf("%d\n",len);
    }

    printf("\nThe longest line was: %s", longest);
     

    return 0;
}

int lenght(char line[], int lim){

    int c,i;

    for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++){
        line[i]=c;
    }
    line[i]='\0';

    return i;
}

void copy(char line[], char longest[]){

    int i=0;

    while((longest[i]=line[i])!='\0'){
        i++;
    }
}
