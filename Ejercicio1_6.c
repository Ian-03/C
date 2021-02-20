#include<stdio.h>

int main(){

    int c;
    
    while((c=getchar())!=EOF){ 
        printf("%d",c!= EOF );  //this line was based on an internet solution
        putchar(c);

    }
    
    printf("\n%d", c!=EOF);

    return 0;
}