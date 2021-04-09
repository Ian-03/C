#include<stdio.h>

void gline (char [], int);

void removeComments (char []);

int main (){

    char s[1000];
 
    gline (s,1000);

    removeComments (s);



    return 0;
}

void gline (char s[], int max){

    int i=0,c;

    while ((c=getchar())!=EOF){
        s[i++]=c;
    }

    s[i]='\0';
}

void removeComments (char s[]){

    for (int i=0; s[i]!='\0'; i++){
        if (s[i]=='/' && s[i+1]=='/'){
            while (s[i]!='\n'){
                i++;
            } 
        }else if (s[i]=='/' && s[i+1]=='*'){
             i+=2; //idk why this while doesnt work correctly when i dont type that i+=2;
            while (s[i]!='*' && s[i+1]!='/'){
                i++;
            }
           i++; 

        }else printf("%c", s[i]);

    }
}