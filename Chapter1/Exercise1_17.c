#include<stdio.h>
#define max 1000

int lenght(char [], int);

int main(){

    int len;
    char line[max];
    
    
    while((len=lenght(line,max))>0){
        if(len>=80){
            printf("%s\n",line);
        }
        printf("%d\n",len);
    }

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
