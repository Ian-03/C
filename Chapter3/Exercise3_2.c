#include<stdio.h>

void getline (char []);

void escape (char [], char []);

int main(){

    const int MAX=1000;
    char s[MAX], t[MAX];

    getline (s);
    escape (t,s);

    printf("%s",t);
    
    return 0;
}

void getline (char s[]){

    int i=0,c;

    while((c=getchar()) != EOF){
        s[i++]=c;
    }
    s[i]='\0';
}

void escape (char t[], char s[]){

    int i=0,j=0;

    while (s[i] != '\0'){  
        switch (s[i]){

            case '\n': t[j++]='\\';
               t[j++]='n';
               break;
            case'\t': t[j++]='\\';
              t[j++]='t';
              break;
            default: t[j++]=s[i]; break;
        }
        i++;
        
    }
}

