#include<stdio.h>

void getline (char [],int);

void squeezy2 (char [], char []);

int main (){

const int MAX=1000;

char line1[MAX];
char line2[MAX];

    getline (line1,MAX);
    getline (line2,MAX);

    squeezy2 (line1,line2);

    printf("\n%s", line1  );

    return 0;
}
 
void squeezy2 (char line1[], char line2[]){

    int j,i;

    for (i=0; line1[i]!='\0'; i++){
        for (j=0; line2[j]!='\0'; j++) {
            if (line2[j]==line1[i]){
                line1[i]=' ';
                break;
            }
        }  
    }
    

}

void getline (char line[], int MAX){

    int i,c;
    
    for (i=0; i<MAX-1 && (c=getchar())!='\n' && c!=EOF; i++){
        line[i]=c;
    } 
    if (c=='\n'){
        line[i++]=c;
        } 
    line[i]='\0';
}