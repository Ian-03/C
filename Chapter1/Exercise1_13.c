#include<stdio.h>

int main(){

    int c,array[10],cc=0;

        printf("\nThis program creates an histogram of the lenghts of the words:\n\n");

        for(int i=0; i<10; i++){
            array[i]=0;
        }

        while((c=getchar())!=EOF){

            if(cc>=1 && c==' ' || c=='\t'){
                    array[cc]++;
                     cc=0;
            }else cc++;    
        }
       
       for(int i=1; i<10; i++){
            printf("\n%d->",i);
            while(array[i]>0){
                printf("* ");
                array[i]--;
            }
        }

    return 0;
}