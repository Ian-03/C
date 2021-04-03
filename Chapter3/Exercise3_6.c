#include<stdio.h>
#include<string.h>

void itoawidth (int, char[], int);

void reverse (char[]);

int main (){

    char s[1000];
    int n=7521;  //you can change the number here

    itoawidth (n, s, 8); //you can change the width using other value in third argument

    return 0;
}

void itoawidth (int n, char s[], int l){

    int sign, i=0, j=0, len;

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

    len=strlen(s);

    if (l>len){ //print the spaces if the width is larger than the string

        while(l>len){
            printf(" ");
            l--;
        }

    }else j=len-l; //if the width is smaller than the string the string will be printed from left to the right


    for(int i=j; l; i++,l--){
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
