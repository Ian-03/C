#include<stdio.h>
#include<limits.h> //this library contains funtions to get the ranges of the variables.

int main(){

    printf("Signed variables: \n");

    printf("\nThe minimum value for an int variable is %d and the maximum is %d\n", INT_MIN, INT_MAX);
    printf("\nThe minimum value for an char variable is %d and the maximum is %d\n", CHAR_MIN, CHAR_MAX);
    printf("\nThe minimum value for an long variable is %d and the maximum is %d\n", LONG_MIN, LONG_MAX);
    printf("\nThe minimum value for an short variable is %d and the maximum is %d\n", SHRT_MIN, SHRT_MAX);

    printf("\nUnsigned variables: \n");

    printf("\nThe maximum value for an int variable is %u\n", UINT_MAX);
    printf("\nThe maximum value for an char variable is %u\n", UCHAR_MAX);
    printf("\nThe maximum value for an long variable is %u\n", ULONG_MAX);
    printf("\nThe maximum value for an short variable is %u\n\n", USHRT_MAX);


    return 0;
}