#include <stdio.h>
#include <stdlib.h>
#define FILMAX 100
#define COLMAX 100

int main (void) {

    int num1 = 0; // Orden
    int temp = 0;
    int cuadradoMagico[FILMAX][COLMAX];
    int i = 0, j = 0;
    int sumaFila, sumaColumna, sumaDiagonal1 = 0, sumaDiagonal2 = 0;
    int numMagico;  // Número mágico
    int correcto = 1;

    do {

    printf ("Introduce un valor impar: ");
    scanf ("%d",&num1);

    temp = num1 % 2;

    } while (temp == 0 || num1 < 3 || num1 > 15);

    for (i = 0; i < num1; i++) {
    
        for (j = 0; j < num1; j++) {
    
            cuadradoMagico[i][j] = -1;
    
        }
    
    }

    int num = 1;  // Número actual
    
    i = 0;
    
    j = num1 / 2;  // Iniciar en la fila 0, columna central

    while (num <= num1 * num1) {

        cuadradoMagico[i][j] = num;

        // Calcular nueva posición
       
        int newI = (i - 1 + num1) % num1;  // Fila anterior (considerando circularidad)
        int newJ = (j + 1) % num1;        // Columna siguiente (considerando circularidad)

        if (cuadradoMagico[newI][newJ] != -1) {  // Si está ocupado

            i = (i + 1) % num1;  // Mover hacia abajo
        
        } else {
        
            i = newI;
        
            j = newJ;
        
        }

        num++;
    }

    numMagico = num1 * (num1 * num1 + 1) / 2;  // Número mágico esperado
    
    printf("\nNúmero Mágico esperado: %d\n", numMagico);

        for (i = 0; i < num1; i++) {
        sumaFila = 0;
        sumaColumna = 0;

        for (j = 0; j < num1; j++) {
            sumaFila += cuadradoMagico[i][j];  // Sumar fila
            sumaColumna += cuadradoMagico[j][i];  // Sumar columna
        }

        printf("Suma de la fila %d: %d\n", i + 1, sumaFila);
        printf("Suma de la columna %d: %d\n", i + 1, sumaColumna);

        if (sumaFila != numMagico || sumaColumna != numMagico) {
            correcto = 0;
        }
    }

    // Verificar diagonales

    for (i = 0; i < num1; i++) {
        sumaDiagonal1 += cuadradoMagico[i][i];               // Diagonal principal
        sumaDiagonal2 += cuadradoMagico[i][num1 - 1 - i];    // Diagonal secundaria
    }

    printf("Suma de la diagonal principal: %d\n", sumaDiagonal1);
    printf("Suma de la diagonal secundaria: %d\n", sumaDiagonal2);

    if (sumaDiagonal1 != numMagico || sumaDiagonal2 != numMagico) {
        correcto = 0;
    }

    // Comprobar si es un cuadrado mágico

    if (correcto) {
        printf("\nEl cuadrado es mágico.\n");
        printf("El Número Mágico es: %d\n", numMagico);
    } else {
        printf("\nEl cuadrado NO es mágico.\n");
    }

    return 0;
}