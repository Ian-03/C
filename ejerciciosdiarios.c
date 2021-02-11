#include<stdio.h>

int main(){

    int fahrenheit=0, celsius;

    printf("This is a table that compares the temperature between fahrenheit adn celsius: \n");
    
    while(fahrenheit<=300){
        
        celsius=5*(fahrenheit-32)/9;

        printf("%d F\t%d C\n", fahrenheit, celsius);
        fahrenheit+=20;
    }

    return 0;
}
