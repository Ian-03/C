#include<stdio.h>
#include<stdlib.h>

#define MAXOP 100
#define NUMBER '0'
#define LETTER 'a'

int getop (char []);

void push (double);

double pop (void); 

void abceros (double []);

int l;

void abceros (double a[]){    //llenar todas las variables con ceros

    for (int i=0; i<26; i++){
        a[i]=0;
    }
} 



#define MAXVAL 100

double val [MAXVAL];

int sp=0;       

void push (double f){

    if (sp < MAXVAL){
        val[sp++]=f;
    }else printf ("error: stack full, can´t push %g\n", f);

}

double pop (void){

    if(sp > 0){
        return val[--sp];
    }else{
        printf ("error: stack empty\n");
        return 0.0;
    }
}

#include<ctype.h>

int getch (void);

void ungetch (int);

int getop (char s[]){

    int i=0, c;

    while ((s[0]=c=getch())==' ' || c=='\t'){
        ;
    }

    s[1]='\0';

    if (!isdigit(c) && !isalpha(c) && c!='.'){
        
        return c;
        }

    if (isalpha(c)){

        l=tolower(c);

        return LETTER;
    }

    if (isdigit(c)){
        
        while (isdigit(s[++i]=c=getch())){
            ;
        }
    }

    if (c=='.'){

        while (isdigit(s[++i]=c=getch())){
            ;
        }
    }

    s[i]='\0';

    if (c!=EOF){
        ungetch(c);
    }

    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp=0;

int getch (void){

    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch (int c){

    if (bufp>=BUFSIZE){

        printf("too many characters\n");
    }else buf[bufp++]=c;
}
    