#include<stdio.h>

void getline (char [], int);

void escape (char [], char []);

int main(){

    const int MAX=1000;
    char s[MAX], t[MAX];

    getline (s,MAX);
    escape (t,s);

    printf("%s",t);
    
    return 0;
}

void getline (char s[], int MAX){

    int i,c;

    for (i=0; i < MAX-1 && (c=getchar()) != EOF; i++){ 
        s[i]=c;
    }
    s[i]='\0';
}

void escape (char t[], char s[]){

    int i=0,j=0;

    while (s[i] != '\0'){  
        if (s[i]=='\n'){
            t[j++]='\\';
            t[j++]='n';
        }else if (s[i]=='\t'){
            t[j++]='\\';
            t[j++]='t';
        }else t[j++]=s[i];
        i++;
        
    }
}