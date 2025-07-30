#include <stdio.h>
#include <stdlib.h>
#define DIMAX 100

int main (void) {

    int array [DIMAX];
    int i = 0;

    printf ("\nIntroduzca un vector de numeros ordenados ascendentemente.\n");

    for(i=0;i<DIMAX;i++) {

            scanf("%d", &array[i]);

        if (i > 0 && array[i] <= array[i-1]) {

            printf("\nDebes introducir un numero mayor que el anterior.\n");
            break;

        }}

    return 0;

}