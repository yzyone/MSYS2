#include <stdio.h>
#include "fun.h"

int main(int, char**){
    printf("hello so\n");

    int a = 1;
    int b = 2;
    int c = sum( a, b );
    printf( "sum: %d + %d = %d\n", a, b, c );
    return 0;
}