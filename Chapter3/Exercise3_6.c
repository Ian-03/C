#include<stdio.h>
#include<string.h>

void itoawidth (int, char[], int);

void reverse (char[]);

int main (){

    char s[1000];
    int n=545;  //you can change the number here

    itoawidth (n, s, 6); //you can change the width using other value in the 5

    return 0;
}

void itoawidth (int n, char s[], int l){

    int sign, i=0;

    if (n<0){
        n=-n;
        sign=1;
    }

    while (n>0){
        s[i++]=n%10+'0';
        n/=10;
    }
    
    if (sign==1){
        s[i++]='-';
    }

    s[i]='\0';

    reverse (s);

    if (l>strlen(s)){

        while(l>strlen(s)){
            printf(" ");
            l--;
        }
    }

    for(int i=0; i<l; i++){
        printf("%c", s[i]);
    }

}

void reverse (char s[]){

    char aux,j;

    for (int i=0, j=strlen(s)-1;  i<j;  i++, j--){
        aux=s[i];
        s[i]=s[j];
        s[j]=aux;
    }
}
