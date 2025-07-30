#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main (void) {

    int dim = 0;
    int listapri[MAX];
    int listainv[MAX];
    int i = 0;

    printf ("\nDame la dim del vector: ");
    scanf ("%d",&dim);

    printf ("\nIntroduce el vector: ");

    for (i=0;i<dim;i++) {

        scanf("%d",&listapri[i]);

    }

    for (i = 0; i < dim; i++) {

        listainv[i] = listapri[dim - 1 - i];
    
    }

    return 0;

}