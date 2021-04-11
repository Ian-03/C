#include<stdio.h>
#include<ctype.h>

#define MAX 1000

void gline (char [], int);

double atof (char []);

int main (){

    char s[MAX];

    gline (s, MAX);

    printf("%f", atof(s));

    return 0;
}

void gline (char s[], int lim){

    int i=0, c;

    while (--lim>0 && (c=getchar())!=EOF && c!='\n'){
        s[i++]=c;
    }
    s[i]='\0';
}

double atof (char s[]){

    double val, power;
    int i, sign;

    for (i=0; isspace(s[i]); i++){
        ;
    }

    sign=(s[i]=='-') ? -1 : 1;

    if (s[i]=='+' || s[i]=='-'){
        i++;
    }

    for (val=0.0; isdigit(s[i]); i++){
        val=10.0*val + (s[i]-'0');
    }

    if (s[i]=='.'){
        i++;
    }

    for (power=1.0; isdigit(s[i]); i++){
        val=10.0*val + (s[i]-'0');
        power*=10.0;
    }

    int sign2=1;

    if (tolower(s[i])=='e'){

        i++;

        sign2=(s[i]=='-') ? -1 : 1;
        
        if (s[i]=='+' || s[i]=='-'){

            i++;
        }

        while(s[i]-'0'!=0){
            if(sign2==- 1){
                power*=10;
            }else power/=10;
            s[i]--;
        }


    }

    return sign*val/power;
}