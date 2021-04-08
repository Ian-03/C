#include<stdio.h>

void gline (char [],int);

char any (char [], char []);

int main (){

const int MAX=1000;

char line1[MAX];
char line2[MAX];

    gline (line1,MAX);
    gline (line2,MAX);

    any (line1,line2);

    return 0;
}
 
char any (char line1[], char line2[]){

    int j,i,c=0;
    char f;

    for (i=0; line1[i]!='\0'; i++){
        if (c==0){
          for (j=0; line2[j]!='\0'; j++) {
             if (line2[j]==line1[i]){
                  f=line1[i];
                  c++;
                  break;
              }
            }  
        }
        else break;
    }

    if(c==0){
        return -1;
    }
    else{
        printf("%c",f);
        } 

}

void gline (char line[], int MAX){

    int i,c;
    
    for (i=0; i<MAX-1 && (c=getchar())!='\n' && c!=EOF; i++){
        line[i]=c;
    } 
    if (c=='\n'){
        line[i++]=c;
        } 
    line[i]='\0';
}
