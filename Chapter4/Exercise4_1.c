#include<stdio.h>
#define MAX 1000

int gline (char [],int);

int strrindex (char [], char []); //returns the position of the rightmost ocurrance of t in s or -1 if none

int main (){

    char s[MAX], t[]="ould";
    
    while ((gline(s,MAX))>0){

        if(strrindex(s,t)>=0){

            printf("%d\n", strrindex(s,t));
        }
    }
      

    return 0;
}

int gline (char s[], int lim){    

    int c,i=0;

    while(--lim>0 && (c=getchar())!='\n' && c!=EOF){
        s[i++]=c;
    }
    if(c=='\n'){
        s[i++]=c;
    }
    s[i]='\0';

    return i;

}

int strrindex (char s[], char t[]){

    int i ,j ,k, rightmost=0;

    for (i=0; s[i]!='\0'; i++){

        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++){
            ;
        }

        if (k>0 && t[k]=='\0' && i>rightmost){
            rightmost=i;
        }
    }

    return (rightmost>0) ? rightmost : -1;
}   