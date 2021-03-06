#include<stdio.h>

int lower (int);
void gline (char [], int);

int main (){

    const int MAX=100;
    char line[MAX];

    gline (line, MAX);

    printf("%s", line);


    return 0;
}

int lower (int c){

    return (c>='A' && c<='Z') ? c + 'a' - 'A' :  c;
}

void gline (char line[], int MAX){

    int i,c;
    
    for (i=0; i<MAX-1 && (c=getchar())!='\n' && c!=EOF; i++){
        line[i]=lower(c);
    } 
    if (c=='\n'){
        line[i++]=c;
        } 
    line[i]='\0';
}
