/*Write a program detab that replaces tabs in the input with theproper number 
of blanks to space to the next tab stop. Assume afixed set of tab stops, say
 every n columns. Should n be a variable or a symbolic parameter?
*/

#include<stdio.h>
#define MAX 1000

int getline(char [], int);

void detab(char [], int);           

int main(){

    char line[MAX];

        while((getline(line,MAX))>0){
            detab(line,MAX);    
        }

    return 0;
}

int getline(char line[], int max){

     int c,i;

    for(i=0; i<max-1 && (c=getchar())!=EOF && c!='\n'; i++){
        line[i]=c;
    }
    if(c=='\n'){
        line[i]=c;
        i++;
    }
    line[i]='\0';

    return i;   
}

void detab(char line[], int max){

    //aaaaaaaaaaa so many rules:c

    int i;
    int flag=0;

    for(i=0; line[i]!='\0'; i++){

        if(line[i]!='\t'){
            printf("%c",line[i]);
        }else if(line[i]=='\t' && line[i-1]!='\t' && i!=0){
            printf("____");
        }else if(line[0]=='\t' && flag==0){;
            printf("________");
            flag=1;
        } else{ 
            printf("________");
        }
            
        
    }
}