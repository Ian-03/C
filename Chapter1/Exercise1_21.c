#include<stdio.h>
#include<string.h>

void entab (char []);

void gline (char [], int); 

int cont;

int main (){

    char s[100];

    gline(s,100);

    entab(s);

    return 0;
}

void gline (char s[], int max){

    int i,c;

    for(i=0; i<max-1 && (c=getchar())!=EOF && c!='\n'; i++){
        cont=(c=='\t') ? cont+8 : cont+1;
    }
    
    s[i+1]='\0';
}

void entab (char s[]){

    int cc=0,t,b;

    while (cont>=8){
        cont-=8;
        cc++;
    }

    t=cc;
    b=cont;
    
    while (cc>0 || cont>0){
        if (cc-->0){
            printf("\t");
        }else if (cont-->0){
            printf(" ");
        }
    } 
    
    printf("tabs: %d  blanks: %d", t, b);

}