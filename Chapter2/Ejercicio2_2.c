#include<stdio.h>
#define MAX 1000

int main(){

    int c,i=0;
    char line[MAX];

    while(i<MAX){
        c=getchar();    
            if(c!=EOF){
                if(c!='\n'){
                    line[i]=c;
                    i++;
                }else return 0;
            }else return 0;
    }


    return 0;
}
