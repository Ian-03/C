#include<stdio.h>

int conversion(int);

int main(){

    int celsius=0,upper=300,step=20;

    while(celsius<=upper){
        printf("%d c* \t%d f*\n",celsius, conversion(celsius));
        celsius=celsius+step;
    }


    return 0;
}

int conversion(int celsius){

    int fahren=0;
    fahren=(celsius*5/9)+32;
    return fahren;
}