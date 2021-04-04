#include<stdio.h>
#include<string.h>

void itob (int, char[], int);

void reverse (char[]);

int main (){

    char s[100];
    int n=75;   //change number here
    int b=16;    //change the base that you want (2>=b>=36)

    itob (n,s,b); 

    return 0;
}

void itob (int n, char s[], int b){

    int i=0,sign=0;

    if(n<0){
        n=-n;
        sign++;
    }

    while(n>0){
        s[i++]=(n%b<10) ? n%b+'0' : n%b+55;  //if the remaning is larger than 9 that means that it
        n/=b;                                //will be a letter and the character 'A' is at 65th position .
    }

    if(sign==1){
        s[i++]='-';
    }

    s[i]='\0';

    reverse (s);

    printf("%s",s);

}

void reverse (char s[]){

    char aux;
    int j,i;

    for (i=0,j=strlen(s)-1; i<j; i++,j--){
        aux=s[i];
        s[i]=s[j];
        s[j]=aux;
    }
}