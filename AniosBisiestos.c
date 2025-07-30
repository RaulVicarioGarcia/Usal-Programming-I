#include <stdio.h>
#include <stdlib.h>
#define TAM 100

int esBisiesto (int anio);
void primerosBisiestosXXI (int *vector, int dim, int *totbisiestossiglo);

int main (void) {

    int vector[TAM];
    int total;

    primerosBisiestosXXI (vector, 5, &total);

    printf("Total de años bisiestos en el siglo XXI: %d\n", total);
    printf("Primeros %d años bisiestos del siglo XXI:\n", 5);

    for (int i = 0; i < 5; i++) {
        printf("%d ", vector[i]);
    }

    printf("\n");

    return 0;
}

int esBisiesto (int anio) {

    if (anio % 4 == 0) {

        if (anio % 100 == 0) {

            if (anio % 400 == 0) {

                return 1;

            } else {

                return 0;

            }

        } else {

            return 1;

        }

    }

    return 0;

}

void primerosBisiestosXXI (int *vector, int dim, int *totbisiestossiglo) {

    int contador = 0;
    int totalBisiestos = 0;
    int i;

    for (i = 2001; i < 2100; i++) {

        if (esBisiesto(i) == 1) {

            totalBisiestos++;

            if (contador < dim) {

                vector[contador] = i;
                contador++;

            }
            
        }

    }

    *totbisiestossiglo = totalBisiestos;

}