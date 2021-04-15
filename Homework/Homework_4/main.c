#include<stdio.h>
#include<stdlib.h>
#include "calc.h"

int main (){

    int type, case_l=0, case_i=0, case_p=0, one=0;
    double op2, abc[26];
    char s[MAXOP], op=0;

    abceros (abc);

    while ((type=getop(s))!=EOF){
        
        switch(type){

            case ':': 

                case_p++;

                break;

            case '=':
                  
                case_i++;
                
                break;

            case LETTER:
                
                push (abc[l-'a']);
                
                case_l++;
                
                break;    

            case NUMBER: 

                one++;

                if(case_l>0 && case_i>0 && case_p>0){  //case a :=

                    abc[l-'a']=atof(s);

                    printf("New Value accepted.\n\n");

                }else if(case_l>0 && case_i>0){ //case a =

                    if(abc[l-'a']==0){
                        
                        abc[l-'a']=atof(s);

                        printf("New Value accepted.\n\n");

                    }else{

                        printf("The variable already has a value. Do you want to change it?\n");

                        printf("Type '1' for YES or type '0' for NO ");

                        op=getchar();

                        switch (op){

                            case '0': printf("The value was conserverd. Value is still:"); break;

                            case '1': abc[l-'a']=atof(s); printf("The value has been changed. New Value:"); break;
                            
                            default: printf("error, invalid option. Value is still:"); break;
                        }
                        push(abc[l-'a']);
                        
                        
                    }

                }else{
                     push(atof(s));
                     one--;
                }
                   
                
                break;

            case '+':
                push (pop() + pop());
                break;

            case '*':
                push (pop() * pop());
                break;

            case '-':
                op2=pop();
                push (pop() - op2);
                break;

            case '/':
                op2=pop();
                if (op2!=0.0){
                    push (pop() / op2);
                }else printf("error: zero divisor\n");
                break; 

            case '%':
				op2 = pop();
				if(op2 != 0.0){
				    push((int)pop() % (int)op2);           // % only works with int
                }else printf("error: divisor de cero\n");
				break;    
    
            case '\n':

                if (one==0){
                    printf("\t%.8g\n\n", pop());
                }
        
                one=0;
                case_l=0;
                case_i=0;
                case_p=0;

                break;

            default: 
                printf("error: unknown command %s\n", s);
                break;
        }
    }

    return 0;   
}