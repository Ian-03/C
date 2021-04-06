#include<stdio.h>
#include<ctype.h>

void gline (char [], int);

int htoi (char []);

int main (){

    const int MAX=100;
    char s[MAX];
    
    gline(s, MAX);

    printf("%d", htoi(s));


    return 0;
}

void gline (char s[], int MAX){

    char c;
    int i;

    for(i=0; i<MAX-1 && (c=getchar())!='\n' && c!=EOF; i++){
        s[i]=c;
    }
    s[i]='\0';
}

int htoi (char s[]){

    int n=0;

    for(int i=0; s[i]!='\0'; i++){
        if(s[i]=='0' && tolower(s[i+1])=='x'){
            i+=2;
        }
        if(isdigit(s[i])){
             n=16*n+(s[i]-'0');
        }else{
            n=16*n+(tolower(s[i])-'a'+10);
        }

     }
     return n;
}
