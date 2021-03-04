#include<stdio.h>
#define MAX 1000

int main(){

    int c,i=0;
    char line[MAX];

    while(i<MAX){
        c=getchar();    
            if((c=getchar())!=EOF){
                if(c!='\n'){
                    line[i]=c;
                    i++;
                }
            }
    }


    return 0;
}