#include<stdio.h>
#define MAX 50

void GetPrimeNumbers(int);

void binary(int j);

int arraysize=0; 

int main(){

    int k,i=0;

    printf("Type the value of *k*: ");   //get the value of k numbers.
    scanf("%d",&k);

    int l=k;

    while((l/2)>0){  //this code is to get the lenght of the largest number and get an accurate amount of ceros.
        l=l/2;
        arraysize++;
    }

    int primes[arraysize];

    for (i=0; i<arraysize; i++){
        primes[i]=0;
    }
    

    GetPrimeNumbers(k);   //functions to get the prime numbers and save them in an array.

    return 0;
}



void binary(int j) //inspired in the rulgamer program
{
    int i=0; 
    int numb[10]={0}; //ceros
    
    while(j>0){
        
	numb[i]=j%2;
	j=j/2; 
	++i; // aumentamos en uno la posicion
    }

    for(int i=9;i>=0;--i){
       printf("%01d",numb[i]);
    }
     printf("\n");
}

void GetPrimeNumbers(int k){
    int counter=0,c2=0;
    int primes[arraysize];

    for(int i=1; i<=k; i++){
        for(int j=1; j<=i; j++){
            if(i%j==0){
                counter++;
            }
        }
        if(counter==2){
            binary(i);          //here if the program finds a prime number it will use the funcion that we did and turned it into an binary number
        }
        counter=0;
    }
}