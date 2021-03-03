#include<stdio.h>

int main(){

    int c,array[10];

        printf("\nThis program creates an histogram of the frecuency of the characters:\n");

        for(int i=0; i<10; i++){
            array[i]=0;
        }

        while((c=getchar())!=EOF){
            if(c>='0' && c<='9'){
                array[c-'0']++;
            }
        }

        for(int i=0; i<10; i++){
            printf("\n%d->",i);
            while(array[i]>0){
                printf("* ");
                array[i]--;
            }
        }

        printf("\n\n");
       

    return 0;
}
