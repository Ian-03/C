//i just could do the part of removing trailing blanks

#include<stdio.h>
#define max 1000

int lenght(char [], int);

void copy(char[], char[]);

int main(){

    int len;
    char line[max];
    
    
    while((len=lenght(line,max))>0){
        printf("%s\n",line);
        printf("%d\n",len);
    }
     

    return 0;
}

int lenght(char line[], int lim){

    int c,i;

    for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++){
        line[i]=c;
        if(c==' '){
            while((c=getchar())==' '){
                ;
            }
            line[i]=' ';
            i++;
            line[i]=c;
        }
        
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
