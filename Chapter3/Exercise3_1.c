#include<stdio.h>

int binsearch (int, int [], int);

int main (){

    int array[24]= {1,2,3,5,8,9,10,13,16,17,22,30,54,58,61,65,70,78,79,83,87,89,98,100}; //random array 

    printf("%d",binsearch(5,array,24)); //you can change the 5 for any number you want to search 

    return 0;
}

int binsearch (int x, int v[], int n){

    int low=0, high=n-1, mid=(high+low)/2;

    while(low<=high && x!=v[mid]){

        mid=(high+low)/2;

        if(x>v[mid]){
            low=mid+1;
        }else{
            high=mid-1;
        }

    }

    return (x==v[mid]) ? mid : -1;
}
