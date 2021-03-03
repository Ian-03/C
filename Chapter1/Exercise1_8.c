#include<stdio.h>

int main(){

    int c, newline=0, tabs=0, blanks=0;

        while((c=getchar())!=EOF){
            if(c=='\n'){
                newline++;
            }
            if(c=='\t'){
                tabs++;
                 }
            if(c==' '){
                 blanks++;
                 } 
            
        }

        printf("\nThe number of new lines is: %d \nThe number of tabs is: %d \nThe number of blanks is: %d \n\n",newline,tabs,blanks);

    return 0;
}