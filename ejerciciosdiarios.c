#include<stdio.h>

int main(){

    char vocal;

    printf("Digite una vocal en minuscula: ");
    scanf("%c", &vocal);

    switch (vocal){
        case 'a':
        printf("A");
        break;
        case 'e':
        printf("E");
        break;
        case 'i':
        printf("I");
        break;
        case 'o':
        printf("O");
        break;
        case 'u':
        printf("U");
        break;
    
    default: printf("ERROR: '%c' no es una vocal en minuscula uwun't", vocal);
        break;
    }


    return 0;
}