#include<stdio.h>
#define TRUE 1
#define FALSE 0

int main(){

    int c,flag=FALSE,flag2=FALSE,flag3=FALSE;

    //I used 3 flags, the first one to only print 1 'X' if there are more numbers in a row.
    //the second flag to know if there are any quote and to ignore the code of the 'X' of numbers.
    //the third flag to know the end of the quotes.

    while((c=getchar())!=EOF){

        if(c=='(' || c=='[' || c=='{' || c=='<' || c=='"' && flag3==FALSE){   //This part is to know if there are any quotes.
            if(c=='"'){
                flag3=TRUE;
            }
            flag2=TRUE;
        }else if(c==')' || c==']' || c=='}' || c=='>' || c=='"'){      //this part is to know the end of those quotes.
            flag3=FALSE;
            flag2=FALSE;
        }

        if(c=='.' || c==',' || c==';' || c==':' || c=='?' || c=='!' || c=='-' || c=='_'){       //this part is to ignore the punctuation
            continue;
        }
        else if(c>='0' && c<='9' && flag2==FALSE){      //this part is to change the number string for an 'X'.
            if(flag==FALSE){
            putchar('X');
            }
            flag=TRUE;
        }
        else {
            putchar(c);     
            flag=FALSE;
            }
            
        
    }


    return 0;
}