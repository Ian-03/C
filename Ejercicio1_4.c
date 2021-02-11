#include<stdio.h>

int main(){

    int celsius=0, fahrenheit;

    while(celsius<=300){

        fahrenheit=9*celsius/5+32;
        printf("%d C\t %d F\n", celsius, fahrenheit);
        celsius+=20;
    }


    return 0;
}